#ifndef _LIBCRCRC_H_
#define _LIBCRCRC_H_

#include <stddef.h>
#include <stdint.h>

int crc16_fprintf( FILE * stream, uint16_t crc );

int crc16_calculate_fprintf( FILE * stream,
         uint16_t crc16( const void * data, size_t length ),
         const void * data, size_t length );


// convenience wrapper around byte-wise xmodem crc16
uint16_t crc16xmodem( const void * data, size_t length );

// convenience wrapper around byte-wise CCITT false crc16
uint16_t crc16ccitt_false( const void * data, size_t length );

#endif /* _LIBCRCRC_H_ */
