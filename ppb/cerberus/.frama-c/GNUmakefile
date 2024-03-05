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
  -includefc_stubs.h

## General flags
FCFLAGS     += \
  -add-symbolic-path=..:. \
  -kernel-warn-key annot:missing-spec=abort \
  -kernel-warn-key typing:implicit-function-declaration=abort \
  -no-autoload-plugins -load-module eva,from,inout,metrics,nonterm,report,scope,variadic \

## Eva-specific flags
EVAFLAGS    += \
  -eva-warn-key builtins:missing-spec=abort \
  -eva-slevel 6000 \

## GUI-only flags
FCGUIFLAGS += \

## Analysis targets (suffixed with .eva)
TARGETS := \
besson_blazy_wilke_6_2.eva \
besson_blazy_wilke_bitfields_1.eva \
besson_blazy_wilke_bitfields_1u.eva \
besson_blazy_wilkie_Fig_1_adapted.eva \
besson_blazy_wilkie_Fig_1.eva \
besson_blazy_wilkie_Fig_2.eva \
cast_struct_and_first_member_1.eva \
cast_struct_inter_member_1.eva \
cast_struct_isomorphic.eva \
cast_struct_same_prefix.eva \
cast_union_and_member_1.eva \
cheri_01_deconst.eva \
cheri_02_container.eva \
cheri_03_ii.eva \
cheri_03_ii_char.eva \
cheri_04a_int_uintptr_t.eva \
cheri_04b_int_unsigned_long.eva \
cheri_05_ia.eva \
cheri_06_mask.eva \
cheri_07_wide.eva \
cheri_08_last_word.eva \
compcertMMv2-1.eva \
compcertMMv2-2.eva \
compcertMMv2-3.eva \
compcertMMv2-4.eva \
compcertMMv2-5.eva \
compcertTSO-1.eva \
compcertTSO-2.eva \
effective_type_10.eva \
effective_type_1.eva \
effective_type_2.eva \
effective_type_5.eva \
effective_type_6.eva \
effective_type_7.eva \
effective_type_8.eva \
effective_type_9.eva \
frama-c-2013-03-13-2.eva \
frama-c-2013-03-13-3.eva \
frama-c-2013-03-13-3-uc.eva \
khmgzv-1.eva \
khmgzv-2.eva \
klw-itp14-1.eva \
klw-itp14-2.eva \
krebbers_biener_1.eva \
null_pointer_1.eva \
null_pointer_2.eva \
null_pointer_3.eva \
null_pointer_4.eva \
padding_10.eva \
padding_struct_copy_1.eva \
padding_struct_copy_2.eva \
padding_struct_copy_3.eva \
padding_struct_copy_of_representation_bytes.eva \
padding_struct_members_copy.eva \
padding_subunion_1.eva \
padding_subunion_2.eva \
padding_unspecified_value_1.eva \
padding_unspecified_value_2.eva \
padding_unspecified_value_3.eva \
padding_unspecified_value_4.eva \
padding_unspecified_value_5.eva \
padding_unspecified_value_6.eva \
padding_unspecified_value_7.eva \
padding_unspecified_value_8.eva \
pointer_add_wrap_1.eva \
pointer_add_wrap_2.eva \
pointer_arith_algebraic_properties_1_global.eva \
pointer_arith_algebraic_properties_2_auto.eva \
pointer_arith_algebraic_properties_2_global.eva \
pointer_arith_algebraic_properties_3_auto.eva \
pointer_arith_algebraic_properties_3_global.eva \
pointer_comparison_7b.eva \
pointer_comparison_7c.eva \
pointer_comparison_eq_1_auto.eva \
pointer_comparison_eq_1_global.eva \
pointer_comparison_eq_2_auto.eva \
pointer_comparison_eq_2_global.eva \
pointer_comparison_eq_zombie_1.eva \
pointer_comparison_eq_zombie_2.eva \
pointer_comparison_rel_1_auto.eva \
pointer_comparison_rel_1_global.eva \
pointer_comparison_rel_different_type_members.eva \
pointer_comparison_rel_substruct.eva \
pointer_copy_memcpy.eva \
pointer_copy_user_ctrlflow_bitwise.eva \
pointer_copy_user_ctrlflow_bytewise_abbrev.eva \
pointer_copy_user_ctrlflow_bytewise.eva \
pointer_copy_user_dataflow_direct_bitwise.eva \
pointer_copy_user_dataflow_direct_bytewise.eva \
pointer_copy_user_dataflow_indirect_bytewise.eva \
pointer_from_concrete_address_1.eva \
pointer_from_concrete_address_2.eva \
pointer_offset_constant_8_malloc.eva \
pointer_offset_from_subtraction_1_auto.eva \
pointer_offset_from_subtraction_1_global.eva \
pointer_offset_from_subtraction_1_malloc.eva \
pointer_offset_from_subtraction_2_auto.eva \
pointer_offset_from_subtraction_2_global.eva \
pointer_offset_xor_auto.eva \
pointer_offset_xor_global.eva \
pointer_stability_1.eva \
pointer_stability_2.eva \
provenance_basic_auto_xy.eva \
provenance_basic_auto_yx.eva \
provenance_basic_global_xy.eva \
provenance_basic_global_yx.eva \
provenance_basic_malloc_offset+12.eva \
provenance_basic_malloc_offset+2.eva \
provenance_basic_malloc_offset-4.eva \
provenance_basic_malloc_offset+4.eva \
provenance_basic_malloc_offset+8.eva \
provenance_basic_mixed_auto.eva \
provenance_basic_mixed_auto_offset-4.eva \
provenance_basic_mixed_auto_offset+4.eva \
provenance_basic_mixed_auto_offset-64.eva \
provenance_basic_mixed_global_offset-4.eva \
provenance_basic_mixed_global_offset+4.eva \
provenance_basic_mixed_global_offset-64.eva \
provenance_basic_using_intptr_t_auto_xy.eva \
provenance_basic_using_intptr_t_auto_yx.eva \
provenance_basic_using_intptr_t_auto_yx_offset-16.eva \
provenance_basic_using_intptr_t_global_xy.eva \
provenance_basic_using_intptr_t_global_xy_offset64.eva \
provenance_basic_using_intptr_t_global_yx.eva \
provenance_basic_using_intptr_t_malloc_offset_-16.eva \
provenance_basic_using_intptr_t_malloc_offset_8.eva \
provenance_equality_auto_cu_yx_a.eva \
provenance_equality_auto_cu_yx_b.eva \
provenance_equality_auto_fn_yx.eva \
provenance_equality_auto_yx.eva \
provenance_equality_global_cu_xy_a.eva \
provenance_equality_global_cu_xy_b.eva \
provenance_equality_global_cu_yx_a.eva \
provenance_equality_global_cu_yx_b.eva \
provenance_equality_global_fn_xy.eva \
provenance_equality_global_fn_yx.eva \
provenance_equality_global_xy.eva \
provenance_equality_global_yx.eva \
provenance_equality_uintptr_t_global_xy.eva \
provenance_equality_uintptr_t_global_yx.eva \
provenance_multiple_1_global.eva \
provenance_multiple_2_global.eva \
provenance_multiple_3_global_yx.eva \
provenance_multiple_4_global_yx.eva \
provenance_multiple_5_auto.eva \
provenance_multiple_5_global.eva \
provenance_roundtrip_via_intptr_t.eva \
provenance_roundtrip_via_unsigned_long.eva \
provenance_tag_bits_via_uintptr_t_1.eva \
provenance_tag_bits_via_uintptr_t_1_no_assert.eva \
provenance_union_punning_1_global.eva \
provenance_union_punning_2_auto_xy.eva \
provenance_union_punning_2_auto_yx.eva \
provenance_union_punning_2_global_xy.eva \
provenance_union_punning_2_global_yx.eva \
provenance_via_io_auto.eva \
provenance_via_io_bytewise_global.eva \
provenance_via_io_global.eva \
provenance_via_io_percentp_global.eva \
provenance_via_io_uintptr_t_global.eva \
read_union_same_prefix_visible.eva \
read_via_invalid_1.eva \
signalling_nan_1.eva \
struct_initialise_members.eva \
struct_inter_submember_1.eva \
tkn-1.eva \
tkn-2.eva \
tkn-3.eva \
tkn-3-commented.eva \
trap_representation_1.eva \
trap_representation_2.eva \
trap_representation_3.eva \
ubc_addr_null_1.eva \
union_punning_gcc_1.eva \
union_punning_gcc_2.eva \
union_punning_gcc_3.eva \
unspecified_value_control_flow_choice.eva \
unspecified_value_daemonic_1.eva \
unspecified_value_library_call_argument.eva \
unspecified_value_representation_bytes_1.eva \
unspecified_value_representation_bytes_2.eva \
unspecified_value_representation_bytes_3.eva \
unspecified_value_representation_bytes_4.eva \
unspecified_value_stability.eva \
unspecified_value_strictness_and_1.eva \
unspecified_value_strictness_int.eva \
unspecified_value_strictness_mod_1.eva \
unspecified_value_strictness_mod_2.eva \
unspecified_value_strictness_unsigned_char.eva \
unspecified_value_struct_copy.eva \
unspecified_value_union_1.eva \
write_union_same_prefix_visible.eva \

