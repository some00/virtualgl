/* Copyright (C)2017 D. R. Commander
 *
 * This library is free software and may be redistributed and/or modified under
 * the terms of the wxWindows Library License, Version 3.1 or (at your option)
 * any later version.  The full license is in the LICENSE.txt file included
 * with this distribution.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * wxWindows Library License for more details.
 */

#ifndef __GLPF_H__
#define __GLPF_H__

#include "pf.h"
#include "boost/endian.hpp"
#include <GL/gl.h>


static const GLenum pf_glformat[PIXELFORMATS]=
{
	GL_RGB,       /* PF_RGB */
	GL_RGBA,      /* PF_RGBX */
	GL_BGR,       /* PF_BGR */
	GL_BGRA,      /* PF_BGRX */
	#ifdef GL_ABGR_EXT
	GL_ABGR_EXT,  /* PF_XBGR */
	#else
	GL_NONE,
	#endif
	GL_BGRA,      /* PF_XRGB */
	GL_RED        /* PF_COMP */
};


static const GLenum pf_gldatatype[PIXELFORMATS]=
{
	GL_UNSIGNED_BYTE,             /* PF_RGB */
	GL_UNSIGNED_BYTE,             /* PF_RGBX */
	GL_UNSIGNED_BYTE,             /* PF_BGR */
	GL_UNSIGNED_BYTE,             /* PF_BGRX */
	GL_UNSIGNED_BYTE,             /* PF_XBGR */
	#ifdef BOOST_BIG_ENDIAN
	GL_UNSIGNED_INT_8_8_8_8_REV,  /* PF_XRGB */
	#else
	GL_UNSIGNED_INT_8_8_8_8,      /* PF_XRGB */
	#endif
	GL_UNSIGNED_BYTE              /* PF_COMP */
};

#endif /* __GLPF_H__ */
