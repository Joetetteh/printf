#include "main.h"

/**
 * get_size - function thst returns the size and precision
 * cast to argument
 * @format: parameter
 * @i: parameter
 *
 * Return: Precision
 */
int get_size(const char *format, int *i)
{
	int current = *i + 1;
	int size = 0;

	if (format[current] == 'l')
		size = S_LONG;
	else if (format[current] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = current - 1;
	else
		*i = current;

	return (size);
}
