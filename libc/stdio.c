#include "stdio.h"

#define STDIO_INT_BUF	(11)

int
printd (int val)
{
	int size = 0;
	int flag = 0;
	char buf[STDIO_INT_BUF];

	if (val < 0)
	{
		flag = 1;
		val = -val;
	}
	else if (val == 0)
	{
		buf[size++] = '0';
	}
	while (val)
	{
		buf[size++] = '0' + (val % 10);
		val /= 10;
	}
	if (flag)
	{
		buf[size++] = '-';
	}
	for (int i = size - 1; i >= 0; i--)
	{
		uart_poll_out(buf[i]);
	}

	return size;
}

int
prints (const char *s)
{
	int size = 0;

	for (; *s != '\0'; s++)
	{
		uart_poll_out(*s);
		size++;
	}

	return size;
}

#define STDIO_HEX_BUF	(16)

int
printx (unsigned int val)
{
	int size = 0;
	char buf[STDIO_HEX_BUF];

	if (val == 0)
	{
		buf[size++] = '0';
	}
	while (val)
	{
		buf[size] = '0' + (val % 16);
		if (buf[size] > '9')
		{
			buf[size] += ('a' - '9' - 1);
		}
		size++;
		val /= 16;
	}
	for (int i = size - 1; i >= 0; i--)
	{
		uart_poll_out(buf[i]);
	}

	return size;
}

int
printX (unsigned int val)
{
	int size = 0;
	char buf[STDIO_HEX_BUF];

	if (val == 0)
	{
		buf[size++] = '0';
	}
	while (val)
	{
		buf[size] = '0' + (val % 16);
		if (buf[size] > '9')
		{
			buf[size] += ('A' - '9' - 1);
		}
		size++;
		val /= 16;
	}
	for (int i = size - 1; i >= 0; i--)
	{
		uart_poll_out(buf[i]);
	}

	return size;
}

int
print (const char *format, va_list arg)
{
	int size = 0;
	for (; *format != '\0'; format++)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
			case 'd':
				size += printd (va_arg (arg, int));
				break;
			case 's':
				size += prints ((const char *) va_arg (arg, int));
				break;
			case 'x':
				size += printx (va_arg (arg, int));
				break;
			case 'X':
				size += printX (va_arg (arg, int));
				break;
			default:
				uart_poll_out ('%');
				size++;
				format--;
				break;
			}
		}
		else
		{
			uart_poll_out (*format);
			size++;
		}
	}

	return size;
}

/**
 * @brief Write formatted output to UART from the format string FORMAT.
 * 
 * @param format 
 * @param ... 
 */
int
printf (const char *format, ...)
{
    va_list arg;
	int done;

    va_start (arg, format);
    done = print (format, arg);
    va_end (arg);

    return done;
}

int
puts (const char *s)
{
	int size = prints (s);
	uart_poll_out('\n');

	return size;
}
int
putchar (const char c)
{
	uart_poll_out (c);

	return 1;
}