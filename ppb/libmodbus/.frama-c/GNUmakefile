# Makefile template for Frama-C/Eva case studies.
# For details and usage information, see the Frama-C User Manual.

### Prologue. Do not modify this block. #######################################
-include path.mk
FRAMAC ?= frama-c
include $(shell $(FRAMAC)-config -print-lib-path)/analysis-scripts/prologue.mk
###############################################################################

# Edit below as needed. Suggested flags are optional.

MACHDEP = gcc_x86_64

## Preprocessing flags (for -cpp-extra-args)
CPPFLAGS    += \
  -include__fc_libc_fixes.h \
  -I../src \
  -I.. \

## General flags
FCFLAGS     += \
  -add-symbolic-path=..:. \
  -kernel-warn-key annot:missing-spec=abort \
  -kernel-warn-key typing:implicit-function-declaration=abort \

## Eva-specific flags
EVAFLAGS    += \
  -eva-warn-key builtins:missing-spec=abort \
  -eva-precision 4 \
  -eva-split-return full \
  -eva-no-alloc-returns-null \

## GUI-only flags
FCGUIFLAGS += \

## Analysis targets (suffixed with .eva)
TARGETS = \
  libmodbus-random-client.eva \
  libmodbus-unit-server.eva \

### Each target <t>.eva needs a rule <t>.parse with source files as prerequisites

libmodbus-random-client.parse: \
  $(sort $(wildcard ../src/*.c)) \
  ../tests/random-test-client.c \
  $(shell $(FRAMAC)-config -print-share-path)/libc/string.c \

libmodbus-unit-server.parse: \
  $(sort $(wildcard ../src/*.c)) \
  ../tests/unit-test-server.c \
  $(shell $(FRAMAC)-config -print-share-path)/libc/netdb.c \
  $(shell $(FRAMAC)-config -print-share-path)/libc/string.c \

### Epilogue. Do not modify this block. #######################################
include $(shell $(FRAMAC)-config -print-lib-path)/analysis-scripts/epilogue.mk
###############################################################################

# optional, for OSCS
-include ../../Makefile.common
