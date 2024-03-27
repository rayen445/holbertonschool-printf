#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format != '\0')
    {
        if (*format == '%')
        {
            if (*(format + 1) == '%')
            {
                count += _putchar('%'); /* Print a single % character */
                format += 2; // Skip both % characters
                continue;
            }
        }
        count += _putchar(*format);
        format++;
    }

    va_end(args);

    return count;
}
