/* Copyright (C)2004 Landmark Graphics
 *
 * This library is free software and may be redistributed and/or modified under
 * the terms of the wxWindows Library License, Version 3 or (at your option)
 * any later version.  The full license is in the LICENSE.txt file included
 * with this distribution.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * wxWindows Library License for more details.
 */

#ifndef __RRCOMMON_H
#define __RRCOMMON_H

#include "hputil.h"
#include "hpsecnet.h"
#include "rr.h"

#define MAXWIN 1024

#define __throw(f,l,m) {RRError e;  e.file=f;  e.line=l;  e.message=(char *)m;  throw(e);}
#define _throw(c) __throw(__FILE__, __LINE__, c)
#define errifnot(f) {if(!(f)) _throw("Unexpected NULL condition");}
#define hpj(f) {if((f)==-1) _throw(hpjGetErrorStr());}
#define fbx(f) {if((f)==-1) __throw("fbx.c", fbx_geterrline(), fbx_geterrmsg());}
#define sock(f) {if((f)==SOCKET_ERROR) _throw(hpnet_strerror());}
#define tryssl(f) {if(!(f)) _throw(hpsecnet_strerror());}
#define tryunix(f) {if((f)==-1) _throw(strerror(errno));}

#include <pthread.h>

// Clever trick to avoid deadlocks.  Create a static instance of this in any
// method you want to lock, and all exit paths from the method will automatically
// unlock it

class rrlock
{
	public:
		rrlock(pthread_mutex_t &m) : mutex(m)
			{pthread_mutex_lock(&mutex);}
		~rrlock() {pthread_mutex_unlock(&mutex);}
	private:
		pthread_mutex_t &mutex;
};

#endif
