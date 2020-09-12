//-----------------------------------------------------------------------------
//
//  $Logfile:: /Quake 2 Engine/Sin/code/game/doors.cpp                        $
// $Revision:: 71                                                             $
//   $Author:: Markd                                                          $
//     $Date:: 11/16/98 9:48p                                                 $
//
// Copyright (C) 1997 by Ritual Entertainment, Inc.
// All rights reserved.
//
// This source is may not be distributed and/or modified without
// expressly written permission by Ritual Entertainment, Inc.
//
// $Log:: /Quake 2 Engine/Sin/code/game/doors.cpp                             $
// 
// 71    11/16/98 9:48p Markd
// made door sounds always stop to kill looping sounds
// 
// 70    11/13/98 4:35p Jimdose
// doors weren't staying open when wait was -1
// 
// 69    10/24/98 3:25a Jimdose
// open was postponing the close event further and further into the future due
// to touchfield activation.  Changed it to a cancel and a post of close.
// fixes doors staying open
// 
// 68    10/24/98 12:42a Markd
// changed origins to worldorigins where appropriate
// 
// 67    10/23/98 11:10p Jimdose
// removed trigger_finished
// Close now cancels pending close events.  Hopefully this fixes the spinning
// door bug.
// 
// 66    10/23/98 10:12p Jimdose
// fixed bug where doors don't close after actors open them
// fixed code that determines direction door should open
// 
// 65    10/21/98 10:58p Jimdose
// fixed (hopefully) most of the door bugs
// 
// 64    10/21/98 2:35a Jimdose
// Don't spawn trigger field when DOOR_TOGGLE is set
// 
// 63    10/19/98 12:07a Jimdose
// made all code use fast checks for inheritance (no text lookups when
// possible)
// isSubclassOf no longer requires ::_classinfo()
// 
// 62    10/16/98 8:24p Jimdose
// Put some extra checks in to make sure master is set
// 
// 61    10/07/98 4:11p Markd
// Fixed using of doors
// 
// 60    10/06/98 6:07p Markd
// Fixed door message code
// 
// 59    10/02/98 7:45p Markd
// put in more door debug info
// 
// 58    9/30/98 3:42p Markd
// put in bulletproofing for start thread functions
// 
// 57    9/24/98 1:50a Jimdose
// Fixed side of door checks when opening doors
// 
// 56    9/23/98 2:19p Markd
// made all doors play sounds not just the masters
// 
// 55    9/23/98 1:31p Markd
// changed default door sound documentation
// 
// 54    9/22/98 4:23p Markd
// Fixed some targetname stuff for lights, doors and scriptobjects
// 
// 53    9/03/98 9:07p Jimdose
// Added CanBeOpenedBy so that the AI can check if a door is useable by an
// actor
// changed owner to master
// Fixed bug with doors that don't stop
// opened doors can be used again to close them
// fixed door blocked
// 
// 52    8/28/98 4:14p Markd
// Added sound_locked support
// 
// 51    8/26/98 6:43p Jimdose
// doors now only show the item needed when other is a client
// 
// 50    8/24/98 6:10p Markd
// Added killable doors, that stop for nothing
// 
// 49    8/24/98 5:47p Markd
// Fixed triggerable doors
// 
// 48    8/24/98 11:32a Markd
// Added Start method to threads, repladed all ProcessEvent(
// EV_ScriptThread_execute) with thread->Start( -1 )
// 
// 47    8/21/98 3:48p Markd
// Added openthread and closethread events
// 
// 46    8/21/98 1:43a Markd
// Added full ScriptDoor functionality
// 
// 45    8/18/98 11:08p Markd
// Added new Alias System
// 
// 44    8/15/98 10:42a Markd
// took out auto-open for actors for non-sin-demo
// 
// 43    8/14/98 8:18p Markd
// Fixed silly str thing to get rid of weird messages.
// 
// 42    8/13/98 4:57p Jimdose
// Made Open check if there are any event args.  If not, it prints a warning so
// that the level designers know.
// 
// 41    8/03/98 7:52p Jimdose
// added hack fix doors for matt
// 
// 40    7/29/98 2:31p Aldie
// Changed health to a float
// 
// 39    7/26/98 3:40p Jimdose
// locked doors don't autoopen for actors
// 
// 38    7/26/98 9:51a Markd
// fixed "snd_locked" bug
// 
// 37    7/26/98 9:22a Jimdose
// Doors auto-open for actors
// 
// 36    7/26/98 1:03a Markd
// Fixed door trigger field
// 
// 35    7/26/98 12:48a Jimdose
// Fixed calculating bbox in LinkDoors
// 
// 34    7/23/98 6:17p Aldie
// Updated damage system and fixed some damage related bugs.  Also put tracers
// back to the way they were, and added gib event to funcscriptmodels
// 
// 33    7/21/98 4:22p Aldie
// Make icons work for locks
// 
// 32    7/21/98 1:10p Aldie
// Added meansofdeath to obituaries
// 
// 31    7/20/98 10:15a Markd
// Fixed funky door problem
// 
// 30    7/18/98 4:42p Markd
// Added snd_locked support for locked doors
// 
// 29    7/11/98 4:49p Markd
// Fixed minor bug in door code with not setting other
// 
// 28    7/11/98 4:46p Markd
// Fixed doors not being lockable
// 
// 27    7/10/98 10:34p Markd
// Fixed locked doors
// 
// 26    7/10/98 2:09p Markd
// Added locking capability to doors
// 
// 25    6/30/98 6:03p Jimdose
// TryOpen now checks if other is NULL
// 
// 24    6/28/98 3:15p Markd
// Fixed sliding doors
// 
// 23    6/27/98 2:17p Aldie
// Updated centerprint to use new method
// 
// 22    6/25/98 8:48p Markd
// Merged RotatingDoors and regular Doors
// 
// 21    6/24/98 8:45p Markd
// Rewrote door code
// 
// 12    6/17/98 10:14p Jimdose
// Added isOpen for AI
// Made doors stay open while an entity is in its trigger field.
// 
// 11    6/10/98 2:10p Aldie
// Updated damage function.
// 
// 10    6/04/98 4:35p Markd
// made door sounds not use PHS
// 
// 9     5/24/98 8:55p Jimdose
// Removed the char * cast from soundindex call
// 
// 8     5/24/98 8:46p Jimdose
// Made a lot of functions more str-friendly.
// Got rid of a lot of char * based strings
// Cleaned up get spawn arg functions and sound functions
// sound functions now use consistant syntax
// 
// 7     5/24/98 3:42p Markd
// fixed str bug
// 
// 6     5/24/98 2:46p Markd
// Made char *'s into const char *'s
// 
// 5     5/24/98 1:04a Jimdose
// Added sound events for ai
// 
// 4     5/22/98 9:38p Jimdose
// added DoorBlocked
// 
// 3     5/03/98 4:36p Jimdose
// Changed Vector class
// 
// 2     4/29/98 9:55p Jimdose
// Created file
// 
// DESCRIPTION:
// Doors are environment objects that rotate open when activated by triggers
// or when used by the player.
// 

