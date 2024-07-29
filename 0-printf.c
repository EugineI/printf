#include"main.h"
#include<unistd.h>
#include<stdio.h>
#include<stdarg.h>
/**
 * _printf - custome printf
 * @format: format handler
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	const char *ptr;
	int count = 0;
	char c, *s;

	va_start(args, format);
	for (ptr = format; *ptr != '\0'; ptr++)
	{
		if (*ptr == '%')
		{
			ptr++;
			switch (*ptr)
			{
				case 'c':
					c = (char)va_arg(args, int);
					write(1, &c, 1);
					count++;
					break;
				case 's':
					s = va_arg(args, char *);
					if (s == NULL)
						s = "(null)";
					for (; *s != '\0'; count++, s++)
						write(1, s, 1);
					break;
				case '%':
					write(1, ptr, 1);
					count++;
					break;
				default:
					break;
			} } else
		{
			write(1, ptr, 1);
			count++; }
	} va_end(args);
	return (count); }
