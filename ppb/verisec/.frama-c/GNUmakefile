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
  -I ../lib \
  -D'__P(args)=args' \

## General flags
FCFLAGS     += \
  -add-symbolic-path=..:. \
  -kernel-warn-key annot:missing-spec=abort \
  -kernel-warn-key typing:implicit-function-declaration=abort \
  -no-autoload-plugins \
  -load-module variadic,metrics,report,scope,from,inout,eva,nonterm \

## Eva-specific flags
EVAFLAGS    += \
  -eva-warn-key builtins:missing-spec=abort \
  -eva-precision 6 \

## GUI-only flags
FCGUIFLAGS += \

## Analysis targets (suffixed with .eva)
TARGETS = \
  programs_apps_apache_CVE-2004-0940_get_tag_iter1_prefixLong_arr_bad.eva \
  programs_apps_apache_CVE-2004-0940_get_tag_iter1_prefixLong_arr_ok.eva \
  programs_apps_apache_CVE-2004-0940_get_tag_iter1_prefixLong_ptr_bad.eva \
  programs_apps_apache_CVE-2004-0940_get_tag_iter1_prefixLong_ptr_ok.eva \
  programs_apps_apache_CVE-2004-0940_get_tag_iter1_prefixShort_arr_bad.eva \
  programs_apps_apache_CVE-2004-0940_get_tag_iter1_prefixShort_arr_ok.eva \
  programs_apps_apache_CVE-2004-0940_get_tag_iter1_prefixShort_ptr_bad.eva \
  programs_apps_apache_CVE-2004-0940_get_tag_iter1_prefixShort_ptr_ok.eva \
  programs_apps_apache_CVE-2004-0940_get_tag_iter2_prefixLong_arr_bad.eva \
  programs_apps_apache_CVE-2004-0940_get_tag_iter2_prefixLong_ptr_bad.eva \
  programs_apps_apache_CVE-2004-0940_get_tag_iter2_prefixShort_arr_bad.eva \
  programs_apps_apache_CVE-2004-0940_get_tag_iter2_prefixShort_ptr_bad.eva \
  programs_apps_apache_CVE-2006-3747_escape_absolute_uri_full_bad.eva \
  programs_apps_apache_CVE-2006-3747_escape_absolute_uri_full_ok.eva \
  programs_apps_apache_CVE-2006-3747_escape_absolute_uri_full_ptr_bad.eva \
  programs_apps_apache_CVE-2006-3747_escape_absolute_uri_full_ptr_ok.eva \
  programs_apps_apache_CVE-2006-3747_escape_absolute_uri_simp1_ok.eva \
  programs_apps_apache_CVE-2006-3747_escape_absolute_uri_simp1_bad.eva \
  programs_apps_apache_CVE-2006-3747_escape_absolute_uri_simp2_ok.eva \
  programs_apps_apache_CVE-2006-3747_escape_absolute_uri_simp2_bad.eva \
  programs_apps_apache_CVE-2006-3747_escape_absolute_uri_simp3_ok.eva \
  programs_apps_apache_CVE-2006-3747_escape_absolute_uri_simp3_bad.eva \
  programs_apps_apache_CVE-2006-3747_escape_absolute_uri_strncmp_ok.eva \
  programs_apps_apache_CVE-2006-3747_escape_absolute_uri_strncmp_bad.eva \
  programs_apps_bind_CA-1999-14_rrextract-nxt_expands_vars_bad.eva \
  programs_apps_bind_CA-1999-14_rrextract-nxt_expands_vars_ok.eva \
  programs_apps_bind_CA-1999-14_rrextract-nxt_simp_ok.eva \
  programs_apps_bind_CA-1999-14_rrextract-nxt_simp_bad.eva \
  programs_apps_bind_CA-1999-14_rrextract-nxt_two_expands_ok.eva \
  programs_apps_bind_CA-1999-14_rrextract-nxt_two_expands_bad.eva \
  programs_apps_bind_CA-1999-14_rrextract-sig_both_ok.eva \
  programs_apps_bind_CA-1999-14_rrextract-sig_both_bad.eva \
  programs_apps_bind_CA-1999-14_rrextract-sig_expand_ok.eva \
  programs_apps_bind_CA-1999-14_rrextract-sig_expand_bad.eva \
  programs_apps_bind_CA-1999-14_rrextract-sig_simp_ok.eva \
  programs_apps_bind_CA-1999-14_rrextract-sig_simp_bad.eva \
  programs_apps_bind_CA-1999-14_rrextract-sig_vars_ok.eva \
  programs_apps_bind_CA-1999-14_rrextract-sig_vars_bad.eva \
  programs_apps_edbrowse_CVE-2006-6909_ftpls_no_strcmp_ok.eva \
  programs_apps_edbrowse_CVE-2006-6909_ftpls_no_strcmp_bad.eva \
  programs_apps_edbrowse_CVE-2006-6909_ftpls_strchr_ok.eva \
  programs_apps_edbrowse_CVE-2006-6909_ftpls_strchr_bad.eva \
  programs_apps_edbrowse_CVE-2006-6909_ftpls_strcmp_ok.eva \
  programs_apps_edbrowse_CVE-2006-6909_ftpls_strcmp_bad.eva \
  programs_apps_gxine_CVE-2007-0406_main_simp_ok.eva \
  programs_apps_gxine_CVE-2007-0406_main_simp_bad.eva \
  programs_apps_libgd_CVE-2007-0455_gdImageStringFTEx_gd_full_ok.eva \
  programs_apps_libgd_CVE-2007-0455_gdImageStringFTEx_gd_full_bad.eva \
  programs_apps_libgd_CVE-2007-0455_gdImageStringFTEx_gd_no_entities_ok.eva \
  programs_apps_libgd_CVE-2007-0455_gdImageStringFTEx_gd_no_entities_bad.eva \
  programs_apps_libgd_CVE-2007-0455_gdImageStringFTEx_gd_simp_ok.eva \
  programs_apps_libgd_CVE-2007-0455_gdImageStringFTEx_gd_simp_bad.eva \
  programs_apps_libgd_CVE-2007-0455_gdImageStringFTEx_gd_some_entities_ok.eva \
  programs_apps_libgd_CVE-2007-0455_gdImageStringFTEx_gd_some_entities_bad.eva \
  programs_apps_MADWiFi_CVE-2006-6332_encode_ie_interproc_ok.eva \
  programs_apps_MADWiFi_CVE-2006-6332_encode_ie_interproc_bad.eva \
  programs_apps_MADWiFi_CVE-2006-6332_encode_ie_no_sprintf_ok.eva \
  programs_apps_MADWiFi_CVE-2006-6332_encode_ie_no_sprintf_bad.eva \
  programs_apps_MADWiFi_CVE-2006-6332_giwscan_cb_giwscan_cb_ok.eva \
  programs_apps_MADWiFi_CVE-2006-6332_giwscan_cb_giwscan_cb_bad.eva \
  programs_apps_NetBSD-libc_CVE-2006-6652_glob1_bounds_ok.eva \
  programs_apps_NetBSD-libc_CVE-2006-6652_glob1_bounds_bad.eva \
  programs_apps_NetBSD-libc_CVE-2006-6652_glob2_anyMeta_int_ok.eva \
  programs_apps_NetBSD-libc_CVE-2006-6652_glob2_anyMeta_int_bad.eva \
  programs_apps_NetBSD-libc_CVE-2006-6652_glob2_anyMeta_ptr_ok.eva \
  programs_apps_NetBSD-libc_CVE-2006-6652_glob2_anyMeta_ptr_bad.eva \
  programs_apps_NetBSD-libc_CVE-2006-6652_glob2_glob2_int_ok.eva \
  programs_apps_NetBSD-libc_CVE-2006-6652_glob2_glob2_int_bad.eva \
  programs_apps_NetBSD-libc_CVE-2006-6652_glob2_glob2_ptr_ok.eva \
  programs_apps_NetBSD-libc_CVE-2006-6652_glob2_glob2_ptr_bad.eva \
  programs_apps_NetBSD-libc_CVE-2006-6652_glob2_loop_ok.eva \
  programs_apps_NetBSD-libc_CVE-2006-6652_glob2_loop_bad.eva \
  programs_apps_NetBSD-libc_CVE-2006-6652_glob2_noAnyMeta_int_ok.eva \
  programs_apps_NetBSD-libc_CVE-2006-6652_glob2_noAnyMeta_int_bad.eva \
  programs_apps_NetBSD-libc_CVE-2006-6652_glob2_noAnyMeta_ptr_ok.eva \
  programs_apps_NetBSD-libc_CVE-2006-6652_glob2_noAnyMeta_ptr_bad.eva \
  programs_apps_OpenSER_CVE-2006-6749_complete_parse_config_bad.eva \
  programs_apps_OpenSER_CVE-2006-6749_complete_parse_config_ok.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_guard_random_index_bad.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_guard_random_index_ok.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_guard_strchr_bad.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_guard_strchr_ok.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_guard_strstr_bad.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_guard_strstr_ok.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripFullBoth_arr_bad.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripFullBoth_arr_inlined_bad.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripFullBoth_arr_inlined_ok.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripFullBoth_arr_ok.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripFullEnd_arr_bad.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripFullEnd_arr_inlined_bad.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripFullEnd_arr_inlined_ok.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripFullEnd_arr_ok.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripFullStart_arr_bad.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripFullStart_arr_inlined_bad.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripFullStart_arr_inlined_ok.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripFullStart_arr_ok.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripNone_arr_bad.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripNone_arr_inlined_bad.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripNone_arr_inlined_ok.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripNone_arr_ok.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripSpacesBoth_arr_bad.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripSpacesBoth_arr_inlined_bad.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripSpacesBoth_arr_inlined_ok.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripSpacesBoth_arr_ok.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripSpacesEnd_arr_bad.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripSpacesEnd_arr_inlined_bad.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripSpacesEnd_arr_inlined_ok.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripSpacesEnd_arr_ok.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripSpacesStart_arr_bad.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripSpacesStart_arr_inlined_bad.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripSpacesStart_arr_inlined_ok.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripSpacesStart_arr_ok.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripFullBoth_arr_bad.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripFullBoth_arr_inlined_bad.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripFullBoth_arr_inlined_ok.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripFullBoth_arr_ok.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripFullEnd_arr_bad.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripFullEnd_arr_inlined_bad.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripFullEnd_arr_inlined_ok.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripFullEnd_arr_ok.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripFullStart_arr_bad.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripFullStart_arr_inlined_bad.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripFullStart_arr_inlined_ok.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripFullStart_arr_ok.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripNone_arr_bad.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripNone_arr_inlined_bad.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripNone_arr_inlined_ok.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripNone_arr_ok.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripSpacesBoth_arr_bad.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripSpacesBoth_arr_inlined_bad.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripSpacesBoth_arr_inlined_ok.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripSpacesBoth_arr_ok.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripSpacesEnd_arr_bad.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripSpacesEnd_arr_inlined_bad.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripSpacesEnd_arr_inlined_ok.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripSpacesEnd_arr_ok.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripSpacesStart_arr_bad.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripSpacesStart_arr_inlined_bad.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripSpacesStart_arr_inlined_ok.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripSpacesStart_arr_ok.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripFullBoth_arr_bad.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripFullBoth_arr_inlined_bad.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripFullBoth_arr_inlined_ok.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripFullBoth_arr_ok.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripFullEnd_arr_bad.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripFullEnd_arr_inlined_bad.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripFullEnd_arr_inlined_ok.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripFullEnd_arr_ok.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripFullStart_arr_bad.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripFullStart_arr_inlined_bad.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripFullStart_arr_inlined_ok.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripFullStart_arr_ok.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripNone_arr_bad.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripNone_arr_inlined_bad.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripNone_arr_inlined_ok.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripNone_arr_ok.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripSpacesBoth_arr_bad.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripSpacesBoth_arr_inlined_bad.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripSpacesBoth_arr_inlined_ok.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripSpacesBoth_arr_ok.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripSpacesEnd_arr_bad.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripSpacesEnd_arr_inlined_bad.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripSpacesEnd_arr_inlined_ok.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripSpacesEnd_arr_ok.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripSpacesStart_arr_bad.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripSpacesStart_arr_inlined_bad.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripSpacesStart_arr_inlined_ok.eva \
  programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripSpacesStart_arr_ok.eva \
  programs_apps_OpenSER_CVE-2006-6876_fetchsms_full_bad.eva \
  programs_apps_OpenSER_CVE-2006-6876_fetchsms_full_ok.eva \
  programs_apps_OpenSER_CVE-2006-6876_fetchsms_istrstr2_loops_bad.eva \
  programs_apps_OpenSER_CVE-2006-6876_fetchsms_istrstr2_loops_ok.eva \
  programs_apps_OpenSER_CVE-2006-6876_fetchsms_istrstr_bad.eva \
  programs_apps_OpenSER_CVE-2006-6876_fetchsms_istrstr_loops_bad.eva \
  programs_apps_OpenSER_CVE-2006-6876_fetchsms_istrstr_loops_ok.eva \
  programs_apps_OpenSER_CVE-2006-6876_fetchsms_istrstr_ok.eva \
  programs_apps_OpenSER_CVE-2006-6876_fetchsms_loops_bad.eva \
  programs_apps_OpenSER_CVE-2006-6876_fetchsms_loops_ok.eva \
  programs_apps_samba_CVE-2007-0453__nss_winbind_ipnodes_getbyname_nonsimp_bad.eva \
  programs_apps_samba_CVE-2007-0453__nss_winbind_ipnodes_getbyname_nonsimp_ok.eva \
  programs_apps_samba_CVE-2007-0453__nss_winbind_ipnodes_getbyname_simp_bad.eva \
  programs_apps_samba_CVE-2007-0453__nss_winbind_ipnodes_getbyname_simp_ok.eva \
  programs_apps_sendmail_CVE-1999-0047_complete_mime2_bad.eva \
  programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_arr_one_char_heavy_test_bad.eva \
  programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_arr_one_char_heavy_test_ok.eva \
  programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_arr_one_char_med_test_bad.eva \
  programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_arr_one_char_med_test_ok.eva \
  programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_arr_one_char_no_test_bad.eva \
  programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_arr_one_char_no_test_ok.eva \
  programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_arr_three_chars_heavy_test_bad.eva \
  programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_arr_three_chars_heavy_test_ok.eva \
  programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_arr_three_chars_med_test_bad.eva \
  programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_arr_three_chars_med_test_ok.eva \
  programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_arr_three_chars_no_test_bad.eva \
  programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_arr_three_chars_no_test_ok.eva \
  programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_arr_two_chars_heavy_test_bad.eva \
  programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_arr_two_chars_heavy_test_ok.eva \
  programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_arr_two_chars_med_test_bad.eva \
  programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_arr_two_chars_med_test_ok.eva \
  programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_arr_two_chars_no_test_bad.eva \
  programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_arr_two_chars_no_test_ok.eva \
  programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_ptr_one_char_heavy_test_bad.eva \
  programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_ptr_one_char_heavy_test_ok.eva \
  programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_ptr_one_char_med_test_bad.eva \
  programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_ptr_one_char_med_test_ok.eva \
  programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_ptr_one_char_no_test_bad.eva \
  programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_ptr_one_char_no_test_ok.eva \
  programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_ptr_three_chars_heavy_test_bad.eva \
  programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_ptr_three_chars_heavy_test_ok.eva \
  programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_ptr_three_chars_med_test_bad.eva \
  programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_ptr_three_chars_med_test_ok.eva \
  programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_ptr_three_chars_no_test_bad.eva \
  programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_ptr_three_chars_no_test_ok.eva \
  programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_ptr_two_chars_heavy_test_bad.eva \
  programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_ptr_two_chars_heavy_test_ok.eva \
  programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_ptr_two_chars_med_test_bad.eva \
  programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_ptr_two_chars_med_test_ok.eva \
  programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_ptr_two_chars_no_test_bad.eva \
  programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_ptr_two_chars_no_test_ok.eva \
  programs_apps_sendmail_CVE-1999-0206_mime_fromqp_mime_fromqp_arr_bad.eva \
  programs_apps_sendmail_CVE-1999-0206_mime_fromqp_mime_fromqp_arr_ok.eva \
  programs_apps_sendmail_CVE-1999-0206_mime_fromqp_mime_fromqp_ptr_bad.eva \
  programs_apps_sendmail_CVE-1999-0206_mime_fromqp_mime_fromqp_ptr_ok.eva \
  programs_apps_sendmail_CVE-2001-0653_complete_tTflag_bad.eva \
  programs_apps_sendmail_CVE-2001-0653_complete_tTflag_ok.eva \
  programs_apps_sendmail_CVE-2001-0653_tTflag_tTflag_arr_one_loop_bad.eva \
  programs_apps_sendmail_CVE-2001-0653_tTflag_tTflag_arr_one_loop_ok.eva \
  programs_apps_sendmail_CVE-2001-0653_tTflag_tTflag_arr_two_loops_bad.eva \
  programs_apps_sendmail_CVE-2001-0653_tTflag_tTflag_arr_two_loops_ok.eva \
  programs_apps_sendmail_CVE-2002-0906_parse_dns_reply_parse_dns_reply_cast_bad.eva \
  programs_apps_sendmail_CVE-2002-0906_parse_dns_reply_parse_dns_reply_cast_ok.eva \
  programs_apps_sendmail_CVE-2002-0906_parse_dns_reply_parse_dns_reply_no_cast_bad.eva \
  programs_apps_sendmail_CVE-2002-0906_parse_dns_reply_parse_dns_reply_no_cast_ok.eva \
  programs_apps_sendmail_CVE-2002-1337_close_angle_close-angle_ptr_no_test_bad.eva \
  programs_apps_sendmail_CVE-2002-1337_close_angle_close-angle_ptr_no_test_ok.eva \
  programs_apps_sendmail_CVE-2002-1337_close_angle_close-angle_ptr_one_test_bad.eva \
  programs_apps_sendmail_CVE-2002-1337_close_angle_close-angle_ptr_one_test_ok.eva \
  programs_apps_sendmail_CVE-2002-1337_close_angle_close-angle_ptr_two_tests_bad.eva \
  programs_apps_sendmail_CVE-2002-1337_close_angle_close-angle_ptr_two_tests_ok.eva \
  programs_apps_sendmail_CVE-2002-1337_complete_crackaddr_bad.eva \
  programs_apps_sendmail_CVE-2003-0161_prescan_prescan_arr_med_test_bad.eva \
  programs_apps_sendmail_CVE-2003-0161_prescan_prescan_arr_med_test_ok.eva \
  programs_apps_sendmail_CVE-2003-0161_prescan_prescan_arr_min_test_bad.eva \
  programs_apps_sendmail_CVE-2003-0161_prescan_prescan_arr_min_test_ok.eva \
  programs_apps_sendmail_CVE-2003-0681_buildfname_buildfname_arr_one_gecos_bad.eva \
  programs_apps_sendmail_CVE-2003-0681_buildfname_buildfname_arr_one_gecos_ok.eva \
  programs_apps_sendmail_CVE-2003-0681_buildfname_buildfname_arr_two_gecos_bad.eva \
  programs_apps_sendmail_CVE-2003-0681_buildfname_buildfname_arr_two_gecos_ok.eva \
  programs_apps_sendmail_CVE-2003-0681_complete_util_bad.eva \
  programs_apps_SpamAssassin_BID-6679_message_write_loop_bad.eva \
  programs_apps_SpamAssassin_BID-6679_message_write_loop_ok.eva \
  programs_apps_wu-ftpd_CVE-1999-0368_realpath-curpath_simple_bad.eva \
  programs_apps_wu-ftpd_CVE-1999-0368_realpath-curpath_simple_ok.eva \
  programs_apps_wu-ftpd_CVE-1999-0368_realpath-linkpath_prefix_bad.eva \
  programs_apps_wu-ftpd_CVE-1999-0368_realpath-linkpath_prefix_ok.eva \
  programs_apps_wu-ftpd_CVE-1999-0368_realpath-linkpath_prefix_simp_bad.eva \
  programs_apps_wu-ftpd_CVE-1999-0368_realpath-linkpath_prefix_simp_ok.eva \
  programs_apps_wu-ftpd_CVE-1999-0368_realpath-linkpath_strcpy_strcat_bad.eva \
  programs_apps_wu-ftpd_CVE-1999-0368_realpath-linkpath_strcpy_strcat_ok.eva \
  programs_apps_wu-ftpd_CVE-1999-0368_realpath-namebuf_iter_ints_bad.eva \
  programs_apps_wu-ftpd_CVE-1999-0368_realpath-namebuf_iter_ints_ok.eva \
  programs_apps_wu-ftpd_CVE-1999-0368_realpath-namebuf_iter_ints_simp_bad.eva \
  programs_apps_wu-ftpd_CVE-1999-0368_realpath-namebuf_iter_ints_simp_ok.eva \
  programs_apps_wu-ftpd_CVE-1999-0368_realpath-namebuf_strcpy_strcat_bad.eva \
  programs_apps_wu-ftpd_CVE-1999-0368_realpath-namebuf_strcpy_strcat_ok.eva \
  programs_apps_wu-ftpd_CVE-2003-0466_fb_realpath_almost_simple_bad.eva \
  programs_apps_wu-ftpd_CVE-2003-0466_fb_realpath_almost_simple_ok.eva \
  programs_apps_wu-ftpd_CVE-2003-0466_fb_realpath_istrrchr_bad.eva \
  programs_apps_wu-ftpd_CVE-2003-0466_fb_realpath_istrrchr_ok.eva \
  programs_apps_wu-ftpd_CVE-2003-0466_fb_realpath_no_symlinks_bad.eva \
  programs_apps_wu-ftpd_CVE-2003-0466_fb_realpath_no_symlinks_ok.eva \
  programs_apps_wu-ftpd_CVE-2003-0466_fb_realpath_simple_bad.eva \
  programs_apps_wu-ftpd_CVE-2003-0466_fb_realpath_simple_ok.eva \
  programs_apps_wu-ftpd_CVE-2003-0466_fb_realpath_symlinks_bad.eva \
  programs_apps_wu-ftpd_CVE-2003-0466_fb_realpath_symlinks_ok.eva \

