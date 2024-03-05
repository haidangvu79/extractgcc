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
  -warn-special-float none \

## Eva-specific flags
EVAFLAGS    += \
  -eva-slevel 16 \
  -eva-domains equality \

## GUI-only flags
FCGUIFLAGS += \

## Analysis targets (suffixed with .eva)
TARGETS = icpc.eva

### Each target <t>.eva needs a rule <t>.parse with source files as prerequisites
icpc.parse: \
  ../src/impls.c \
  ../src/roco.c \
  ../src/sim.c \
  ../src/main.c \

### Epilogue. Do not modify this block. #######################################
include $(shell $(FRAMAC)-config -print-lib-path)/analysis-scripts/epilogue.mk
###############################################################################

# optional, for OSCS
-include ../../Makefile.common
