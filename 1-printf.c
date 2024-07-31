#include<unistd.h>
#include"main.h"
#include<stdarg.h>
/**
 * _printf - printf function.
 * @format: format string
 * Return: count.
 */
int _printf(const char *format, ...)
{
	int count = 0;
	const char *ptr;
	int i;
	va_list args;

	va_start(args, format);
	for (ptr = format; *ptr != '\0'; ptr++)
	{
		if (*ptr == '%')
		{
			ptr++;
			switch (*ptr)
			{
				case 'i':
				case 'd':
					i = va_arg(args, int);
					if (i < 0)
					{
						write(1, "-", 1);
						count++;
						i = -i;
					}
					char buf[12];
					char *pos = &buf[sizeof(buf) - 1];
					*pos = '\0';
					do {
						pos--;
						*pos = '0' + i % 10;
						i /= 10;
					} while (i);
					count += write(1, pos, &buf[sizeof(buf)] - pos);
					break;
				default:
					break; }
		} else
		{
			count += write(1, ptr, 1); }
	} va_end(args);
	return (count); 
