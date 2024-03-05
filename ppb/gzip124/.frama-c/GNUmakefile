# Makefile template for Frama-C/Eva case studies.
# For details and usage information, see the Frama-C User Manual.

### Prologue. Do not modify this block. #######################################
-include path.mk
FRAMAC ?= frama-c
include $(shell $(FRAMAC)-config -print-lib-path)/analysis-scripts/prologue.mk
###############################################################################

# Edit below as needed. Suggested flags are optional.

MACHDEP = x86_32

## Preprocessing flags (for -cpp-extra-args)
CPPFLAGS    += \
  -include$(shell $(FRAMAC)-config -print-share-path)/libc/string.h \
  -DSTDC_HEADERS=1 \
  -DHAVE_UNISTD_H=1 \
  -DDIRENT=1 \
  -DNO_UTIME=1 \
  -I$(shell $(FRAMAC)-config -print-share-path)/libc \
  -I$(DIR) \

## General flags
FCFLAGS  += \
  -add-symbolic-path=..:. \
  -nonterm-ignore do_exit \
  -main eva_main \

## Eva-specific flags
EVAFLAGS += \
  -eva-slevel 4 \
  -eva-no-alloc-returns-null \
  -eva-no-builtins-auto \
  -eva-widening-delay 3 \
  -eva-widening-period 3 \

## GUI-only flags
FCGUIFLAGS += \
## Analysis targets (suffixed with .eva)
TARGETS = gzip124.eva

gzip124.parse: \
  ../gzip.c \
  ../zip.c \
  ../deflate.c \
  ../trees.c \
  ../bits.c \
  ../unzip.c \
  ../inflate.c \
  ../util.c \
  ../crypt.c \
  ../lzw.c \
  ../unlzw.c \
  ../unpack.c \
  ../unlzh.c \
  ../getopt.c \
  $(shell $(FRAMAC)-config -print-share-path)/libc/stdlib.c \
  fc_stubs.c \

### Epilogue. Do not modify this block. #######################################
include $(shell $(FRAMAC)-config -print-lib-path)/analysis-scripts/epilogue.mk
###############################################################################

# optional, for OSCS
-include ../../Makefile.common
