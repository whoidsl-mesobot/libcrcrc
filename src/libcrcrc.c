
#include "libcrcrc.h"

// decide whether to expose all methods and install all headers, or just the
// main `libcrcrc.h` -- for now, get the other headers here in the `.c`
#include "crc16xmodem.h"
#include "crc16ccitt_false.h"

uint16_t crc16xmodem( const void * data, size_t length ) {
    return crc16xmodem_byte( 0, data, length );
}

uint16_t crc16ccitt_false( const void * data, size_t length ) {
    return crc16ccitt_false_byte( 0xFFFF, data, length );
}
