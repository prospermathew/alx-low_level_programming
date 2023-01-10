0x09 Static Libraries
0-isupper.c

                

#include "main.h"

/**

 * _isupper - uppercase letters

 * @c: char to check

 *

 * Return: 0 or 1

 */

int _isupper(int c)

{

        if (c >= 'A' && c <= 'Z')

                return (1);

        else

        return (0);

}

 

 


0-memset.c

                

#include "main.h"

/**

 * _memset - fill a block of memory with a specific value

 * @s: starting address of memory to be filled

 * @b: the desired value

 * @n: number of bytes to be changed

 *

 * Return: changed array with new value for n bytes

 */

char *_memset(char *s, char b, unsigned int n)

{

        int i = 0;


        for (; n > 0; i++)

        {

                s[i] = b;

                n--;

        }

        return (s);

}

 



0-strcat.c


#include "main.h"

 /**

 * _strcat - concatenates two strings

 * @dest: input value

 * @src: input value

 *

 * Return: void        

 */

char *_strcat(char *dest, char *src)

{

        int i;

        int j;


        i = 0;

        while (dest[i] != '\0')

        {

                i++;

        }

        j = 0;

        while (src[j] != '\0')

        {

                dest[i] = src[j];

                i++;

                j++;

        }                


        dest[i] = '\0';

        return (dest);

}
