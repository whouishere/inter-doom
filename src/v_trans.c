//
// Copyright(C) 2005-2014 Simon Howard
// Copyright(C) 2014 Fabian Greffrath, Paul Haeberli
// Copyright(C) 2016-2022 Julian Nechaevsky
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//


#include <math.h>
#include "v_trans.h"


// -----------------------------------------------------------------------------
// [crispy] here used to be static color translation tables based on
// the ones found in Boom and MBF. Nowadays these are recalculated
// by means of actual color space conversions in r_data:R_InitColormaps().
// -----------------------------------------------------------------------------

static byte cr_red[256];
static byte cr_darkred[256];
static byte cr_green[256];
static byte cr_darkgreen[256];
static byte cr_olive[256];
static byte cr_blue[256];
static byte cr_blue2[256];
static byte cr_darkblue[256];
static byte cr_yellow[256];
static byte cr_orange[256];
static byte cr_white[256];
static byte cr_gray[256];
static byte cr_darkgray[256];
static byte cr_tan[256];
static byte cr_brown[256];
static byte cr_almond[256];
static byte cr_khaki[256];
static byte cr_pink[256];
static byte cr_burgundy[256];
static byte cr_green2gray_heretic[256];
static byte cr_green2red_heretic[256];
static byte cr_green2gold_heretic[256];
static byte cr_green2orange_heretic[256];
static byte cr_green2blue_heretic[256];
static byte cr_gold2green_heretic[256];
static byte cr_gold2red_heretic[256];
static byte cr_gold2blue_heretic[256];
static byte cr_gold2gray_heretic[256];
static byte cr_gold2orange_heretic[256];
static byte cr_white2gray_heretic[256];
static byte cr_white2darkgray_heretic[256];
static byte cr_white2red_heretic[256];
static byte cr_white2darkred_heretic[256];
static byte cr_white2green_heretic[256];
static byte cr_white2darkgreen_heretic[256];
static byte cr_white2olive_heretic[256];
static byte cr_white2blue_heretic[256];
static byte cr_white2darkblue_heretic[256];
static byte cr_white2purple_heretic[256];
static byte cr_white2niagara_heretic[256];
static byte cr_white2azure_heretic[256];
static byte cr_white2yellow_heretic[256];
static byte cr_white2gold_heretic[256];
static byte cr_white2darkgold_heretic[256];
static byte cr_white2tan_heretic[256];
static byte cr_white2brown_heretic[256];
static byte cr_red2darkred_heretic[256];
static byte cr_red2green_heretic[256];
static byte cr_red2midgreen_heretic[256];
static byte cr_red2darkgreen_heretic[256];
static byte cr_red2yellow_heretic[256];
static byte cr_red2gold_heretic[256];
static byte cr_red2brown_heretic[256];
static byte cr_red2magenta_heretic[256];
static byte cr_red2gray_heretic[256];
static byte cr_red2white_heretic[256];
static byte cr_red2black_heretic[256];
static byte cr_monochrome_heretic[256];
static byte cr_red2darkred_hexen[256];
static byte cr_red2green_hexen[256];
static byte cr_red2darkgreen_hexen[256];
static byte cr_red2yellow_hexen[256];
static byte cr_red2gold_hexen[256];
static byte cr_red2gray_hexen[256];
static byte cr_red2darkgray_hexen[256];
static byte cr_gray2darkgray_hexen[256];
static byte cr_gray2darkergray_hexen[256];
static byte cr_gray2red_hexen[256];
static byte cr_gray2darkred_hexen[256];
static byte cr_gray2green_hexen[256];
static byte cr_gray2darkgreen_hexen[256];
static byte cr_gray2olive_hexen[256];
static byte cr_gray2blue_hexen[256];
static byte cr_gray2darkblue_hexen[256];
static byte cr_gray2niagara_hexen[256];
static byte cr_gray2yellow_hexen[256];
static byte cr_gray2darkgold_hexen[256];
static byte cr_gray2tan_hexen[256];
static byte cr_gray2brown_hexen[256];
static byte cr_green2blue_hexen[256];
static byte cr_green2gray_hexen[256];
static byte cr_green2red_hexen[256];
static byte cr_yellow2gray_hexen[256];
static byte cr_yellow2green_hexen[256];
static byte cr_yellow2red_hexen[256];
static byte cr_gold2gray_strife[256];
static byte cr_gold2green_strife[256];
static byte cr_gold2red_strife[256];
static byte cr_gold2darkgold_strife[256];

static byte cr_stop[256];

