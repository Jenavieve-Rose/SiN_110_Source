//-----------------------------------------------------------------------------
//
//  $Logfile:: /Quake 2 Engine/Sin/code/game/g_phys.h                         $
// $Revision:: 5                                                              $
//   $Author:: Jimdose                                                        $
//     $Date:: 11/13/98 10:04p                                                $
//
// Copyright (C) 1998 by Ritual Entertainment, Inc.
// All rights reserved.
//
// This source is may not be distributed and/or modified without
// expressly written permission by Ritual Entertainment, Inc.
//
// $Log:: /Quake 2 Engine/Sin/code/game/g_phys.h                              $
// 
// 5     11/13/98 10:04p Jimdose
// added G_CheckWater
// got rid of unused physics functions
// 
// 4     10/04/98 10:28p Aldie
// Added multiple weapon changes.  Damage, flashes, quantum stuff
// 
// 3     9/14/98 6:12p Markd
// Added MOVETYPE_VEHICLE
// 
// 2     8/29/98 9:49p Jimdose
// created file
// 
// 1     8/29/98 6:44p Jimdose
//
// DESCRIPTION:
// Global header file for g_phys.cpp
// 

#ifndef __G_PHYS_H__
#define __G_PHYS_H__

#include "g_local.h"

typedef enum
	{
	STEPMOVE_OK,
	STEPMOVE_BLOCKED_BY_ENTITY,
	STEPMOVE_BLOCKED_BY_WORLD,
	STEPMOVE_BLOCKED_BY_WATER,
	STEPMOVE_BLOCKED_BY_FALL,
	STEPMOVE_STUCK,
	} stepmoveresult_t;

#define	STEPSIZE	18

// movetype values
typedef enum
	{
	MOVETYPE_NONE,			// never moves
	MOVETYPE_NOCLIP,		// origin and angles change with no interaction
	MOVETYPE_PUSH,			// no clip to world, push on box contact
	MOVETYPE_STOP,			// no clip to world, stops on box contact
	MOVETYPE_WALK,			// gravity
	MOVETYPE_STEP,			// gravity, special edge handling
	MOVETYPE_FLY,
	MOVETYPE_TOSS,			// gravity
	MOVETYPE_FLYMISSILE,	// extra size to monsters
	MOVETYPE_BOUNCE,
   MOVETYPE_SLIDE,
   MOVETYPE_VEHICLE,
   MOVETYPE_HURL
	} movetype_t;

void		G_RunEntity (Entity *ent);
void		G_Impact( Entity *e1, trace_t *trace );
qboolean	G_PushMove( Entity *pusher, Vector move, Vector amove );
void     G_CheckWater( Entity *ent );

#endif /* g_phys.h */
