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
  -D_XOPEN_SOURCE=200112L \
  -DNB_TESTS=3 \

## General flags
FCFLAGS     += \
  -cpp-command "gcc -E -C -I.." \
  -cpp-frama-c-compliant \
  -add-symbolic-path=..:. \
  -kernel-warn-key typing:implicit-function-declaration=abort \
  -warn-special-float none \

## Eva-specific flags
EVAFLAGS    += \
  -eva-mlevel 1 \
  -eva-use-spec atoi,malloc,free,calloc,Transform,parse_include,SCH_AddTimeout \
  -eva-warn-key=alarm \
  -eva-malloc-functions malloc,realloc,Malloc,Malloc2,Realloc,Realloc2 \
  -eva-warn-key builtins:missing-spec=abort \
  -eva-warn-key malloc:weak \
  -eva-domains equality,gauges \
  -eva-domains-function symbolic-locations:prune_register \
  -eva-domains-function symbolic-locations:SST_DoNewRegression \
  -eva-domains-function symbolic-locations:SST_AccumulateSample \
  -eva-domains-function symbolic-locations:find_min_delay_sample \
  -eva-domains-function symbolic-locations:UTI_NormaliseTimespec \
  -eva-domains-function symbolic-locations:estimate_asymmetry \

## GUI-only flags
FCGUIFLAGS += \

TEST_COMMON_SRCS = \
  ../test/unit/test.c \
  $(shell $(FRAMAC)-config -print-share-path)/libc/string.c \
  $(shell $(FRAMAC)-config -print-share-path)/libc/stdlib.c \
  $(shell $(FRAMAC)-config -print-share-path)/libc/stdio.c \
  $(shell $(FRAMAC)-config -print-share-path)/libc/glob.c \
  $(shell $(FRAMAC)-config -print-share-path)/libc/netdb.c \
  ../addrfilt.c \
  ../array.c \
  ../clientlog.c \
  ../cmdparse.c \
  ../conf.c \
  ../hash_intmd5.c \
  ../keys.c \
  ../local.c \
  ../memory.c \
  ../nameserv.c \
  ../ntp_io.c \
  ../reference.c \
  ../regress.c \
  ../sched.c \
  ../smooth.c \
  ../sources.c \
  ../sourcestats.c \
  ../util.c \
  ../stubs.c \
  fc_stubs.c \

# logging.c voluntarily omitted, to skip analyzing logging functions

## Analysis targets (suffixed with .eva)
TARGETS = chrony-ntp-core.eva chrony-regress.eva

### Each target <t>.eva needs a rule <t>.parse with source files as prerequisites
chrony-ntp-core.parse: \
  $(TEST_COMMON_SRCS) \
  ../test/unit/ntp_core.c \

chrony-ntp-core.eva: EVAFLAGS += -main eva_main

# The following parsing rule reuses variable TEST_COMMON_SRCS to avoid
# having to manually list the sources. Note that the unit test version of
# regress.c redefines some functions from the other regress.c file, so
# we remove the latter from the list of sources.
chrony-regress.parse: \
  $(filter-out ../regress.c,$(TEST_COMMON_SRCS)) \
  ../test/unit/regress.c \

chrony-regress.eva: EVAFLAGS += -main eva_main -eva-domains octagon

### Epilogue. Do not modify this block. #######################################
include $(shell $(FRAMAC)-config -print-lib-path)/analysis-scripts/epilogue.mk
###############################################################################

# optional, for OSCS
-include ../../Makefile.common
