#include "main.h"

/**
 * get_flags - flag function
 * @format: Formatted string in which to print the arguments
 * @i: parameter
 * Return: return flags
 */

int get_flags(const char *format, int *i)
{
	int x, current;
	int flags_ = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (current = *i + 1; format[current] != '\0'; current++)
	{
		for (x = 0; FLAGS_CH[x] != '\0'; x++)
			if (format[current] == FLAGS_CH[x])
			{
				flags_ |= FLAGS_ARR[x];
				break;
			}

		if (FLAGS_CH[x] == 0)
			break;
	}

	*i = current - 1;

	return (flags_);
}
