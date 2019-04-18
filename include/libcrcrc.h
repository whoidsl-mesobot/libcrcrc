#ifndef _LIBCRCRC_H_
#define _LIBCRCRC_H_

#include <stddef.h>
#include <stdint.h>

// convenience wrapper around byte-wise xmodem crc16
uint16_t crc16xmodem( const void * data, size_t length );



#endif /* _LIBCRCRC_H_ */
