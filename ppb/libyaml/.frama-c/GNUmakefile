# Makefile template for Frama-C/Eva case studies.
# For details and usage information, see the Frama-C User Manual.

### Prologue. Do not modify this block. #######################################
-include path.mk
FRAMAC ?= frama-c
include $(shell $(FRAMAC)-config -print-lib-path)/analysis-scripts/prologue.mk
###############################################################################

# Edit below as needed. Suggested flags are optional.

MACHDEP = x86_64

## Preprocessing flags (for -cpp-extra-args)
CPPFLAGS    += \
  -I../include \
  -DHAVE_CONFIG_H \
  -DYAML_DECLARE_STATIC \

## General flags
FCFLAGS     += \
  -add-symbolic-path=..:. \
  -kernel-warn-key annot:missing-spec=abort \
  -kernel-warn-key typing:implicit-function-declaration=abort \

## Eva-specific flags
EVAFLAGS    += \
  -eva-warn-key builtins:missing-spec=abort \

## GUI-only flags
FCGUIFLAGS += \

## Analysis targets (suffixed with .eva)
TARGETS = \
  test-reader.eva \
  test-version.eva \

# TODO: modify handling of dynamic memory allocation to speed up these tests
#  run-dumper.eva \
#  run-emitter.eva \
#  run-parser-test-suite.eva \
#  run-scanner.eva \

COMMON_SRCS=\
  ../src/api.c \
  ../src/dumper.c \
  ../src/emitter.c \
  ../src/loader.c \
  ../src/parser.c \
  ../src/reader.c \
  ../src/scanner.c \
  ../src/writer.c \

### Each target <t>.eva needs a rule <t>.parse with source files as prerequisites
run-dumper.parse: \
  $(COMMON_SRCS) \
  fc_stubs.c \
  ../tests/run-dumper.c \

run-emitter.parse: \
  $(COMMON_SRCS) \
  fc_stubs.c \
  ../tests/run-emitter.c \

run-emitter-test-suite.parse: \
  $(COMMON_SRCS) \
  fc_stubs.c \
  ../tests/run-emitter-test-suite.c \

run-parser.parse: \
  $(COMMON_SRCS) \
  fc_stubs.c \
  ../tests/run-parser.c \

run-parser-test-suite.parse: \
  $(COMMON_SRCS) \
  fc_stubs.c \
  ../tests/run-parser-test-suite.c \

run-scanner.parse: \
  $(COMMON_SRCS) \
  fc_stubs.c \
  ../tests/run-scanner.c \

run-*.parse: FCFLAGS +=  -main eva_main

test-reader.parse: \
  $(COMMON_SRCS) \
  ../tests/test-reader.c \

test-version.parse: \
  $(COMMON_SRCS) \
  ../tests/test-version.c \

### Epilogue. Do not modify this block. #######################################
include $(shell $(FRAMAC)-config -print-lib-path)/analysis-scripts/epilogue.mk
###############################################################################

# optional, for OSCS
-include ../../Makefile.common
