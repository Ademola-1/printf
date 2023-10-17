#include "main.h"

/**
 * _printf - writes output to standard output stream.
 * @format: input string
 *
 * Return: The length of the printed content.
 */

int _printf(const char *format, ...)
{
	int printChar = 0;

	char *str;
	char c;
	int str_len;
	int argsNum;
	va_list argsList;

	if (format == NULL)
		return (-1);

	va_start(argsList, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			printChar++;
		}
		else
		{
			format++;

			if (*format == '\0')
				break;
			if (*format == '%')
			{
				write(1, format, 1);
				printChar++;
			}
			else if (*format == 'c')
			{
				c = va_arg(argsList, int);
				write(1, &c, 1);
				printChar++;
			}
			else if (*format == 's')
			{
				str = va_arg(argsList, char*);
				str_len = 0;
				while (str[str_len] != '\0')
					str_len++;
				write(1, str, str_len);
				printChar = printChar + str_len;
			}
			else if (*format == 'd' || *format == 'i')
			{
				argsNum = va_arg(argsList, int);
				printf("%d", argsNum);
				printChar += snprintf(NULL, 0, "%d", argsNum);
			}
		}
		format++;
	}

	va_end(argsList);
	return (printChar);
}
