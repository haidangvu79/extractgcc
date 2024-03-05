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

## General flags
FCFLAGS     += \
  -add-symbolic-path=..:. \
  -kernel-warn-key annot:missing-spec=abort \
  -kernel-warn-key typing:implicit-function-declaration=abort \
  -main eva_main \

## Eva-specific flags
EVAFLAGS    += \
  -eva-warn-key builtins:missing-spec=abort \
  -eva-no-alloc-returns-null \

## GUI-only flags
FCGUIFLAGS += \

## Analysis targets (suffixed with .eva)
TARGETS = qlz-compress.eva qlz-decompress.eva qlz-stream-compress.eva qlz-stream-decompress.eva

### Each target <t>.eva needs a rule <t>.parse with source files as prerequisites
qlz-compress.parse: \
  ../compress_file.c \
  ../quicklz.c \
  fc_stubs.c \

qlz-decompress.parse: \
  ../decompress_file.c \
  ../quicklz.c \
  fc_stubs.c \

qlz-stream-compress.parse: CPPFLAGS += -DQLZ_COMPRESSION_LEVEL=3 -DQLZ_STREAMING_BUFFER=10000
qlz-stream-compress.parse: \
  ../stream_compress.c \
  ../quicklz.c \
  fc_stubs.c \

qlz-stream-decompress.parse: CPPFLAGS += -DQLZ_COMPRESSION_LEVEL=3 -DQLZ_STREAMING_BUFFER=10000
qlz-stream-decompress.parse: \
  ../stream_decompress.c \
  ../quicklz.c \
  fc_stubs.c \

### Epilogue. Do not modify this block. #######################################
include $(shell $(FRAMAC)-config -print-lib-path)/analysis-scripts/epilogue.mk
###############################################################################

# optional, for OSCS
-include ../../Makefile.common
