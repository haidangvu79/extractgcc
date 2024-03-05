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
CPPFLAGS    += -I ../code/harness -I ../code -I ../code/intel/linux \
               -DTRACE_HARNESS -DTRACE_TARGET

## General flags
FCFLAGS     += \
  -add-symbolic-path=..:. \
  -kernel-warn-key annot:missing-spec=abort \
  -kernel-warn-key typing:implicit-function-declaration=abort \

## Eva-specific flags
EVAFLAGS    += \
  -eva-warn-key builtins:missing-spec=abort \
  -eva-domains equality \
  -eva-auto-loop-unroll 180 \

# -eva-slevel 10 seems insufficient to remove the 5th alarm
# -eva-auto-loop-unroll is also necessary to avoid a 5th alarm

## GUI-only flags
FCGUIFLAGS += \

## Analysis targets (suffixed with .eva)
TARGETS = debie1.eva

### Each target <t>.eva needs a rule <t>.parse with source files as prerequisites
debie1.parse: \
  $(sort $(wildcard ../code/*.c)) \
  ../code/harness/harness.c \
  ../code/intel/linux/target.c \

### Epilogue. Do not modify this block. #######################################
include $(shell $(FRAMAC)-config -print-lib-path)/analysis-scripts/epilogue.mk
###############################################################################

# optional, for OSCS
-include ../../Makefile.common