static byte cr_red2blue[256] =
	{  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15,
      16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
      32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43,207,207, 46,207,
      48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63,
      64, 65, 66,207, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
      80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95,
      96, 97, 98, 99,100,101,102,103,104,105,106,107,108,109,110,111,
     112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,
     128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,
     144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,
     160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,
     200,200,201,201,202,202,203,203,204,204,205,205,206,206,207,207,
     192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,
     208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,
     224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,
     240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255};

static byte cr_red2green[256] =
    {  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15,
      16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
      32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43,127,127, 46,127,
      48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63,
      64, 65, 66,127, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
      80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95,
      96, 97, 98, 99,100,101,102,103,104,105,106,107,108,109,110,111,
     112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,
     128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,
     144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,
     160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,
     112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,
     192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,
     208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,
     224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,
     240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255};

static byte cr_red2gray[256] =
    {  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15,
      16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
      32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
      48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63,
      64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
      80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95,
      96, 97, 98, 99,100,101,102,103,104,105,106,107,108,109,110,111,
     112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,
     128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,
     144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,
     160,161,162,163,164,165,166,167,104,105,106,107,108,109,110,111,
     104,104,105,105,106,106,107,107,108,108,109,109,110,110,111,111,
     192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,
     208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,
     224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,
     240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255};

byte *cr[] =
{
    (byte *) &cr_red,
    (byte *) &cr_darkred,
    (byte *) &cr_green,
    (byte *) &cr_darkgreen,
    (byte *) &cr_olive,
    (byte *) &cr_blue,
    (byte *) &cr_blue2,
    (byte *) &cr_darkblue,
    (byte *) &cr_yellow,
    (byte *) &cr_orange,
    (byte *) &cr_white,
    (byte *) &cr_gray,
    (byte *) &cr_darkgray,
    (byte *) &cr_tan,
    (byte *) &cr_brown,
    (byte *) &cr_almond,
    (byte *) &cr_khaki,
    (byte *) &cr_pink,
    (byte *) &cr_burgundy,
    (byte *) &cr_green2gray_heretic,
    (byte *) &cr_green2red_heretic,
    (byte *) &cr_green2gold_heretic,
    (byte *) &cr_green2orange_heretic,
    (byte *) &cr_green2blue_heretic,
    (byte *) &cr_gold2green_heretic,
    (byte *) &cr_gold2red_heretic,
    (byte *) &cr_gold2blue_heretic,
    (byte *) &cr_gold2gray_heretic,
    (byte *) &cr_gold2orange_heretic,
    // ----------------------------
    (byte *) &cr_white2gray_heretic,
    (byte *) &cr_white2darkgray_heretic,
    (byte *) &cr_white2red_heretic,
    (byte *) &cr_white2darkred_heretic,
    (byte *) &cr_white2green_heretic,
    (byte *) &cr_white2darkgreen_heretic,
    (byte *) &cr_white2olive_heretic,
    (byte *) &cr_white2blue_heretic,
    (byte *) &cr_white2darkblue_heretic,
    (byte *) &cr_white2purple_heretic,
    (byte *) &cr_white2niagara_heretic,
    (byte *) &cr_white2azure_heretic,
    (byte *) &cr_white2yellow_heretic,
    (byte *) &cr_white2gold_heretic,
    (byte *) &cr_white2darkgold_heretic,
    (byte *) &cr_white2tan_heretic,
    (byte *) &cr_white2brown_heretic,
    // ----------------------------
    (byte *) &cr_red2darkred_heretic,
    (byte *) &cr_red2green_heretic,
	(byte *) &cr_red2midgreen_heretic,
    (byte *) &cr_red2darkgreen_heretic,
    (byte *) &cr_red2yellow_heretic,
    (byte *) &cr_red2gold_heretic,
    (byte *) &cr_red2brown_heretic,
    (byte *) &cr_red2magenta_heretic,
    (byte *) &cr_red2gray_heretic,
    (byte *) &cr_red2white_heretic,
    (byte *) &cr_red2black_heretic,
    (byte *) &cr_monochrome_heretic,
    // ----------------------------
    (byte *) &cr_red2darkred_hexen,
    (byte *) &cr_red2green_hexen,
    (byte *) &cr_red2darkgreen_hexen,
    (byte *) &cr_red2yellow_hexen,
    (byte *) &cr_red2gold_hexen,
    (byte *) &cr_red2gray_hexen,
    (byte *) &cr_red2darkgray_hexen,
    // ----------------------------
    (byte *) &cr_gray2darkgray_hexen,
    (byte *) &cr_gray2darkergray_hexen,
    (byte *) &cr_gray2red_hexen,
    (byte *) &cr_gray2darkred_hexen,
    (byte *) &cr_gray2green_hexen,
    (byte *) &cr_gray2darkgreen_hexen,
    (byte *) &cr_gray2olive_hexen,
    (byte *) &cr_gray2blue_hexen,
    (byte *) &cr_gray2darkblue_hexen,
    (byte *) &cr_gray2niagara_hexen,
    (byte *) &cr_gray2yellow_hexen,
    (byte *) &cr_gray2darkgold_hexen,
    (byte *) &cr_gray2tan_hexen,
    (byte *) &cr_gray2brown_hexen,
    // ----------------------------
    (byte *) &cr_green2blue_hexen,
    (byte *) &cr_green2gray_hexen, // remove me
    (byte *) &cr_green2red_hexen,  // remove me
    // ----------------------------
    (byte *) &cr_yellow2gray_hexen,
    (byte *) &cr_yellow2green_hexen,
    (byte *) &cr_yellow2red_hexen,
    // ----------------------------
    (byte *) &cr_gold2gray_strife,
    (byte *) &cr_gold2green_strife,
    (byte *) &cr_gold2red_strife,
    (byte *) &cr_gold2darkgold_strife,

    // [JN] Terminator - don't override tablified colors after this point:
    (byte *) &cr_stop,

    // [JN] Tablified colors:
    (byte *) &cr_red2blue,
    (byte *) &cr_red2green,
    (byte *) &cr_red2gray,
};

