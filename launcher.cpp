//-----------------------------------------------------------------------------
//
//  $Logfile:: /Quake 2 Engine/Sin/code/game/launcher.cpp                     $
// $Revision:: 12                                                             $
//   $Author:: Markd                                                          $
//     $Date:: 10/24/98 12:42a                                                $
//
// Copyright (C) 1998 by Ritual Entertainment, Inc.
// All rights reserved.
//
// This source is may not be distributed and/or modified without
// expressly written permission by Ritual Entertainment, Inc.
//
// $Log:: /Quake 2 Engine/Sin/code/game/launcher.cpp                          $
// 
// 12    10/24/98 12:42a Markd
// changed origins to worldorigins where appropriate
// 
// 11    10/13/98 5:04p Markd
// Fixed launcher sounds
// 
// 10    10/13/98 12:55a Markd
// Fixed launcher that uses info_notnulls
// 
// 9     10/01/98 4:01p Markd
// Added Archive and Unarchive functions
// 
// 8     8/29/98 5:27p Markd
// added specialfx, replaced misc with specialfx where appropriate
// 
// 7     7/06/98 4:07p Aldie
// Removed some dependencies on some headers.
// 
// 6     5/24/98 8:46p Jimdose
// Made a lot of functions more str-friendly.
// Got rid of a lot of char * based strings
// Cleaned up get spawn arg functions and sound functions
// sound functions now use consistant syntax
// 
// 5     5/24/98 4:48p Jimdose
// Made char *'s const
// 
// 4     5/20/98 11:11a Markd
// removed char * dependency
// 
// 3     5/06/98 3:14p Aldie
// Added targeting of the launcher.
// 
// 2     5/05/98 8:35p Aldie
// First version of Generic launcher
//
// DESCRIPTION: Generic Projectile Launcher
// 

#include "g_local.h"
#include "misc.h"
#include "specialfx.h"

/****************************************************************************
/*SINED func_launcher (0 1 0) ? 
Creates an object that launches projectiles. 

"projectile" Sets the projectile that you want to launch (Examples: Rocket, Spear, etc...)
"launchsound" Sets the launching sound.
/*****************************************************************************/

class EXPORT_FROM_DLL GenericLauncher : public Entity
   {
   private:
      Vector		launchAngle;
      float			x_var;
      float			y_var;
      float			z_var;
      str			projectile;
      str			launchsound;

   public:
      CLASS_PROTOTYPE( GenericLauncher );
      GenericLauncher( );
      void Launch(Event *ev);
      void LaunchProjectile(Event *ev);
      void Setdir(Event *ev);
      void SetXdir(Event *ev);
      void SetYdir(Event *ev);
      void SetZdir(Event *ev);
      void SetXvar(Event *ev);
      void SetYvar(Event *ev);
      void SetZvar(Event *ev);
      void SetupDir(Event *ev);
	   virtual void Archive( Archiver &arc );
      virtual void Unarchive( Archiver &arc );
	};

EXPORT_FROM_DLL void GenericLauncher::Archive
	(
	Archiver &arc
	)
   {
   Entity::Archive( arc );

   arc.WriteVector( launchAngle );
   arc.WriteFloat( x_var );
   arc.WriteFloat( y_var );
   arc.WriteFloat( z_var );
   arc.WriteString( projectile );
   arc.WriteString( launchsound );
   }

EXPORT_FROM_DLL void GenericLauncher::Unarchive
	(
	Archiver &arc
	)
   {
   Entity::Unarchive( arc );

   arc.ReadVector( &launchAngle );
   arc.ReadFloat( &x_var );
   arc.ReadFloat( &y_var );
   arc.ReadFloat( &z_var );
   arc.ReadString( &projectile );
   arc.ReadString( &launchsound );
   }

CLASS_DECLARATION( Entity, GenericLauncher, "func_launcher" );

Event EV_GenericLauncher_Launch( "launch" );
Event EV_GenericLauncher_Setdir( "setdir" );
Event EV_GenericLauncher_SetXdir( "setXdir" );
Event EV_GenericLauncher_SetYdir( "setYdir" );
Event EV_GenericLauncher_SetZdir( "setZdir" );
Event EV_GenericLauncher_SetXvar( "setXvar" );
Event EV_GenericLauncher_SetYvar( "setYvar" );
Event EV_GenericLauncher_SetZvar( "setZvar" );
Event EV_GenericLauncher_SetupDir( "setupdir" );