#include "g_local.h"
#include "entity.h"
#include "trigger.h"
#include "mover.h"
#include "doors.h"
#include "sentient.h"
#include	"areaportal.h"
#include "scriptmaster.h"
#include "item.h"
#include "actor.h"
#include "player.h"

Event EV_Door_TriggerFieldTouched( "door_triggerfield" );
Event EV_Door_TryOpen( "tryToOpen" );
Event EV_Door_Close( "close" );
Event EV_Door_Open( "open" );
Event EV_Door_DoClose( "doclose" );
Event EV_Door_DoOpen( "doopen" );
Event EV_Door_CloseEnd( "doorclosed" );
Event EV_Door_OpenEnd( "dooropened" );
Event EV_Door_Fire( "toggledoor" );
Event EV_Door_Link( "linkdoor" );
Event EV_Door_SetTime( "time" );
Event EV_Door_Lock( "lock" );
Event EV_Door_Unlock( "unlock" );

CLASS_DECLARATION( ScriptSlave, Door, "NormalDoor" );

#define DOOR_START_OPEN			1
#define DOOR_OPEN_DIRECTION	2
#define DOOR_DONT_LINK			4
#define DOOR_TOGGLE				32
#define DOOR_AUTO_OPEN			64
#define DOOR_TARGETED 			128

#define STATE_OPEN		1
#define STATE_OPENING	2
#define STATE_CLOSING   3
#define STATE_CLOSED		4

/*

Doors are similar to buttons, but can spawn a fat trigger field around them
to open without a touch, and they link together to form simultanious
double/quad doors.
 
Door.master is the master door.  If there is only one door, it points to itself.
If multiple doors, all will point to a single one.

Door.enemy chains from the master door through all doors linked in the chain.

*/

ResponseDef Door::Responses[] =
	{
		{ &EV_Door_TriggerFieldTouched,  ( Response )Door::FieldTouched },
	   { &EV_Trigger_Effect,			   ( Response )Door::TryOpen },
	   { &EV_Activate,			         ( Response )Door::TryOpen },
	   { &EV_Door_TryOpen,	            ( Response )Door::TryOpen },
	   { &EV_Door_Close,		            ( Response )Door::Close },
	   { &EV_Door_Open,		            ( Response )Door::Open },
	   { &EV_Door_CloseEnd,	            ( Response )Door::CloseEnd },
		{ &EV_Door_OpenEnd,	            ( Response )Door::OpenEnd },
	   { &EV_Door_Fire,		            ( Response )Door::DoorFire },
	   { &EV_Door_Link,		            ( Response )Door::LinkDoors },
	   { &EV_Door_SetTime,	            ( Response )Door::SetTime },
	   { &EV_Use,							   ( Response )Door::DoorUse },
	   { &EV_Killed,						   ( Response )Door::DoorFire },
	   { &EV_Blocked,						   ( Response )Door::DoorBlocked },
	   { &EV_Door_Lock,		            ( Response )Door::LockDoor },
	   { &EV_Door_Unlock,		         ( Response )Door::UnlockDoor },
	   { &EV_Touch,						   NULL },
		{ NULL, NULL }
	};

