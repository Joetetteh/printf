#include "main.h"
/**
 *is_printable - Evaluates if a char is printable
 *@c: Character value
 *Return: 1 or 0
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}


/**
 *append_hexa_code - Append ascci in hex
 *@buffer: Temporarily holds characters
 *@i: Index.
 *@ascii_code: ASSCI CODE.
 *Return: 3 on success
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;
	buffer[i++] = '\\';
	buffer[i++] = 'x';
	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];
	return (3);
}


/**
 *is_digit - Checks for digit
 *@c: Char arguement
 *Return: 1 on success else 0
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/**
 *convert_size_number - Convert to set size
 *@num: Arguement to cast
 *@size: Size.
 *Return: Return value from num
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);
	return ((int)num);
}



/**
 *convert_size_unsgnd - Casts num to size
 *@num: Expected cast number
 *@size: Size of cast
 *Return: Returns num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);
	return ((unsigned int)num);
}

