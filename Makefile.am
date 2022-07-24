AM_CFLAGS = -std=gnu99 -I $(top_srcdir)/include

lib_LTLIBRARIES = libcrcrc.la

dist_doc_DATA = README.md

pkginclude_HEADERS = \
		include/crc16xmodem.h \
		include/crc16ccitt_false.h \
		include/libcrcrc.h

libcrcrc_la_SOURCES = src/libcrcrc.c \
		     src/crc16xmodem.c \
		     src/crc16ccitt_false.c

libcrcrc_la_CFLAGS = $(AM_CFLAGS)
libcrcrc_la_LDFLAGS = -version-info 0:2 -module -shared -export-dynamic

TESTS = test-libcrcrc

check_PROGRAMS = test-libcrcrc

test_libcrcrc_SOURCES = test/test-libcrcrc.c
test_libcrcrc_CFLAGS = $(AM_CFLAGS)
test_libcrcrc_LDFLAGS = -L@builddir@ -lcrcrc

.PHONY: test
test: check

CLEANFILES = gmon.out
