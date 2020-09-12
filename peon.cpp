//-----------------------------------------------------------------------------
//
//  $Logfile:: /Quake 2 Engine/Sin/code/game/peon.cpp                         $
// $Revision:: 9                                                              $
//   $Author:: Aldie                                                          $
//     $Date:: 11/18/98 7:56p                                                 $
//
// Copyright (C) 1998 by Ritual Entertainment, Inc.
// All rights reserved.
//
// This source is may not be distributed and/or modified without
// expressly written permission by Ritual Entertainment, Inc.
//
// $Log:: /Quake 2 Engine/Sin/code/game/peon.cpp                              $
// 
// 9     11/18/98 7:56p Aldie
// dontsave goo
// 
// 8     11/18/98 1:40a Jimdose
// goo goes away quicker
// 
// 7     10/27/98 5:03p Markd
// Upped damage on goo
// 
// 6     10/27/98 3:53a Markd
// Don't always put dynamic lights on goo
// 
// 5     10/26/98 2:50p Aldie
// Fixed a bug with checking of NULL owners
// 
// 4     10/26/98 3:50a Markd
// put in prediction
// 
// 3     10/25/98 4:43a Markd
// incremental
// 
// 2     10/23/98 10:03p Markd
// First check in
// 
// 1     10/23/98 8:20p Markd
// 
// DESCRIPTION:
// Peon
// 

#include "g_local.h"
#include "actor.h"
#include "specialfx.h"
#include "surface.h"
#include "peon.h"


class EXPORT_FROM_DLL Goo : public Projectile
   {
	public:
      CLASS_PROTOTYPE( Goo );

                     Goo();
      virtual void   Setup( Entity *owner, Vector pos, Vector vel );
      virtual void   GooTouch( Event *ev );
  	};

CLASS_DECLARATION( Projectile, Goo, NULL );

ResponseDef Goo::Responses[] =
	{
      { &EV_Touch,                           ( Response )Goo::GooTouch },
      { NULL, NULL }
	};

Goo::Goo()
   {
   }

void Goo::GooTouch
   (
   Event *ev
   )

   {
   Entity      *other;
   Entity      *owner;
   int         damg;
   Vector      v;
   Vector      norm;
   Vector      shockangles;

   other = ev->GetEntity( 1 );
	assert( other );

	if ( other->isSubclassOf( Teleporter ) )
		{
		return;
		}

	if ( other->entnum == this->owner )
		{
		return;
		}

   owner = G_GetEntity( this->owner );

   if ( !owner )
      owner = world;

	setSolidType( SOLID_NOT );

   // Hit the shy, so remove everything
	if ( HitSky() )
		{
		PostEvent( EV_Remove, 0 );
		return;
		}

  	damg = 40 + ( int )G_Random( 40 );
	
   // Single player packs a bigger punch
   if ( !deathmatch->value && owner->isClient() )
      damg *= 1.5;
   
   if ( other->takedamage )
   	other->Damage( this, owner, damg, worldorigin, velocity, level.impact_trace.plane.normal, 32, 0, MOD_PULSE, -1, -1, 1.0f );

   if ( other == world )
      {
      RandomAnimate( "splat", NULL );
      PostEvent( EV_Remove, 5 );
      }
   else
      {
      PostEvent( EV_Remove, 0 );
      }
   }
     
void Goo::Setup
   (
   Entity *owner,
   Vector pos, 
   Vector vel
   )

   {
	this->owner = owner->entnum;
	edict->owner = owner->edict;

   // Align the projectile
  	angles = vel.toAngles();
	angles[ PITCH ] = -angles[ PITCH ];
   setAngles( angles );
//   edict->s.angles[ROLL] = rand() % 360;

   // Flies like a grenade
	setMoveType( MOVETYPE_TOSS );
	setSolidType( SOLID_BBOX );
	edict->clipmask = MASK_PROJECTILE;
   setModel( "goo.def" );
   RandomAnimate( "goo", NULL );
     
   // Set the flying velocity
   velocity = vel;

	takedamage = DAMAGE_NO;

   if ( G_Random( 10 ) < 2 )
      {
      // Set the light and effects
      edict->s.renderfx |= RF_DLIGHT;
      edict->s.radius    = 100;
      edict->s.color_r   = 0.1f;
      edict->s.color_g   = 0.9f;
      edict->s.color_b   = 0.1f;
      }

   flags |= FL_DONTSAVE;

   // Set size and origin
   setSize( "-1 -1 -1", "1 1 1" );
	setOrigin( pos );
   worldorigin.copyTo(edict->s.old_origin);
   
   // Remove the projectile in the future
   PostEvent( EV_Remove, 30 );
   }

CLASS_DECLARATION( Actor, Peon, "monster_peon" );

Event	EV_Peon_SpawnGoo( "spawngoo" );

ResponseDef Peon::Responses[] =
	{
	   { &EV_Peon_SpawnGoo, ( Response )Peon::SpawnGoo },
		{ NULL, NULL }
	};

Peon::Peon()
	{
   gootime = 0;
	setModel( "peon.def" );
   modelIndex( "goo.def" );
	}

void Peon::SpawnGoo
	(
	Event *ev
	)

	{
   Goo * goo;
   Vector vel;
   Vector pos;
   Vector target;
   float  speed;
   char bonename[ 32 ];
   int num;

   if ( !currentEnemy )
      return;

   num = (int)G_Random( 6 ) + 1;
   sprintf( bonename, "goo%d", num );

   GetBone( bonename, &pos, NULL, NULL, NULL );

   pos += worldorigin;

   speed = 900;

   target = G_PredictPosition( pos, currentEnemy->centroid, currentEnemy->velocity, speed );

   vel = G_CalculateImpulse
      (
      pos,
      target,
      speed,
      1
      );
   goo = new Goo;
   goo->Setup( this, pos, vel );
	}

void Peon::Prethink
	(
	void
	)
   {
   if ( currentEnemy && ( gootime < level.time ) )
      {
      Vector delta;
      Vector dir;
      ScriptVariable * stage;
      int stagenum;

      stage = levelVars.GetVariable( "eonpeon_stage" );
      if ( stage )
         {
         stagenum = stage->intValue();
         }
      else
         {
         stagenum = 0;
         }
      if ( stagenum < 2 )
         {
         gootime = level.time + 1;
         }
      else
         {
         dir = Vector( orientation[ 0 ] );
         delta = currentEnemy->centroid - centroid;
         if ( delta.length() < 1000 )
            {
#if 0
            float dot;

            dot = delta * dir;

            if ( dot < -0.5f )
               {
               gootime = level.time + 5;
   			   DoAction( "rearattack", false );
               }
#else
            if ( stagenum == 2 )
               gootime = level.time + 5;
            else
               gootime = level.time;

 			   DoAction( "rearattack", false );
#endif
            }
         }
      }

   //
   // call our superclass
   //
   Actor::Prethink();
   }

