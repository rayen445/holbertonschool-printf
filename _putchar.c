#include "main.h"

/**
 * _putchar - Custom putchar function
 * @c: Character to print
 *
 * Return: On success 1.
 *         On error, -1 is returned.
 */
int _putchar(char c)
{
    /* Implementation of _putchar function */
    return (write(1, &c, 1)); // Assuming file descriptor 1 is stdout
}
