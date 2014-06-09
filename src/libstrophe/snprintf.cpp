/**
 * Copyright Wush Wu 2014
 * This code is the fresh new implementation of xmpp_snprintf and xmpp_vsnprintf
 */

#include <cstdarg>
#include <cstdio>

extern "C" int xmpp_snprintf (char *str, size_t count, const char *fmt, ...);
extern "C" int xmpp_vsnprintf (char *str, size_t count, const char *fmt, va_list arg);

int xmpp_snprintf (char *str, size_t count, const char *fmt, ...)
{
  va_list ap;
  int total;
    
  va_start(ap, fmt);
  str = va_arg(ap, char *);
  count = va_arg(ap, size_t);
  fmt = va_arg(ap, char *);
  total = xmpp_vsnprintf(str, count, fmt, ap);
  va_end(ap);
  return total;
}

int xmpp_vsnprintf (char *str, size_t count, const char *fmt, va_list arg) {
  return vsnprintf(str, count, fmt, arg);
}
