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
  -CC

## General flags
FCFLAGS     += \
  -add-symbolic-path=..:. \
  -kernel-warn-key annot:missing-spec=abort \
  -kernel-warn-key typing:implicit-function-declaration=abort \
  -warn-left-shift-negative \
  -warn-right-shift-negative \
  -warn-signed-downcast \
  -warn-signed-overflow \
  -warn-unsigned-downcast \
  -warn-unsigned-overflow \

# Note: -eva-precision 5 does not terminate in 30 minutes

## Eva-specific flags
EVAFLAGS    += \
  -eva-warn-key builtins:missing-spec=abort \
  -eva-warn-undefined-pointer-comparison none \
  -eva-precision 2 \


## WP-specific flags
# Tested with these tools:
# - Why3 1.5.0
# - Alt-Ergo 2.4.2
WPFLAGS += \
  -wp-par 12 \
  -wp-timeout 15 \
  -wp-no-init-const \

## GUI-only flags
FCGUIFLAGS += \

## Analysis targets (suffixed with .eva)
TARGETS = x509-parser.eva

### Each target <t>.eva needs a rule <t>.parse with source files as prerequisites
x509-parser.parse: \
  ../src/x509-parser.c \

## We want WP to run after Eva, so we chain them by loading the result of the
## Eva analysis before running WP.
x509-parser.wp: PARSE_RESULT = x509-parser.eva

## The following E-ACSL target relies on some errors deliberately introduced
## in the code, and triggered at runtime. Note that, depending on your
## configuration, the execution of the non-instrumented code may terminate
## succesfully, without any indication that a buffer overflow took place.
eacsl: ../x509-parser.stack.exe ../x509-parser.heap.exe

EACSL_FLAGS = \
  -M \
  --rte=mem \
  -F "-no-annot" \
  -F "-rte-verbose 0 -variadic-verbose 0" \
  -c \
  -E -D__FC_EACSL__ \

EACSL_SCRIPT:=$(shell dirname $(shell which $(FRAMAC)))/e-acsl-gcc.sh

../x509-parser.stack.exe: ../src/x509-parser.c ../src/main.c
	$(EACSL_SCRIPT) $(EACSL_FLAGS) \
	-E -DEACSL_STACK_OVERFLOW \
	$^ -O $@ -o x509-parser.stack.frama.c

../x509-parser.heap.exe: ../src/x509-parser.c ../src/main.c
	$(EACSL_SCRIPT) $(EACSL_FLAGS) \
	-E -DEACSL_HEAP_OVERFLOW \
	$^ -O $@ -o x509-parser.stack.frama.c

### Epilogue. Do not modify this block. #######################################
include $(shell $(FRAMAC)-config -print-lib-path)/analysis-scripts/epilogue.mk
###############################################################################

# optional, for OSCS
-include ../../Makefile.common
