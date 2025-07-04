/* ========================================================================
 * Copyright 1988-2007 University of Washington
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * 
 * ========================================================================
 */

/*
 * Program:	Operating-system dependent routines -- HP/UX version
 *
 * Author:	Mark Crispin
 *		Networks and Distributed Computing
 *		Computing & Communications
 *		University of Washington
 *		Administration Building, AG-44
 *		Seattle, WA  98195
 *		Internet: MRC@CAC.Washington.EDU
 *
 * Date:	11 May 1989
 * Last Edited:	16 August 2007
 */

#define isodigit(c)    (((unsigned)(c)>=060)&((unsigned)(c)<=067))
#define toint(c)       ((c)-'0')

#include <stdio.h>

#include "tcp_unix.h"		/* must be before osdep includes tcp.h */
#include "mail.h"
#include "osdep.h"
#include <stdio.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <sys/utsname.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <ctype.h>
#include <errno.h>
#ifndef errno
extern int errno;		/* just in case */
#endif
extern char *sys_errlist[];
extern int sys_nerr;
#include <pwd.h>
#include "misc.h"


#include "fs_unix.c"
#include "ftl_unix.c"
#include "nl_unix.c"
#include "env_unix.c"
#define fork vfork
#include "tcp_unix.c"
#include "gr_waitp.c"
#include "flocksim.c"
#include "tz_sv4.c"
#undef setpgrp
#include "setpgrp.c"
#include "utime.c"

/* Emulator for BSD gethostid() call
 * Returns: a unique identifier for the system.  
 * Even though HP/UX has an undocumented gethostid() system call,
 * it does not work (at least for non-privileged users).  
 */

long gethostid (void)
{
  struct utsname udata;
  return (uname (&udata)) ? 0xfeedface : atol (udata.__idnumber);
}