Door::Door()
	{
	float t;

	nextdoor = 0;
	trigger = 0;
   locked = false;
   master = this;
   lastblocktime = 0;
   diropened = 0;

	showModel();

	sound_stop		= G_GetStringArg( "sound_stop", gi.GlobalAlias_FindRandom( "door_stop" ) );
	sound_move		= G_GetStringArg( "sound_move", gi.GlobalAlias_FindRandom( "door_moving" ) );
	sound_message	= G_GetStringArg( "sound_message" );
	sound_locked	= G_GetStringArg( "sound_locked" );

	gi.soundindex( sound_stop.c_str() );
	gi.soundindex( sound_move.c_str() );
   if ( sound_message.length() > 1 )
	   gi.soundindex( sound_message.c_str() );

	health		= G_GetFloatArg( "health" );
	max_health	= health;

	traveltime = G_GetFloatArg( "time", 0.3 );

	if ( traveltime < FRAMETIME )
		{
		traveltime = FRAMETIME;
		}

	speed = 1.0f / traveltime;
	wait	= G_GetFloatArg( "wait", 3 );

   if ( ( spawnflags & DOOR_TOGGLE ) && ( wait == 3 ) )
      wait = 0;

	dmg = G_GetIntArg( "dmg", 0 );

	setSolidType( SOLID_BSP );
	setMoveType( MOVETYPE_PUSH );

	setSize( mins, maxs );

	dir = G_GetMovedir();
	t = dir[ 0 ];
	dir[ 0 ] = -dir[ 1 ];
	dir[ 1 ] = t;

	setOrigin( origin );
	doormin = absmin;
	doormax = absmax;


	// DOOR_START_OPEN is to allow an entity to be lighted in the closed position
	// but spawn in the open position
	if ( spawnflags & DOOR_START_OPEN )
		{
		state = STATE_OPEN;
   	PostEvent( EV_Door_Open, 0.05f );
		}
	else
		{
		state = STATE_CLOSED;
		}
   previous_state = state;

	if ( health )
		{
		takedamage = DAMAGE_YES;
		}
	
	// LinkDoors can't be done until all of the doors have been spawned, so
	// the sizes can be detected properly.
	nextdoor = 0;
	PostEvent( EV_Door_Link, 0 );

	// Default to work with monsters and players 
	respondto = TRIGGER_PLAYERS | TRIGGER_MONSTERS;
	if ( spawnflags & 8 )
		{
		respondto &= ~TRIGGER_PLAYERS;
		}
	if ( spawnflags & 16 )
		{
		respondto &= ~TRIGGER_MONSTERS;
		}
	}

qboolean Door::isOpen
	(
	void
	)

	{
	return ( state == STATE_OPEN );
	}

void Door::OpenEnd
	(
	Event *ev
	)

	{
//	if ( master == this )
		{
		if ( sound_stop.length() > 1 )
			{
			ProcessEvent( EV_DoorSound );
			sound( sound_stop, 1, CHAN_VOICE + CHAN_NO_PHS_ADD, ATTN_NORM );
			}
      else
         {
         RandomGlobalSound( "null_sound", 1, CHAN_VOICE + CHAN_NO_PHS_ADD, ATTN_NORM );
         }
		}
   previous_state = state;
	state = STATE_OPEN;
	if ( spawnflags & DOOR_TOGGLE )
		{
		// don't close automatically
		return;
		}

	if ( ( wait > 0 ) && ( master == this ) )
		{
		PostEvent( EV_Door_Close, wait );
		}
	}

void Door::CloseEnd
	(
	Event *ev
	)

	{
//	if ( master == this )
		{
		if ( sound_stop.length() > 1 )
			{
			ProcessEvent( EV_DoorSound );
			sound( sound_stop, 1, CHAN_VOICE + CHAN_NO_PHS_ADD, ATTN_NORM );
			}
      else
         {
         RandomGlobalSound( "null_sound", 1, CHAN_VOICE + CHAN_NO_PHS_ADD, ATTN_NORM );
         }
		}

	SetAreaPortals( Target(), false );

   previous_state = state;
	state = STATE_CLOSED;
	}

void Door::Close
	(
	Event *ev
	)
	
	{
	Door *door;

   CancelEventsOfType( EV_Door_Close );

   previous_state = state;
	state = STATE_CLOSING;

	ProcessEvent( EV_Door_DoClose );

	if ( sound_move.length() > 1 )
		{
		ProcessEvent( EV_DoorSound );
		sound( sound_move, 1, CHAN_VOICE + CHAN_NO_PHS_ADD, ATTN_NORM );
		}
	if ( master == this )
		{
		if ( max_health )
			{
			takedamage	= DAMAGE_YES;
			health		= max_health;
			}

		// trigger all paired doors
		door = ( Door * )G_GetEntity( nextdoor );
		assert( door->isSubclassOf( Door ) );
		while( door && ( door != this ) )
			{
			door->ProcessEvent( EV_Door_Close );
			door = ( Door * )G_GetEntity( door->nextdoor );
			assert( door->isSubclassOf( Door ) );
			}
		}
	}

