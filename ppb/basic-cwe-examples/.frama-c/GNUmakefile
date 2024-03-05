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

## General flags
FCFLAGS     += \
  -add-symbolic-path=..:. \
  -kernel-warn-key annot:missing-spec=abort \
  -kernel-warn-key typing:implicit-function-declaration=abort \

## Eva-specific flags
EVAFLAGS    += \
  -eva-warn-key builtins:missing-spec=abort \

## Analysis targets (suffixed with .eva)
IMPRECISE_TARGETS = cwe20.eva cwe20-2.eva cwe119.eva cwe190.eva cwe416.eva cwe588.eva cwe761.eva cwe787.eva

PRECISE_TARGETS = $(subst .eva,-precise.eva,$(IMPRECISE_TARGETS))

OTHER_TARGETS = cwe190-unsigned.eva

TARGETS = $(IMPRECISE_TARGETS) $(PRECISE_TARGETS) $(OTHER_TARGETS)

### Each target <t>.eva needs a rule <t>.parse with source files as prerequisites
cwe20.parse:  ../cwe20.c
cwe20-2.parse:  ../cwe20-2.c
cwe119.parse: ../cwe119.c
cwe190.parse: ../cwe190.c
cwe416.parse: ../cwe416.c
cwe588.parse: ../cwe588.c
cwe761.parse: ../cwe761.c
cwe787.parse: ../cwe787.c

cwe20-precise.parse:  ../cwe20.c
cwe20-2-precise.parse:  ../cwe20-2.c
cwe119-precise.parse: ../cwe119.c
cwe190-precise.parse: ../cwe190.c
cwe416-precise.parse: ../cwe416.c
cwe588-precise.parse: ../cwe588.c
cwe761-precise.parse: ../cwe761.c
cwe787-precise.parse: ../cwe787.c

cwe761-precise.parse: CPPFLAGS+=-DFC_EVA_PRECISE

cwe190-unsigned.parse: ../cwe190-unsigned.c

cwe20-precise.eva:   EVAFLAGS +=
cwe20-2-precise.eva: EVAFLAGS += -eva-precision 5
cwe119-precise.eva:  EVAFLAGS +=
cwe190-precise.eva:  EVAFLAGS +=
cwe416-precise.eva:  EVAFLAGS +=
cwe588-precise.eva:  EVAFLAGS +=
cwe761-precise.eva:  EVAFLAGS += -eva-precision 1
cwe787-precise.eva:  EVAFLAGS += -eva-precision 2
cwe190-unsigned.eva:  EVAFLAGS += -warn-unsigned-overflow

### Epilogue. Do not modify this block. #######################################
include $(shell $(FRAMAC)-config -print-lib-path)/analysis-scripts/epilogue.mk
###############################################################################

# optional, for OSCS
-include ../../Makefile.common
