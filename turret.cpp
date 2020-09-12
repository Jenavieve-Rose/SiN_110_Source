//-----------------------------------------------------------------------------
//
//  $Logfile:: /Quake 2 Engine/Sin/code/game/turret.cpp                       $
// $Revision:: 35                                                             $
//   $Author:: Aldie                                                          $
//     $Date:: 11/06/98 9:26p                                                 $
//
// Copyright (C) 1998 by Ritual Entertainment, Inc.
// All rights reserved.
//
// This source is may not be distributed and/or modified without
// expressly written permission by Ritual Entertainment, Inc.
//
// $Log:: /Quake 2 Engine/Sin/code/game/turret.cpp                            $
// 
// 35    11/06/98 9:26p Aldie
// Moved spawning of explosion to centroid of turret
// 
// 34    10/21/98 12:10a Aldie
// Added EV_Activate to the responses.
// 
// 33    10/15/98 5:02p Markd
// Fixed turret problems with invulnerability
// 
// 32    10/15/98 3:37p Markd
// Added forcefield to turrets with no health
// 
// 31    10/14/98 12:13a Aldie
// Don't need to mess with AttackFinished for turrets
// 
// 30    10/13/98 7:14p Aldie
// Fixed a warning when no thread was found
// 
// 29    10/13/98 2:30p Aldie
// Fix attack_finished to update the weapon as well.
// 
// 28    10/09/98 4:54p Markd
// Changed script code to ExecuteThread
// 
// 27    9/30/98 5:39p Aldie
// Added showinfo command
// 
// 26    9/30/98 4:36p Aldie
// Fixed some weirdness with turrets.
// 
// 25    9/30/98 3:42p Markd
// put in bulletproofing for start thread functions
// 
// 24    9/23/98 5:19p Markd
// Put DAMAGE_NO in killed functions of these classes
// 
// 23    9/22/98 4:57p Aldie
// Moved lagtime check right before firing
// 
// 22    9/20/98 9:09p Aldie
// Fixed patience and lagtime for turrets
// 
// 21    9/20/98 5:13p Aldie
// Changed some stuff with the thread and targeting when the turret sees a
// player
// 
// 20    9/19/98 6:14p Aldie
// Added trigger targets and thread to turrets
// 
// 19    9/15/98 6:45p Aldie
// Fixed some sound aliases
// 
// 18    9/01/98 3:05p Markd
// Rewrote explosion code
// 
// 17    8/29/98 9:46p Jimdose
// Added call info to G_Trace
// 
// 16    8/29/98 5:27p Markd
// added specialfx, replaced misc with specialfx where appropriate
// 
// 15    8/18/98 11:08p Markd
// Added new Alias System
// 
// 14    7/26/98 6:54a Aldie
// Removed setting of takedamage.  This is now the responsibility of the
// subclass
// 
// 13    7/25/98 7:19p Aldie
// Client side explosion
// 
// 12    7/23/98 7:12p Aldie
// Update turret stuff so it triggers it's targets
// 
// 11    7/23/98 12:17p Aldie
// Removed takedamage=no from the down event
// 
// 10    7/22/98 8:40p Aldie
// Deactivate a turret will make it go down.
// 
// 9     7/22/98 5:16p Aldie
// Changed general behavior
// 
// 8     7/17/98 4:42p Aldie
// Made "fire" call an event when it's through
// 
// 7     7/10/98 5:39p Aldie
// Moved some settings from base class to subclasses
// 
// 6     7/10/98 3:07p Aldie
// Activate and deactivate turrets.
// 
// 5     7/07/98 4:11p Aldie
// New version of turret
//
// DESCRIPTION:
// Generic turret

#include "g_local.h"
#include "turret.h"
#include "explosion.h"
#include "misc.h"
#include "weapon.h"
#include "specialfx.h"

Event EV_Turret_GoUp( "raise" );
Event EV_Turret_GoDown( "lower" );
Event EV_Turret_Down( "down" );
Event EV_Turret_Seek( "seek" );
Event EV_Turret_Turn( "turn" );
Event EV_Turret_EndSeek( "endseek" );
Event EV_Turret_Attack( "attack" );
Event EV_Turret_CheckVicinity( "checkvicinity" );
Event EV_Turret_AttackStart( "attack_start" );
Event EV_Turret_AttackFinished( "attack_finished" );
Event EV_Turret_Activate( "activate" );
Event EV_Turret_Deactivate( "deactivate" );
Event EV_Turret_Lagtime( "lagtime" );
Event EV_Turret_SetSightTime( "setsighttime" );

