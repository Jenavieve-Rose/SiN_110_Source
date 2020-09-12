//-----------------------------------------------------------------------------
//
//  $Logfile:: /Quake 2 Engine/Sin/code/game/light.cpp                        $
// $Revision:: 21                                                             $
//   $Author:: Aldie                                                          $
//     $Date:: 10/09/98 8:58p                                                 $
//
// Copyright (C) 1997 by Ritual Entertainment, Inc.
// All rights reserved.
//
// This source is may not be distributed and/or modified without
// expressly written permission by Ritual Entertainment, Inc.
//
// $Log:: /Quake 2 Engine/Sin/code/game/light.cpp                             $
// 
// 21    10/09/98 8:58p Aldie
// Lightstyle on lensflare from Lights
// 
// 20    9/22/98 5:19p Markd
// Fixed lights not removing themselves
// 
// 19    9/22/98 4:23p Markd
// Fixed some targetname stuff for lights, doors and scriptobjects
// 
// 18    9/14/98 11:20a Jimdose
// Made Light process EV_Remove so that we have more edicts at startup
// 
// 17    8/30/98 7:05p Markd
// lights don't respond to Touch.
// 
// 16    8/29/98 7:46p Markd
// Don't set a light style if style is < 32
// 
// 15    7/09/98 12:05a Jimdose
// made constructor post remove event instead of processing it
// 
// 14    6/25/98 8:47p Markd
// Added keyed items for Triggers, Rewrote Item class, rewrote every pickup
// method
// 
// 13    6/17/98 7:18p Markd
// Added on_style and off_style support
// 
// 12    5/24/98 8:46p Jimdose
// Made a lot of functions more str-friendly.
// Got rid of a lot of char * based strings
// Cleaned up get spawn arg functions and sound functions
// sound functions now use consistant syntax
// 
// 11    4/04/98 6:05p Jimdose
// Made response from EV_Trigger_ActivateTargets to EV_Trigger_Effect
// 
// 10    3/27/98 9:47p Jimdose
// Fixed light so that it reacts to activate targets events
// 
// 9     3/25/98 3:55p Jimdose
// fixed bug where lightramp wasn't responding to any events.
// 
// 8     3/23/98 1:31p Jimdose
// Revamped event and command system
// 
// 7     3/02/98 8:49p Jimdose
// Changed the classid parameter of CLASS_DECLARATION to a quoted string so
// that you could have a NULL classid.
// 
// 6     3/02/98 5:41p Jimdose
// Created file
// 
// DESCRIPTION:
// Classes for creating and controlling lights.
// 

#include "g_local.h"
#include "entity.h"
#include "trigger.h"
#include "light.h"
#include "scriptmaster.h"

CLASS_DECLARATION( Trigger, BaseLight, NULL );

Event EV_Light_TurnOn( "turnOn" );
Event EV_Light_TurnOff( "turnOff" );
Event EV_Light_SetLightStyle( "lightstyle" );

ResponseDef BaseLight::Responses[] =
	{
	   { &EV_Light_TurnOn,			( Response )Light::TurnOn },
	   { &EV_Light_TurnOff,			( Response )Light::TurnOff },
	   { &EV_Light_SetLightStyle,	( Response )Light::EventSetLightStyle },
		{ &EV_Touch,	NULL },
		{ NULL, NULL }
	};

BaseLight::BaseLight()
	{
	hideModel();
	edict->svflags |= SVF_NOCLIENT;
	setSolidType( SOLID_NOT );
	style = G_GetIntArg( "style" );
	on_style = G_GetStringArg( "onstyle", "m" );
	off_style = G_GetStringArg( "offstyle", "a" );
	respondto = TRIGGER_PLAYERS;
	}

int BaseLight::GetStyle
   (
   void
   )

   {
   return style;
   }

void BaseLight::SetLightStyle
	(
	const char *stylestring
	)

	{
   if ( style < 32 )
      return;
	lightstyle = stylestring;
	gi.configstring( CS_LIGHTS + style, lightstyle.c_str() );
	}

void BaseLight::EventSetLightStyle
	(
	Event *ev
	)

	{
	SetLightStyle( ev->GetString( 1 ) );
	}

void BaseLight::TurnOn
	(
	Event *ev
	)

	{
	SetLightStyle( on_style.c_str() );
	}

void BaseLight::TurnOff
	(
	Event *ev
	)

	{
	SetLightStyle( off_style.c_str() );
	}

/*****************************************************************************/
/*SINED light_ramp (0 .5 .8) (-8 -8 -8) (8 8 8) TOGGLE

Non-displayed light that ramps its intensity from one level to another when trigger.

time			How many seconds the ramping will take (default 1.0)
startlevel	Value between 0 and 2.0 (default 0)
endlevel		Value between 0 and 2.0 (default 1.0)
"key"       The item needed to activate this. (default nothing)

/*****************************************************************************/

CLASS_DECLARATION( BaseLight, LightRamp, "light_ramp" );

Event EV_RampLight( "ramplight" );

ResponseDef LightRamp::Responses[] =
	{
		{ &EV_Trigger_Effect,			( Response )LightRamp::StartRamp },
		{ &EV_RampLight,					( Response )LightRamp::RampLight },
		{ NULL, NULL }
	};