### Each target <t>.eva needs a rule <t>.parse with source files as prerequisites
programs_apps_apache_CVE-2004-0940_get_tag_iter1_prefixLong_arr_bad.parse: \
  ../programs/apps/apache/CVE-2004-0940/get_tag/iter1_prefixLong_arr_bad.c \
  ../programs/apps/apache/CVE-2004-0940/apache.c \

programs_apps_apache_CVE-2004-0940_get_tag_iter1_prefixLong_arr_ok.parse: \
  ../programs/apps/apache/CVE-2004-0940/get_tag/iter1_prefixLong_arr_ok.c \
  ../programs/apps/apache/CVE-2004-0940/apache.c \

programs_apps_apache_CVE-2004-0940_get_tag_iter1_prefixLong_ptr_bad.parse: \
  ../programs/apps/apache/CVE-2004-0940/get_tag/iter1_prefixLong_ptr_bad.c \
  ../programs/apps/apache/CVE-2004-0940/apache.c \

programs_apps_apache_CVE-2004-0940_get_tag_iter1_prefixLong_ptr_ok.parse: \
  ../programs/apps/apache/CVE-2004-0940/get_tag/iter1_prefixLong_ptr_ok.c \
  ../programs/apps/apache/CVE-2004-0940/apache.c \

programs_apps_apache_CVE-2004-0940_get_tag_iter1_prefixShort_arr_bad.parse: \
  ../programs/apps/apache/CVE-2004-0940/get_tag/iter1_prefixShort_arr_bad.c \
  ../programs/apps/apache/CVE-2004-0940/apache.c \