char **crstr = 0;

/*
Date: Sun, 26 Oct 2014 10:36:12 -0700
From: paul haeberli <paulhaeberli@yahoo.com>
Subject: Re: colors and color conversions
To: Fabian Greffrath <fabian@greffrath.com>

Yes, this seems exactly like the solution I was looking for. I just
couldn't find code to do the HSV->RGB conversion. Speaking of the code,
would you allow me to use this code in my software? The Doom source code
is licensed under the GNU GPL, so this code yould have to be under a
compatible license.

    Yes. I'm happy to contribute this code to your project.  GNU GPL or anything
    compatible sounds fine.

Regarding the conversions, the procedure you sent me will leave grays
(r=g=b) untouched, no matter what I set as HUE, right? Is it possible,
then, to also use this routine to convert colors *to* gray?

    You can convert any color to an equivalent grey by setting the saturation
    to 0.0


    - Paul Haeberli
*/

#define CTOLERANCE      (0.0001)

typedef struct vect {
    float x;
    float y;
    float z;
} vect;

static void hsv_to_rgb (vect *hsv, vect *rgb)
{
    float h, s, v;

    h = hsv->x;
    s = hsv->y;
    v = hsv->z;
    h *= 360.0;
    if (s < CTOLERANCE)
    {
        rgb->x = v;
        rgb->y = v;
        rgb->z = v;
    }
    else
    {
        int i;
        float f, p, q, t;

        if (h >= 360.0)
        {
            h -= 360.0;
        }
        h /= 60.0;
        i = floor(h);
        f = h - i;
        p = v*(1.0-s);
        q = v*(1.0-(s*f));
        t = v*(1.0-(s*(1.0-f)));
        switch (i)
        {
            case 0:
                rgb->x = v;
                rgb->y = t;
                rgb->z = p;
            break;
            case 1:
                rgb->x = q;
                rgb->y = v;
                rgb->z = p;
            break;
            case 2:
                rgb->x = p;
                rgb->y = v;
                rgb->z = t;
            break;
            case 3:
                rgb->x = p;
                rgb->y = q;
                rgb->z = v;
            break;
            case 4:
                rgb->x = t;
                rgb->y = p;
                rgb->z = v;
            break;
            case 5:
                rgb->x = v;
                rgb->y = p;
                rgb->z = q;
            break;
        }
    }
}

static void rgb_to_hsv(vect *rgb, vect *hsv)
{
    float h, s, v;
    float cmax, cmin;
    float r, g, b;

    r = rgb->x;
    g = rgb->y;
    b = rgb->z;
    /* find the cmax and cmin of r g b */
    cmax = r;
    cmin = r;
    cmax = (g > cmax ? g : cmax);
    cmin = (g < cmin ? g : cmin);
    cmax = (b > cmax ? b : cmax);
    cmin = (b < cmin ? b : cmin);
    v = cmax;           /* value */
    
    if (cmax > CTOLERANCE)
    {
        s = (cmax - cmin) / cmax;
    }
    else
    {
        s = 0.0;
        h = 0.0;
    }
    if (s < CTOLERANCE)
    {
        h = 0.0;
    }
    else
    {
        float cdelta;
        float rc, gc, bc;

        cdelta = cmax-cmin;
        rc = (cmax - r) / cdelta;
        gc = (cmax - g) / cdelta;
        bc = (cmax - b) / cdelta;
        if (r == cmax)
        {
            h = bc - gc;
        }
        else if (g == cmax)
        {
            h = 2.0 + rc - bc;
        }
        else
        {
            h = 4.0 + gc - rc;
        }
        h = h * 60.0;
        if (h < 0.0)
        {
            h += 360.0;
        }
    }
    hsv->x = h / 360.0;
    hsv->y = s;
    hsv->z = v;
}

 
// [crispy] copied over from i_video.c
int V_GetPaletteIndex(byte *palette, int r, int g, int b)
{
    int best, best_diff, diff;
    int i;

    best = 0; best_diff = INT_MAX;

    for (i = 0; i < 256; ++i)
    {
        diff = (r - palette[3 * i + 0]) * (r - palette[3 * i + 0])
             + (g - palette[3 * i + 1]) * (g - palette[3 * i + 1])
             + (b - palette[3 * i + 2]) * (b - palette[3 * i + 2]);

        if (diff < best_diff)
        {
            best = i;
            best_diff = diff;
        }

        if (diff == 0)
        {
            break;
        }
    }

    return best;
}

