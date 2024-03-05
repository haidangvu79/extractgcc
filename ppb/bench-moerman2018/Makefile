# Based on .frama-c/GNUmakefile

SOURCES := $(sort $(wildcard base/*.c */*/*.c))

# [target] converts a file name into a suitable target name,
# removing the initial '../', the final '.c', and converting '/' into '_'.
target = $(subst /,_,$(patsubst %.c,%,$(1:%=%)))

GOOD_TARGETS := $(foreach s,$(SOURCES),$(call target,$(s))_good)
BAD_TARGETS := $(foreach s,$(SOURCES),$(call target,$(s))_bad)
TARGETS := $(GOOD_TARGETS) $(BAD_TARGETS)

all: $(TARGETS)

CPPFLAGS += -Icommon

define generate-build-rules =
  $(call target,$(1))_good: $(if $(findstring cross_file,$(1)),common/common.c,) $(1)
	$$(CC) $$(CPPFLAGS) $$(CFLAGS) -o $$@ $$^ $$(LDFLAGS)
  $(call target,$(1))_good: CPPFLAGS+="-DNO_BUG"
  $(call target,$(1))_bad: $(if $(findstring cross_file,$(1)),common/common.c,) $(1)
	$$(CC) $$(CPPFLAGS) $$(CFLAGS) -o $$@ $$^ $$(LDFLAGS)
endef
$(foreach s,$(SOURCES),$(eval $(call generate-build-rules,$(s))))

clean:
	rm -f $(TARGETS)

.PHONY: clean