programs_apps_apache_CVE-2004-0940_get_tag_iter1_prefixShort_arr_ok.parse: \
  ../programs/apps/apache/CVE-2004-0940/get_tag/iter1_prefixShort_arr_ok.c \
  ../programs/apps/apache/CVE-2004-0940/apache.c \

programs_apps_apache_CVE-2004-0940_get_tag_iter1_prefixShort_ptr_bad.parse: \
  ../programs/apps/apache/CVE-2004-0940/get_tag/iter1_prefixShort_ptr_bad.c \
  ../programs/apps/apache/CVE-2004-0940/apache.c \

programs_apps_apache_CVE-2004-0940_get_tag_iter1_prefixShort_ptr_ok.parse: \
  ../programs/apps/apache/CVE-2004-0940/get_tag/iter1_prefixShort_ptr_ok.c \
  ../programs/apps/apache/CVE-2004-0940/apache.c \

programs_apps_apache_CVE-2004-0940_get_tag_iter2_prefixLong_arr_bad.parse: \
  ../programs/apps/apache/CVE-2004-0940/get_tag/iter2_prefixLong_arr_bad.c \
  ../programs/apps/apache/CVE-2004-0940/apache.c \

programs_apps_apache_CVE-2004-0940_get_tag_iter2_prefixLong_ptr_bad.parse: \
  ../programs/apps/apache/CVE-2004-0940/get_tag/iter2_prefixLong_ptr_bad.c \
  ../programs/apps/apache/CVE-2004-0940/apache.c \

programs_apps_apache_CVE-2004-0940_get_tag_iter2_prefixShort_arr_bad.parse: \
  ../programs/apps/apache/CVE-2004-0940/get_tag/iter2_prefixShort_arr_bad.c \
  ../programs/apps/apache/CVE-2004-0940/apache.c \

programs_apps_apache_CVE-2004-0940_get_tag_iter2_prefixShort_ptr_bad.parse: \
  ../programs/apps/apache/CVE-2004-0940/get_tag/iter2_prefixShort_ptr_bad.c \
  ../programs/apps/apache/CVE-2004-0940/apache.c \

programs_apps_apache_CVE-2006-3747_escape_absolute_uri_full_bad.parse: \
  ../programs/apps/apache/CVE-2006-3747/escape_absolute_uri/full_bad.c \

programs_apps_apache_CVE-2006-3747_escape_absolute_uri_full_ok.parse: \
  ../programs/apps/apache/CVE-2006-3747/escape_absolute_uri/full_ok.c \

programs_apps_apache_CVE-2006-3747_escape_absolute_uri_full_ptr_bad.parse: \
  ../programs/apps/apache/CVE-2006-3747/escape_absolute_uri/full_ptr_bad.c \

programs_apps_apache_CVE-2006-3747_escape_absolute_uri_full_ptr_ok.parse: \
  ../programs/apps/apache/CVE-2006-3747/escape_absolute_uri/full_ptr_ok.c \

programs_apps_apache_CVE-2006-3747_escape_absolute_uri_simp1_ok.parse: \
  ../programs/apps/apache/CVE-2006-3747/escape_absolute_uri/simp1_ok.c \

programs_apps_apache_CVE-2006-3747_escape_absolute_uri_simp1_bad.parse: \
  ../programs/apps/apache/CVE-2006-3747/escape_absolute_uri/simp1_bad.c \

programs_apps_apache_CVE-2006-3747_escape_absolute_uri_simp2_ok.parse: \
  ../programs/apps/apache/CVE-2006-3747/escape_absolute_uri/simp2_ok.c \

programs_apps_apache_CVE-2006-3747_escape_absolute_uri_simp2_bad.parse: \
  ../programs/apps/apache/CVE-2006-3747/escape_absolute_uri/simp2_bad.c \

programs_apps_apache_CVE-2006-3747_escape_absolute_uri_simp3_ok.parse: \
  ../programs/apps/apache/CVE-2006-3747/escape_absolute_uri/simp3_ok.c \

programs_apps_apache_CVE-2006-3747_escape_absolute_uri_simp3_bad.parse: \
  ../programs/apps/apache/CVE-2006-3747/escape_absolute_uri/simp3_bad.c \

