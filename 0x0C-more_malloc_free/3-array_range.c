TASKS
TASKS

               

0. Trust no one

               

Write a function that allocates memory using malloc.

               

               

Prototype: void *malloc_checked(unsigned int b);

               

               

Returns a pointer to the allocated memory

               

               

if malloc fails, the malloc_checked function should cause normal process termination with a status value of 98

               

               

1. string_nconcat

               

Write a function that concatenates two strings.

               

               

Prototype: char *string_nconcat(char *s1, char *s2, unsigned int n);

               

               

The returned pointer shall point to a newly allocated space in memory, which contains s1, followed by the first n bytes of s2, and null terminated

               

               

If the function fails, it should return NULL

               

               

If n is greater or equal to the length of s2 then use the entire string s2

               

               

if NULL is passed, treat it as an empty string

               

               

2. calloc

               

Write a function that allocates memory for an array, using malloc.

               

               

Prototype: void *_calloc(unsigned int nmemb, unsigned int size);

               

               

The _calloc function allocates memory for an array of nmemb elements of size bytes each and returns a pointer to the allocated memory.

               

               

The memory is set to zero

               

               

If nmemb or size is 0, then _calloc returns NULL

               

               

If malloc fails, then _calloc returns NULL

               

               

3. array_range

               

Write a function that creates an array of integers.

               

               

Prototype: int *array_range(int min, int max);

               

               

The array created should contain all the values from min (included) to max (included), ordered from min to max

               

               

Return: the pointer to the newly created array

               

               

If min > max, return NULL

               

               

If malloc fails, return NULL

               

               

4. realloc

               

Write a function that reallocates a memory block using malloc and free

               

               

Prototype: void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

               

               

where ptr is a pointer to the memory previously allocated with a call to malloc: malloc(old_size)

               

               

old_size is the size, in bytes, of the allocated space for ptr and new_size is the new size, in bytes of the new memory block

               

               

The contents will be copied to the newly allocated space, in the range from the start of ptr up to the minimum of the old and new sizes

               

               

If new_size > old_size, the “added” memory should not be initialized

               

               

If new_size == old_size do not do anything and return ptr

               

               

If ptr is NULL, then the call is equivalent to malloc(new_size), for all values of old_size and new_size

               

               

If new_size is equal to zero, and ptr is not NULL, then the call is equivalent to free(ptr). Return NULL

               

               

Don’t forget to free ptr when it makes sense

               

               

5. We must accept finite disappointment, but never lose infinite hope

               

Write a program that multiplies two positive numbers.

               

               

Usage: mul num1 num2

               

               

num1 and num2 will be passed in base 10

               

               

Print the result, followed by a new line

               

               

If the number of arguments is incorrect, print Error, followed by a new line, and exit with a status of 98

               

               

num1 and num2 should only be composed of digits. If not, print Error, followed by a new line, and exit with a status of 98

               

               

You are allowed to use more than 5 functions in your file

               

               

You can use bc (man bc) to check your results.



mkdir 0x0C-more_malloc_free


cd 0x0C-more_malloc_free


echo '0x0C' > README.md


vi main.h

 

Main.h codes

#ifndef MAIN_H

#define MAIN_H

#include <stdio.h>

#include <stdlib.h>

#include <limits.h>

int _putchar(char c);

void *malloc_checked(unsigned int b);

char *string_nconcat(char *s1, char *s2, unsigned int n);

void *_calloc(unsigned int nmemb, unsigned int size);

int *array_range(int min, int max);

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);


#endif




vi 0-malloc_checked.c


#include <stdlib.h>

#include "main.h"

/**

 * malloc_checked - allocates memory using malloc

 * @b: number of bytes to allocates

 *

 * Return: a pointer to the allocated memory.

 * if malloc fails, status value is equal to 98.

 */

void *malloc_checked(unsigned int b)

{

        char *p;


        p = malloc(b);

        if (p == NULL)

                exit(98);

        return (p);

}

_______________________________________________________________



vi 1-string_nconcat.c


#include "main.h"

#include <stdlib.h>


/**

 * string_nconcat - concatenates two strings.

 * @s1: first string.

 * @s2: second string.

 * @n: amount of bytes.

 *

 * Return: pointer to the allocated memory.

 * if malloc fails, status value is equal to 98.

 */

char *string_nconcat(char *s1, char *s2, unsigned int n)

{

        char *sout;

        unsigned int ls1, ls2, lsout, i;


        if (s1 == NULL)

                s1 = "";


        if (s2 == NULL)

                s2 = "";


        for (ls1 = 0; s1[ls1] != '\0'; ls1++)

                ;


        for (ls2 = 0; s2[ls2] != '\0'; ls2++)

                ;


        if (n > ls2)

                n = ls2;


        lsout = ls1 + n;


        sout = malloc(lsout + 1);


        if (sout == NULL)

                return (NULL);


        for (i = 0; i < lsout; i++)

                if (i < ls1)

                        sout[i] = s1[i];

                else

                        sout[i] = s2[i - ls1];


        sout[i] = '\0';


        return (sout);

}




vi 2-calloc.c


#include "main.h"

#include <stdlib.h>

/**

 * _calloc - allocates memory for an array.

 * @nmemb: number of elements.

 * @size: size of bytes.

 *

 * Return: pointer to the allocated memory.

 * if nmemb or size is 0, returns NULL.

 * if malloc fails, returns NULL.

 */

void *_calloc(unsigned int nmemb, unsigned int size)

{

        char *p;

        unsigned int i;


        if (nmemb == 0 || size == 0)

                return (NULL);


        p = malloc(nmemb * size);


        if (p == NULL)

                return (NULL);


        for (i = 0; i < (nmemb * size); i++)

                p[i] = 0;


        return (p);

}



vi 3-array_range.c


#include "main.h"

#include <stdlib.h>

/**

 * array_range - creates an array of integers.

 * @min: minimum value.

 * @max: maximum value.

 *

 * Return: pointer to the newly created array.

 * if man > mix, returns NULL.

 * if malloc fails, returns NULL.

 */

int *array_range(int min, int max)

{

        int *ar;

        int i;


        if (min > max)

                return (NULL);


        ar = malloc(sizeof(*ar) * ((max - min) + 1));


        if (ar == NULL)

                return (NULL);


        for (i = 0; min <= max; i++, min++)

                ar[i] = min;


        return (ar);

}
