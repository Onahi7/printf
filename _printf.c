#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * print_buffer - Prints the buffer contents to stdout
 * @buffer: The buffer to print
 * @buff_ind: The index indicating length of buffer contents
 *
 * Return: Number of bytes printed, or negative on failure
*/ 
int print_buffer(char *buffer, int buff_ind);

/**
 * _printf - Print formatted output
 * @format: Format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
        va_list args;
        va_start(args, format);

        int chars_written = 0;

        if (!format || (format[0] == '%' && format[1] == '\0'))
                return (-1);
        
        for (int i = 0; format[i]; i++)
        {
                if (format[i] == '%')
                {
                        /* Handle format specifiers */
                }
                else
                {
                        /* Buffer characters */
                        if (chars_written < BUFF_SIZE - 1)
                                buffer[chars_written++] = format[i];
                }
        }

        /* Flush buffer */
        print_buffer(buffer, chars_written);

        va_end(args);

        return (chars_written);
}

/**
 * print_buffer - Print a portion of buffer
 * @buffer: The buffer to print
 * @buff_ind: Number of bytes stored in buffer to print
 *
 * Return: Number of bytes printed, or -1 on failure
 */
int print_buffer(char *buffer, int buff_ind)
{
        int bytes;
        
        if (buff_ind > 0)
        {
                bytes = write(STDOUT_FILENO, buffer, buff_ind);
                if (bytes < 0)
                        return (-1);
        }

        return (bytes);
}
