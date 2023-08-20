#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

/** 
 * main - Test _printf
 * Return: 0
*/
int main(void) {
    _printf("Hello %c%s%c", 'A', "World", '!');
    return 0;
}

/**
 * _printf - Format and print output 
 * @format: Format string
 * Return: Number of chars printed
*/
int _printf(const char *format, ...) {

    int chars_printed = 0;
  
    va_list args;
    va_start(args, format);

    if (!format) {
        va_end(args);
        return -1; 
    }

    while (*format) {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'c':
                    {
                        char c = (char)va_arg(args, int);
                        chars_printed += write(1, &c, 1); 
                    }
                    break;
                case 's':
                    {
                        char *str = va_arg(args, char*);
                        chars_printed += write(1, str, strlen(str));
                    }
                    break;
            }
        } else {
            chars_printed += write(1, format, 1);
        }
        format++;
    }

    va_end(args);
    return chars_printed;
}
