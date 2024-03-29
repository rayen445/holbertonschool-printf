#include "MAIN.h"

int main(void)
{
    int num = 123;
    char *str = "Hello, world!";
    
    // Test printing integers
    _printf("Integer: %d\n", num);
    
    // Test printing strings
    _printf("String: %s\n", str);

    // Test printing multiple values
    _printf("Integer: %d, String: %s\n", num, str);

    return 0;
}
