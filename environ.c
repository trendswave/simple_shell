#include "shell.h"

/**
 * 
 *
 * 
 */
char *_genv(const char *var)
{
	int j, k, ln = 0;

	while (var[ln] != '\0')
		ln++;

	if (ln == 0)
		return (NULL);

	for (j = 0 ; environ[j] != NULL ; j++)
	{
		for (k = 0 ; var[k] != '\0' ; k++)
		{
			if (environ[j][k] != var[k])
				break;
		}
		if (var[k] == '\0')
			return (environ[j] + k + 1);
	}
	return (NULL);
}
/**
 *
 *
 *
 */

int _how(char *data)
{
        struct stat status;

        while (data)
        {
                if (stat(data, &status) == 0)
                {
                        return (0);
                }
                break;
        }
        return (-1);
}
