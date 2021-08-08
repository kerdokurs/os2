// #include "io.h"
// #include "utils.h"
// #include "string.h"

#include "os_stdlib.h"
#include "io.h"

int osmain()
{
  void *ptr = malloc(1);
  --ptr;
  char *const hello_world = "Hello, world!\0";
  write(hello_world, 15);
  // clear_screen();

  // const char * const hello_world = "Hello, world!\nWelcome to KerdoOS!\n";
  // string_t hw_str = string((char *)hello_world);
  // println(&hw_str);

  // string_t header_str = string((char * const)("Choose option:\nF) File explorer"));
  // println(&header_str);

  // char input = getc();
  // write(&input, 1);

  // uint64_t c = 100000000;

  // for (uint8_t x = 0; x < 10; x++)
  // {
  //   move_cursor_to(0, x);
  //   for (uint64_t y = 0; y < c; y++)
  //   {
  //     asm("nop");
  //   }
  // }

  // char *buf = (char *)malloc(80);
  // write(buf, 80);

  while (1)
    ;

  return 0;
}