void Door::Open
	(
	Event *ev
	)

	{
	Door *door;
	Event *e;
	Entity *other;

	if ( ev->NumArgs() < 1 )
		{
		ev->Error( "No entity specified to open door.  Door may open the wrong way." );
		other = world;
		}
	else
		{
		other = ev->GetEntity( 1 );
		}

	if ( state == STATE_OPENING )
		{
		// already going up
		return;	
		}

	if ( state == STATE_OPEN )
		{
		// reset top wait time
		if ( wait > 0 )
			{
         CancelEventsOfType( EV_Door_Close );
         PostEvent( EV_Door_Close, wait );
			}
		return;
		}

   previous_state = state;
	state = STATE_OPENING;

	e = new Event( EV_Door_DoOpen );
	e->AddEntity( other );
	ProcessEvent( e );

	if ( sound_move.length() > 1 )
		{
		ProcessEvent( EV_DoorSound );
		sound( sound_move, 1, CHAN_VOICE + CHAN_NO_PHS_ADD, ATTN_NORM );
		}
	if ( master == this )
		{
		// trigger all paired doors
		door = ( Door * )G_GetEntity( nextdoor );
		assert( door->isSubclassOf( Door ) );
		while( door && ( door != this ) )
			{
			e = new Event( EV_Door_Open );
			e->AddEntity( other );
			door->ProcessEvent( e );
			door = ( Door * )G_GetEntity( door->nextdoor );
			assert( door->isSubclassOf( Door ) );
			}

		SetAreaPortals( Target(), true );
		}
	}

void Door::DoorUse
	(
	Event *ev
	)
	
	{
	Entity *other;
   qboolean respond;
	Event *e;

	other = ev->GetEntity( 1 );

	respond = ( ( ( respondto & TRIGGER_PLAYERS ) && other->isClient() ) ||
		( ( respondto & TRIGGER_MONSTERS ) && other->isSubclassOf( Actor ) ) );

   if ( !respond )
      return;

	// only allow use when not triggerd by other events
	if ( health || ( spawnflags & ( DOOR_AUTO_OPEN | DOOR_TARGETED ) ) )
		{
      if ( other->isSubclassOf( Sentient ) && ( state == STATE_CLOSED ) )
         {
         if ( health )
            {
            gi.centerprintf ( other->edict, "jcx yv 20 string \"This door is jammed.\"" );
            }
         else if ( spawnflags & DOOR_TARGETED )
            {
            RandomGlobalSound( "door_triggered", 1, CHAN_VOICE + CHAN_NO_PHS_ADD, ATTN_NORM );
            //gi.centerprintf ( other->edict, "jcx yv 20 string \"This door opens elsewhere.\"" );
            }
         }
		return;
		}

   assert( master );
   if ( !master )
      {
      // bulletproofing
      master = this;
      }

	if ( master->state == STATE_CLOSED )
		{
		e = new Event( EV_Door_TryOpen );
		e->AddEntity( other );
		master->ProcessEvent( e );
		}
	else if ( master->state == STATE_OPEN )
		{
		e = new Event( EV_Door_Close );
		e->AddEntity( other );
		master->ProcessEvent( e );
		}
	}

void Door::DoorFire
	(
	Event *ev
	)
	
	{
	Event *e;
	Entity *other;

	other = ev->GetEntity( 1 );

	assert( master == this );
	if ( master != this )
		{
		gi.error( "DoorFire: master != self" );
		}

	// no more messages
	SetMessage( NULL );

	// reset health in case we were damage triggered
	health = max_health;

	// will be reset upon return
	takedamage = DAMAGE_NO;

	if ( ( spawnflags & ( DOOR_TOGGLE | DOOR_START_OPEN ) ) && ( state == STATE_OPENING || state == STATE_OPEN ) )
		{
		spawnflags &= ~DOOR_START_OPEN;
		ProcessEvent( EV_Door_Close );
		}
	else
		{
		e = new Event( EV_Door_Open );
		e->AddEntity( other );
		ProcessEvent( e );
		}
	}

void Door::DoorBlocked
	(
	Event *ev
	)

	{
	Event *e;
	Entity *other;

   assert( master );
	if ( ( master ) && ( master != this ) )
		{
		master->ProcessEvent( ev );
		return;
		}

   if ( lastblocktime > level.time )
      {
      return;
      }

   lastblocktime = level.time + 0.3;

	other = ev->GetEntity( 1 );

	if ( dmg )
		{
		other->Damage( this, this, (int)dmg, worldorigin, vec_zero, vec_zero, 0, 0, MOD_CRUSH, -1, -1, 1.0f );
		}

   // 
   // if we killed him, lets keep on going
   //
   if ( other->health <= 0 )
		{
      return;
		}
	
	if ( state == STATE_OPENING || state == STATE_OPEN )
		{
		spawnflags &= ~DOOR_START_OPEN;
		ProcessEvent( EV_Door_Close );
		}
	else
		{
		e = new Event( EV_Door_Open );
		e->AddEntity( other );
		ProcessEvent( e );
		}
	}