programs_apps_apache_CVE-2006-3747_escape_absolute_uri_strncmp_ok.parse: \
  ../programs/apps/apache/CVE-2006-3747/escape_absolute_uri/strncmp_ok.c \

programs_apps_apache_CVE-2006-3747_escape_absolute_uri_strncmp_bad.parse: \
  ../programs/apps/apache/CVE-2006-3747/escape_absolute_uri/strncmp_bad.c \

programs_apps_bind_CA-1999-14_rrextract-nxt_expands_vars_bad.parse: \
  ../programs/apps/bind/CA-1999-14/rrextract-nxt/expands_vars_bad.c \
  ../programs/apps/bind/CA-1999-14/bind.c \

programs_apps_bind_CA-1999-14_rrextract-nxt_expands_vars_ok.parse: \
  ../programs/apps/bind/CA-1999-14/rrextract-nxt/expands_vars_ok.c \
  ../programs/apps/bind/CA-1999-14/bind.c \

programs_apps_bind_CA-1999-14_rrextract-nxt_simp_ok.parse: \
  ../programs/apps/bind/CA-1999-14/rrextract-nxt/simp_ok.c \
  ../programs/apps/bind/CA-1999-14/bind.c \

programs_apps_bind_CA-1999-14_rrextract-nxt_simp_bad.parse: \
  ../programs/apps/bind/CA-1999-14/rrextract-nxt/simp_bad.c \
  ../programs/apps/bind/CA-1999-14/bind.c \

programs_apps_bind_CA-1999-14_rrextract-nxt_two_expands_ok.parse: \
  ../programs/apps/bind/CA-1999-14/rrextract-nxt/two_expands_ok.c \
  ../programs/apps/bind/CA-1999-14/bind.c \

programs_apps_bind_CA-1999-14_rrextract-nxt_two_expands_bad.parse: \
  ../programs/apps/bind/CA-1999-14/rrextract-nxt/two_expands_bad.c \
  ../programs/apps/bind/CA-1999-14/bind.c \

programs_apps_bind_CA-1999-14_rrextract-sig_both_ok.parse: \
  ../programs/apps/bind/CA-1999-14/rrextract-sig/both_ok.c \
  ../programs/apps/bind/CA-1999-14/bind.c \

programs_apps_bind_CA-1999-14_rrextract-sig_both_bad.parse: \
  ../programs/apps/bind/CA-1999-14/rrextract-sig/both_bad.c \
  ../programs/apps/bind/CA-1999-14/bind.c \

programs_apps_bind_CA-1999-14_rrextract-sig_expand_ok.parse: \
  ../programs/apps/bind/CA-1999-14/rrextract-sig/expand_ok.c \
  ../programs/apps/bind/CA-1999-14/bind.c \

programs_apps_bind_CA-1999-14_rrextract-sig_expand_bad.parse: \
  ../programs/apps/bind/CA-1999-14/rrextract-sig/expand_bad.c \
  ../programs/apps/bind/CA-1999-14/bind.c \

programs_apps_bind_CA-1999-14_rrextract-sig_simp_ok.parse: \
  ../programs/apps/bind/CA-1999-14/rrextract-sig/simp_ok.c \
  ../programs/apps/bind/CA-1999-14/bind.c \

programs_apps_bind_CA-1999-14_rrextract-sig_simp_bad.parse: \
  ../programs/apps/bind/CA-1999-14/rrextract-sig/simp_bad.c \
  ../programs/apps/bind/CA-1999-14/bind.c \

programs_apps_bind_CA-1999-14_rrextract-sig_vars_ok.parse: \
  ../programs/apps/bind/CA-1999-14/rrextract-sig/vars_ok.c \
  ../programs/apps/bind/CA-1999-14/bind.c \

programs_apps_bind_CA-1999-14_rrextract-sig_vars_bad.parse: \
  ../programs/apps/bind/CA-1999-14/rrextract-sig/vars_bad.c \
  ../programs/apps/bind/CA-1999-14/bind.c \

programs_apps_edbrowse_CVE-2006-6909_ftpls_no_strcmp_ok.parse: \
  ../programs/apps/edbrowse/CVE-2006-6909/ftpls/no_strcmp_ok.c \

programs_apps_edbrowse_CVE-2006-6909_ftpls_no_strcmp_bad.parse: \
  ../programs/apps/edbrowse/CVE-2006-6909/ftpls/no_strcmp_bad.c \

programs_apps_edbrowse_CVE-2006-6909_ftpls_strchr_ok.parse: \
  ../programs/apps/edbrowse/CVE-2006-6909/ftpls/strchr_ok.c \

programs_apps_edbrowse_CVE-2006-6909_ftpls_strchr_bad.parse: \
  ../programs/apps/edbrowse/CVE-2006-6909/ftpls/strchr_bad.c \

programs_apps_edbrowse_CVE-2006-6909_ftpls_strcmp_ok.parse: \
  ../programs/apps/edbrowse/CVE-2006-6909/ftpls/strcmp_ok.c \

programs_apps_edbrowse_CVE-2006-6909_ftpls_strcmp_bad.parse: \
  ../programs/apps/edbrowse/CVE-2006-6909/ftpls/strcmp_bad.c \

programs_apps_gxine_CVE-2007-0406_main_simp_ok.parse: \
  ../programs/apps/gxine/CVE-2007-0406/main/simp_ok.c \

programs_apps_gxine_CVE-2007-0406_main_simp_bad.parse: \
  ../programs/apps/gxine/CVE-2007-0406/main/simp_bad.c \

programs_apps_libgd_CVE-2007-0455_gdImageStringFTEx_gd_full_ok.parse: \
  ../programs/apps/libgd/CVE-2007-0455/gdImageStringFTEx/gd_full_ok.c \

programs_apps_libgd_CVE-2007-0455_gdImageStringFTEx_gd_full_bad.parse: \
  ../programs/apps/libgd/CVE-2007-0455/gdImageStringFTEx/gd_full_bad.c \

programs_apps_libgd_CVE-2007-0455_gdImageStringFTEx_gd_no_entities_ok.parse: \
  ../programs/apps/libgd/CVE-2007-0455/gdImageStringFTEx/gd_no_entities_ok.c \

programs_apps_libgd_CVE-2007-0455_gdImageStringFTEx_gd_no_entities_bad.parse: \
  ../programs/apps/libgd/CVE-2007-0455/gdImageStringFTEx/gd_no_entities_bad.c \

programs_apps_libgd_CVE-2007-0455_gdImageStringFTEx_gd_simp_ok.parse: \
  ../programs/apps/libgd/CVE-2007-0455/gdImageStringFTEx/gd_simp_ok.c \

programs_apps_libgd_CVE-2007-0455_gdImageStringFTEx_gd_simp_bad.parse: \
  ../programs/apps/libgd/CVE-2007-0455/gdImageStringFTEx/gd_simp_bad.c \

programs_apps_libgd_CVE-2007-0455_gdImageStringFTEx_gd_some_entities_ok.parse: \
  ../programs/apps/libgd/CVE-2007-0455/gdImageStringFTEx/gd_some_entities_ok.c \

programs_apps_libgd_CVE-2007-0455_gdImageStringFTEx_gd_some_entities_bad.parse: \
  ../programs/apps/libgd/CVE-2007-0455/gdImageStringFTEx/gd_some_entities_bad.c \

programs_apps_MADWiFi_CVE-2006-6332_encode_ie_interproc_ok.parse: \
  ../programs/apps/MADWiFi/CVE-2006-6332/encode_ie/interproc_ok.c \

programs_apps_MADWiFi_CVE-2006-6332_encode_ie_interproc_bad.parse: \
  ../programs/apps/MADWiFi/CVE-2006-6332/encode_ie/interproc_bad.c \

programs_apps_MADWiFi_CVE-2006-6332_encode_ie_no_sprintf_ok.parse: \
  ../programs/apps/MADWiFi/CVE-2006-6332/encode_ie/no_sprintf_ok.c \

programs_apps_MADWiFi_CVE-2006-6332_encode_ie_no_sprintf_bad.parse: \
  ../programs/apps/MADWiFi/CVE-2006-6332/encode_ie/no_sprintf_bad.c \

programs_apps_MADWiFi_CVE-2006-6332_giwscan_cb_giwscan_cb_ok.parse: \
  ../programs/apps/MADWiFi/CVE-2006-6332/giwscan_cb/giwscan_cb_ok.c \

programs_apps_MADWiFi_CVE-2006-6332_giwscan_cb_giwscan_cb_bad.parse: \
  ../programs/apps/MADWiFi/CVE-2006-6332/giwscan_cb/giwscan_cb_bad.c \

programs_apps_NetBSD-libc_CVE-2006-6652_glob1_bounds_ok.parse: \
  ../programs/apps/NetBSD-libc/CVE-2006-6652/glob1/bounds_ok.c \

programs_apps_NetBSD-libc_CVE-2006-6652_glob1_bounds_bad.parse: \
  ../programs/apps/NetBSD-libc/CVE-2006-6652/glob1/bounds_bad.c \

programs_apps_NetBSD-libc_CVE-2006-6652_glob2_anyMeta_int_ok.parse: \
  ../programs/apps/NetBSD-libc/CVE-2006-6652/glob2/anyMeta_int_ok.c \

programs_apps_NetBSD-libc_CVE-2006-6652_glob2_anyMeta_int_bad.parse: \
  ../programs/apps/NetBSD-libc/CVE-2006-6652/glob2/anyMeta_int_bad.c \

