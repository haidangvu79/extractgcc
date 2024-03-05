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
  -I.. \

## General flags
FCFLAGS     += \
  -main eva_main \
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
  miniz-example1.eva \
  miniz-example2.eva \
  miniz-example3.eva \
  miniz-example4.eva \
  miniz-example5.eva \
  miniz-example6.eva \

### Each target <t>.eva needs a rule <t>.parse with source files as prerequisites
miniz-example1.parse: \
  stubs.c \
  ../examples/example1.c \
  ../miniz.c \
  ../miniz_tdef.c \
  ../miniz_tinfl.c \

miniz-example2.parse: \
  stubs.c \
  ../examples/example2.c \
  ../miniz.c \
  ../miniz_tdef.c \
  ../miniz_tinfl.c \
  ../miniz_zip.c \

miniz-example3.parse: \
  stubs.c \
  ../examples/example3.c \
  ../miniz.c \
  ../miniz_tdef.c \
  ../miniz_tinfl.c \

miniz-example4.parse: \
  stubs.c \
  ../examples/example4.c \
  ../miniz.c \
  ../miniz_tinfl.c \

miniz-example5.parse: \
  stubs.c \
  ../examples/example5.c \
  ../miniz.c \
  ../miniz_tdef.c \
  ../miniz_tinfl.c \

miniz-example6.parse: \
  stubs.c \
  ../examples/example6.c \
  ../miniz.c \
  ../miniz_tdef.c \

miniz-example6.parse: FCFLAGS += \
  -cpp-extra-args-per-file=../miniz.c:"-DMINIZ_NO_TIME -DMINIZ_NO_STDIO" \
  -cpp-extra-args-per-file=../miniz_tdef.c:"-DMINIZ_NO_TIME -DMINIZ_NO_STDIO" \

### Epilogue. Do not modify this block. #######################################
include $(shell $(FRAMAC)-config -print-lib-path)/analysis-scripts/epilogue.mk
###############################################################################

# optional, for OSCS
-include ../../Makefile.common
