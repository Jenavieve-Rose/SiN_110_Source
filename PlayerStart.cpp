//-----------------------------------------------------------------------------
//
//  $Logfile:: /Quake 2 Engine/Sin/code/game/PlayerStart.cpp                  $
// $Revision:: 14                                                             $
//   $Author:: Jimdose                                                        $
//     $Date:: 12/15/98 6:17p                                                 $
//
// Copyright (C) 1997 by Ritual Entertainment, Inc.
// All rights reserved.
//
// This source is may not be distributed and/or modified without
// expressly written permission by Ritual Entertainment, Inc.
//
// $Log:: /Quake 2 Engine/Sin/code/game/PlayerStart.cpp                       $
// 
// 14    12/15/98 6:17p Jimdose
// made ProgressiveStart respond to EV_Activate
// 
// 13    12/09/98 8:05p Jimdose
// added progressive start
// 
// 12    8/14/98 8:18p Markd
// reworked camera class
// 
// 11    8/08/98 7:29p Aldie
// Added intermissions for deathmatch
// 
// 10    3/23/98 1:31p Jimdose
// Revamped event and command system
// 
// 9     3/02/98 8:49p Jimdose
// Changed the classid parameter of CLASS_DECLARATION to a quoted string so
// that you could have a NULL classid.
// 
// 8     2/19/98 5:08p Jimdose
// Changed offset of SINED entity box
// 
// 7     2/04/98 4:32p Jimdose
// Added Sined headers
// 
// 6     2/03/98 10:51a Jimdose
// Updated to work with Quake 2 engine
// Moved initialization to constructor and removed Init function
// 
// 5     1/23/98 3:04p Jimdose
// Made compatible with Q2 based progs
// 
// 3     10/27/97 3:29p Jimdose
// Removed dependency on quakedef.h
// 
// 2     9/26/97 6:47p Jimdose
// Added standard Ritual headers
//
// DESCRIPTION:
// Player start location entity declarations
// 

#include "g_local.h"
#include "entity.h"
#include "trigger.h"
#include "PlayerStart.h"

/*****************************************************************************/
/*SINED info_player_start (1 0 0) (-16 -16 0) (16 16 64)

The normal starting point for a level.

/*****************************************************************************/

CLASS_DECLARATION( Entity, PlayerStart, "info_player_start" );

ResponseDef PlayerStart::Responses[] =
	{
		{ NULL, NULL }
	};

PlayerStart::PlayerStart()
	{
	float angle;

	angle = G_GetFloatArg( "angle", 0 );
	angles = Vector( 0, angle, 0 );
	}

/*****************************************************************************/
/*SINED info_player_progressivestart (1 0 0) (-16 -16 0) (16 16 64)

Starting point for a level.  When triggered, sets next spawnpoint to itself.
Used for respawn point in Sin Arcade.  This must have a targetname for it to work.

"starthere" set to 1 to make this the default spawnpoint.  (Note: multiple progressive
starts with starthere set will override each other).

/*****************************************************************************/

CLASS_DECLARATION( PlayerStart, ProgressiveStart, "info_player_progressivestart" );

ResponseDef ProgressiveStart::Responses[] =
	{
		{ &EV_Activate,		   ( Response )ProgressiveStart::SetSpawnpoint },
		{ NULL, NULL }
	};

ProgressiveStart::ProgressiveStart()
	{
   if ( !targetname.length() )
      {
      gi.error( "ProgressiveStart without targetname at (%f,%f,%f)\n", origin.x, origin.y, origin.z );
      }

   if ( G_GetIntArg( "starthere" ) )
      {
      game.spawnpoint = targetname;
      }
	}

void ProgressiveStart::SetSpawnpoint
   (
   Event *ev
   )

   {
   game.spawnpoint = targetname;
   }
	
/*****************************************************************************/
/*  saved out by quaked in region mode

/*****************************************************************************/

CLASS_DECLARATION( PlayerStart, TestPlayerStart, "testplayerstart" );

ResponseDef TestPlayerStart::Responses[] =
	{
		{ NULL, NULL }
	};

/*****************************************************************************/
/*SINED info_player_deathmatch (1 0 1) (-16 -16 0) (16 16 64)

potential spawning position for deathmatch games

/*****************************************************************************/

CLASS_DECLARATION( PlayerStart, PlayerDeathmatchStart, "info_player_deathmatch" );

ResponseDef PlayerDeathmatchStart::Responses[] =
	{
		{ NULL, NULL }
	};

/*****************************************************************************/
/*SINED info_player_coop (1 0 1) (-16 -16 0) (16 16 64)

potential spawning position for coop games

/*****************************************************************************/

CLASS_DECLARATION( PlayerStart, PlayerCoopStart, "info_player_coop" );

ResponseDef PlayerCoopStart::Responses[] =
	{
		{ NULL, NULL }
	};

/*****************************************************************************/
/*SINED info_player_intermission (1 0 1) (-16 -16 0) (16 16 64)

viewing point in between deathmatch levels

/*****************************************************************************/

CLASS_DECLARATION( Camera, PlayerIntermission, "info_player_intermission" );

ResponseDef PlayerIntermission::Responses[] =
	{
		{ NULL, NULL }
	};

PlayerIntermission::PlayerIntermission
   (
   )

   {
   currentstate.watch.splineangles = false;
   newstate.watch.splineangles = false;
   }