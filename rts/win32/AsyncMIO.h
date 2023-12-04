/* AsyncIO.h
 *
 * Integrating Win32 asynchronous I/O with the GHC RTS.
 *
 * (c) sof, 2002-2003.
 *
 * NOTE: This is the MIO manager, only used for --io-manager=posix.
 *       For the WINIO manager see AsyncWinIO.h.
 */

#pragma once

#include "Rts.h"

extern unsigned int
addIORequest(int   fd,
             bool  forWriting,
             bool  isSock,
             HsInt len,
             char* buf);
extern unsigned int addDelayRequest(HsInt usecs);
extern unsigned int addDoProcRequest(void* proc, void* param);
extern int  startupAsyncIO(void);
extern void shutdownAsyncIO(bool wait_threads);

extern int awaitRequests(bool wait);

extern void abandonRequestWait(void);
extern void resetAbandonRequestWait(void);
