
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <arpa/inet.h>

#include "libcrcrc.h"



// Xmodem 0x04 --> 0x4084
// VESC get values: 0x 02 01 *04* =40 84= 03
static int test_crc16xmodem_04( void ) {
    const char data = 0x04;
    uint16_t expected = htons( 0x4084 );
    uint16_t crc = 0;
    crc = crc16xmodem( &data, 1 );
    crc16_calculate_fprintf( stderr, &crc16xmodem, &data, 1 );
    assert( crc == expected );
    return EXIT_SUCCESS;
}

static int test_crc16xmodem_04_inclusive( void ) {
    const char data[3] = { '\x04' ,'\x40', '\x84' };
    uint16_t crc = crc16xmodem( data, 3 );
    crc16_calculate_fprintf( stderr, &crc16xmodem, data, 3 );
    assert( crc == 0 );
    return EXIT_SUCCESS;
}


static int test_crc16xmodem_vesc_duty_cycle( void ) {
    const char data[5] = { 0x05, 0x00, 0x01, 0x86, 0xA0 };
    uint16_t expected = htons( 0x10B3 );
    uint16_t crc = 0;
    crc = crc16xmodem( data, 5 );
    crc16_calculate_fprintf( stderr, &crc16xmodem, data, 5 );
    assert( crc == expected );
    return EXIT_SUCCESS;
}

static int test_crc16xmodem_vesc_duty_cycle_inclusive( void ) {
    const char data[7] = { 0x05, 0x00, 0x01, 0x86, 0xA0, 0x10, 0xB3 };
    uint16_t crc = crc16xmodem( data, 7 );
    crc16_calculate_fprintf( stderr, &crc16xmodem, data, 7 );
    assert( crc == 0 );
    return EXIT_SUCCESS;
}


static int test_crc16ccitt_false( void ) {
    const char data = 0x03;
    uint16_t expected = htons( 0xD193 );
    uint16_t crc = 0;
    crc = crc16ccitt_false( &data, 1 );
    assert( crc == expected );
    return EXIT_SUCCESS;
}

static int test_crc16ccitt_false_inclusive( void ) {
    const char data[3] = { '\x03' ,'\xD1', '\x93' };
    uint16_t crc = crc16ccitt_false( data, 3 );
    assert( crc == 0 );
    return EXIT_SUCCESS;
}


int main( void ) {
    int status = EXIT_SUCCESS;
    status &= test_crc16xmodem_04();
    status &= test_crc16xmodem_04_inclusive();
    status &= test_crc16xmodem_vesc_duty_cycle();
    status &= test_crc16xmodem_vesc_duty_cycle_inclusive();
    status &= test_crc16ccitt_false();
    status &= test_crc16ccitt_false_inclusive();
    return status;
}