programs_apps_NetBSD-libc_CVE-2006-6652_glob2_anyMeta_ptr_ok.parse: \
  ../programs/apps/NetBSD-libc/CVE-2006-6652/glob2/anyMeta_ptr_ok.c \

programs_apps_NetBSD-libc_CVE-2006-6652_glob2_anyMeta_ptr_bad.parse: \
  ../programs/apps/NetBSD-libc/CVE-2006-6652/glob2/anyMeta_ptr_bad.c \

programs_apps_NetBSD-libc_CVE-2006-6652_glob2_glob2_int_ok.parse: \
  ../programs/apps/NetBSD-libc/CVE-2006-6652/glob2/glob2_int_ok.c \

programs_apps_NetBSD-libc_CVE-2006-6652_glob2_glob2_int_bad.parse: \
  ../programs/apps/NetBSD-libc/CVE-2006-6652/glob2/glob2_int_bad.c \

programs_apps_NetBSD-libc_CVE-2006-6652_glob2_glob2_ptr_ok.parse: \
  ../programs/apps/NetBSD-libc/CVE-2006-6652/glob2/glob2_ptr_ok.c \

programs_apps_NetBSD-libc_CVE-2006-6652_glob2_glob2_ptr_bad.parse: \
  ../programs/apps/NetBSD-libc/CVE-2006-6652/glob2/glob2_ptr_bad.c \

programs_apps_NetBSD-libc_CVE-2006-6652_glob2_loop_ok.parse: \
  ../programs/apps/NetBSD-libc/CVE-2006-6652/glob2/loop_ok.c \

programs_apps_NetBSD-libc_CVE-2006-6652_glob2_loop_bad.parse: \
  ../programs/apps/NetBSD-libc/CVE-2006-6652/glob2/loop_bad.c \

programs_apps_NetBSD-libc_CVE-2006-6652_glob2_noAnyMeta_int_ok.parse: \
  ../programs/apps/NetBSD-libc/CVE-2006-6652/glob2/noAnyMeta_int_ok.c \

programs_apps_NetBSD-libc_CVE-2006-6652_glob2_noAnyMeta_int_bad.parse: \
  ../programs/apps/NetBSD-libc/CVE-2006-6652/glob2/noAnyMeta_int_bad.c \

programs_apps_NetBSD-libc_CVE-2006-6652_glob2_noAnyMeta_ptr_ok.parse: \
  ../programs/apps/NetBSD-libc/CVE-2006-6652/glob2/noAnyMeta_ptr_ok.c \

programs_apps_NetBSD-libc_CVE-2006-6652_glob2_noAnyMeta_ptr_bad.parse: \
  ../programs/apps/NetBSD-libc/CVE-2006-6652/glob2/noAnyMeta_ptr_bad.c \

programs_apps_OpenSER_CVE-2006-6749_complete_parse_config_bad.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/complete/parse_config_bad.c \

programs_apps_OpenSER_CVE-2006-6749_complete_parse_config_ok.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/complete/parse_config_ok.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_guard_random_index_bad.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression/guard_random_index_bad.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_guard_random_index_ok.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression/guard_random_index_ok.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_guard_strchr_bad.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression/guard_strchr_bad.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_guard_strchr_ok.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression/guard_strchr_ok.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_guard_strstr_bad.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression/guard_strstr_bad.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_guard_strstr_ok.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression/guard_strstr_ok.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripFullBoth_arr_bad.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases1_stripFullBoth_arr_bad.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripFullBoth_arr_inlined_bad.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases1_stripFullBoth_arr_inlined_bad.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripFullBoth_arr_inlined_ok.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases1_stripFullBoth_arr_inlined_ok.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripFullBoth_arr_ok.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases1_stripFullBoth_arr_ok.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripFullEnd_arr_bad.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases1_stripFullEnd_arr_bad.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripFullEnd_arr_inlined_bad.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases1_stripFullEnd_arr_inlined_bad.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripFullEnd_arr_inlined_ok.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases1_stripFullEnd_arr_inlined_ok.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripFullEnd_arr_ok.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases1_stripFullEnd_arr_ok.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripFullStart_arr_bad.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases1_stripFullStart_arr_bad.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripFullStart_arr_inlined_bad.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases1_stripFullStart_arr_inlined_bad.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripFullStart_arr_inlined_ok.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases1_stripFullStart_arr_inlined_ok.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripFullStart_arr_ok.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases1_stripFullStart_arr_ok.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripNone_arr_bad.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases1_stripNone_arr_bad.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripNone_arr_inlined_bad.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases1_stripNone_arr_inlined_bad.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripNone_arr_inlined_ok.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases1_stripNone_arr_inlined_ok.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripNone_arr_ok.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases1_stripNone_arr_ok.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripSpacesBoth_arr_bad.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases1_stripSpacesBoth_arr_bad.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripSpacesBoth_arr_inlined_bad.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases1_stripSpacesBoth_arr_inlined_bad.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripSpacesBoth_arr_inlined_ok.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases1_stripSpacesBoth_arr_inlined_ok.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripSpacesBoth_arr_ok.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases1_stripSpacesBoth_arr_ok.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripSpacesEnd_arr_bad.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases1_stripSpacesEnd_arr_bad.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripSpacesEnd_arr_inlined_bad.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases1_stripSpacesEnd_arr_inlined_bad.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripSpacesEnd_arr_inlined_ok.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases1_stripSpacesEnd_arr_inlined_ok.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripSpacesEnd_arr_ok.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases1_stripSpacesEnd_arr_ok.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripSpacesStart_arr_bad.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases1_stripSpacesStart_arr_bad.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripSpacesStart_arr_inlined_bad.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases1_stripSpacesStart_arr_inlined_bad.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripSpacesStart_arr_inlined_ok.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases1_stripSpacesStart_arr_inlined_ok.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases1_stripSpacesStart_arr_ok.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases1_stripSpacesStart_arr_ok.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripFullBoth_arr_bad.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases2_stripFullBoth_arr_bad.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripFullBoth_arr_inlined_bad.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases2_stripFullBoth_arr_inlined_bad.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripFullBoth_arr_inlined_ok.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases2_stripFullBoth_arr_inlined_ok.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripFullBoth_arr_ok.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases2_stripFullBoth_arr_ok.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripFullEnd_arr_bad.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases2_stripFullEnd_arr_bad.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripFullEnd_arr_inlined_bad.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases2_stripFullEnd_arr_inlined_bad.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripFullEnd_arr_inlined_ok.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases2_stripFullEnd_arr_inlined_ok.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripFullEnd_arr_ok.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases2_stripFullEnd_arr_ok.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripFullStart_arr_bad.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases2_stripFullStart_arr_bad.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripFullStart_arr_inlined_bad.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases2_stripFullStart_arr_inlined_bad.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripFullStart_arr_inlined_ok.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases2_stripFullStart_arr_inlined_ok.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripFullStart_arr_ok.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases2_stripFullStart_arr_ok.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripNone_arr_bad.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases2_stripNone_arr_bad.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripNone_arr_inlined_bad.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases2_stripNone_arr_inlined_bad.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripNone_arr_inlined_ok.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases2_stripNone_arr_inlined_ok.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripNone_arr_ok.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases2_stripNone_arr_ok.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripSpacesBoth_arr_bad.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases2_stripSpacesBoth_arr_bad.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripSpacesBoth_arr_inlined_bad.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases2_stripSpacesBoth_arr_inlined_bad.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripSpacesBoth_arr_inlined_ok.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases2_stripSpacesBoth_arr_inlined_ok.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripSpacesBoth_arr_ok.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases2_stripSpacesBoth_arr_ok.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripSpacesEnd_arr_bad.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases2_stripSpacesEnd_arr_bad.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripSpacesEnd_arr_inlined_bad.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases2_stripSpacesEnd_arr_inlined_bad.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripSpacesEnd_arr_inlined_ok.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases2_stripSpacesEnd_arr_inlined_ok.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripSpacesEnd_arr_ok.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases2_stripSpacesEnd_arr_ok.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripSpacesStart_arr_bad.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases2_stripSpacesStart_arr_bad.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripSpacesStart_arr_inlined_bad.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases2_stripSpacesStart_arr_inlined_bad.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripSpacesStart_arr_inlined_ok.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases2_stripSpacesStart_arr_inlined_ok.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases2_stripSpacesStart_arr_ok.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases2_stripSpacesStart_arr_ok.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripFullBoth_arr_bad.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases3_stripFullBoth_arr_bad.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripFullBoth_arr_inlined_bad.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases3_stripFullBoth_arr_inlined_bad.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripFullBoth_arr_inlined_ok.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases3_stripFullBoth_arr_inlined_ok.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripFullBoth_arr_ok.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases3_stripFullBoth_arr_ok.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripFullEnd_arr_bad.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases3_stripFullEnd_arr_bad.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripFullEnd_arr_inlined_bad.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases3_stripFullEnd_arr_inlined_bad.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripFullEnd_arr_inlined_ok.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases3_stripFullEnd_arr_inlined_ok.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripFullEnd_arr_ok.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases3_stripFullEnd_arr_ok.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripFullStart_arr_bad.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases3_stripFullStart_arr_bad.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripFullStart_arr_inlined_bad.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases3_stripFullStart_arr_inlined_bad.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripFullStart_arr_inlined_ok.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases3_stripFullStart_arr_inlined_ok.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripFullStart_arr_ok.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases3_stripFullStart_arr_ok.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripNone_arr_bad.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases3_stripNone_arr_bad.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripNone_arr_inlined_bad.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases3_stripNone_arr_inlined_bad.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripNone_arr_inlined_ok.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases3_stripNone_arr_inlined_ok.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripNone_arr_ok.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases3_stripNone_arr_ok.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripSpacesBoth_arr_bad.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases3_stripSpacesBoth_arr_bad.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripSpacesBoth_arr_inlined_bad.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases3_stripSpacesBoth_arr_inlined_bad.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripSpacesBoth_arr_inlined_ok.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases3_stripSpacesBoth_arr_inlined_ok.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripSpacesBoth_arr_ok.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases3_stripSpacesBoth_arr_ok.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripSpacesEnd_arr_bad.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases3_stripSpacesEnd_arr_bad.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripSpacesEnd_arr_inlined_bad.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases3_stripSpacesEnd_arr_inlined_bad.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripSpacesEnd_arr_inlined_ok.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases3_stripSpacesEnd_arr_inlined_ok.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripSpacesEnd_arr_ok.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases3_stripSpacesEnd_arr_ok.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripSpacesStart_arr_bad.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases3_stripSpacesStart_arr_bad.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripSpacesStart_arr_inlined_bad.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases3_stripSpacesStart_arr_inlined_bad.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripSpacesStart_arr_inlined_ok.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases3_stripSpacesStart_arr_inlined_ok.c \

