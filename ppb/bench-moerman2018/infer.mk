INFER = infer run

CPPFLAGS    += \
  -Icommon \

# excludes files with recursive functions
filter-out-substring = $(foreach v,$(2),$(if $(findstring $(1),$(v)),,$(v)))
SRCS:=$(sort $(call filter-out-substring,leak,$(call filter-out-substring,recursion,$(wildcard base/*.c */*/*.c))))

GOOD_TARGETS:=$(foreach s,$(SRCS),$(subst /,_,$(s:%.c=%))_good.infer)
BAD_TARGETS:=$(foreach s,$(SRCS),$(subst /,_,$(s:%.c=%))_bad.infer)
TARGETS:=$(GOOD_TARGETS) $(BAD_TARGETS)

define generate-infer-rules =
  $(subst /,_,$(1:%.c=%))_good.infer: $(if $(findstring cross_file,$(1)),common/common.c,) $(1)
	$(INFER) -o $$@ -- clang -DNO_BUG $(CPPFLAGS) $$^

  $(subst /,_,$(1:%.c=%))_bad.infer: $(if $(findstring cross_file,$(1)),common/common.c,) $(1)
	$(INFER) -o $$@ -- clang $(CPPFLAGS) $$^

  $(subst /,_,$(1:%.c=%))_good.infer/eval.txt: $(subst /,_,$(1:%.c=%))_good.infer infer_evaluate_case.sh
	./infer_evaluate_case.sh good $$</bugs.txt > $$</eval.txt

  $(subst /,_,$(1:%.c=%))_bad.infer/eval.txt: $(subst /,_,$(1:%.c=%))_bad.infer infer_evaluate_case.sh
	./infer_evaluate_case.sh bad $$</bugs.txt > $$</eval.txt
endef

$(foreach s,$(SRCS),$(eval $(call generate-infer-rules,$(s))))

infer_eval_sumup.txt: $(addsuffix /eval.txt, $(TARGETS))
	cat $^ > infer_eval_sumup.txt

evaluate: infer_eval_sumup.txt
.PHONY: infer_eval_sumup.txt

good: $(GOOD_TARGETS)

bad: $(BAD_TARGETS)

all: good bad

clean:
	@rm -rf *_good.infer
	@rm -rf *_bad.infer
	@rm -rf a.out
	@rm -rf infer-out
