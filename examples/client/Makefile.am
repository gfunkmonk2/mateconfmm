#Build the executable, but don't install it.
noinst_PROGRAMS = test_client

#Where to find the header files needed by the source files:
INCLUDES =  -I$(top_srcdir)/mateconf $(MATECONFMM_EXAMPLES_CFLAGS)

#The libraries that the executable needs to link against:
LIBS = $(top_builddir)/mateconf/mateconfmm/libmateconfmm-2.6.la @LIBS@ @MATECONFMM_EXAMPLES_LIBS@

#List of source files needed to build the executable:
test_client_SOURCES = main.cc window_test.h window_test.cc
