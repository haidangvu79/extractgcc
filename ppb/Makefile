.ONESHELL:
ROOT_DIR := $(dir $(realpath $(lastword $(MAKEFILE_LIST))))

help::
	@echo "*** PREPARATION TARGETS (first-time user)"
	@echo "- 'make submodules': initialize the git submodules"
	@echo "- 'make framac' (optional): build and install a local Frama-C"
	@echo "   (alternatively, you can use a Frama-C installed in the PATH)"
	@echo "   Note: this target always forces a rebuild, and"
	@echo "         supplies -j automatically"
	@echo ""
	@echo "*** EXECUTION TARGETS"
	@echo "- 'make all': run all analyses"
	@echo "   Note: if you change the Frama-C version, you need to add -B"
	@echo "         (targets are not marked as dependent on Frama-C itself)"
	@echo "- 'make clean': clean all analyses"
	@echo ""
	@echo "*** USAGE WITH FRAMA-C INSTALLED IN THE PATH"
	@echo "- delete 'path.mk' or comment its lines"
	@echo ""
	@echo "*** NON-FRAMA-C BUILD TARGETS"
	@echo "- 'make build': build each case study, using its own Makefile,"
	@echo "  CMake, Meson, etc. You can set BUILD_WRAPPER to a command"
	@echo "  which will wrap the calls to the build tool."
	@echo "  Note: this is highly system-dependent and requires several"
	@echo "  libraries and tools. This target is only provided for "
	@echo "  convenience, and cannot be relied upon for CI runs."

# Note: if the user runs `make framac` before `make submodules`, the latter
# will fail.
submodules:
	@git submodule init
	git submodule update
	if ! grep '^build/$$' .git/modules/frama-c/info/exclude >/dev/null; then
	  echo "build/" >> .git/modules/frama-c/info/exclude;
	  echo "git ignoring 'build' directory in frama-c submodule";
	fi

framac: frama-c/build/bin/frama-c

# frama-c cannot depend on .git/.../something because when it is used as
# a submodule, it does not have a `.git` directory.
# also, such dependency would prevent usage with FRAMAC=path/to/other/framac
frama-c/build/bin/frama-c:
	@echo "Compiling and (re)installing local Frama-C..."
	mkdir -p frama-c/build
	echo "*** cleaning previous builds..."
	$(MAKE) -C frama-c clean >/dev/null
	echo "*** running make..."
	$(MAKE) -C frama-c -j --quiet >/dev/null
	echo "*** running make install..."
	$(MAKE) -C frama-c install PREFIX=$(ROOT_DIR)/frama-c/build >/dev/null
	echo "Local Frama-C (re-)installed."

TARGETS=\
  2048 \
  basic-cwe-examples \
  bench-moerman2018 \
  c-testsuite \
  cerberus \
  chrony \
  debie1 \
  genann \
  gzip124 \
  hiredis \
  icpc \
  ioccc \
  itc-benchmarks \
  jsmn \
  kgflags \
  khash \
  kilo \
  libmodbus \
  libspng \
  libyaml \
  line-following-robot \
  microstrain \
  mini-gmp \
  miniz \
  monocypher \
  papabench \
  polarssl \
  qlz \
  safestringlib \
  semver \
  solitaire \
  stmr \
  tsvc \
  tweetnacl-usable \
  verisec \
  x509-parser \

help::
	@echo ""
	@echo "Known targets:"
	@echo "$(sort $(TARGETS))"

# A target for "fast" analyses, used to speed up testing
QUICK_TARGETS=$(filter-out polarssl gzip124 libmodbus monocypher chrony,$(TARGETS))

all: $(TARGETS)

summary:
	frama-c/share/analysis-scripts/summary.py

$(TARGETS):
	+$(MAKE) -C $@/.frama-c

quick: $(QUICK_TARGETS)

%.clean:
	$(MAKE) -C $*/.frama-c clean

clean: $(addsuffix .clean,$(TARGETS))

%.parse:
	$(MAKE) -C $*/.frama-c parse

parse: $(addsuffix .parse,$(TARGETS))

%.sarif:
	$(MAKE) -C $*/.frama-c sarif

sarif: $(addsuffix .sarif,$(TARGETS))

display-targets:
	@echo $(foreach target,$(TARGETS),\
	        $(addprefix $(target)/,\
	          $(shell $(MAKE) --quiet -C $(target)/.frama-c display-targets)))

%.eva: .FORCE
	$(MAKE) -C $(dir $@) $(notdir $@)

# For most case studies, 'make' is sufficient, but some of them require other
# commands (which are overridden below).
%.build:
	$(BUILD_WRAPPER) $(MAKE) -C $*

%.build.clean:
	$(MAKE) -C $* clean

build: $(addsuffix .build,$(TARGETS))

build-clean: $(addsuffix .build.clean,$(TARGETS))

cerberus.build:
	@echo "Some Cerberus tests are not compilable (by design)"

cerberus.build.clean:
	@echo "Cerberus: nothing to clean"

icpc.build:
	$(BUILD_WRAPPER) $(MAKE) -C icpc/src

icpc.build.clean:
	$(MAKE) -C icpc/src clean

.FORCE:

.PHONY: $(TARGETS) frama-c/build/bin/frama-c help
