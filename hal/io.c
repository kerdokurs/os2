#include "io.h"
// #include "utils.h"

/* The I/O ports */
#define FB_COMMAND_PORT 0x3D4
#define FB_DATA_PORT 0x3D5

/* The I/O port commands */
#define FB_HIGH_BYTE_COMMAND 14
#define FB_LOW_BYTE_COMMAND 15

#define FB_TEXT_COLOR 0
#define FB_BACKGROUND_COLOR 15

#define SCREEN_COLS 80
#define SCREEN_ROWS 25

#define KBD_DATA_PORT 0x60

static char *fb = (char *)0x000b8000;

static uint8_t current_cursor_x = 0;
static uint8_t current_cursor_y = 0;

unsigned char read_scan_code()
{
  return inb(KBD_DATA_PORT);
}

// static char *empty_buf[SCREEN_COLS] = {0};

/** fb_write_cell:
 *  Writes a character with the given foreground and background to position i
 *  in the framebuffer.
 *
 *  @param i  The location in the framebuffer
 *  @param c  The character
 *  @param fg The foreground color
 *  @param bg The background color
*/
void fb_write_cell(unsigned int i, char c, unsigned char fg, unsigned char bg)
{
  fb[i] = c;
  fb[i + 1] = ((fg & 0x0f) << 4) | (bg & 0x0f);
}

void move_cursor_to(uint8_t x, uint8_t y)
{
  current_cursor_x = x;
  current_cursor_y = y;

  uint16_t pos = y * 80 + x;

  outb(0x3D4, 0x0F);
  outb(0x3D5, (uint8_t)(pos & 0xFF));
  outb(0x3D4, 0x0E);
  outb(0x3D5, (uint8_t)((pos >> 8) & 0xFF));
}

void write(char *buf, uint16_t size)
{
  // Buffer iterator
  uint16_t i = 0;

  for (; i < size; ++i)
  {
    if (buf[i] == '\n')
    {
      move_cursor_to(0, current_cursor_y + 1);
      continue;
    }

    fb_write_cell((current_cursor_y * 80 + current_cursor_x) * 2, buf[i], FB_TEXT_COLOR, FB_BACKGROUND_COLOR);
    move_cursor_to(current_cursor_x + 1, current_cursor_y);
  }
}

// void println(string_t *str)
// {
//   write(str->buf, str->length);
//   move_cursor_to(0, current_cursor_y + 1);
// }

// void clear_screen()
// {
//   move_cursor_to(0, 0);
//   char *buf = malloc(80 * sizeof(char));
//   memset(buf, 80 * sizeof(char), ' ');
//   memset(buf + 79 * sizeof(char), sizeof(char), '\0');

//   string_t str = string(buf);

//   uint8_t y = SCREEN_ROWS;

//   while (y--)
//   {
//     println(&str);
//   }

//   free(buf);

//   move_cursor_to(0, 0);
// }