byte V_Colorize (byte *playpal, int cr, byte source, boolean keepgray109)
{
    vect rgb, hsv;

    // [crispy] preserve gray drop shadow in IWAD status bar numbers
    if (cr == CR_NONE || (keepgray109 && source == 109))
    {
        return source;
    }

    rgb.x = playpal[3 * source + 0] / 255.;
    rgb.y = playpal[3 * source + 1] / 255.;
    rgb.z = playpal[3 * source + 2] / 255.;

    rgb_to_hsv(&rgb, &hsv);

    // if (cr == CR_DARK)
    // {
    //     hsv.z *= 0.5;
    // }
    // else if (cr == CR_GRAY)
    // {
    //     hsv.y = 0;
    // }
    // else
    {
        // [crispy] hack colors to full saturation
        hsv.y = 1.0;

        if (cr == CR_RED)
        {
            hsv.x = 0.;
        }
        else if (cr == CR_DARKRED)
        {
            hsv.z *= 0.666;
        }
        else if (cr == CR_GREEN)
        {
            hsv.x = (145. * hsv.z + 120. * (1. - hsv.z))/360.;
        }
        else if (cr == CR_DARKGREEN)
        {
            hsv.x = (145. * hsv.z + 120. * (1. - hsv.z))/360.;
            hsv.z *= 0.65;
        }
        else if (cr == CR_OLIVE)
        {
            hsv.x = 0.20;
            hsv.y *= 0.65;
            hsv.z *= 0.45;
        }
        else if (cr == CR_BLUE)
        {
            hsv.x = 0.61;
            hsv.z *= 2.0;
        }
        else if (cr == CR_BLUE2)
        {
            hsv.x = 0.65;
            hsv.z *= 1.2;
        }
        else if (cr == CR_DARKBLUE)
        {
            hsv.x = 0.65;
            hsv.z *= 0.75;
        }
        else if (cr == CR_YELLOW)
        {
            hsv.x = (7.0 + 53. * hsv.z)/360.;
            hsv.y = 1.0 - 0.4 * hsv.z;
            hsv.z = 0.2 + 0.8 * hsv.z;
        }
        else if (cr == CR_ORANGE)
        {
            hsv.x = 0.0666;
            hsv.z *= 1.15;
        }
        else if (cr == CR_WHITE)
        {
            hsv.y = 0;
        }
        else if (cr == CR_GRAY)
        {
            hsv.y = 0;
            hsv.z *= 0.5;
        }
        else if (cr == CR_DARKGRAY)
        {
            hsv.y = 0;
            hsv.z *= 0.35;
        }
        else if (cr == CR_TAN)
        {
            hsv.x = 0.08;
            hsv.y = 0.35;
        }
        else if (cr == CR_BROWN)
        {
            hsv.x = 0.1;
            hsv.y = 0.75;
            hsv.z *= 0.65;
        }
        else if (cr == CR_ALMOND)
        {
            hsv.x = 0.08;
            hsv.y = 0.35;
            hsv.z *= 0.75;
        }
        else if (cr == CR_KHAKI)
        {
            hsv.x = 0.15;
            hsv.y = 0.55;
            hsv.z *= 0.55;
        }
        else if (cr == CR_PINK)
        {
            hsv.y = 0.69;
        }
        else if (cr == CR_BURGUNDY)
        {
            hsv.y = 0.85;
            hsv.z *= 0.70;
        }
    }

    hsv_to_rgb(&hsv, &rgb);

    rgb.x *= 255.;
    rgb.y *= 255.;
    rgb.z *= 255.;

    return V_GetPaletteIndex(playpal, (int) rgb.x, (int) rgb.y, (int) rgb.z);
}
