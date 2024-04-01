#include "main.h"
#include <stdarg.h>

/**
 * _printf - prints output according to a format
 * @format: character string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;

    va_start(args, format);

    while (*format)
    {
        /* Handle regular characters */
        if (*format != '%')
        {
            printed_chars += _putchar(*format);
            format++;
            continue;
        }

        /* Handle conversion specifiers */
        format++; /* Skip '%' */
        if (*format == 'd' || *format == 'i')
        {
            int num = va_arg(args, int);
            printed_chars += print_number(num);
        }
        else
        {
            printed_chars += _putchar('%');
            printed_chars += _putchar(*format);
        }

        format++;
    }

    va_end(args);
    return printed_chars;
}
