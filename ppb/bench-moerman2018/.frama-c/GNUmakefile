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
  -I../common \

## General flags
FCFLAGS     += \
  -add-symbolic-path=..:. \
  -kernel-warn-key annot:missing-spec=abort \
  -kernel-warn-key typing:implicit-function-declaration=abort \

## Eva-specific flags
EVAFLAGS    += \
  -eva-warn-key builtins:missing-spec=abort \
  -eva-precision 3 \

## GUI-only flags
FCGUIFLAGS += \

# This bench has several targets, so we use Makefile functions to generate
# them. A few test cases are not run.

# exclude files with recursive functions, and those testing memory leaks
filter-out-substring = $(foreach v,$(2),$(if $(findstring $(1),$(v)),,$(v)))
SRCS:=$(sort $(call filter-out-substring,leak,\
               $(call filter-out-substring,recursion,\
                 $(wildcard ../base/*.c ../*/*/*.c))))

# [target] converts a file name into a suitable target name,
# removing the initial '../', the final '.c', and converting '/' into '_'.
target = $(subst /,_,$(patsubst %.c,%,$(1:../%=%)))

GOOD_TARGETS:=$(foreach s,$(SRCS),$(call target,$(s))_good.eva)
BAD_TARGETS:=$(foreach s,$(SRCS),$(call target,$(s))_bad.eva)
TARGETS:=$(GOOD_TARGETS) $(BAD_TARGETS)

define generate-parse-rules =
  $(call target,$(1))_good.parse: $(if $(findstring cross_file,$(1)),../common/common.c,) $(1)
  $(call target,$(1))_good.parse: CPPFLAGS+="-DNO_BUG"
  $(call target,$(1))_bad.parse: $(if $(findstring cross_file,$(1)),../common/common.c,) $(1)

  $(call target,$(1))_good.eva/eval.txt: $(call target,$(1))_good.eva evaluate_case.sh
	./evaluate_case.sh good $$</alarms.csv > $$</eval.txt
  $(call target,$(1))_bad.eva/eval.txt: $(call target,$(1))_bad.eva evaluate_case.sh
	./evaluate_case.sh bad $$</alarms.csv > $$</eval.txt
endef
$(foreach s,$(SRCS),$(eval $(call generate-parse-rules,$(s))))

eval_summary.txt: $(addsuffix /eval.txt, $(TARGETS))
	@echo "Updating summary: $(abspath $@)"
	@cat $^ > eval_summary.txt

evaluate: eval_summary.txt
.PHONY: eval_summary.txt

all: evaluate

### Epilogue. Do not modify this block. #######################################
include $(shell $(FRAMAC)-config -print-lib-path)/analysis-scripts/epilogue.mk
###############################################################################

# optional, for OSCS
-include ../../Makefile.common