CLASS_DECLARATION( Sentient, Turret, NULL )

ResponseDef Turret::Responses[] =
	{
	   { &EV_Turret_GoUp,				( Response )Turret::GoUp },
	   { &EV_Turret_GoDown,				( Response )Turret::GoDown },
		{ &EV_Turret_Down,				( Response )Turret::Down },
		{ &EV_Turret_Seek,				( Response )Turret::Seek },
		{ &EV_Turret_Turn,				( Response )Turret::Turn },
		{ &EV_Turret_EndSeek,			( Response )Turret::EndSeek },
		{ &EV_Turret_Attack,				( Response )Turret::Fire },
		{ &EV_Turret_CheckVicinity,	( Response )Turret::CheckVicinity },
		{ &EV_Turret_AttackStart,		( Response )Turret::AttackStart },
		{ &EV_Turret_AttackFinished,	( Response )Turret::AttackFinished },
      { &EV_Turret_Activate,	      ( Response )Turret::Activate },
      { &EV_Turret_Deactivate,	   ( Response )Turret::Deactivate },
      { &EV_Turret_Lagtime,	      ( Response )Turret::Lagtime },
      { &EV_Turret_SetSightTime,    ( Response )Turret::SetSightTime },
		{ &EV_Pain,							( Response )Turret::Pain },
		{ &EV_Killed,						( Response )Turret::Killed },
		{ &EV_Activate,					( Response )Turret::Activate },
      { NULL, NULL }
	};

void Turret::Lagtime
   (
   Event *ev
   )

   {
   lagtime = ev->GetFloat( 1 );
   }

Turret::Turret
	(
	void
	)

	{
   str            hstr;

	base				= 0;
	enemy				= 0;
	lastSightTime	= 0;
	attacking		= false;
	turning			= false;
	active			= false;
	turntime			= 0;

   thread         = G_GetStringArg( "sightthread", "" );
   sight_target   = G_GetStringArg( "sighttarget", "" );
   patience       = G_GetFloatArg( "patience", 1 );
   lagtime        = G_GetFloatArg( "lagtime", 0 );
   firetime       = 0;

   takedamage		= DAMAGE_YES;

   hstr = G_GetStringArg( "health" );
   if ( hstr != "" )
      {
      health = G_GetFloatArg( "health" );
      if ( health )
         {
         flags |= FL_SPARKS;
         }
      else
         {
         flags |= FL_FORCEFIELD;
         }
      }
   else
      {
      flags |= FL_SPARKS;
      }

   if ( Targeted() )
      activated = false;
   else
      activated = true;
	}

void Turret::Activate
   (
   Event *ev
   )

   {
   activated = true;
   firetime = level.time + lagtime;
   }

void Turret::Deactivate
   (
   Event *ev
   )

   {
   activated = false;
   ProcessEvent( EV_Turret_GoDown );
   }

void Turret::Killed
	(
	Event *ev
	)

	{
   Entity      *attacker;
   Vector      dir;
   int         power;
   const char  *name;
   int         num;
   Entity      *ent;
   Event       *event;

   takedamage = DAMAGE_NO;
   attacker		= ev->GetEntity( 1 );
	power    	= ev->GetInteger( 2 );
	if ( power < 40 )
		{
		power = 40;
		}

	ProcessEvent( EV_BreakingSound );

   dir = worldorigin - attacker->worldorigin;
	CreateExplosion( centroid, 30, 0.5, true, this, attacker, this );
   //
   // kill the killtargets
   //
	name = KillTarget();
	if ( name && strcmp( name, "" ) )
		{
		num = 0;
		do
			{
			num = G_FindTarget( num, name );
			if ( !num )
				{
				break;
				}

			ent = G_GetEntity( num );
			ent->PostEvent( EV_Remove, 0 );
			} 
		while ( 1 );
		}
		
   //
   // fire targets
   //
	name = Target();
	if ( name && strcmp( name, "" ) )
		{
		num = 0;
		do
			{
			num = G_FindTarget( num, name );
			if ( !num )
				{
				break;
				}

			ent = G_GetEntity( num );
		
			event = new Event( EV_Activate );
			event->AddEntity( attacker );
			ent->PostEvent( event, 0 );
			}
		while ( 1 );
		}

	ProcessEvent( EV_Turret_GoDown );
   PostEvent( EV_Remove, 0 );
	}

