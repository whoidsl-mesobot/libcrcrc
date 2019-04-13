AM_CFLAGS = -Wall -std=gnu99 -pg -g -I ./include

lib_LTLIBRARIES = libcrcrc.la

dist_doc_DATA = README.md

include_HEADERS = include/libcrcrc.h

libvesc_la_SOURCES = src/libcrcrc.c \
		     src/crc16xmodem.h \
		     src/crc16cmodem.c

libcrcrc_la_CFLAGS = $(AM_CFLAGS)
libcrcrc_la_LDFLAGS = -version-info 0:1 -module -shared -export-dynamic

TESTS = test-libcrcrc

check_PROGRAMS = test-libcrcrc

test_libcrcrc_SOURCES = test/test-libcrcrc.c
test_libcrcrc_CFLAGS = $(AM_CFLAGS)
test_libcrcrc_LDFLAGS = -L@builddir@ -lcrcrc
