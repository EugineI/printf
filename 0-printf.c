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
	char c, *s, *pos, buf[12];
	int i;

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
				case 'i':
				case 'd':
					i = va_arg(args, int);
					if (i < 0)
					{
						write(1, "-", 1);
						count++;
						i = -i; }
					pos = &buf[sizeof(buf) - 1];
					*pos = '\0';
					do {
						pos--;
						*pos = '0' + i % 10;
						i /= 10;
					} while (i);
					count += write(1, pos, &buf[sizeof(buf)] - pos);
					break;
				default:
					write (1, ptr - 1, 1);
					write(1, ptr, 1);
					count += 2;
					break;
			} } else
		{
			write(1, ptr, 1);
			count++; }
	} va_end(args);
	return (count); }
	int main() {
		    int num = 123;
		        char ch = 'A';
			    char *str = "Hello";
			        
			        _printf("Character: %c\n", ch); 
				    _printf("String: %s\n", str); 
				        _printf("Integer: %d\n", num); 
					    _printf("Negative Integer: %i\n", -456); 
					        _printf("This is a %% sign\n");  
						    _printf("Unsupported: %f\n", 3.14); 
						        return 0;
	}