#TODO: support stdalign.h and _Alignas for the following targets:
#TARGETS+=effective_type_3 effective_type_4

# Syntactically invalid and non-obvious to fix
#use_struct_isomorphic.parse: use_struct_isomorphic.c

# Redefines memcpy
# compcertMMv2-6.eva

### Each target <t>.eva needs a rule <t>.parse with source files as prerequisites
besson_blazy_wilke_6_2.parse: ../besson_blazy_wilke_6_2.c
besson_blazy_wilke_bitfields_1.parse: ../besson_blazy_wilke_bitfields_1.c
besson_blazy_wilke_bitfields_1u.parse: ../besson_blazy_wilke_bitfields_1u.c
besson_blazy_wilkie_Fig_1_adapted.parse: ../besson_blazy_wilkie_Fig_1_adapted.c
besson_blazy_wilkie_Fig_1.parse: ../besson_blazy_wilkie_Fig_1.c
besson_blazy_wilkie_Fig_2.parse: ../besson_blazy_wilkie_Fig_2.c
cast_struct_and_first_member_1.parse: ../cast_struct_and_first_member_1.c
cast_struct_inter_member_1.parse: ../cast_struct_inter_member_1.c
cast_struct_isomorphic.parse: ../cast_struct_isomorphic.c
cast_struct_same_prefix.parse: ../cast_struct_same_prefix.c
cast_union_and_member_1.parse: ../cast_union_and_member_1.c
cheri_01_deconst.parse: ../cheri_01_deconst.c
cheri_02_container.parse: ../cheri_02_container.c
cheri_03_ii.parse: ../cheri_03_ii.c
cheri_03_ii_char.parse: ../cheri_03_ii_char.c
cheri_04a_int_uintptr_t.parse: ../cheri_04a_int_uintptr_t.c
cheri_04b_int_unsigned_long.parse: ../cheri_04b_int_unsigned_long.c
cheri_05_ia.parse: ../cheri_05_ia.c
cheri_06_mask.parse: ../cheri_06_mask.c
cheri_07_wide.parse: ../cheri_07_wide.c
cheri_08_last_word.parse: ../cheri_08_last_word.c
compcertMMv2-1.parse: ../compcertMMv2-1.c
compcertMMv2-2.parse: ../compcertMMv2-2.c
compcertMMv2-3.parse: ../compcertMMv2-3.c
compcertMMv2-4.parse: ../compcertMMv2-4.c
compcertMMv2-5.parse: ../compcertMMv2-5.c
compcertTSO-1.parse: ../compcertTSO-1.c
compcertTSO-2.parse: ../compcertTSO-2.c
effective_type_10.parse: ../effective_type_10.c
effective_type_1.parse: ../effective_type_1.c
effective_type_2.parse: ../effective_type_2.c
effective_type_3.parse: ../effective_type_3.c
effective_type_4.parse: ../effective_type_4.c
effective_type_5.parse: ../effective_type_5.c
effective_type_6.parse: ../effective_type_6.c
effective_type_7.parse: ../effective_type_7.c
effective_type_8.parse: ../effective_type_8.c
effective_type_9.parse: ../effective_type_9.c
frama-c-2013-03-13-2.parse: ../frama-c-2013-03-13-2.c
frama-c-2013-03-13-3.parse: ../frama-c-2013-03-13-3.c
frama-c-2013-03-13-3-uc.parse: ../frama-c-2013-03-13-3-uc.c
khmgzv-1.parse: ../khmgzv-1.c
khmgzv-2.parse: ../khmgzv-2.c
klw-itp14-1.parse: ../klw-itp14-1.c
klw-itp14-2.parse: ../klw-itp14-2.c
krebbers_biener_1.parse: ../krebbers_biener_1.c
null_pointer_1.parse: ../null_pointer_1.c
null_pointer_2.parse: ../null_pointer_2.c
null_pointer_3.parse: ../null_pointer_3.c
null_pointer_4.parse: ../null_pointer_4.c
padding_10.parse: ../padding_10.c
padding_struct_copy_1.parse: ../padding_struct_copy_1.c
padding_struct_copy_2.parse: ../padding_struct_copy_2.c
padding_struct_copy_3.parse: ../padding_struct_copy_3.c
padding_struct_copy_of_representation_bytes.parse: ../padding_struct_copy_of_representation_bytes.c
padding_struct_members_copy.parse: ../padding_struct_members_copy.c
padding_subunion_1.parse: ../padding_subunion_1.c
padding_subunion_2.parse: ../padding_subunion_2.c
padding_unspecified_value_1.parse: ../padding_unspecified_value_1.c
padding_unspecified_value_2.parse: ../padding_unspecified_value_2.c
padding_unspecified_value_3.parse: ../padding_unspecified_value_3.c
padding_unspecified_value_4.parse: ../padding_unspecified_value_4.c
padding_unspecified_value_5.parse: ../padding_unspecified_value_5.c
padding_unspecified_value_6.parse: ../padding_unspecified_value_6.c
padding_unspecified_value_7.parse: ../padding_unspecified_value_7.c
padding_unspecified_value_8.parse: ../padding_unspecified_value_8.c
pointer_add_wrap_1.parse: ../pointer_add_wrap_1.c
pointer_add_wrap_2.parse: ../pointer_add_wrap_2.c
pointer_arith_algebraic_properties_1_global.parse: ../pointer_arith_algebraic_properties_1_global.c
pointer_arith_algebraic_properties_2_auto.parse: ../pointer_arith_algebraic_properties_2_auto.c
pointer_arith_algebraic_properties_2_global.parse: ../pointer_arith_algebraic_properties_2_global.c
pointer_arith_algebraic_properties_3_auto.parse: ../pointer_arith_algebraic_properties_3_auto.c
pointer_arith_algebraic_properties_3_global.parse: ../pointer_arith_algebraic_properties_3_global.c
pointer_comparison_7b.parse: ../pointer_comparison_7b.c
pointer_comparison_7c.parse: ../pointer_comparison_7c.c
pointer_comparison_eq_1_auto.parse: ../pointer_comparison_eq_1_auto.c
pointer_comparison_eq_1_global.parse: ../pointer_comparison_eq_1_global.c
pointer_comparison_eq_2_auto.parse: ../pointer_comparison_eq_2_auto.c
pointer_comparison_eq_2_global.parse: ../pointer_comparison_eq_2_global.c
pointer_comparison_eq_zombie_1.parse: ../pointer_comparison_eq_zombie_1.c
pointer_comparison_eq_zombie_2.parse: ../pointer_comparison_eq_zombie_2.c
pointer_comparison_rel_1_auto.parse: ../pointer_comparison_rel_1_auto.c
pointer_comparison_rel_1_global.parse: ../pointer_comparison_rel_1_global.c
pointer_comparison_rel_different_type_members.parse: ../pointer_comparison_rel_different_type_members.c
pointer_comparison_rel_substruct.parse: ../pointer_comparison_rel_substruct.c
pointer_copy_memcpy.parse: ../pointer_copy_memcpy.c
pointer_copy_user_ctrlflow_bitwise.parse: ../pointer_copy_user_ctrlflow_bitwise.c
pointer_copy_user_ctrlflow_bytewise_abbrev.parse: ../pointer_copy_user_ctrlflow_bytewise_abbrev.c
pointer_copy_user_ctrlflow_bytewise.parse: ../pointer_copy_user_ctrlflow_bytewise.c
pointer_copy_user_dataflow_direct_bitwise.parse: ../pointer_copy_user_dataflow_direct_bitwise.c
pointer_copy_user_dataflow_direct_bytewise.parse: ../pointer_copy_user_dataflow_direct_bytewise.c
pointer_copy_user_dataflow_indirect_bytewise.parse: ../pointer_copy_user_dataflow_indirect_bytewise.c
pointer_from_concrete_address_1.parse: ../pointer_from_concrete_address_1.c
pointer_from_concrete_address_2.parse: ../pointer_from_concrete_address_2.c
pointer_offset_constant_8_malloc.parse: ../pointer_offset_constant_8_malloc.c
pointer_offset_from_subtraction_1_auto.parse: ../pointer_offset_from_subtraction_1_auto.c
pointer_offset_from_subtraction_1_global.parse: ../pointer_offset_from_subtraction_1_global.c
pointer_offset_from_subtraction_1_malloc.parse: ../pointer_offset_from_subtraction_1_malloc.c
pointer_offset_from_subtraction_2_auto.parse: ../pointer_offset_from_subtraction_2_auto.c
pointer_offset_from_subtraction_2_global.parse: ../pointer_offset_from_subtraction_2_global.c
pointer_offset_xor_auto.parse: ../pointer_offset_xor_auto.c
pointer_offset_xor_global.parse: ../pointer_offset_xor_global.c
pointer_stability_1.parse: ../pointer_stability_1.c
pointer_stability_2.parse: ../pointer_stability_2.c
provenance_basic_auto_xy.parse: ../provenance_basic_auto_xy.c
provenance_basic_auto_yx.parse: ../provenance_basic_auto_yx.c
provenance_basic_global_xy.parse: ../provenance_basic_global_xy.c
provenance_basic_global_yx.parse: ../provenance_basic_global_yx.c
provenance_basic_malloc_offset+12.parse: ../provenance_basic_malloc_offset+12.c
provenance_basic_malloc_offset+2.parse: ../provenance_basic_malloc_offset+2.c
provenance_basic_malloc_offset-4.parse: ../provenance_basic_malloc_offset-4.c
provenance_basic_malloc_offset+4.parse: ../provenance_basic_malloc_offset+4.c
provenance_basic_malloc_offset+8.parse: ../provenance_basic_malloc_offset+8.c
provenance_basic_mixed_auto.parse: ../provenance_basic_mixed_auto.c
provenance_basic_mixed_auto_offset-4.parse: ../provenance_basic_mixed_auto_offset-4.c
provenance_basic_mixed_auto_offset+4.parse: ../provenance_basic_mixed_auto_offset+4.c
provenance_basic_mixed_auto_offset-64.parse: ../provenance_basic_mixed_auto_offset-64.c
provenance_basic_mixed_global_offset-4.parse: ../provenance_basic_mixed_global_offset-4.c
provenance_basic_mixed_global_offset+4.parse: ../provenance_basic_mixed_global_offset+4.c
provenance_basic_mixed_global_offset-64.parse: ../provenance_basic_mixed_global_offset-64.c
provenance_basic_using_intptr_t_auto_xy.parse: ../provenance_basic_using_intptr_t_auto_xy.c
provenance_basic_using_intptr_t_auto_yx.parse: ../provenance_basic_using_intptr_t_auto_yx.c
provenance_basic_using_intptr_t_auto_yx_offset-16.parse: ../provenance_basic_using_intptr_t_auto_yx_offset-16.c
provenance_basic_using_intptr_t_global_xy.parse: ../provenance_basic_using_intptr_t_global_xy.c
provenance_basic_using_intptr_t_global_xy_offset64.parse: ../provenance_basic_using_intptr_t_global_xy_offset64.c
provenance_basic_using_intptr_t_global_yx.parse: ../provenance_basic_using_intptr_t_global_yx.c
provenance_basic_using_intptr_t_malloc_offset_-16.parse: ../provenance_basic_using_intptr_t_malloc_offset_-16.c
provenance_basic_using_intptr_t_malloc_offset_8.parse: ../provenance_basic_using_intptr_t_malloc_offset_8.c
provenance_equality_auto_cu_yx_a.parse: ../provenance_equality_auto_cu_yx_a.c
provenance_equality_auto_cu_yx_b.parse: ../provenance_equality_auto_cu_yx_b.c
provenance_equality_auto_fn_yx.parse: ../provenance_equality_auto_fn_yx.c
provenance_equality_auto_yx.parse: ../provenance_equality_auto_yx.c
provenance_equality_global_cu_xy_a.parse: ../provenance_equality_global_cu_xy_a.c
provenance_equality_global_cu_xy_b.parse: ../provenance_equality_global_cu_xy_b.c
provenance_equality_global_cu_yx_a.parse: ../provenance_equality_global_cu_yx_a.c
provenance_equality_global_cu_yx_b.parse: ../provenance_equality_global_cu_yx_b.c
provenance_equality_global_fn_xy.parse: ../provenance_equality_global_fn_xy.c
provenance_equality_global_fn_yx.parse: ../provenance_equality_global_fn_yx.c
provenance_equality_global_xy.parse: ../provenance_equality_global_xy.c
provenance_equality_global_yx.parse: ../provenance_equality_global_yx.c
provenance_equality_uintptr_t_global_xy.parse: ../provenance_equality_uintptr_t_global_xy.c
provenance_equality_uintptr_t_global_yx.parse: ../provenance_equality_uintptr_t_global_yx.c
provenance_multiple_1_global.parse: ../provenance_multiple_1_global.c
provenance_multiple_2_global.parse: ../provenance_multiple_2_global.c
provenance_multiple_3_global_yx.parse: ../provenance_multiple_3_global_yx.c
provenance_multiple_4_global_yx.parse: ../provenance_multiple_4_global_yx.c
provenance_multiple_5_auto.parse: ../provenance_multiple_5_auto.c
provenance_multiple_5_global.parse: ../provenance_multiple_5_global.c
provenance_roundtrip_via_intptr_t.parse: ../provenance_roundtrip_via_intptr_t.c
provenance_roundtrip_via_unsigned_long.parse: ../provenance_roundtrip_via_unsigned_long.c
provenance_tag_bits_via_uintptr_t_1.parse: ../provenance_tag_bits_via_uintptr_t_1.c
provenance_tag_bits_via_uintptr_t_1_no_assert.parse: ../provenance_tag_bits_via_uintptr_t_1_no_assert.c
provenance_union_punning_1_global.parse: ../provenance_union_punning_1_global.c
provenance_union_punning_2_auto_xy.parse: ../provenance_union_punning_2_auto_xy.c
provenance_union_punning_2_auto_yx.parse: ../provenance_union_punning_2_auto_yx.c
provenance_union_punning_2_global_xy.parse: ../provenance_union_punning_2_global_xy.c
provenance_union_punning_2_global_yx.parse: ../provenance_union_punning_2_global_yx.c
provenance_via_io_auto.parse: ../provenance_via_io_auto.c
provenance_via_io_bytewise_global.parse: ../provenance_via_io_bytewise_global.c
provenance_via_io_global.parse: ../provenance_via_io_global.c
provenance_via_io_percentp_global.parse: ../provenance_via_io_percentp_global.c
provenance_via_io_uintptr_t_global.parse: ../provenance_via_io_uintptr_t_global.c
read_union_same_prefix_visible.parse: ../read_union_same_prefix_visible.c
read_via_invalid_1.parse: ../read_via_invalid_1.c
signalling_nan_1.parse: ../signalling_nan_1.c
struct_initialise_members.parse: ../struct_initialise_members.c
struct_inter_submember_1.parse: ../struct_inter_submember_1.c
tkn-1.parse: ../tkn-1.c
tkn-2.parse: ../tkn-2.c
tkn-3.parse: ../tkn-3.c
tkn-3-commented.parse: ../tkn-3-commented.c
trap_representation_1.parse: ../trap_representation_1.c
trap_representation_2.parse: ../trap_representation_2.c
trap_representation_3.parse: ../trap_representation_3.c
ubc_addr_null_1.parse: ../ubc_addr_null_1.c
union_punning_gcc_1.parse: ../union_punning_gcc_1.c
union_punning_gcc_2.parse: ../union_punning_gcc_2.c
union_punning_gcc_3.parse: ../union_punning_gcc_3.c
unspecified_value_control_flow_choice.parse: ../unspecified_value_control_flow_choice.c
unspecified_value_daemonic_1.parse: ../unspecified_value_daemonic_1.c
unspecified_value_library_call_argument.parse: ../unspecified_value_library_call_argument.c
unspecified_value_representation_bytes_1.parse: ../unspecified_value_representation_bytes_1.c
unspecified_value_representation_bytes_2.parse: ../unspecified_value_representation_bytes_2.c
unspecified_value_representation_bytes_3.parse: ../unspecified_value_representation_bytes_3.c
unspecified_value_representation_bytes_4.parse: ../unspecified_value_representation_bytes_4.c
unspecified_value_stability.parse: ../unspecified_value_stability.c
unspecified_value_strictness_and_1.parse: ../unspecified_value_strictness_and_1.c
unspecified_value_strictness_int.parse: ../unspecified_value_strictness_int.c
unspecified_value_strictness_mod_1.parse: ../unspecified_value_strictness_mod_1.c
unspecified_value_strictness_mod_2.parse: ../unspecified_value_strictness_mod_2.c
unspecified_value_strictness_unsigned_char.parse: ../unspecified_value_strictness_unsigned_char.c
unspecified_value_struct_copy.parse: ../unspecified_value_struct_copy.c
unspecified_value_union_1.parse: ../unspecified_value_union_1.c
write_union_same_prefix_visible.parse: ../write_union_same_prefix_visible.c

### Epilogue. Do not modify this block. #######################################
include $(shell $(FRAMAC)-config -print-lib-path)/analysis-scripts/epilogue.mk
###############################################################################

# optional, for OSCS
-include ../../Makefile.common
