#include <string.h>
#include <os_stdlib.h>

char *strcpy(char *dest, const char *src)
{
  while (*src)
    *(dest++) = *(src++);

  return 0;
}

string_t *make_string(const char *buf)
{
  string_t *string = malloc(sizeof(string_t));

  uint32_t length = 0;
  char *ptr = (char *)buf;
  while (*(ptr++) != '\0')
    length++;

  string->length = length;

  string->buf = (char *)malloc(length);
  strcpy(string->buf, buf);

  return string;
}
