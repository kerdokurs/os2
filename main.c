#include <os_stdlib.h>
#include <io.h>
#include <string.h>
#include <os_stdio.h>

int osmain()
{
  clear_screen();
  string_t *string = make_string("Hello, world!");
  print(string);

  while (1)
    ;

  return 0;
}
