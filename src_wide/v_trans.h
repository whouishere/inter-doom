// Emacs style mode select   -*- C++ -*- 
//-----------------------------------------------------------------------------
//
// $Id: v_video.h,v 1.9 1998/05/06 11:12:54 jim Exp $
//
//  BOOM, a modified and improved DOOM engine
//  Copyright (C) 1999 by
//  id Software, Chi Hoang, Lee Killough, Jim Flynn, Rand Phares, Ty Halderman
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 2
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 
//  02111-1307, USA.
//
// DESCRIPTION:
//  Gamma correction LUT.
//  Color range translation support
//  Functions to draw patches (by post) directly to screen.
//  Functions to blit a block to the screen.
//
//-----------------------------------------------------------------------------

// Russian Doom (C) 2016-2018 Julian Nechaevsky


#ifndef __V_TRANS__
#define __V_TRANS__

#include "doomtype.h"

enum
{
    CR_NONE,
    CR_DARK,
    CR_GRAY,
    CR_GREEN,
    CR_GOLD,
    CR_RED,
    CR_BLUE,
    CR_RED2BLUE,
    CR_RED2GREEN,
    CRMAX
} cr_t;

extern byte *cr[CRMAX];
extern char **crstr;

extern byte *tranmap;

void CrispyReplaceColor (char *str, const int cr, const char *col);

#endif // __V_TRANS__
