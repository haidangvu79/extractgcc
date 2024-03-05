/********Software Analysis - FY2013*************/
/*
* File Name: ptr_subtraction.c
* Defect Classification
* ---------------------
* Defect Type: Pointer related defects
* Defect Sub-type: Incorrect pointer arithmetic
*
*/

#include "HeaderFile.h"

/*
 * Types of defects: an incorrect pointer arithmetic
 * Complexity: an incorrect pointer arithmetic
 */
void ptr_subtraction_001 ()
{
	char buf1[5];
	char buf2[5];
	intptr_t offset;
	offset = buf2 - buf1; /*Tool should detect this line as error*/ /*ERROR:Incorrect pointer arithmetic*/
        sink = offset;
}

/*
 * Types of defects: an incorrect pointer arithmetic
 * Complexity: an incorrect pointer arithmetic
 */
void ptr_subtraction_002 ()
{
	int x= 10;
	int *ptr = &x;
	char *buf ;
	// Frama-C/Eva: this test, besides not corresponding to the name
	// (no pointer subtraction here), does not invoke undefined behavior.
	// A tool might decide to use a heuristic approach to detect such kinds
	// of pointer misuse, but it would lead to false positives in programs
	// which deliberately perform complex operations.
	// Here in particular, 'buf' will point at "past one" after the end
	// of the object 'x' (which can always be seen as an array with 1
	// element). Such pointers are not invalid (and necessary, e.g. in
	// loops, to indicate termination) and can be used in comparisons.
	// It cannot be _dereferenced_ without invoking UB, but it is not
	// dereferenced in this test.
	// For Frama-C, we add such a dereferencing, so that the test remains
	// useful; however, it should then probably fall under a different
	// category.
	buf= (char *)(ptr+1); /*Tool should detect this line as error*/ /*ERROR:Incorrect pointer arithmetic*//*FC-noUB*/
#ifdef __FRAMAC__
	*buf = 11; /*Tool should detect this line as error*/ /*ERROR:Incorrect pointer arithmetic*//*FC-adapted*/
#endif
}

/*
 * Types of defects: an incorrect pointer arithmetic
 * Complexity: volatile
 */
extern volatile int vflag;
void ptr_subtraction_main ()
{
	if (vflag ==1 || vflag ==888)
	{
		ptr_subtraction_001();
	}

	if (vflag ==2 || vflag ==888)
	{
		ptr_subtraction_002();
	}

}