void Door::FieldTouched
	(
	Event *ev
	)

	{
	Entity *other;

	other = ev->GetEntity( 1 );

#ifdef SIN_DEMO
	if ( ( state != STATE_OPEN ) && !( spawnflags & DOOR_AUTO_OPEN ) && 
		( !other || !other->isSubclassOf( Actor ) ) )
#else
	if ( ( state != STATE_OPEN ) && !( spawnflags & DOOR_AUTO_OPEN ) )
#endif
		{
		return;
		}

	TryOpen( ev );
	}

qboolean	Door::CanBeOpenedBy
	(
	Entity *ent
	)

	{
   assert( master );
	if ( ( master ) && ( master != this ) )
		{
		return master->CanBeOpenedBy( ent );
		}

	if ( !locked && !key.length() )
		{
		return true;
		}
		
	if ( ent && ent->isSubclassOf( Sentient ) && ( ( Sentient * )ent )->HasItem( key.c_str() ) )
		{
		return true;
		}

	return false;
	}

void Door::TryOpen
	(
	Event *ev
	)

	{
	Entity *other;
	Event *event;

	//FIXME
	// hack so that doors aren't triggered by guys when game starts.
	// have to fix delay that guys go through before setting up their threads
	if ( level.time < 0.4 )
		{
		return;
		}

	other = ev->GetEntity( 1 );

   assert( master );
	if ( master && ( this != master ) )
		{
		event = new Event( EV_Door_TryOpen );
		event->AddEntity( other );
		master->ProcessEvent( event );
		return;
		}

	if ( !other || ( other->health <= 0 ) )
		{
		return;
		}

   if ( locked )
      {
      if ( sound_locked.length() > 1 )
         {
         other->sound( sound_locked.c_str(), 1, CHAN_VOICE );
         }
      else if ( other->isSubclassOf( Player) )
         {
         other->RandomSound( "snd_locked", 1, CHAN_VOICE );
         //gi.centerprintf ( other->edict, "jcx yv 20 string \"This door is locked.\"" );
         }

		// locked doors don't open for anyone
      return;
      }

   if ( !CanBeOpenedBy( other ) )
		{
      Item        *item;
      ClassDef		*cls;  

		if ( other->isClient() )
			{
			cls = getClass( key.c_str() );
			if ( !cls )
				{
				gi.dprintf( "No item named '%s'\n", key.c_str() );
				return;
				}
			item = ( Item * )cls->newInstance();
			item->CancelEventsOfType( EV_Item_DropToFloor );
			item->CancelEventsOfType( EV_Remove );
			item->ProcessPendingEvents();
			gi.centerprintf ( other->edict, "jcx yv 20 string \"You need this item:\" jcx yv -20 icon %d", item->GetIconIndex() );
			delete item;
			}
      return;
      }

	// once we're opened by an item, we no longer need that item to open the door
	key = "";

	if ( Message().length() )
		{
      gi.centerprintf( other->edict, "jcx jcy string \"%s\"", Message().c_str() );
		sound( sound_message, 1, CHAN_VOICE + CHAN_NO_PHS_ADD, ATTN_NORM );
		}

	event = new Event( EV_Door_Fire );
	event->AddEntity( other );
	ProcessEvent( event );
	}

void Door::SpawnTriggerField
	(
	Vector fmins, 
	Vector fmaxs
	)

	{
	TouchField *trig;
	Vector min;
	Vector max;
	
	min = fmins - "60 60 8";
	max = fmaxs + "60 60 8";

	trig = new TouchField;
	trig->Setup( this, EV_Door_TriggerFieldTouched, min, max, respondto );
	
	trigger = trig->entnum;
	}

EXPORT_FROM_DLL qboolean Door::DoorTouches
	(
	Door *e1
	)

	{
	if ( e1->doormin.x > doormax.x )
		{
		return false;
		}
	if ( e1->doormin.y > doormax.y )
		{
		return false;
		}
	if ( e1->doormin.z > doormax.z )
		{
		return false;
		}
	if ( e1->doormax.x < doormin.x )
		{
		return false;
		}
	if ( e1->doormax.y < doormin.y )
		{
		return false;
		}
	if ( e1->doormax.z < doormin.z )
		{
		return false;
		}

	return true;
	}

