//-----------------------------------------------------------------------------
//
//  $Logfile:: /Quake 2 Engine/Sin/code/game/bouncingbetty.h                  $
// $Revision:: 10                                                             $
//   $Author:: Aldie                                                          $
//     $Date:: 10/24/98 12:52a                                                $
//
// Copyright (C) 1997 by Ritual Entertainment, Inc.
// All rights reserved.
//
// This source is may not be distributed and/or modified without
// expressly written permission by Ritual Entertainment, Inc.
//
// $Log:: /Quake 2 Engine/Sin/code/game/bouncingbetty.h                       $
// 
// 10    10/24/98 12:52a Aldie
// Added killed event
// 
// 9     10/07/98 8:04p Aldie
// Move bubbles to client
// 
// 8     9/29/98 5:58p Markd
// put in archive and unarchive
// 
// 7     4/10/98 2:36a Jimdose
// Works with Q2
// 
// 6     4/08/98 4:22p Jimdose
// Getting ready to conver to Q2
// 
// 4     12/15/97 1:34a Jimdose
// Increased the detection range for the betty
// 
// 3     12/14/97 5:48p Jimdose
// Finished basic behaviour code
// 
// 2     12/13/97 4:43p Jimdose
// Created file
//
// DESCRIPTION:
// 

#ifndef __BOUNCINGBETTY_H__
#define __BOUNCINGBETTY_H__

#include "g_local.h"
#include "entity.h"

#define BOUNCINGBETTY_RANGE 192

class EXPORT_FROM_DLL BettyLauncher : public Entity
	{
	protected:
		qboolean firing;
		int		activator;

	public:
      CLASS_PROTOTYPE( BettyLauncher );

						BettyLauncher();
		qboolean		inRange( Entity *ent );
		void			CheckVicinity( Event *ev );
		void			Launch( Event *ev );
		void			AttackFinished( Event *ev );
		void			ReleaseBetty( Event *ev );
      void        Killed( Event *ev );
	   virtual void Archive( Archiver &arc );
      virtual void Unarchive( Archiver &arc );
	};

inline EXPORT_FROM_DLL void BettyLauncher::Archive
	(
	Archiver &arc
	)
   {
   Entity::Archive( arc );

   arc.WriteBoolean( firing );
   arc.WriteInteger( activator );
   }

inline EXPORT_FROM_DLL void BettyLauncher::Unarchive
	(
	Archiver &arc
	)
   {
   Entity::Unarchive( arc );

   arc.ReadBoolean( &firing );
   arc.ReadInteger( &activator );
   }

class EXPORT_FROM_DLL BouncingBetty : public Entity
	{
	protected:
		int		activator;

	public:
      CLASS_PROTOTYPE( BouncingBetty );

					BouncingBetty();
		void		Launch( Vector pos, int activatorEnt );
		void		Detonate( Event *ev );
		void		Explode( Event *ev );
	   virtual void Archive( Archiver &arc );
      virtual void Unarchive( Archiver &arc );
	};

inline EXPORT_FROM_DLL void BouncingBetty::Archive
	(
	Archiver &arc
	)
   {
   Entity::Archive( arc );

   arc.WriteInteger( activator );
   }

inline EXPORT_FROM_DLL void BouncingBetty::Unarchive
	(
	Archiver &arc
	)
   {
   Entity::Unarchive( arc );

   arc.ReadInteger( &activator );
   }

class EXPORT_FROM_DLL BettySpike : public Entity
	{
	protected:
		int		activator;

	public:
      CLASS_PROTOTYPE( BettySpike );

		void		SpikeTouch( Event *ev );
		void		Setup( Vector pos, Vector dir );
	   virtual void Archive( Archiver &arc );
      virtual void Unarchive( Archiver &arc );
	};

inline EXPORT_FROM_DLL void BettySpike::Archive
	(
	Archiver &arc
	)
   {
   Entity::Archive( arc );

   arc.WriteInteger( activator );
   }

inline EXPORT_FROM_DLL void BettySpike::Unarchive
	(
	Archiver &arc
	)
   {
   Entity::Unarchive( arc );

   arc.ReadInteger( &activator );
   }

#endif /* bouncingbetty.h */
