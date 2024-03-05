# Comment the line below to use frama-c installed in the PATH,
# or replace it with the directory of another, locally-installed Frama-C.
FRAMAC_DIR=../../frama-c/build/bin
ifeq ($(wildcard $(FRAMAC_DIR)),)
# Frama-C not installed locally (or invalid FRAMAC_DIR); check if the latter
ifeq ($(shell command -v frama-c),)
$(error frama-c found neither in PATH nor in FRAMAC_DIR)
endif
else
# Note: when installed _locally_, we know that bin and lib have the same
#       parent directory.
export OCAMLPATH := $(FRAMAC_DIR)/../lib:$(OCAMLPATH)
FRAMAC=$(FRAMAC_DIR)/frama-c
FRAMAC_GUI=$(FRAMAC_DIR)/frama-c-gui
IVETTE=$(FRAMAC_DIR)/ivette -B $(FRAMAC)
endif