void Door::LinkDoors
	(
	Event *ev
	)

	{
	Door	*ent;
	Door	*next;
	Vector			cmins;
	Vector			cmaxs;
	int				t;
	int				i;

	if ( nextdoor )
		{
		// already linked by another door
		return;
		}

	// master doors own themselves
	master = this;

	if ( spawnflags & DOOR_DONT_LINK )
		{
		// don't want to link this door
		nextdoor = entnum;
		return;	
		}

	cmins = absmin;
	cmaxs = absmax;
	
	ent = this;
	for( t = entnum; t != 0; t = G_FindClass( t, getClassID() ) )
		{
		next = ( Door * )G_GetEntity( t );
		if ( !ent->DoorTouches( next ) )
			{
			continue;
			}

		if ( next->nextdoor )
			{
			error( "cross connected doors.  Targetname = %s entity %d", TargetName(), entnum );
			}
		
		ent->nextdoor = next->entnum;
		ent = next;

		for( i = 0; i < 3; i++ )
			{
			if ( ent->absmin[ i ] < cmins[ i ] )
				{
				cmins[ i ] = ent->absmin[ i ];
				}
			if ( ent->absmax[ i ] > cmaxs[ i ] )
				{
				cmaxs[ i ] = ent->absmax[ i ];
				}
			}

		// set master door
		ent->master = this;

		if ( ent->health )
			{
			health = ent->health;
			}

		if ( ent->Targeted() )
			{
			if ( !Targeted() )
				{
				SetTargetName( ent->TargetName() );
				}
			else if ( strcmp( TargetName(), ent->TargetName() ) )
				{
				// not a critical error, but let them know about it.
				gi.dprintf( "cross connected doors" );

				ent->SetTargetName( TargetName() );
				}
			}

		if ( ent->Message().length() )
			{
			if ( Message().length() && !strcmp( Message().c_str(), ent->Message().c_str() ) )
				{
				// not a critical error, but let them know about it.
				gi.dprintf( "Different messages on linked doors.  Targetname = %s", TargetName() );
				}

			// only master should have a message
			SetMessage( ent->Message().c_str() );
			ent->SetMessage( NULL );
			}
		}

	// make the chain a loop
	ent->nextdoor = entnum;

	// open up any portals we control
	SetAreaPortals( Target(), ( spawnflags & DOOR_START_OPEN ) ? true : false );

	// shootable or targeted doors don't need a trigger
	if ( health || ( spawnflags & DOOR_TARGETED ) )
		{
		// Don't let the player trigger the door
		return;
		}

   // Don't spawn trigger field when set to toggle
   if ( !( spawnflags & DOOR_TOGGLE ) )
      {
	   SpawnTriggerField( cmins, cmaxs );
      }
	}

void Door::SetTime
	(
	Event *ev
	)

	{
	traveltime = ev->GetFloat( 1 );
	if ( traveltime < FRAMETIME )
		{
		traveltime = FRAMETIME;
		}

	speed = 1.0f / traveltime;
	}

void Door::LockDoor
	(
	Event *ev
	)

	{
   locked = true;
	}

void Door::UnlockDoor
	(
	Event *ev
	)

	{
   locked = false;
	}

/*****************************************************************************/
/*SINED func_rotatingdoor (0 .5 .8) ? START_OPEN OPEN_DIRECTION DOOR_DONT_LINK NOT_PLAYERS NOT_MONSTERS TOGGLE AUTO_OPEN TARGETED
if two doors touch, they are assumed to be connected and operate as a unit.

TOGGLE causes the door to wait in both the start and end states for a trigger event.
DOOR_DONT_LINK is for when you have two doors that are touching but you want to operate independently.

START_OPEN causes the door to move to its destination when spawned, and operate in reverse.  It is used to temporarily or permanently close off an area when triggered (not usefull for touch or takedamage doors).
OPEN_DIRECTION indicates which direction to open when START_OPEN is set.
AUTO_OPEN causes the door to open when a player is near instead of waiting for the player to use the door.
TARGETED door is only operational from triggers or script

"message"		is printed when the door is touched if it is a trigger door and it hasn't been fired yet
"openangle"    how wide to open the door
"angle"			determines the opening direction.  point toward the middle of the door (away from the hinge)
"targetname"	if set, no touch field will be spawned and a remote button or trigger field activates the door.
"health"			if set, door must be shot open
"time"			move time (0.3 default)
"wait"			wait before returning (3 default, -1 = never return)
"dmg"				damage to inflict when blocked (0 default)
"key"          The item needed to open this door (default nothing)

"sound_stop"		Specify the sound that plays when the door stops moving (default global door_stop)
"sound_move"		Specify the sound that plays when the door opens or closes (default global door_moving)
"sound_message"	Specify the sound that plays when the door displays a message
"sound_locked"	   Specify the sound that plays when the door is locked
  
/*****************************************************************************/
CLASS_DECLARATION( Door, RotatingDoor, "func_rotatingdoor" );

ResponseDef RotatingDoor::Responses[] =
	{
	   { &EV_Door_DoClose,		            ( Response )RotatingDoor::DoClose },
	   { &EV_Door_DoOpen,		            ( Response )RotatingDoor::DoOpen },
		{ NULL, NULL }
	};

void RotatingDoor::DoOpen
   (
 	Event *ev
   )

	{
	Vector ang;

	if ( previous_state == STATE_CLOSED )
      {
      if ( ev->NumArgs() > 0 )
         {
   	   Entity *other;
	      Vector p;

	      other = ev->GetEntity( 1 );
         p = other->worldorigin - worldorigin;
         p.z = 0;
         diropened = dir * p;
         }
      else
         {
         diropened = 0 - init_door_direction;
         }
      }

	if ( diropened < 0 )
		{
		ang = startangle + Vector( 0, angle, 0 );
		}
	else
		{
		ang = startangle - Vector( 0, angle, 0 );
		}

	MoveTo( worldorigin, ang, fabs( speed*angle ), EV_Door_OpenEnd );
   }

