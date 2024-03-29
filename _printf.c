#include "MAIN.h"
#include <stdio.h>

/**
 * _printf - Our own version of printf function
 * @format: Format string containing the format specifiers
 * Return: Number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    const char *ptr = format;
    int printed_chars = 0;

    va_start(args, format);

    while (*ptr != '\0')
    {
        if (*ptr == '%')
        {
            ptr++; // Movepast '%'
            if (*ptr == 'd' || *ptr == 'i')
            {
                int num = va_arg(args, int);
                printed_chars += printf("%d", num);
            }
            else
            {
                // Hndle other converssion speifiers if necessary
            }
        }
        else
        {
            putchar(*ptr);
            printed_chars++;
        }
        ptr++;
    }

    va_end(args);
    return printed_chars;
}
