#include <stdarg.h>
#include <stdio.h>

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
            format++;
            switch (*format)
            {
                case 'c':
                    count += putchar(va_arg(args, int));
                    break;
                case 's':
                    {
                        char *str = va_arg(args, char *);
                        if (str == NULL)
                            str = "(null)";
                        while (*str != '\0')
                        {
                            count += putchar(*str);
                            str++;
                        }
                        break;
                    }
                case '%':
                    count += putchar('%');
                    break;
                default:
                    count += putchar('%');
                    count += putchar(*format);
                    break;
            }
        }
        else
        {
            count += putchar(*format);
        }
        format++;
    }

    va_end(args);

    return count;
}

int main(void)
{
    int chars_printed = _printf("%s\n", "Hello, world!");
    printf("Number of characters printed: %d\n", chars_printed);

    chars_printed = _printf("This is a character: %c\n", 'A');
    printf("Number of characters printed: %d\n", chars_printed);

    chars_printed = _printf("Printing a percent sign: %%\n");
    printf("Number of characters printed: %d\n", chars_printed);

    return (0);
}
