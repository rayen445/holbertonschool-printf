#include "main.h"

/**
 * _printf.c 
 *  Format 
 *
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
            format++;
            switch (*format)
            {
                case 'c':
                    count += _putchar(va_arg(args, int));
                    break;
                case 's':
                    {
                        char *str = va_arg(args, char *);
                        if (str == NULL)
                            str = "(null)";
                        while (*str != '\0')
                        {
                            count += _putchar(*str);
                            str++;
                        }
                        break;
                    }
                case '%':
                    count += _putchar('%');
                    break;
                default:
                    count += _putchar('%');
                    count += _putchar(*format);
                    break;
            }
        }
        else
        {
            count += _putchar(*format);
        }
        format++;
    }

    va_end(args);

    return count;
}
