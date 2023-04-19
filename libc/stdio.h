#ifndef __STDIO__
#define __STDIO__

#include <common.h>
#include "../uart/uart.h"

int printd (int val);
int prints (const char *s);
int printx (unsigned int val);
int printX (unsigned int val);
int print (const char *format, va_list arg);
int printf (const char *format, ...);

int puts(const char *s);
int putchar(const char c);

#endif	// stdio.h
