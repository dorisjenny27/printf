#include "header.h"

int _printf(const char *format, ...)
{
  /* Count the return value for _printf */
  int count = 0;
  
  va_list data;
  va_start(data, *format);

  for (int i = 0; format[i] != '\0'; i++)
  {
      if (format[i] != '%')
      {
          _putchar(format[i]); // Output the character directly if it's not '%'
          count = count + 1;   // Increase the count of characters printed
      }
      else if(format[i] == '%') // If the character is '%', it marks the beginning of a format specifier
      {
          switch (format[++i]) // Check the next character after '%' to identify the format specifier
          {
              case 'c':
                {
                  char x = va_arg(data, int);
                  _putchar(x);
                  count = count + 1;
  
                    // Code to handle the '%c' format specifier is expected to be placed here
                    // This specifier is used to print a single character, and its corresponding argument
                    // must be an integer (representing an ASCII value) that will be converted to the character.
                    // Example: printf("Hello %c", 'M'); // Output: A //TECNO CAMON A33 //OPPO 
                    break;
                   }

              case 's':
                {
                  char *p = va_arg(data, char*);
                  // for (int y = 0; p[y] != '\0'; y++)
                  //   {
                  //     _putchar(p[y]);
                  //   }
                  //*str = *p = address of
                  count = count + _putstr(&p);
                  break;
                }
            
              case '%':
                {
                  _putchar('%');
                  count = count + 1;
                  break;
                }

              // case 'd':
              //   {
              //     va_arg(data, int);
              //       _putchar(8  );
              //       //_printf("%d", 897);
              //   }
              // Other cases for different format specifiers (e.g., '%d', '%s', etc.) are expected to be added here.
          }
      }
  }

  return (count);
}
