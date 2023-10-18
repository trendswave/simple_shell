#include "shell.h"
/**
 * ascii - this is to convert integer(int) to string.
 * @p: integer(int) given to be converted.
 * Return: Returns pointer to the new string.
 *
 */

char *ascii(int p)
{

	long q;
	int check, red;
	char *s;

	/* creating space for max/min int character string */
	s = malloc(sizeof(char) * 12);
	/* if string passed is NULL, return NULL */
	if (s == NULL)
		return (NULL);

	/* cast the passed integer n into a long variable */
	q = p;

	/* initialize count to zero */
	check = 0;

	/* if x is a negative number */
	if (q < 0)
	{
		/* append the negative sign */
		s[check++] = '-';
		/* convert the number to a positive number */
		q = q * -1;
	}
	/* if x is greater than 9 */
	if (q > 9)
	{
		red = 10;

		/* if x is > 10, parse through to get to highest place */
		while (q / red >= 10)
			red = red * 10;

		/* append the converted highest's place int into the string */
		s[check++] = ((q / red) + '0');

		/* if x is upto or equal to 10 */
		while (red >= 10)
		{
			/* move >> through number */
			red = red / 10;
			/*insert converted numbers into the string */
			s[check++] = (((q / red) % 10)  + '0');
		}

	}
	/* else if x is a single digit, convert and insert to string */
	else
		s[check++] = q + '0';

	/* insert null */
	s[check] = 0;
	return (s);
}