programs_apps_OpenSER_CVE-2006-6749_parse_expression_list_cases3_stripSpacesStart_arr_ok.parse: \
  ../programs/apps/OpenSER/CVE-2006-6749/parse_expression_list/cases3_stripSpacesStart_arr_ok.c \

programs_apps_OpenSER_CVE-2006-6876_fetchsms_full_bad.parse: \
  ../programs/apps/OpenSER/CVE-2006-6876/fetchsms/full_bad.c \
  fc_stubs.c \

programs_apps_OpenSER_CVE-2006-6876_fetchsms_full_ok.parse: \
  ../programs/apps/OpenSER/CVE-2006-6876/fetchsms/full_ok.c \
  fc_stubs.c \

programs_apps_OpenSER_CVE-2006-6876_fetchsms_istrstr2_loops_bad.parse: \
  ../programs/apps/OpenSER/CVE-2006-6876/fetchsms/istrstr2_loops_bad.c \
  fc_stubs.c \

programs_apps_OpenSER_CVE-2006-6876_fetchsms_istrstr2_loops_ok.parse: \
  ../programs/apps/OpenSER/CVE-2006-6876/fetchsms/istrstr2_loops_ok.c \
  fc_stubs.c \

programs_apps_OpenSER_CVE-2006-6876_fetchsms_istrstr_bad.parse: \
  ../programs/apps/OpenSER/CVE-2006-6876/fetchsms/istrstr_bad.c \
  fc_stubs.c \

programs_apps_OpenSER_CVE-2006-6876_fetchsms_istrstr_loops_bad.parse: \
  ../programs/apps/OpenSER/CVE-2006-6876/fetchsms/istrstr_loops_bad.c \
  fc_stubs.c \

programs_apps_OpenSER_CVE-2006-6876_fetchsms_istrstr_loops_ok.parse: \
  ../programs/apps/OpenSER/CVE-2006-6876/fetchsms/istrstr_loops_ok.c \
  fc_stubs.c \

programs_apps_OpenSER_CVE-2006-6876_fetchsms_istrstr_ok.parse: \
  ../programs/apps/OpenSER/CVE-2006-6876/fetchsms/istrstr_ok.c \
  fc_stubs.c \

programs_apps_OpenSER_CVE-2006-6876_fetchsms_loops_bad.parse: \
  ../programs/apps/OpenSER/CVE-2006-6876/fetchsms/loops_bad.c \

programs_apps_OpenSER_CVE-2006-6876_fetchsms_loops_ok.parse: \
  ../programs/apps/OpenSER/CVE-2006-6876/fetchsms/loops_ok.c \

programs_apps_samba_CVE-2007-0453__nss_winbind_ipnodes_getbyname_nonsimp_bad.parse: \
  ../programs/apps/samba/CVE-2007-0453/_nss_winbind_ipnodes_getbyname/nonsimp_bad.c \

programs_apps_samba_CVE-2007-0453__nss_winbind_ipnodes_getbyname_nonsimp_ok.parse: \
  ../programs/apps/samba/CVE-2007-0453/_nss_winbind_ipnodes_getbyname/nonsimp_ok.c \

programs_apps_samba_CVE-2007-0453__nss_winbind_ipnodes_getbyname_simp_bad.parse: \
  ../programs/apps/samba/CVE-2007-0453/_nss_winbind_ipnodes_getbyname/simp_bad.c \

programs_apps_samba_CVE-2007-0453__nss_winbind_ipnodes_getbyname_simp_ok.parse: \
  ../programs/apps/samba/CVE-2007-0453/_nss_winbind_ipnodes_getbyname/simp_ok.c \

programs_apps_sendmail_CVE-1999-0047_complete_mime2_bad.parse: \
  ../programs/apps/sendmail/CVE-1999-0047/complete/mime2_bad.c \

programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_arr_one_char_heavy_test_bad.parse: \
  ../programs/apps/sendmail/CVE-1999-0047/mime7to8/mime7to8_arr_one_char_heavy_test_bad.c \

programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_arr_one_char_heavy_test_ok.parse: \
  ../programs/apps/sendmail/CVE-1999-0047/mime7to8/mime7to8_arr_one_char_heavy_test_ok.c \

programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_arr_one_char_med_test_bad.parse: \
  ../programs/apps/sendmail/CVE-1999-0047/mime7to8/mime7to8_arr_one_char_med_test_bad.c \

programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_arr_one_char_med_test_ok.parse: \
  ../programs/apps/sendmail/CVE-1999-0047/mime7to8/mime7to8_arr_one_char_med_test_ok.c \

programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_arr_one_char_no_test_bad.parse: \
  ../programs/apps/sendmail/CVE-1999-0047/mime7to8/mime7to8_arr_one_char_no_test_bad.c \

programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_arr_one_char_no_test_ok.parse: \
  ../programs/apps/sendmail/CVE-1999-0047/mime7to8/mime7to8_arr_one_char_no_test_ok.c \

programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_arr_three_chars_heavy_test_bad.parse: \
  ../programs/apps/sendmail/CVE-1999-0047/mime7to8/mime7to8_arr_three_chars_heavy_test_bad.c \

programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_arr_three_chars_heavy_test_ok.parse: \
  ../programs/apps/sendmail/CVE-1999-0047/mime7to8/mime7to8_arr_three_chars_heavy_test_ok.c \

programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_arr_three_chars_med_test_bad.parse: \
  ../programs/apps/sendmail/CVE-1999-0047/mime7to8/mime7to8_arr_three_chars_med_test_bad.c \

programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_arr_three_chars_med_test_ok.parse: \
  ../programs/apps/sendmail/CVE-1999-0047/mime7to8/mime7to8_arr_three_chars_med_test_ok.c \

programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_arr_three_chars_no_test_bad.parse: \
  ../programs/apps/sendmail/CVE-1999-0047/mime7to8/mime7to8_arr_three_chars_no_test_bad.c \

programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_arr_three_chars_no_test_ok.parse: \
  ../programs/apps/sendmail/CVE-1999-0047/mime7to8/mime7to8_arr_three_chars_no_test_ok.c \

programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_arr_two_chars_heavy_test_bad.parse: \
  ../programs/apps/sendmail/CVE-1999-0047/mime7to8/mime7to8_arr_two_chars_heavy_test_bad.c \

programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_arr_two_chars_heavy_test_ok.parse: \
  ../programs/apps/sendmail/CVE-1999-0047/mime7to8/mime7to8_arr_two_chars_heavy_test_ok.c \

programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_arr_two_chars_med_test_bad.parse: \
  ../programs/apps/sendmail/CVE-1999-0047/mime7to8/mime7to8_arr_two_chars_med_test_bad.c \

programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_arr_two_chars_med_test_ok.parse: \
  ../programs/apps/sendmail/CVE-1999-0047/mime7to8/mime7to8_arr_two_chars_med_test_ok.c \

programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_arr_two_chars_no_test_bad.parse: \
  ../programs/apps/sendmail/CVE-1999-0047/mime7to8/mime7to8_arr_two_chars_no_test_bad.c \

programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_arr_two_chars_no_test_ok.parse: \
  ../programs/apps/sendmail/CVE-1999-0047/mime7to8/mime7to8_arr_two_chars_no_test_ok.c \

programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_ptr_one_char_heavy_test_bad.parse: \
  ../programs/apps/sendmail/CVE-1999-0047/mime7to8/mime7to8_ptr_one_char_heavy_test_bad.c \

programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_ptr_one_char_heavy_test_ok.parse: \
  ../programs/apps/sendmail/CVE-1999-0047/mime7to8/mime7to8_ptr_one_char_heavy_test_ok.c \

programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_ptr_one_char_med_test_bad.parse: \
  ../programs/apps/sendmail/CVE-1999-0047/mime7to8/mime7to8_ptr_one_char_med_test_bad.c \

programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_ptr_one_char_med_test_ok.parse: \
  ../programs/apps/sendmail/CVE-1999-0047/mime7to8/mime7to8_ptr_one_char_med_test_ok.c \

programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_ptr_one_char_no_test_bad.parse: \
  ../programs/apps/sendmail/CVE-1999-0047/mime7to8/mime7to8_ptr_one_char_no_test_bad.c \

programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_ptr_one_char_no_test_ok.parse: \
  ../programs/apps/sendmail/CVE-1999-0047/mime7to8/mime7to8_ptr_one_char_no_test_ok.c \

programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_ptr_three_chars_heavy_test_bad.parse: \
  ../programs/apps/sendmail/CVE-1999-0047/mime7to8/mime7to8_ptr_three_chars_heavy_test_bad.c \

programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_ptr_three_chars_heavy_test_ok.parse: \
  ../programs/apps/sendmail/CVE-1999-0047/mime7to8/mime7to8_ptr_three_chars_heavy_test_ok.c \

programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_ptr_three_chars_med_test_bad.parse: \
  ../programs/apps/sendmail/CVE-1999-0047/mime7to8/mime7to8_ptr_three_chars_med_test_bad.c \

programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_ptr_three_chars_med_test_ok.parse: \
  ../programs/apps/sendmail/CVE-1999-0047/mime7to8/mime7to8_ptr_three_chars_med_test_ok.c \

programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_ptr_three_chars_no_test_bad.parse: \
  ../programs/apps/sendmail/CVE-1999-0047/mime7to8/mime7to8_ptr_three_chars_no_test_bad.c \

programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_ptr_three_chars_no_test_ok.parse: \
  ../programs/apps/sendmail/CVE-1999-0047/mime7to8/mime7to8_ptr_three_chars_no_test_ok.c \

programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_ptr_two_chars_heavy_test_bad.parse: \
  ../programs/apps/sendmail/CVE-1999-0047/mime7to8/mime7to8_ptr_two_chars_heavy_test_bad.c \

programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_ptr_two_chars_heavy_test_ok.parse: \
  ../programs/apps/sendmail/CVE-1999-0047/mime7to8/mime7to8_ptr_two_chars_heavy_test_ok.c \

programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_ptr_two_chars_med_test_bad.parse: \
  ../programs/apps/sendmail/CVE-1999-0047/mime7to8/mime7to8_ptr_two_chars_med_test_bad.c \

programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_ptr_two_chars_med_test_ok.parse: \
  ../programs/apps/sendmail/CVE-1999-0047/mime7to8/mime7to8_ptr_two_chars_med_test_ok.c \

programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_ptr_two_chars_no_test_bad.parse: \
  ../programs/apps/sendmail/CVE-1999-0047/mime7to8/mime7to8_ptr_two_chars_no_test_bad.c \

programs_apps_sendmail_CVE-1999-0047_mime7to8_mime7to8_ptr_two_chars_no_test_ok.parse: \
  ../programs/apps/sendmail/CVE-1999-0047/mime7to8/mime7to8_ptr_two_chars_no_test_ok.c \

programs_apps_sendmail_CVE-1999-0206_mime_fromqp_mime_fromqp_arr_bad.parse: \
  ../programs/apps/sendmail/CVE-1999-0206/mime_fromqp/mime_fromqp_arr_bad.c \

programs_apps_sendmail_CVE-1999-0206_mime_fromqp_mime_fromqp_arr_ok.parse: \
  ../programs/apps/sendmail/CVE-1999-0206/mime_fromqp/mime_fromqp_arr_ok.c \

programs_apps_sendmail_CVE-1999-0206_mime_fromqp_mime_fromqp_ptr_bad.parse: \
  ../programs/apps/sendmail/CVE-1999-0206/mime_fromqp/mime_fromqp_ptr_bad.c \

programs_apps_sendmail_CVE-1999-0206_mime_fromqp_mime_fromqp_ptr_ok.parse: \
  ../programs/apps/sendmail/CVE-1999-0206/mime_fromqp/mime_fromqp_ptr_ok.c \

programs_apps_sendmail_CVE-2001-0653_complete_tTflag_bad.parse: \
  ../programs/apps/sendmail/CVE-2001-0653/complete/tTflag_bad.c \
  ../programs/apps/sendmail/CVE-2001-0653/complete/my-main.c \

programs_apps_sendmail_CVE-2001-0653_complete_tTflag_bad.parse: \
  CPPFLAGS += -I ../programs/apps/sendmail/CVE-2001-0653/complete

programs_apps_sendmail_CVE-2001-0653_complete_tTflag_ok.parse: \
  ../programs/apps/sendmail/CVE-2001-0653/complete/tTflag_ok.c \
  ../programs/apps/sendmail/CVE-2001-0653/complete/my-main.c \

programs_apps_sendmail_CVE-2001-0653_complete_tTflag_ok.parse: \
  CPPFLAGS += -I ../programs/apps/sendmail/CVE-2001-0653/complete

programs_apps_sendmail_CVE-2001-0653_tTflag_tTflag_arr_one_loop_bad.parse: \
  ../programs/apps/sendmail/CVE-2001-0653/tTflag/tTflag_arr_one_loop_bad.c \

programs_apps_sendmail_CVE-2001-0653_tTflag_tTflag_arr_one_loop_ok.parse: \
  ../programs/apps/sendmail/CVE-2001-0653/tTflag/tTflag_arr_one_loop_ok.c \

programs_apps_sendmail_CVE-2001-0653_tTflag_tTflag_arr_two_loops_bad.parse: \
  ../programs/apps/sendmail/CVE-2001-0653/tTflag/tTflag_arr_two_loops_bad.c \

programs_apps_sendmail_CVE-2001-0653_tTflag_tTflag_arr_two_loops_ok.parse: \
  ../programs/apps/sendmail/CVE-2001-0653/tTflag/tTflag_arr_two_loops_ok.c \

programs_apps_sendmail_CVE-2002-0906_parse_dns_reply_parse_dns_reply_cast_bad.parse: \
  ../programs/apps/sendmail/CVE-2002-0906/parse_dns_reply/parse_dns_reply_cast_bad.c \

programs_apps_sendmail_CVE-2002-0906_parse_dns_reply_parse_dns_reply_cast_ok.parse: \
  ../programs/apps/sendmail/CVE-2002-0906/parse_dns_reply/parse_dns_reply_cast_ok.c \

programs_apps_sendmail_CVE-2002-0906_parse_dns_reply_parse_dns_reply_no_cast_bad.parse: \
  ../programs/apps/sendmail/CVE-2002-0906/parse_dns_reply/parse_dns_reply_no_cast_bad.c \

programs_apps_sendmail_CVE-2002-0906_parse_dns_reply_parse_dns_reply_no_cast_ok.parse: \
  ../programs/apps/sendmail/CVE-2002-0906/parse_dns_reply/parse_dns_reply_no_cast_ok.c \

programs_apps_sendmail_CVE-2002-1337_close_angle_close-angle_ptr_no_test_bad.parse: \
  ../programs/apps/sendmail/CVE-2002-1337/close_angle/close-angle_ptr_no_test_bad.c \

programs_apps_sendmail_CVE-2002-1337_close_angle_close-angle_ptr_no_test_ok.parse: \
  ../programs/apps/sendmail/CVE-2002-1337/close_angle/close-angle_ptr_no_test_ok.c \

programs_apps_sendmail_CVE-2002-1337_close_angle_close-angle_ptr_one_test_bad.parse: \
  ../programs/apps/sendmail/CVE-2002-1337/close_angle/close-angle_ptr_one_test_bad.c \

programs_apps_sendmail_CVE-2002-1337_close_angle_close-angle_ptr_one_test_ok.parse: \
  ../programs/apps/sendmail/CVE-2002-1337/close_angle/close-angle_ptr_one_test_ok.c \

programs_apps_sendmail_CVE-2002-1337_close_angle_close-angle_ptr_two_tests_bad.parse: \
  ../programs/apps/sendmail/CVE-2002-1337/close_angle/close-angle_ptr_two_tests_bad.c \

programs_apps_sendmail_CVE-2002-1337_close_angle_close-angle_ptr_two_tests_ok.parse: \
  ../programs/apps/sendmail/CVE-2002-1337/close_angle/close-angle_ptr_two_tests_ok.c \

programs_apps_sendmail_CVE-2002-1337_complete_crackaddr_bad.parse: \
  ../programs/apps/sendmail/CVE-2002-1337/complete/crackaddr_bad.c \

programs_apps_sendmail_CVE-2003-0161_prescan_prescan_arr_med_test_bad.parse: \
  ../programs/apps/sendmail/CVE-2003-0161/prescan/prescan_arr_med_test_bad.c \

programs_apps_sendmail_CVE-2003-0161_prescan_prescan_arr_med_test_ok.parse: \
  ../programs/apps/sendmail/CVE-2003-0161/prescan/prescan_arr_med_test_ok.c \

programs_apps_sendmail_CVE-2003-0161_prescan_prescan_arr_min_test_bad.parse: \
  ../programs/apps/sendmail/CVE-2003-0161/prescan/prescan_arr_min_test_bad.c \

programs_apps_sendmail_CVE-2003-0161_prescan_prescan_arr_min_test_ok.parse: \
  ../programs/apps/sendmail/CVE-2003-0161/prescan/prescan_arr_min_test_ok.c \

programs_apps_sendmail_CVE-2003-0681_buildfname_buildfname_arr_one_gecos_bad.parse: \
  ../programs/apps/sendmail/CVE-2003-0681/buildfname/buildfname_arr_one_gecos_bad.c \

