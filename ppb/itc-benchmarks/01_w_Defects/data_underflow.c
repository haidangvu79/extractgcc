/********Software Analysis - FY2013*************/
/*
* File Name: data_underflow.c
* Defect Classification
* ---------------------
* Defect Type: Numerical defects
* Defect Sub-type: Data underflow
* Description: Defect Code to identify defects in data underflow in static declaration
*/

#include "HeaderFile.h"
/*
 * Types of defects: underflow
 * Complexity: int	Underflow with -2	Constant
 */
void data_underflow_001 ()
{
	int min = -2147483647;	/* 0x80000001 */
	int ret;
	ret = min - 2;/*Tool should detect this line as error*/ /*ERROR:Data Underflow*/
        sink = ret;
}

/*
 * Types of defects: underflow
 * Complexity: unsigned int	Underflow with -1	Constant
 */
void data_underflow_002 ()
{
	unsigned int min = 0;
	unsigned int ret;
	ret = min - 1;/*Tool should detect this line as error*/ /*ERROR:Data Underflow*//*FC-alarm-but-noUB*/
        sink = ret;
}

/*
 * Types of defects: underflow
 * Complexity: int	Decrement	-
 */
void data_underflow_003 ()
{
	int min = -2147483647;	/* 0x80000001 */
	int ret;
	min --;
	// Frama-C/Eva: the actual error (underflow) happens in the line below
	min --;/*Tool should detect this line as error*/ /*ERROR:Data Underflow*//*FC-adjusted*/
	ret = min;
        sink = ret;
}

/*
 * Types of defects: underflow
 * Complexity: int	underflow with -128 Constant
 */
void data_underflow_004 ()
{
	int min = -2147483521;
	int ret;
	ret = min - 128;/*Tool should detect this line as error*/ /*ERROR:Data Underflow*/
        sink = ret;
}

/*
 * Types of defects: underflow
 * Complexity: int	Multiply by underflow	Constant
 */
void data_underflow_005 ()
{
	int min = -1073741825;	/* 0xbfffffff */
	int ret;
	ret = min * 2;/*Tool should detect this line as error*/ /*ERROR:Data Underflow*/
        sink = ret;
}

/*
 * Types of defects: underflow
 * Complexity: the operands is a constant
 */
void data_underflow_006 ()
{
	int ret;
	ret = (-2147483647) - 2;/*Tool should detect this line as error*/ /*ERROR:Data Underflow*/
        sink = ret;
}

/*
 * Types of defects: underflow
 * Complexity: floating point underflow ( float )
 */
void data_underflow_007 ()
{
	float ret;

	/* 0 00000000 00000000000000000000001 */
	float min = 1.40129846e-45F;

        // Frama-C/Eva: the C standard does not consider this as an undefined
        // behavior (operation on non-zero floating-point values leading to
        // a zero floating-point value).
        // There are currently no options in Frama-C/Eva to enable this as a
        // warning, though there are analyses and plug-ins related to
        // floating-point error estimation and propagation.
	ret = min / 2.0F;/*Tool should detect this line as error*/ /*ERROR:Data Underflow*//*FC-noUB*/
        sink = ret;
}

/*
 * Types of defects: underflow
 * Complexity: floating point underflow (double)
 */
void data_underflow_008 ()
{
	double ret;

	/* 0 00000000000 0000000000000000000000000000000000000000000000000001 */
	double min = 4.9406564584124654e-324;

        // Frama-C/Eva: the C standard does not consider this as an undefined
        // behavior. See comment in data_underflow_007 for more details.
	ret = min / 2.0;/*Tool should detect this line as error*/ /*ERROR:Data Underflow*//*FC-noUB*/
        sink = ret;
}

/*
 * Types of defects: underflow
 * Complexity:  underflow (char)
 */
void data_underflow_009 ()
{
	char min = -128;	/* 0x80000002 */
	char ret;
	ret = min - 2;/*Tool should detect this line as error*/ /*ERROR:Data Underflow*//*FC-alarm-but-noUB*/
        sink = ret;
}

/*
 * Types of defects: underflow
 * Complexity: int	Underflow at The return value of the function
 */
int data_underflow_010_func_001 ()
{
	return 2;
}

void data_underflow_010 ()
{
	int min = -2147483647;
	int ret;
	ret = min - data_underflow_010_func_001(); /*Tool should detect this line as error*/ /*ERROR:Data Under*/
        sink = ret;
}

/*
 * Types of defects: underflow
 * Complexity: int	Underflow at Function arguments
 */
void data_underflow_011_func_001 (int d)
{
	int min = -2147483647;
	int ret;
	ret = min - d; /*Tool should detect this line as error*/ /*ERROR:Data Underflow*/
        sink = ret;
}

void data_underflow_011 ()
{
	data_underflow_011_func_001(2);
}

/*
 * Types of defects: Underflow
 * Complexity: int	underflow at	An array of element values
 */
void data_underflow_012 ()
{
	int min = -2147483647;
	int dlist[4] = {0, 1, -2, -1};
	int ret;
        // Frama-C/Eva: there is an error in the test: _subtracting_ a negative
        // number from a negative number leads to a larger (smaller in absolute
        // value) number, which causes no overflow. The test was patched to
        // trigger the negative overflow.
	//ret = min - dlist[2];
	ret = min + dlist[2]; /*Tool should detect this line as error*/ /*ERROR:Data underflow*//*FC-adapted*/
        sink = ret;
}

/*
 * Types of defects: underflow
 * Data underflow main function
 */
extern volatile int vflag;
void data_underflow_main ()
{
	if (vflag ==1 || vflag ==888)
	{
		data_underflow_001();
	}

	if (vflag ==2 || vflag ==888)
	{
		data_underflow_002();
	}

	if (vflag ==3 || vflag ==888)
	{
		data_underflow_003();
	}

	if (vflag ==4 || vflag ==888)
	{
		data_underflow_004();
	}

	if (vflag ==5 || vflag ==888)
	{
		data_underflow_005();
	}

	if (vflag ==6 || vflag ==888)
	{
		data_underflow_006();
	}

	if (vflag ==7 || vflag ==888)
	{
		data_underflow_007();
	}

	if (vflag ==8 || vflag ==888)
	{
		data_underflow_008();
	}

	if (vflag ==9 || vflag ==888)
	{
		data_underflow_009();
	}

	if (vflag ==10 || vflag ==888)
	{
		data_underflow_010();
	}

	if (vflag ==11 || vflag ==888)
	{
		data_underflow_011();
	}

	if (vflag ==12 || vflag ==888)
	{
		data_underflow_012();
	}
}