ResponseDef GenericLauncher::Responses[] =
	{
      { &EV_Activate,            				   ( Response )GenericLauncher::LaunchProjectile },
      { &EV_GenericLauncher_Launch,				   ( Response )GenericLauncher::Launch },
      { &EV_GenericLauncher_SetXdir,				( Response )GenericLauncher::SetXdir },
      { &EV_GenericLauncher_SetYdir,				( Response )GenericLauncher::SetYdir },
      { &EV_GenericLauncher_SetZdir,				( Response )GenericLauncher::SetZdir },
      { &EV_GenericLauncher_SetXvar,            ( Response )GenericLauncher::SetXvar },
      { &EV_GenericLauncher_SetYvar,            ( Response )GenericLauncher::SetYvar },
      { &EV_GenericLauncher_SetZvar,            ( Response )GenericLauncher::SetZvar },
      { &EV_GenericLauncher_SetupDir,           ( Response )GenericLauncher::SetupDir },
		{ NULL, NULL }
	};

GenericLauncher::GenericLauncher( )
   {
   showModel();
   setSolidType( SOLID_BSP );
   projectile = G_GetStringArg( "projectile" );
   launchsound = G_GetStringArg( "launchsound" );
   launchAngle = G_GetMovedir();

   x_var = 0;
   y_var = 0;
   z_var = 0;

   PostEvent( EV_GenericLauncher_SetupDir, 0 );
   }

void GenericLauncher::SetupDir( Event *ev )
   {
   int num;
   const char *target;
   Entity *dest;

   target = Target();
   if (target)
      {
      if (num = G_FindTarget(0, target))
         {
         dest = G_GetEntity( num );
         assert( dest );
         VectorSubtract(dest->worldorigin, origin, launchAngle);
         }
      }
   }

void GenericLauncher::SetXdir( Event *ev )
   {
   launchAngle.x = ev->GetFloat( 1 );
   }

void GenericLauncher::SetYdir( Event *ev )
   {
   launchAngle.y = ev->GetFloat(1);
   }

void GenericLauncher::SetZdir( Event *ev )
   {
   launchAngle.z = ev->GetFloat(1);
   }

void GenericLauncher::Setdir(Event *ev)
   {
   launchAngle = ev->GetVector(1);
   }

void GenericLauncher::SetXvar( Event *ev )
   {
   x_var = ev->GetFloat(1);
   }

void GenericLauncher::SetYvar( Event *ev )
   {
   y_var = ev->GetFloat(1);
   }

void GenericLauncher::SetZvar( Event *ev )
   {
   z_var = ev->GetFloat(1);
   }

void GenericLauncher::LaunchProjectile(Event *ev)
   {
   Vector         ang;
   ClassDef	      *cls;
   Projectile     *obj;

   ang.x = launchAngle.x + G_CRandom(x_var);
   ang.y = launchAngle.y + G_CRandom(y_var);
   ang.z = launchAngle.z + G_CRandom(z_var);

   cls = getClass( projectile.c_str() );
   if (cls)
      {
      if ( launchsound.length() )
         {
         this->sound( launchsound, 1, CHAN_WEAPON, ATTN_NORM );
         }
      obj = (Projectile *)cls->newInstance();
      obj->Setup( this, worldorigin, ang.normalize());
      }   
   }

void GenericLauncher::Launch(Event *ev)
   {
   Vector         ang;
   ClassDef	      *cls;
   Projectile     *obj;

   ang.x = launchAngle.x + G_CRandom(x_var);
   ang.y = launchAngle.y + G_CRandom(y_var);
   ang.z = launchAngle.z + G_CRandom(z_var);

   cls = getClass( ev->GetString(1));
   if (cls)
      {
      if ( launchsound.length() )
         {
         this->sound( launchsound, 1, CHAN_WEAPON, ATTN_NORM );
         }
      obj = (Projectile *)cls->newInstance();
      obj->Setup( this, worldorigin, ang.normalize());
      }
   }

