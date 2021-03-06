/** \file
 * \brief GDI+ Control
 *
 * See Copyright Notice in cd.h
 */
 
#include "cd.h"
#include "cd_private.h"
#include "cdgdiplus.h"
#include <stdlib.h>
#include <memory.h>

cdContext* cdContextNativeWindowPlus(void);
cdContext* cdContextImagePlus(void);
cdContext* cdContextDBufferPlus(void);
cdContext* cdContextPrinterPlus(void);
cdContext* cdContextEMFPlus(void);
cdContext* cdContextClipboardPlus(void);
void cdwpGdiPlusStartup(int debug);
void cdwpGdiPlusShutdown(void);

void cdInitGdiPlus(void)
{
  cdInitContextPlus();
}

void cdInitContextPlus(void)
{
  cdContext* ctx_list[CD_CTXPLUS_COUNT];
  memset(ctx_list, 0, sizeof(ctx_list));

  ctx_list[CD_CTXPLUS_NATIVEWINDOW] = cdContextNativeWindowPlus();
  ctx_list[CD_CTXPLUS_IMAGE] = cdContextImagePlus();
  ctx_list[CD_CTXPLUS_DBUFFER] = cdContextDBufferPlus();
  ctx_list[CD_CTXPLUS_PRINTER] = cdContextPrinterPlus();
  ctx_list[CD_CTXPLUS_EMF] = cdContextEMFPlus();
  ctx_list[CD_CTXPLUS_CLIPBOARD] = cdContextClipboardPlus();

  cdInitContextPlusList(ctx_list);

  cdwpGdiPlusStartup(0);
}

void cdFinishContextPlus(void)
{
  cdwpGdiPlusShutdown();
}
