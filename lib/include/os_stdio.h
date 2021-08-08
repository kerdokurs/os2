#pragma once

#include <os_stdlib.h>
#include <string.h>

/** write:
 * Writes a character buffer to the screen. Buffer needs to end with a 0-byte to end the writing. The max length of the buffer is 256.
 */
void write(char *buf, size_t size);

void print(string_t *str);
