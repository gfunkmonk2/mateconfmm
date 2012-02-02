## Copyright (c) 2002
## The mateconfmm development team.

SUBDIRS			= private

sublib_name		= mateconfmm
sublib_libname = mateconfmm-2.6
sublib_libversion = $(MATECONFMM_SO_VERSION)
sublib_namespace	= Conf
sublib_cflags		= $(MATECONFMM_CFLAGS)
sublib_topdir = mateconf

files_extra_h	= callback.h init.h value_listhelpers.h setinterface.h
files_extra_h_private = 
files_extra_cc	= callback.cc init.cc setinterface.cc

include $(top_srcdir)/build_shared/Makefile_build_gensrc.am_fragment

lib_LTLIBRARIES = libmateconfmm-2.6.la
libmateconfmm_2_6_la_SOURCES = $(files_all_cc)
libmateconfmm_2_6_la_LDFLAGS = $(common_ldflags)
libmateconfmm_2_6_la_LIBADD = $(MATECONFMM_LIBS)

EXTRA_DIST = $(files_extra_h_private)