void RotatingDoor::DoClose
   (
 	Event *ev
   )

	{
	MoveTo( worldorigin, startangle, fabs( speed*angle ), EV_Door_CloseEnd );
   }

RotatingDoor::RotatingDoor()
	{
	startangle = angles;

	angle = G_GetFloatArg( "openangle", 90 );

   init_door_direction = (spawnflags & DOOR_OPEN_DIRECTION);
	}

/*
/*****************************************************************************/
/*SINED func_door (0 .5 .8) ? START_OPEN x DOOR_DONT_LINK NOT_PLAYERS NOT_MONSTERS TOGGLE AUTO_OPEN TARGETED
if two doors touch, they are assumed to be connected and operate as a unit.

TOGGLE causes the door to wait in both the start and end states for a trigger event.
DOOR_DONT_LINK is for when you have two doors that are touching but you want to operate independently.

START_OPEN causes the door to move to its destination when spawned, and operate in reverse.  It is used to temporarily or permanently close off an area when triggered (not usefull for touch or takedamage doors).
OPEN_DIRECTION indicates which direction to open when START_OPEN is set.
AUTO_OPEN causes the door to open when a player is near instead of waiting for the player to use the door.
TARGETED door is only operational from triggers or script

"message"		is printed when the door is touched if it is a trigger door and it hasn't been fired yet
"angle"			determines the opening direction.  point toward the middle of the door (away from the hinge)
"targetname"	if set, no touch field will be spawned and a remote button or trigger field activates the door.
"health"			if set, door must be shot open
"speed"			move speed (100 default)
"time"			move time (1/speed default, overides speed)
"wait"			wait before returning (3 default, -1 = never return)
"lip"				lip remaining at end of move (8 default)
"dmg"				damage to inflict when blocked (0 default)
"key"          The item needed to open this door (default nothing)

"sound_stop"		Specify the sound that plays when the door stops moving (default global door_stop)
"sound_move"		Specify the sound that plays when the door opens or closes (default global door_moving)
"sound_message"	Specify the sound that plays when the door displays a message
"sound_locked"	   Specify the sound that plays when the door is locked
  
/*****************************************************************************/
CLASS_DECLARATION( Door, SlidingDoor, "func_door" );

ResponseDef SlidingDoor::Responses[] =
	{
	   { &EV_Door_DoClose,		            ( Response )SlidingDoor::DoClose },
	   { &EV_Door_DoOpen,		            ( Response )SlidingDoor::DoOpen },
		{ NULL, NULL }
	};

void SlidingDoor::DoOpen
   (
 	Event *ev
   )

	{
	MoveTo( pos2, angles, speed*totalmove, EV_Door_OpenEnd );
   }

void SlidingDoor::DoClose
   (
 	Event *ev
   )

	{
	MoveTo( pos1, angles, speed*totalmove, EV_Door_CloseEnd );
   }

SlidingDoor::SlidingDoor()
	{
   Vector movedir;
   float sp;

	lip = G_GetFloatArg( "lip", 8 );

	movedir = G_GetMovedir();
	totalmove = fabs( movedir * size ) - lip;
	pos1 = worldorigin;
	pos2 = pos1 + movedir * totalmove;
   setOrigin( pos1 );

	sp = G_GetFloatArg( "speed", 0 );
   if (sp)
      {
      speed = sp / totalmove;
      }
	}

/*
/*****************************************************************************/
/*SINED func_scriptdoor (0 .5 .8) ? START_OPEN x DOOR_DONT_LINK NOT_PLAYERS NOT_MONSTERS TOGGLE AUTO_OPEN TARGETED
if two doors touch, they are assumed to be connected and operate as a unit.

TOGGLE causes the door to wait in both the start and end states for a trigger event.
DOOR_DONT_LINK is for when you have two doors that are touching but you want to operate independently.

START_OPEN causes the door to move to its destination when spawned, and operate in reverse.  It is used to temporarily or permanently close off an area when triggered (not usefull for touch or takedamage doors).
OPEN_DIRECTION indicates which direction to open when START_OPEN is set.
AUTO_OPEN causes the door to open when a player is near instead of waiting for the player to use the door.
TARGETED door is only operational from triggers or script

"message"		is printed when the door is touched if it is a trigger door and it hasn't been fired yet
"angle"			determines the opening direction.  point toward the middle of the door (away from the hinge)
"targetname"	if set, no touch field will be spawned and a remote button or trigger field activates the door.
"health"			if set, door must be shot open
"speed"			move speed (100 default)
"time"			move time (1/speed default, overides speed)
"wait"			wait before returning (3 default, -1 = never return)
"dmg"				damage to inflict when blocked (0 default)
"key"          The item needed to open this door (default nothing)
"initthread"   code to execute to setup the door (optional)
"openthread"   code to execute when opening the door (required)
"closethread"  code to execute when closing the door (required)

"sound_stop"		Specify the sound that plays when the door stops moving (default global door_stop)
"sound_move"		Specify the sound that plays when the door opens or closes (default global door_moving)
"sound_message"	Specify the sound that plays when the door displays a message
"sound_locked"	   Specify the sound that plays when the door is locked
  
/*****************************************************************************/
CLASS_DECLARATION( Door, ScriptDoor, "func_scriptdoor" );