void LightRamp::RampLight
	(
	Event *ev
	)
	
	{
	char st[ 2 ];

	currentlevel += rate;
	if ( currentlevel >= maxlevel )
		{
		if ( !( spawnflags & 1 ) )
			{
			rate = 0;
			}
		currentlevel = maxlevel;
		}
	else if ( currentlevel <= minlevel )
		{
		if ( !( spawnflags & 1 ) )
			{
			rate = 0;
			}
		currentlevel = minlevel;
		}
	else
		{
		PostEvent( EV_RampLight, FRAMETIME );
		}

	st[ 0 ] = 'L';
	st[ 1 ] = 'a' + ( int )( currentlevel * 12.5 );
	st[ 1 ] = min( 'z', st[ 1 ] );
	st[ 1 ] = max( 'a', st[ 1 ] );
	st[ 2 ] = 0;

	SetLightStyle( st );
	}

void LightRamp::StartRamp
	(
	Event *ev
	)
	
	{
	if ( rate )
		{
		rate = -rate;
		CancelEventsOfType( EV_RampLight );
		ProcessEvent( EV_RampLight );
		}
	
	ActivateTargets( ev );
	}

LightRamp::LightRamp()
	{
	float		startlevel;
	float		endlevel;
	float		time;
	char		st[ 2 ];

	startlevel	= G_GetFloatArg( "startlevel", 1.0 );
	endlevel		= G_GetFloatArg( "endlevel", 0 );
	time			= G_GetFloatArg( "time", 1.0 );

	minlevel = min( startlevel, endlevel );
	maxlevel = max( startlevel, endlevel );

	minlevel = min( 2.0, minlevel );
	minlevel = max( 0, minlevel );
	
	maxlevel = min( 2.0, maxlevel );
	maxlevel = max( 0, maxlevel );

	rate		= FRAMETIME * ( maxlevel - minlevel ) / time;

	currentlevel = startlevel;

	st[ 0 ] = 'a' + ( int )( currentlevel * 12.5 );
	st[ 0 ] = min( 'z', st[ 0 ] );
	st[ 0 ] = max( 'a', st[ 0 ] );
	st[ 1 ] = 0;

	SetLightStyle( st );
	}

/*****************************************************************************/
/*SINED trigger_lightramp (0 1 0) (-8 -8 -8) (8 8 8) TOGGLE

Ramps light values on surface based light sources.
Set style to the identifier contained in groupname in the surfaces to control.

time			How many seconds the ramping will take (default 1.0)
startlevel	Value between 0 and 2.0 (default 0)
endlevel		Value between 0 and 2.0 (default 1.0)
"key"       The item needed to activate this. (default nothing)

Default style is 0.

/*****************************************************************************/

CLASS_DECLARATION( LightRamp, TriggerLightRamp, "trigger_lightramp" );

ResponseDef TriggerLightRamp::Responses[] =
	{
		{ NULL, NULL }
	};

/*****************************************************************************/
/*SINED light (0 1 0) (-8 -8 -8) (8 8 8) START_OFF

Non-displayed light.

Default light value is 300.
Default style is 0.

If targeted, will toggle between on and off.
Default _cone value is 10 (used to set size of light for spotlights)
"on_style" light style to set to when "on" (default is "m")
"off_style" light style to set to when "off" (default is "a")
"key"      The item needed to activate this. (default nothing)

/*****************************************************************************/

#define START_OFF	1

CLASS_DECLARATION( BaseLight, Light, "light" );

ResponseDef Light::Responses[] =
	{
		{ &EV_Trigger_Effect,		( Response )Light::ToggleLight },
		{ NULL, NULL }
	};

void Light::ToggleLight
	(
	Event *ev
	)

	{
	if ( style >= 32 )
		{
		if ( spawnflags & START_OFF )
			{
			ProcessEvent( EV_Light_TurnOn );
			spawnflags &= ~START_OFF;
			}
		else
			{
			ProcessEvent( EV_Light_TurnOff );
			spawnflags |= START_OFF;
			}
		}

	ActivateTargets( ev );
	}

Light::Light()
	{
   const char * tname;

   tname = TargetName();
	if ( !tname || !tname[ 0 ] )
		{
   	const char	*classname;

   	classname = G_GetSpawnArg( "classname" );
      if ( classname && !strcmp( classname, "light" ) )
         {
   		ProcessEvent( EV_Remove );
         }
		return;
		}

	if ( style >= 32 )
		{
		if ( spawnflags & START_OFF )
			{
			SetLightStyle( off_style.c_str() );
			}
		else
			{
			SetLightStyle( on_style.c_str() );
			}
		}
	}

/*****************************************************************************/
/*SINED trigger_SetLightStyle (0 1 0) (-8 -8 -8) (8 8 8) START_OFF

Used for controlling surface based light sources.

Set style to the identifier contained in groupname in the surfaces to control.

Default style is 0.

If targeted, will toggle between on and off.

"on_style" light style to set to when "on" (default is "m")
"off_style" light style to set to when "off" (default is "a")
"key"      The item needed to activate this. (default nothing)

/*****************************************************************************/

CLASS_DECLARATION( Light, TriggerLightStyle, "trigger_SetLightStyle" );

ResponseDef TriggerLightStyle::Responses[] =
	{
		{ NULL, NULL }
	};
