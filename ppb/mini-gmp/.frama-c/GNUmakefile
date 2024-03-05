# Makefile template for Frama-C/Eva case studies.
# For details and usage information, see the Frama-C User Manual.

### Prologue. Do not modify this block. #######################################
-include path.mk
FRAMAC ?= frama-c
include $(shell $(FRAMAC)-config -print-lib-path)/analysis-scripts/prologue.mk
###############################################################################

# Edit below as needed. Suggested flags are optional.

MACHDEP = gcc_x86_32

## Preprocessing flags (for -cpp-extra-args)
CPPFLAGS    += \
  -std=c99 \
  -I .. \
  -D__gmp_asprintf=asprintf

# note: '-std=c99' is used to avoid issues with old GCCs (< 5) due to the
#       presence of inline attributes.

## General flags
FCFLAGS     += \
  -add-symbolic-path=..:. \
  -kernel-warn-key annot:missing-spec=abort \
  -kernel-warn-key typing:implicit-function-declaration=abort \
  -main testmain \

## Eva-specific flags
EVAFLAGS    += \
  -eva-warn-key builtins:missing-spec=abort \

## GUI-only flags
FCGUIFLAGS += \

## Analysis targets (suffixed with .eva)
TARGETS = mini-gmp.eva

### Each target <t>.eva needs a rule <t>.parse with source files as prerequisites
mini-gmp.parse: \
  $(shell $(FRAMAC)-config -print-share-path)/libc/stdio.c \
  ../tests/testutils.c \
  ../tests/t-add.c \
  ../tests/hex-random.c \
  ../tests/mini-random.c \
  fc_stubs.h \

### Epilogue. Do not modify this block. #######################################
include $(shell $(FRAMAC)-config -print-lib-path)/analysis-scripts/epilogue.mk
###############################################################################

# optional, for OSCS
-include ../../Makefile.common