Event EV_ScriptDoor_DoInit( "doinit" );
Event EV_ScriptDoor_SetOpenThread( "openthread" );
Event EV_ScriptDoor_SetCloseThread( "closethread" );

ResponseDef ScriptDoor::Responses[] =
	{
	   { &EV_ScriptDoor_DoInit,		      ( Response )ScriptDoor::DoInit },
	   { &EV_Door_DoClose,		            ( Response )ScriptDoor::DoClose },
	   { &EV_Door_DoOpen,		            ( Response )ScriptDoor::DoOpen },
	   { &EV_ScriptDoor_SetOpenThread,           ( Response )ScriptDoor::SetOpenThread },
	   { &EV_ScriptDoor_SetCloseThread,          ( Response )ScriptDoor::SetCloseThread },
		{ NULL, NULL }
	};

void ScriptDoor::SetOpenThread
   (
 	Event *ev
   )
	{
   openthreadname = ev->GetString( 1 );
   }

void ScriptDoor::SetCloseThread
   (
 	Event *ev
   )
	{
   closethreadname = ev->GetString( 1 );
   }

void ScriptDoor::DoInit
   (
 	Event *ev
   )
	{
   const char * label = NULL;
   GameScript * s;
   const char * tname;

   s = ScriptLib.GetScript( ScriptLib.GetGameScript() );

   if ( !s )
      {
      warning( "DoInit", "Null game script" );
      return;
      }

   if ( initthreadname.length() )
      label = initthreadname.c_str();

	doorthread = Director.CreateThread( s, label, MODEL_SCRIPT );
   if ( !doorthread )
      {
      warning( "DoInit", "Could not allocate thread." );
      return;
      }
	doorthread->Vars()->SetVariable( "self", this );
   tname = TargetName();
   if ( tname && tname[ 0 ] )
      {
      str name;
      name = "$" + str( tname );
	   doorthread->Vars()->SetVariable( "targetname", name.c_str() );
      }
	doorthread->Vars()->SetVariable( "startorigin", startorigin );
	doorthread->Vars()->SetVariable( "startangles", startangle );
	doorthread->Vars()->SetVariable( "movedir", movedir );
	doorthread->Vars()->SetVariable( "doorsize", doorsize );
   if ( initthreadname.length() )
      {
      // start right away
      doorthread->Start( -1 );
      }
   }

void ScriptDoor::DoOpen
   (
 	Event *ev
   )
	{
   if ( !doorthread )
      {
      warning( "DoOpen", "No Thread allocated." );
      return;
      }
   else
      {
      if ( !doorthread->Goto( openthreadname.c_str() ) )
         {
         warning( "DoOpen", "Could not goto %s", openthreadname.c_str() );
         return;
         }
      }

   if ( previous_state == STATE_CLOSED )
      {
      diropened = 0;
      if ( ev->NumArgs() > 0 )
         {
   	   Entity *other;
	      Vector p;

	      other = ev->GetEntity( 1 );
	      p = other->worldorigin - worldorigin;
         p.z = 0;
         diropened = dir * p;
         }
      }
	doorthread->Vars()->SetVariable( "origin", worldorigin );
	doorthread->Vars()->SetVariable( "opendot", diropened );
   doorthread->Start( 0 );
   }

void ScriptDoor::DoClose
   (
 	Event *ev
   )
	{
   if ( !doorthread )
      {
      warning( "DoClose", "No Thread allocated." );
      return;
      }
   else
      {
      if ( !doorthread->Goto( closethreadname.c_str() ) )
         {
         warning( "DoOpen", "Could not goto %s", closethreadname.c_str() );
         }
      }
	doorthread->Vars()->SetVariable( "origin", worldorigin );
   doorthread->Start( 0 );
   }

ScriptDoor::ScriptDoor()
	{
   const char * text;

	startangle = angles;
   //
   // see if we have an initthread
   //
	text = G_GetSpawnArg( "initthread" );
   if ( text )
      initthreadname = text;

   //
   // see if we have an openthread
   //
	text = G_GetSpawnArg( "openthread" );
   if ( text )
      openthreadname = text;
   else
      warning("ScriptDoor","No openthread defined for door at %.2f %.2f %.2f", origin[0], origin[1], origin[2] );

   //
   // see if we have an closethread
   //
	text = G_GetSpawnArg( "closethread" );
   if ( text )
      closethreadname = text;
   else
      warning("ScriptDoor","No closethread defined for door at %.2f %.2f %.2f", origin[0], origin[1], origin[2] );
   //
   // clear out the sounds if necessary
   // scripted doors typically have their own sounds
   //
   text = G_GetSpawnArg( "sound_stop" );
   if ( !text )
      sound_stop = "";
   text = G_GetSpawnArg( "sound_move" );
   if ( !text )
      sound_move = "";

	movedir = G_GetMovedir();
   startorigin = worldorigin;
	doorsize = fabs( movedir * size );
	PostEvent( EV_ScriptDoor_DoInit, 0 );
	}
