/*
 ============================================================================
 Description : Main section of Test Suite, Software Analysis - FY2013 (Ansi-style)
 ============================================================================
 */

#include "HeaderFile.h"

volatile int vflag;
volatile int vflag_copy;
volatile int vflag_file;

int idx, sink;
double dsink;
void *psink;

int main(int argc,char*argv[])
{
	if(argv[1])
	{

	vflag_copy = atoi(argv[1]);
	vflag_file = (int)floor((double)vflag_copy/1000.0);
	vflag = (int)floor((int)vflag_copy%1000);
	printf("vflag_file = %d vflag_func = %d vflag_copy =%d \n" , vflag_file, vflag,vflag_copy);
	/* BitShift errors */
	if (vflag_file == 1 || vflag_file == 888)
	{
		bit_shift_main();
	}

	/* Buffer overrun(dynamic buffer) */
	if (vflag_file ==2 || vflag_file == 888)
	{
		dynamic_buffer_overrun_main ();
	}

	/* Buffer underrun(dynamic buffer) */
	if (vflag_file ==3 || vflag_file == 888)
	{
		dynamic_buffer_underrun_main();
	}

// Frama-C/Eva: tests disabled; Eva is not dedicated to this kind of syntactic
// property, which is better suited for syntactic tools such as rule checkers.
// They constitute no violation of the C standard and are not reported by Eva.
#ifndef __FRAMAC__
	/* Compared to NULL and the function address */
	if (vflag_file ==4 || vflag_file == 888)
	{
		cmp_funcadr_main();
	}
#endif

// Frama-C/Eva: tests disabled; Eva is not dedicated to this kind of syntactic
// property, which is better suited for syntactic tools such as rule checkers.
// They constitute no violation of the C standard and are not reported by Eva.
#ifndef __FRAMAC__
	/* Conflicting Condition */
	if (vflag_file ==5 || vflag_file == 888 )
	{
		conflicting_cond_main();
	}
#endif

	/* From the large size of the data type's assignment to small */
	if (vflag_file ==6 || vflag_file == 888)
	{
		data_lost_main();
	}

	/* overrun */
	if (vflag_file ==7 || vflag_file == 888)
	{
		data_overflow_main();
	}

	/* underrun */
	if (vflag_file ==8 || vflag_file == 888)
	{
		data_underflow_main();
	}

// Frama-C/Eva: tests disabled; Eva is not dedicated to this kind of syntactic
// property, which is better suited for syntactic tools such as rule checkers.
// They constitute no violation of the C standard and are not reported by Eva.
// Note that Eva does report information about dead code, but not in the form
// of warnings.
#ifndef __FRAMAC__
	/* Dead code elimination */
	if (vflag_file ==9 || vflag_file == 888)
	{
		dead_code_main();
	}
#endif

// Frama-C/Eva: tests disabled, since Frama-C/Eva does not perform
// concurrency analysis (Mthread plug-in required)
#ifndef __FRAMAC__
	/* Dead lock */
	if (vflag_file ==10 || vflag_file == 888)
	{
		dead_lock_main();
	}
#endif

// Frama-C/Eva: tests disabled; while the property itself is related to
// undefined behavior (removing `\0` at the end of a string), the tests
// do not contain any UB themselves; tools need to try and guess the intent
// of the code when reporting such errors; for instance, maybe the absence
// of a NUL terminator is intended. Also, the last test is wrong
// (it performs a string copy including the NUL terminator).
#ifndef __FRAMAC__
	/* Deletion of Structure sentinel */
	if(vflag_file==11 || vflag_file == 888)
	{
		deletion_of_data_structure_sentinel_main ();
	}
#endif

	/* Double Free*/
	if (vflag_file ==12 || vflag_file == 888)
	{
		double_free_main ();
	}

// Frama-C/Eva: tests disabled, since Frama-C/Eva does not perform
// concurrency analysis (Mthread plug-in required)
#ifndef __FRAMAC__
	/* Double lock*/
	if (vflag_file ==13 || vflag_file == 888)
	{
		double_lock_main();
	}
#endif

// Frama-C/Eva: tests disabled, since Frama-C/Eva does not perform
// concurrency analysis (Mthread plug-in required)
#ifndef __FRAMAC__
	/* Double Release*/
	if (vflag_file ==14 || vflag_file == 888)
	{
		double_release_main();
	}
#endif

// Frama-C/Eva: an endless loop is not a violation of the C standard,
// therefore Frama-C/Eva does not, by default, reports them as alarms.
// Although it is able to detect them (and the Nonterm plug-in, derived
// from Eva, can report some kinds of infinite loops), Eva is not dedicated
// to this kind of property.
// We did not disable these tests because it turns out that, in all test
// cases, there is a loop counter which leads to overflow, which is reported
// by Frama-C. In such cases, we can claim Frama-C/Eva can identify such
// kinds of unintentional infinite loops.
	/* Unintentional Endless loop */
	if (vflag_file ==15 || vflag_file == 888)
	{
		endless_loop_main();
	}

    /* free non dynamic allocated memory main */
	if(vflag_file==16 || vflag_file == 888)
	{
		free_nondynamic_allocated_memory_main ();
	}

// Frama-C/Eva: freeing a NULL pointer is explicitly allowed in the
// standard. A tool may want to report this, but it will require
// heuristics to avoid reporting legitimate uses.
// Note that several tests in this file contain actual undefined
// behaviors, where NULL pointers are dereferenced or passed as arguments
// to strcpy(). At least half of the tests contain some such unrelated UBs.
#ifndef __FRAMAC__
	/* Free NULL Pointer*/
	if (vflag_file ==17 || vflag_file == 888)
	{
		free_null_pointer_main();
	}
#endif

// Frama-C/Eva: tests disabled; the tests related to wrong function pointers contain
// some syntactic errors which prevent Frama-C from parsing the files,
// therefore they were disabled.
#ifndef __FRAMAC__
	/* Bad function pointer casting */
	if (vflag_file ==18 || vflag_file == 888)
	{
		func_pointer_main();
	}
#endif

// Frama-C/Eva: tests disabled; Eva is not dedicated to this kind of syntactic
// property. Although Frama-C can report such cases, the platform is focused
// on sound semantic analyses. There are currently no options in Eva to emit
// alarms for unused return values of functions, since they constitute no
// violation of the C standard.
#ifndef __FRAMAC__
	/* Return value of function never checked*/
	if (vflag_file ==19 || vflag_file == 888)
	{
		function_return_value_unchecked_main();
	}
#endif

	/* improper Error handling  */
	if(vflag_file==20 || vflag_file == 888)
	{
		/*This is Cpp file*/;
	}

// Frama-C/Eva: tests disabled; Eva is not dedicated to this kind of syntactic
// property, which is better suited for syntactic tools such as rule checkers.
// They constitute no violation of the C standard and are not reported by Eva.
#ifndef __FRAMAC__
	/* improper termination of block */
	if(vflag_file==21 || vflag_file == 888)
	{
		improper_termination_of_block_main ();
	}
#endif

// Frama-C/Eva: tests disabled; Eva is not dedicated to this kind of syntactic
// property, which is better suited for syntactic tools such as rule checkers.
// They constitute no violation of the C standard and are not reported by Eva.
#ifndef __FRAMAC__
	/* Useless assignment */
	if (vflag_file ==22 || vflag_file == 888)
	{
		insign_code_main();
	}
#endif

// Frama-C/Eva: tests disabled; the Frama-C kernel reports such syntactic
// issues during its "virtual link" phase, but in this test suite we focus
// on semantic properties analyzed by Eva.
#ifndef __FRAMAC__
	/* External variable type mistake */
	if (vflag_file ==23 || vflag_file == 888)
	{
		invalid_extern_main();
	}
#endif

	/* Invalid Memory Access */
	if (vflag_file ==24 || vflag_file == 888)
	{
		invalid_memory_access_main();
	}

	/* Allocate small size of memory for type struct/union (static) */
	if (vflag_file ==25 || vflag_file == 888)
	{
		littlemem_st_main();
	}

// Frama-C/Eva: tests disabled, since Frama-C/Eva does not perform
// concurrency analysis (Mthread plug-in required)
#ifndef __FRAMAC__
	/* Live Lock */
	if (vflag_file ==26 || vflag_file == 888)
	{
		livelock_main();
	}
#endif

// Frama-C/Eva: tests disabled, since Frama-C/Eva does not perform
// concurrency analysis (Mthread plug-in required)
#ifndef __FRAMAC__
	/*Lock never unlock main main*/
	if (vflag_file ==27 || vflag_file == 888)
	{
		lock_never_unlock_main();
	}
#endif

	/*Memory allocation failure main*/
	if (vflag_file ==28 || vflag_file == 888)
	{
		memory_allocation_failure_main();
	}

// Frama-C/Eva: tests disabled; note that memory leaks do not
// constitute undefined behavior. Still, it is useful to detect
// such situations; currently Eva does not report them, but it might
// do so in the future.
#ifndef __FRAMAC__
	/* Memory leak */
	if (vflag_file ==29 || vflag_file == 888)
	{
		memory_leak_main();
	}
#endif

// Frama-C/Eva: the Frama-C kernel reports such syntactic
// issues during parsing, but in this test suite we focus
// on semantic properties analyzed by Eva.
// In this case, we leave the tests since the Frama-C
// kernel already emits alarms related to missing return statements.
	/* Non void function does not return value */
	if (vflag_file ==30 || vflag_file == 888)
	{
		not_return_main();
	}

	/* NULL pointer reference (access) */
	if (vflag_file ==31 || vflag_file == 888)
	{
		null_pointer_main();
	}

	/* Buffer overruns ( static buffer ) */
	if (vflag_file ==32 || vflag_file == 888)
	{
		overrun_st_main();
	}

// Frama-C/Eva: tests disabled;
// similarly to deletion_of_data_structure_sentinel, these tests are
// related to undefined behavior (memcpy of overlapping areas), but they
// do not invoke UB in any way. They implement some loops which copy data,
// and which happen to rewrite some data which has just been written.
// To identify such cases, a tool would need to guess that the function being
// implemented is memcpy (and not memmove!), and then check for overlap.
// Note that Frama-C allows the usage of ACSL annotations to specify properties
// such as \separated(a, b), which forbid overlap of the specified memory areas.
#ifndef __FRAMAC__
	/* Copy of the overlapped area */
	if (vflag_file ==33 || vflag_file == 888)
	{
		ow_memcpy_main();
	}
#endif

// Frama-C/Eva: these tests are related to the floating-point
// function pow() and some cases which are arbitrarily defined as erroneous,
// according to the specification of the benchmark suite.
// The C standard defers such questions to the IEC 60559 standard
// (also known as IEEE 754). In particular, there are very few undefined
// behaviors related to floating-point numbers; most issues are covered by
// NaNs (not a number). For instance, the conversion of a floating-point value
// into an integer is undefined if the value is not representable (too large).
// In Frama-C, option -warn-special-float allows the detection of cases such
// as infinities and NaNs, but not underflows.
// To be able to detect all of these issues, we adapted the specification of
// function pow() available in the Frama-C standard library to include an extra
// clause to check for underflows.
	/* Power related errors */
	if(vflag_file==34 || vflag_file == 888)
	{
		pow_related_errors_main ();
	}

	/* An incorrect pointer arithmetic */
	if (vflag_file ==35 || vflag_file == 888)
	{
		ptr_subtraction_main();
	}

// Frama-C/Eva: tests disabled, since Frama-C/Eva does not perform
// concurrency analysis (Mthread plug-in required)
#ifndef __FRAMAC__
	/* Race condition */
	if (vflag_file ==36 || vflag_file == 888)
	{
		race_condition_main ();
	}
#endif

// Frama-C/Eva: tests disabled; Eva is not dedicated to this kind of syntactic
// property. The platform is focused on sound semantic analyses.
// There are currently no options in Eva to emit alarms for such redundant
// conditions, since they constitute no violation of the C standard.
#ifndef __FRAMAC__
	/* Redundant Condition */
	if (vflag_file ==37 || vflag_file == 888)
	{
		redundant_cond_main();
	}
#endif

	/* Back in the local variables (area) */
	if (vflag_file ==38 || vflag_file == 888)
	{
		return_local_main();
	}

	/* signed/unsigned The issues associated with assignment */
	if (vflag_file ==39 || vflag_file == 888)
	{
		sign_conv_main();
	}

// Frama-C/Eva: tests disabled, since Frama-C/Eva does not perform
// concurrency analysis (Mthread plug-in required)
#ifndef __FRAMAC__
	/* Sleep lock */
	if (vflag_file ==40 || vflag_file == 888)
	{
		sleep_lock_main();
	}
#endif

// Frama-C/Eva: tests disabled, since Frama-C/Eva does not perform
// concurrency analysis (Mthread plug-in required)
#ifndef __FRAMAC__
	/*Unlock without lock main*/
	if (vflag_file ==41 || vflag_file == 888)
	{
		st_cross_thread_access_main();
	}
#endif

// Frama-C/Eva: all tests related to stack overflow were disabled since
// they are hardware- and compiler-dependent:
// these tests do not violate the C standard (they contain no undefined
// behavior).
// They seem to have been coded for a specific hardware architecture
// with limited stack space and strong assumptions about code generation
// by a compiler. For instance, such assumptions include:
// - the fact that local variables are allocated on the stack;
// - the compiler is not able to optimize or randomize stack usage
//   (unlike e.g. GCC);
// - the tool has information about the available stack space,
//   and only reports an error when a stack slot is accessed
//   (instead of e.g. reporting it at the variable declaration).
// Overall, this are not suitable tests for semantics-based tools.
// Note: the C standard does not even contain the word "stack".
#ifndef __FRAMAC__
	/* Stack overflow */
	if (vflag_file ==42 || vflag_file == 888)
	{
		st_overflow_main();
	}
#endif

	/*Unlock without lock main*/
	if (vflag_file ==43 || vflag_file == 888)
	{
		st_underrun_main();
	}

	/* Buffer under run ( static buffer ) */
	if (vflag_file ==44 || vflag_file == 888)
	{
		underrun_st_main();
	}

	/* Uninitialized Memory */
	if (vflag_file ==45 || vflag_file == 888)
	{
		uninit_memory_access_main();
	}

	/* Uninitialized Pointer */
	if (vflag_file ==46 || vflag_file == 888)
	{
		uninit_pointer_main();
	}

	/* Uninitialized variable */
	if (vflag_file ==47 || vflag_file == 888)
	{
		uninit_var_main();
	}

// Frama-C/Eva: tests disabled, since Frama-C/Eva does not perform
// concurrency analysis (Mthread plug-in required)
#ifndef __FRAMAC__
	/*Unlock without lock main*/
	if (vflag_file ==48 || vflag_file == 888)
	{
		unlock_without_lock_main();
	}
#endif

// Frama-C/Eva: tests disabled; Eva is not dedicated to this kind of syntactic
// property. Although Frama-C can report such cases, the platform is focused
// on sound semantic analyses. There are currently no options in Eva to emit
// alarms for unused variables, since they constitute no violation of the
// C standard.
#ifndef __FRAMAC__
	/* Unused variable */
	if (vflag_file ==49 || vflag_file == 888)
	{
		unused_var_main();
	}
#endif

// Frama-C/Eva: source removed (contains deliberate parsing error)
#ifndef __FRAMAC__
	/* Wrong arguments passed to a function pointer*/
	if (vflag_file ==50 || vflag_file == 888)
	{
		wrong_arguments_func_pointer_main();
	}
#endif

	/* Division by zero */
	if (vflag_file ==51 || vflag_file == 888)
	{
		zero_division_main();
	}
	printf("Printed from main function ");
	}
	else
	{
		printf("Enter File XXX and Function XXX \n");
		printf("Example: To Execute 2nd File 3rd Function , Enter 002003 \n");
		printf("Example: To Execute All Files ,Enter 888888 \n");
		printf("Example: To Execute All functions in a File :Sample - To execute all functions in 3rd file,Enter 003888 \n");
	}
    return 0;
}
