#ifndef INCLUDE_IO_H
#define INCLUDE_IO_H

#include "os_stdlib.h"
// #include "stdint.h"
// #include "string.h"

/** outb:
 *  Sends the given data to the given I/O port. Defined in io.s
 *
 *  @param port The I/O port to send the data to
 *  @param data The data to send to the I/O port
 */
void outb(unsigned short port, unsigned char data);

/** inb:
 *  Read a byte from an I/O port.
 *
 *  @param  port The address of the I/O port
 *  @return      The read byte
 */
extern unsigned char inb(unsigned short port);

/** read_scan_code:
*  Reads a scan code from the keyboard
*
*  @return The scan code (NOT an ASCII character!)
*/
extern unsigned char read_scan_code();

void move_cursor_to(uint8_t x, uint8_t y);

/** write:
 * Writes a character buffer to the screen. Buffer needs to end with a 0-byte to end the writing. The max length of the buffer is 256.
 */
void write(char *buf, uint16_t size);

void clear_screen();

#endif