programs_apps_sendmail_CVE-2003-0681_buildfname_buildfname_arr_one_gecos_ok.parse: \
  ../programs/apps/sendmail/CVE-2003-0681/buildfname/buildfname_arr_one_gecos_ok.c \

programs_apps_sendmail_CVE-2003-0681_buildfname_buildfname_arr_two_gecos_bad.parse: \
  ../programs/apps/sendmail/CVE-2003-0681/buildfname/buildfname_arr_two_gecos_bad.c \

programs_apps_sendmail_CVE-2003-0681_buildfname_buildfname_arr_two_gecos_ok.parse: \
  ../programs/apps/sendmail/CVE-2003-0681/buildfname/buildfname_arr_two_gecos_ok.c \

programs_apps_sendmail_CVE-2003-0681_complete_util_bad.parse: \
  ../programs/apps/sendmail/CVE-2003-0681/complete/util_bad.c \

programs_apps_SpamAssassin_BID-6679_message_write_loop_bad.parse: \
  ../programs/apps/SpamAssassin/BID-6679/message_write/loop_bad.c \

programs_apps_SpamAssassin_BID-6679_message_write_loop_ok.parse: \
  ../programs/apps/SpamAssassin/BID-6679/message_write/loop_ok.c \

programs_apps_wu-ftpd_CVE-1999-0368_realpath-curpath_simple_bad.parse: \
  ../programs/apps/wu-ftpd/CVE-1999-0368/realpath-curpath/simple_bad.c \
  ../programs/apps/wu-ftpd/CVE-1999-0368/wu-ftpd.c \

programs_apps_wu-ftpd_CVE-1999-0368_realpath-curpath_simple_ok.parse: \
  ../programs/apps/wu-ftpd/CVE-1999-0368/realpath-curpath/simple_ok.c \
  ../programs/apps/wu-ftpd/CVE-1999-0368/wu-ftpd.c \

programs_apps_wu-ftpd_CVE-1999-0368_realpath-linkpath_prefix_bad.parse: \
  ../programs/apps/wu-ftpd/CVE-1999-0368/realpath-linkpath/prefix_bad.c \

programs_apps_wu-ftpd_CVE-1999-0368_realpath-linkpath_prefix_ok.parse: \
  ../programs/apps/wu-ftpd/CVE-1999-0368/realpath-linkpath/prefix_ok.c \

programs_apps_wu-ftpd_CVE-1999-0368_realpath-linkpath_prefix_simp_bad.parse: \
  ../programs/apps/wu-ftpd/CVE-1999-0368/realpath-linkpath/prefix_simp_bad.c \

programs_apps_wu-ftpd_CVE-1999-0368_realpath-linkpath_prefix_simp_ok.parse: \
  ../programs/apps/wu-ftpd/CVE-1999-0368/realpath-linkpath/prefix_simp_ok.c \

programs_apps_wu-ftpd_CVE-1999-0368_realpath-linkpath_strcpy_strcat_bad.parse: \
  ../programs/apps/wu-ftpd/CVE-1999-0368/realpath-linkpath/strcpy_strcat_bad.c \
  ../programs/apps/wu-ftpd/CVE-1999-0368/wu-ftpd.c \

programs_apps_wu-ftpd_CVE-1999-0368_realpath-linkpath_strcpy_strcat_ok.parse: \
  ../programs/apps/wu-ftpd/CVE-1999-0368/realpath-linkpath/strcpy_strcat_ok.c \
  ../programs/apps/wu-ftpd/CVE-1999-0368/wu-ftpd.c \

programs_apps_wu-ftpd_CVE-1999-0368_realpath-namebuf_iter_ints_bad.parse: \
  ../programs/apps/wu-ftpd/CVE-1999-0368/realpath-namebuf/iter_ints_bad.c \
  ../programs/apps/wu-ftpd/CVE-1999-0368/wu-ftpd.c \
  fc_stubs.c \

programs_apps_wu-ftpd_CVE-1999-0368_realpath-namebuf_iter_ints_ok.parse: \
  ../programs/apps/wu-ftpd/CVE-1999-0368/realpath-namebuf/iter_ints_ok.c \
  ../programs/apps/wu-ftpd/CVE-1999-0368/wu-ftpd.c \
  fc_stubs.c \

programs_apps_wu-ftpd_CVE-1999-0368_realpath-namebuf_iter_ints_simp_bad.parse: \
  ../programs/apps/wu-ftpd/CVE-1999-0368/realpath-namebuf/iter_ints_simp_bad.c \
  ../programs/apps/wu-ftpd/CVE-1999-0368/wu-ftpd.c \
  fc_stubs.c \

programs_apps_wu-ftpd_CVE-1999-0368_realpath-namebuf_iter_ints_simp_ok.parse: \
  ../programs/apps/wu-ftpd/CVE-1999-0368/realpath-namebuf/iter_ints_simp_ok.c \
  ../programs/apps/wu-ftpd/CVE-1999-0368/wu-ftpd.c \
  fc_stubs.c \

programs_apps_wu-ftpd_CVE-1999-0368_realpath-namebuf_strcpy_strcat_bad.parse: \
  ../programs/apps/wu-ftpd/CVE-1999-0368/realpath-namebuf/strcpy_strcat_bad.c \

programs_apps_wu-ftpd_CVE-1999-0368_realpath-namebuf_strcpy_strcat_ok.parse: \
  ../programs/apps/wu-ftpd/CVE-1999-0368/realpath-namebuf/strcpy_strcat_ok.c \

programs_apps_wu-ftpd_CVE-2003-0466_fb_realpath_almost_simple_bad.parse: \
  ../programs/apps/wu-ftpd/CVE-2003-0466/fb_realpath/almost_simple_bad.c \
  ../programs/apps/wu-ftpd/CVE-1999-0368/wu-ftpd.c \
  fc_stubs.c \

programs_apps_wu-ftpd_CVE-2003-0466_fb_realpath_almost_simple_ok.parse: \
  ../programs/apps/wu-ftpd/CVE-2003-0466/fb_realpath/almost_simple_ok.c \
  ../programs/apps/wu-ftpd/CVE-1999-0368/wu-ftpd.c \
  fc_stubs.c \

programs_apps_wu-ftpd_CVE-2003-0466_fb_realpath_istrrchr_bad.parse: \
  ../programs/apps/wu-ftpd/CVE-2003-0466/fb_realpath/istrrchr_bad.c \
  ../programs/apps/wu-ftpd/CVE-1999-0368/wu-ftpd.c \
  fc_stubs.c \

programs_apps_wu-ftpd_CVE-2003-0466_fb_realpath_istrrchr_ok.parse: \
  ../programs/apps/wu-ftpd/CVE-2003-0466/fb_realpath/istrrchr_ok.c \
  ../programs/apps/wu-ftpd/CVE-1999-0368/wu-ftpd.c \
  fc_stubs.c \

programs_apps_wu-ftpd_CVE-2003-0466_fb_realpath_no_symlinks_bad.parse: \
  ../programs/apps/wu-ftpd/CVE-2003-0466/fb_realpath/no_symlinks_bad.c \
  ../programs/apps/wu-ftpd/CVE-1999-0368/wu-ftpd.c \
  fc_stubs.c \

programs_apps_wu-ftpd_CVE-2003-0466_fb_realpath_no_symlinks_ok.parse: \
  ../programs/apps/wu-ftpd/CVE-2003-0466/fb_realpath/no_symlinks_ok.c \
  ../programs/apps/wu-ftpd/CVE-1999-0368/wu-ftpd.c \
  fc_stubs.c \

programs_apps_wu-ftpd_CVE-2003-0466_fb_realpath_simple_bad.parse: \
  ../programs/apps/wu-ftpd/CVE-2003-0466/fb_realpath/simple_bad.c \
  ../programs/apps/wu-ftpd/CVE-1999-0368/wu-ftpd.c \

programs_apps_wu-ftpd_CVE-2003-0466_fb_realpath_simple_ok.parse: \
  ../programs/apps/wu-ftpd/CVE-2003-0466/fb_realpath/simple_ok.c \
  ../programs/apps/wu-ftpd/CVE-1999-0368/wu-ftpd.c \

programs_apps_wu-ftpd_CVE-2003-0466_fb_realpath_symlinks_bad.parse: \
  ../programs/apps/wu-ftpd/CVE-2003-0466/fb_realpath/symlinks_bad.c \
  ../programs/apps/wu-ftpd/CVE-1999-0368/wu-ftpd.c \
  fc_stubs.c \
  $(shell $(FRAMAC)-config -print-share-path)/libc/string.c \

programs_apps_wu-ftpd_CVE-2003-0466_fb_realpath_symlinks_ok.parse: \
  ../programs/apps/wu-ftpd/CVE-2003-0466/fb_realpath/symlinks_ok.c \
  ../programs/apps/wu-ftpd/CVE-1999-0368/wu-ftpd.c \
  fc_stubs.c \
  $(shell $(FRAMAC)-config -print-share-path)/libc/string.c \

# phony target to quickly check sanity: *_ok tests must have no errors,
# *_bad tests must have errors.
check:
	@./sanity-check.sh $(addsuffix /alarms.csv ,$(TARGETS))

.PHONY: check

### Epilogue. Do not modify this block. #######################################
include $(shell $(FRAMAC)-config -print-lib-path)/analysis-scripts/epilogue.mk
###############################################################################

# optional, for OSCS
-include ../../Makefile.common
