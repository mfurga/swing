#ifndef _SWG_LOG_H_INCLUDED_
#define _SWG_LOG_H_INCLUDED_

#include "swg_core.h"

#define SWG_LOG_DEBUG               5
#define SWG_LOG_INFO                4
#define SWG_LOG_ALERT               3
#define SWG_LOG_WARN                2
#define SWG_LOG_ERROR               1
#define SWG_LOG_CRITICAL            0

typedef struct swg_log_s {
  FILE *file;
  swg_uint_t level;
} swg_log_t;

#if (SWG_DEBUG)

#define swg_log_debug0(log, fmt)                                         \
        swg_log_debug(log, fmt)

#define swg_log_debug1(log, fmt, arg1)                                   \
        swg_log_debug(log, fmt, arg1)

#define swg_log_debug2(log, fmt, arg1, arg2)                             \
        swg_log_debug(log, fmt, arg1, arg2)

#define swg_log_debug3(log, fmt, arg1, arg2, arg3)                       \
        swg_log_debug(log, fmt, arg1, arg2, arg3)

#define swg_log_debug4(log, fmt, arg1, arg2, arg3, arg4)                 \
        swg_log_debug(log, fmt, arg1, arg2, arg3, arg4)

#define swg_log_debug5(log, fmt, arg1, arg2, arg3, arg4, arg5)           \
        swg_log_debug(log, fmt, arg1, arg2, arg3, arg4, arg5)

#define swg_log_debug6(log, fmt, arg1, arg2, arg3, arg4, arg5, arg6)     \
        swg_log_debug(log, fmt, arg1, arg2, arg3, arg4, arg5, arg6)

#else  // !SWG_DEBUG

#define swg_log_debug0(log, fmt)
#define swg_log_debug1(log, fmt, arg1)
#define swg_log_debug2(log, fmt, arg1, arg2)
#define swg_log_debug3(log, fmt, arg1, arg2, arg3)
#define swg_log_debug4(log, fmt, arg1, arg2, arg3, arg4)
#define swg_log_debug5(log, fmt, arg1, arg2, arg3, arg4, arg5)
#define swg_log_debug6(log, fmt, arg1, arg2, arg3, arg4, arg5, arg6)

#endif

void swg_log_debug(const swg_log_t *log, const char *fmt, ...);

void swg_log_error(swg_uint_t level, const swg_log_t *log, const char *fmt, ...);

static void swg_log_error_core(swg_uint_t level, const swg_log_t *log, const char *fmt, ...);

#endif  // _SWG_LOG_H_INCLUDED_
