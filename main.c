#include "main.h"

int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    char c;

    va_start(args, format);

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'c':
                    c = (char) va_arg(args, int);
                    write(1, &c, 1);
                    count++;
                    break;
                case 's':
                    {
                        char *str = va_arg(args, char *);
                        while (*str != '\0')
                        {
                            write(1, str, 1);
                            str++;
                            count++;
                        }
                        break;
                    }
                case '%':
                    write(1, "%", 1);
                    count++;
                    break;
                default:
                    break;
            }
        }
        else
        {
            write(1, format, 1);
            count++;
        }
        format++;
    }

    va_end(args);

    return count;
}
