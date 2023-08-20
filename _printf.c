#include "main.h"
#include <stdarg.h>
#include <unistd.h>

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
  
  va_list args;
  va_start(args, format);

  int chars_printed = 0;

  if (!format) {
    va_end(args);
    return -1;
  }

  while (*format) {
    if (*format == '%') {
      format++;
      switch (*format) {
       case 'c':
         chars_printed += write(1, va_arg(args, int), 1);
         break;
       case 's':
         chars_printed += write(1, va_arg(args, char *), 
           strlen(va_arg(args, char *)));
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
