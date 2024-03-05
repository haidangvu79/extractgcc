# Makefile template for Frama-C/Eva case studies.
# For details and usage information, see the Frama-C User Manual.

### Prologue. Do not modify this block. #######################################
-include path.mk
FRAMAC ?= frama-c
include $(shell $(FRAMAC)-config -print-lib-path)/analysis-scripts/prologue.mk
###############################################################################

# Edit below as needed. Suggested flags are optional.

FRAMAC_SHARE = $(shell $(FRAMAC)-config -print-share-path)

MACHDEP = x86_32


## Preprocessing flags (for -cpp-extra-args)
CPPFLAGS    += \
  -include__fc_builtin.h \
  -D_POSIX_C_SOURCE=200809L \

## General flags
FCFLAGS     += \
  -add-symbolic-path=..:. \
  -main eva_main \
  -warn-special-float none \

## Eva-specific flags
EVAFLAGS    += \
  -eva-ilevel 16 \

## GUI-only flags
FCGUIFLAGS += \

TEST_SRCS := \
  $(sort $(wildcard ../*.c)) \
  $(FRAMAC_SHARE)/libc/string.c \
  $(FRAMAC_SHARE)/libc/netdb.c \
  fc_stubs.c \

## Analysis targets (suffixed with .eva)
TARGETS = hiredis-format.eva hiredis-misc.eva

### Each target <t>.eva needs a rule <t>.parse with source files as prerequisites
hiredis-format.parse: CPPFLAGS += -DEVA_TEST_FORMAT
hiredis-format.parse: $(TEST_SRCS)

hiredis-misc.parse: CPPFLAGS += -DEVA_TEST_MISC
hiredis-misc.parse: $(TEST_SRCS)

hiredis-tcp.parse: CPPFLAGS += -DEVA_TEST_TCP
hiredis-tcp.parse: $(TEST_SRCS)

hiredis-unix.parse: CPPFLAGS += -DEVA_TEST_UNIX
hiredis-unix.parse: $(TEST_SRCS)

hiredis-tcp-long.parse: CPPFLAGS += -DEVA_TEST_TCP -DEVA_TEST_BLOCKING_LONG
hiredis-tcp-long.parse: $(TEST_SRCS)

hiredis-unix-long.parse: CPPFLAGS += -DEVA_TEST_UNIX -DEVA_TEST_BLOCKING_LONG
hiredis-unix-long.parse: $(TEST_SRCS)

### Epilogue. Do not modify this block. #######################################
include $(shell $(FRAMAC)-config -print-lib-path)/analysis-scripts/epilogue.mk
###############################################################################

# optional, for OSCS
-include ../../Makefile.common
