#include "swg_log.h"

static const char *log_levels[] = {
  "critical",
  "error",
  "warn",
  "alert",
  "info",
  "debug"
};

void swg_log_error(swg_uint_t level, const swg_log_t *log, const char *fmt, ...)
{
  va_list args;

  if (log->level >= level) {
    va_start(args, fmt);
    (void) swg_log_error_core(level, log, fmt, args);
    va_end(args);
  }
}

static void swg_log_error_core(swg_uint_t level, const swg_log_t *log, const char *fmt, ...)
{
  va_list args;

  fprintf(log->file, "[%s] ", log_levels[level]);

  va_start(args, fmt);
  vfprintf(log->file, fmt, args);
  va_end(args);
}

