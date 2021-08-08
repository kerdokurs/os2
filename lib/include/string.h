#pragma once

#include <os_stdlib.h>
#include <os_stdint.h>

char *strcpy(char *dest, const char *src);

typedef struct string_t
{
  char *buf;
  size_t length;
} string_t;

string_t *make_string(const char *buf);
