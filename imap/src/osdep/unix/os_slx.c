/* ========================================================================
 * Copyright 2008-2009 Mark Crispin
 * ========================================================================
 */

/*
 * Program:	Operating-system dependent routines -- modern Linux version
 *
 * Author:	Mark Crispin
 *
 * Date:	1 August 1993
 * Last Edited:	18 May 2009
 *
 * Previous versions of this file were:
 *
 * Copyright 1988-2007 University of Washington
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 */
 
#include "tcp_unix.h"		/* must be before osdep includes tcp.h */
#include "mail.h"
#include "osdep.h"
#include <stdio.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <ctype.h>
#include <errno.h>
#ifndef errno
extern int errno;		/* just in case */
#endif
#include <pwd.h>
#include <shadow.h>
#include "misc.h"


#include "fs_unix.c"
#include "ftl_unix.c"
#include "nl_unix.c"
#include "env_unix.c"
#include "getspnam.c"		/* has socklen_t in spite of man page?? */
#define fork vfork
#include "tcp_unix.c"
#include "gr_waitp.c"
#include "tz_sv4.c"
#include "flocklnx.c"
#include "utime.c"
