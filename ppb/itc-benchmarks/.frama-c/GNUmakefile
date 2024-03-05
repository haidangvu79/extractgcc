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
  -I../include \
  -includefc_stubs.h \

## General flags
FCFLAGS     += \
  -add-symbolic-path=..:. \
  -kernel-warn-key annot:missing-spec=abort \
  -kernel-warn-key typing:implicit-function-declaration=abort \
  -warn-signed-downcast \
  -warn-unsigned-downcast \
  -warn-unsigned-overflow \

## Eva-specific flags
EVAFLAGS    += \
  -eva-warn-key builtins:missing-spec=abort \
  -eva-no-alloc-returns-null \
  -eva-mlevel 10 \
  -main eva_main \
  -eva-precision 3 \
  -eva-builtin titcb_pow:Frama_C_pow \

# -eva-precision 3 reduces 1 unknown w.r.t. -eva-precision 2

## GUI-only flags
FCGUIFLAGS += \

## Analysis targets (suffixed with .eva)
TARGETS = 01_w_Defects.eva 02_wo_Defects.eva

### Each target <t>.eva needs a rule <t>.parse with source files as prerequisites
# NOTE: string.c is required due to the usage of strdup() in some tests,
# and also to avoid loss of precision when strcpy() is used.
# Both are related to tests in st_underrun.c

SUBDIR_SRCS=\
  main.c \
  bit_shift.c \
  buffer_overrun_dynamic.c \
  buffer_underrun_dynamic.c \
  data_lost.c \
  data_overflow.c \
  data_underflow.c \
  double_free.c \
  endless_loop.c \
  free_nondynamic_allocated_memory.c \
  invalid_memory_access.c \
  littlemem_st.c \
  memory_allocation_failure.c \
  not_return.c \
  null_pointer.c \
  overrun_st.c \
  pow_related_errors.c \
  ptr_subtraction.c \
  return_local.c \
  sign_conv.c \
  st_underrun.c \
  underrun_st.c \
  uninit_memory_access.c \
  uninit_pointer.c \
  uninit_var.c \
  zero_division.c \

01_w_Defects.parse: \
  fc_stubs.c \
  $(shell $(FRAMAC)-config -print-share-path)/libc/stdio.c \
  $(shell $(FRAMAC)-config -print-share-path)/libc/string.c \
  $(foreach file,$(SUBDIR_SRCS),$(wildcard ../01_w_Defects/$(file))) \

02_wo_Defects.parse: \
  fc_stubs.c \
  $(shell $(FRAMAC)-config -print-share-path)/libc/stdio.c \
  $(shell $(FRAMAC)-config -print-share-path)/libc/string.c \
  $(foreach file,$(SUBDIR_SRCS),$(wildcard ../02_wo_Defects/$(file))) \

### Epilogue. Do not modify this block. #######################################
include $(shell $(FRAMAC)-config -print-lib-path)/analysis-scripts/epilogue.mk
###############################################################################

# optional, for OSCS
-include ../../Makefile.common