qboolean Turret::CanSee
	(
	Entity *ent
	)

	{
	Vector delta;
	Vector start;
	Vector end;
	trace_t trace;

	start = worldorigin + gunoffset;
	end = ( ent->absmin + ent->absmax ) * 0.5;

	// Check if he's visible
	trace = G_Trace( start, vec_zero, vec_zero, end, this, MASK_OPAQUE, "Turret::CanSee" );
	if ( trace.fraction == 1.0 || trace.ent == ent->edict )
		{
		return true;
		}

	return false;
	}

int Turret::Range
	( 
	float dist
	)

   {
	if ( dist > wakeupdistance )
		{
		return TURRET_OUTOFRANGE;
		}
	if ( dist > firingdistance )
		{
		return TURRET_WAKEUPRANGE;
		}
	return TURRET_FIRERANGE;
	}

float Turret::Distance
	( 
	Entity *targ 
	)

   {
	Vector delta;
	
	delta = worldorigin + gunoffset - ( targ->absmin + targ->absmax ) * 0.5;
	return delta.length();
	}

void Turret::Pain
	(
	Event *ev
	)

	{
	Entity	*attacker;
	Vector	dir;

	if ( takedamage == DAMAGE_NO )
		{
		return;
		}

	attacker		= ev->GetEntity( 2 );

   dir = worldorigin - attacker->worldorigin;

   if ( attacker != this )
	   enemy = attacker->entnum;
	}

qboolean Turret::FindTarget
	( 
	void 
	)

   {
   Entity	*ent;
	edict_t	*ed;
	int		i;
	float		dist;
	float		bestdist;
	Entity	*bestent;

	bestent = NULL;
	bestdist = wakeupdistance + 1;
	for( i = 0; i < game.maxclients; i++ )
		{
		ed = &g_edicts[ 1 + i ];
		if ( !ed->inuse || !ed->entity )
			{
			continue;
			}

		ent = ed->entity;
	   if ( ( ent->health < 0 ) || ( ent->flags & FL_NOTARGET ) )
			{
			continue;
			}

		dist = Distance( ent );
		if ( Range( dist ) == TURRET_OUTOFRANGE )
			{
			continue;
			}

		if ( ( dist < bestdist ) && CanSee( ent ) )
			{
			bestent = ent;
			bestdist = dist;
			}
		}
	
	if ( bestent )
		{
		enemy = bestent->entnum;
		return true;
		}

	enemy = 0;
	return false;
	}

//FIXME
// make this a common function
float Turret::AdjustAngle
	(
	float maxadjust,
	float currangle,
	float targetangle
	)

   {
   float dangle;
	float magangle;

	dangle = currangle - targetangle;

	if ( dangle )
		{
		magangle = ( float )fabs( dangle );
		if ( magangle < maxadjust )
			{
			currangle = targetangle;
			}
		else 
			{
			if ( magangle > 180.0f  )
				{
				maxadjust = -maxadjust;
				}
			if ( dangle > 0 )
				{
				maxadjust = -maxadjust;
				}
			currangle += maxadjust;
			}
		}

	while( currangle >= 360.0f )
		{
		currangle -= 360.0f;
		}

	while( currangle < 0.0f )
		{
		currangle += 360.0f;
		}

	return currangle;
	}

void Turret::Seek
	(
	Event *ev
	)

	{
	Entity	*ent;
	Vector	v;
	Vector	s;
	float		t;
	int		range;
	Vector	f;
	
	active = true;
	ent = NULL;
	if ( enemy )
		{
		ent = G_GetEntity( enemy );
		if ( ( !ent ) || ( ent->health <= 0 ) || ( ent->flags & FL_NOTARGET ) )
			{
			enemy = 0;
			ent = NULL;
			}
		else
			{
			range = Range( Distance( ent ) );
			}
		}

	if ( ( lastSightTime ) && ( ( lastSightTime + patience ) < level.time ) )
		{
		ProcessEvent( EV_Turret_GoDown );
		}

	if ( !enemy )
		{
		FindTarget();
		PostEvent( EV_Turret_Seek, FRAMETIME * 2 );
		return;
		}

	if ( ( range != TURRET_OUTOFRANGE ) && ent && CanSee( ent ) )
		{
		lastSightTime = level.time;

		v = ent->worldorigin - worldorigin;
		neworientation = v.toYaw();
		}

	if ( ( angles.y != neworientation ) && !turning )
		{
		ProcessEvent( EV_Turret_Turn );
		}

	t = worldorigin.z + gunoffset.z;
	if ( ( !attacking ) && ( t < ent->absmax.z ) && ( t > ent->absmin.z ) && 
		( range == TURRET_FIRERANGE ) )
		{
      // Allow some freetime to let player get somewhere before turret shoots
      if ( level.time < firetime )
         {
    	   PostEvent( EV_Turret_Seek, FRAMETIME * 2 );
         return;
         }
		ProcessEvent( EV_Turret_Attack );
		}

	PostEvent( EV_Turret_Seek, FRAMETIME * 2 );
	}

