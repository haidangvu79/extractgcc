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
  -CC \
  -I.. \

# -CC is used to preserve loop unroll annotations from expanded macros

## General flags
FCFLAGS     += \
  -json-compilation-database .. \
  -add-symbolic-path=..:. \
  -kernel-warn-key annot:missing-spec=abort \
  -kernel-warn-key typing:implicit-function-declaration=abort \

# (Optional) Eva-specific flags
EVAFLAGS    += \
  -eva-subdivide-non-linear 16 \
  -eva-ilevel 13 \
  -eva-no-alloc-returns-null \
  -eva-use-spec $(call fc_list,$(USE_SPEC)) \
  -eva-slevel 2 \

USE_SPEC  += \
  my_set_session \
  my_get_session \
  aes_setkey_enc \
  aes_setkey_dec \
  aes_crypt_cbc \
  des3_crypt_ecb \
  des3_crypt_cbc \
  des_setkey \
  arc4_crypt \
  ssl_free \
  x509_free \
  x509parse_crt \
  x509parse_key \
  x509parse_verifycrl \
  hardclock \
  sha4_update \
  sha4_process \
  sha1_process \
  sha1_finish \
  aes_crypt_ecb \
  md5_process \
  ctr_drbg_random \
  dhm_check_range \
  dhm_make_params \
  mpi_free \
  mpi_exp_mod \
  mpi_fill_random \
  mpi_read_string \
  mpi_read_binary \
  mpi_msb \
  mpi_write_binary \
  mpi_cmp_mpi \
  mpi_cmp_abs \
  mpi_copy \
  mpi_sub_mpi \
  mpi_mod_mpi \
  mpi_mul_mpi \
  mpi_add_abs \
  mpi_sub_abs \
  camellia_crypt_cbc \
  camellia_feistel \
  sha4 \

## GUI-only flags
FCGUIFLAGS += \

## Analysis targets (suffixed with .eva)
TARGETS = polarssl-server.eva

### Each target <t>.eva needs a rule <t>.parse with source files as prerequisites
polarssl-server.parse: \
  fc_stubs.h \
  $(sort $(wildcard ../library/*.c)) \
  ../programs/ssl/ssl_server.c \

### Epilogue. Do not modify this block. #######################################
include $(shell $(FRAMAC)-config -print-lib-path)/analysis-scripts/epilogue.mk
###############################################################################

# optional, for OSCS
-include ../../Makefile.common
