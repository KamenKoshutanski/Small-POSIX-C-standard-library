#ifndef _STDARG_H
#define _STDARG_H

typedef int type;
typedef int last_arg;

void va_start(va_list ap, last_arg);
type var_arg(va_list ap, type);
void va_end(va_list ap);

#endif