void Turret::Fire
	(
	Event *ev
	)

	{
   RandomAnimate( "fire", EV_Turret_AttackFinished );
	}

void Turret::Turn
	(
	Event *ev
	)

	{
	if ( angles[ 1 ] != neworientation )
		{
		turntime = level.time + 0.2;
		if ( !turning )
			{
			ProcessEvent( EV_MachineSound );
			RandomSound( "snd_seek", 1 );
			turning = true;
			}
		}
	else if ( turntime < level.time )
		{
		turning = false;
		ProcessEvent( EV_MachineSound );
		RandomSound( "snd_stop", 1 );
		return;
		}

	angles[ 1 ] = AdjustAngle( 12, angles[ 1 ], neworientation );	
	setAngles( angles );
	PostEvent( EV_Turret_Turn, FRAMETIME );
	}

void Turret::EndSeek
	(
	Event *ev
	)

	{
   RandomSound( "snd_stop", 1 );
	CancelEventsOfType( EV_Turret_Seek );
	CancelEventsOfType( EV_Turret_Turn );
   CancelEventsOfType( EV_Turret_Attack );
   ProcessEvent( EV_Turret_AttackFinished );
	turning = false;
	lastSightTime = 0;
	enemy = false;
	active = false;
	}

void Turret::CheckVicinity
	(
	Event *ev
	)

	{
	Event *e;

   if ( activated  && FindTarget() )
      {
		e = new Event( EV_Turret_GoUp );
		e->AddEntity( G_GetEntity( enemy ) );
		ProcessEvent( e );
      }
	}

void Turret::SetSightTime
   (
   Event *ev 
   )

   {
   lastSightTime = level.time;
   }

void Turret::GoUp
	(
	Event *ev
	)

	{
	Entity      *b;
	Entity      *ent;
   const char  *name;
   int         num;
   Event       *event;

	lastSightTime = level.time;
	ent = ev->GetEntity( 1 );
	enemy = ent->entnum;

	if ( !active )
		{
		active = true;
		}

   if ( base )
      {
   	b = G_GetEntity( base );
	   assert( b );
	   if ( b )
		   {
		   b->ProcessEvent( EV_Turret_GoUp );
	   	}
      }
   
   firetime = level.time + lagtime;

   RandomAnimate( "raise", EV_Turret_SetSightTime );

   // Turret just woke up, trigger targets and call thread.
 	name = sight_target.c_str();
	if ( name && strcmp( name, "" ) )
		{
		num = 0;
		do
			{
			num = G_FindTarget( num, name );
			if ( !num )
				{
				break;
				}

			ent = G_GetEntity( num );
		
			event = new Event( EV_Activate );
			event->AddEntity( G_GetEntity( enemy ) );
			ent->PostEvent( event, 0 );
			}
		while ( 1 );
		}

   if ( thread.length() && !ExecuteThread( thread ) )
      {
      warning( "GoUp", "%s not found.", thread.c_str() );
      }
	}

void Turret::GoDown
	(
	Event *ev
	)

	{
	Entity *b;

	if ( base )
      {
      b = G_GetEntity( base );
	   assert( b );
	   if ( b )
		   {
		   b->ProcessEvent( EV_Turret_GoDown );
		   }
      }
	ProcessEvent( EV_Turret_EndSeek );
	RandomAnimate( "lower", EV_Turret_Down );
	}

void Turret::Down
	(
	Event *ev
	)

	{
	}

void Turret::AttackStart
	(
   Event *ev
	)

	{
	attacking = true;
	}

void Turret::AttackFinished
	(
	Event *ev
	)

	{
	attacking = false;
   }

