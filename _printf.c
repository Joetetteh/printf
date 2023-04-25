#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - the _Printf function
 * @format: parameter
 * Return: strings
 */

int _printf(const char *format, ...)
{
	int i;
	int print_chars = 0;
	int flags;
	int width;
	int precision, size, buff_index = 0;
	va_list list;
	char buffer[BUFF_SIZE];
	int printed = 0;



	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_index++] = format[i];
			if (buff_index == BUFF_SIZE)
				print_buffer(buffer, &buff_index);

			print_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_index);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;

			printed = handle_print(format, &i, list, buffer, flags,
			width, precision, size);

			if (printed == -1)
				return (-1);
			print_chars += printed;
		}
	}

	print_buffer(buffer, &buff_index);

	va_end(list);

	return (print_chars);
}

/**
 * print_buffer - a function to display content of buffer array
 * @buffer: parameter representing Array of chars
 * @buff_index: parameter
 */

void print_buffer(char buffer[], int *buff_index)
{
	if (*buff_index > 0)
		write(1, &buffer[0], *buff_index);

	*buff_index = 0;
}
