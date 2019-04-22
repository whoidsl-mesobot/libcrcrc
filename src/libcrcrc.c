#include <arpa/inet.h>

#include <stdio.h>
#include <inttypes.h>

#include "libcrcrc.h"

// decide whether to expose all methods and install all headers, or just the
// main `libcrcrc.h` -- for now, get the other headers here in the `.c`
#include "crc16xmodem.h"
#include "crc16ccitt_false.h"

// for sanity...
int crc16_fprintf( FILE * stream, uint16_t crc ) {
    return fprintf( stream, "0x%04" PRIx16, crc );
}


int crc16_calculate_fprintf( FILE * stream,
        uint16_t crc16( const void * data, size_t length ),
        const void * data, size_t length ) {
    uint16_t crc = crc16( data, length );
    int n = 0;
    n += fprintf( stream, "%zub data, crc16( ", length );
    for( int j = 0; j < length; j++ ) {
        n += fprintf( stderr, "%02" PRIx8 " ", ((uint8_t *)data)[j] );
    }
    n += fprintf( stream, ") = " );
    n += crc16_fprintf( stream, crc );
    n += fprintf( stream, "\n" );
    return n;
}


uint16_t crc16xmodem( const void * data, size_t length ) {
    return htons( crc16xmodem_byte( 0, data, length ) );
}


uint16_t crc16ccitt_false( const void * data, size_t length ) {
    return htons( crc16ccitt_false_byte( 0xFFFF, data, length ) );
}
