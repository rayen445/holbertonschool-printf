#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...);

int main(void)
{
    int num = 123;
    _printf("This is a number: %d\n", num);
    return 0;
}

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int printed_chars = 0;

    while (*format)
    {
        if (*format == '%' && (*(format + 1) == 'd' || *(format + 1) == 'i'))
        {
            int num = va_arg(args, int);
            printf("%d", num);
            format++; // Skip 'd' or 'i'
            printed_chars++;
        }
        else
        {
            putchar(*format);
            printed_chars++;
        }
        format++;
    }

    va_end(args);
    return printed_chars;
}
