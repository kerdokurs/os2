#include <os_stdio.h>
#include <io.h>

void print(string_t *str)
{
  write(str->buf, str->length);
}
