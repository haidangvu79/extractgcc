/********Software Analysis - FY2013*************/
/*
* File Name: pow_related_errors.c
* Defect Classification
* ---------------------
* Defect Type: Numerical defects
* Defect Sub-type: Power related errors
* Description: Defect Free Code to identify false positives in power related errors
*/

/*
* Types of defects: Errors related to power functions
* Complexity: Very high values of number and exponent results in overflow of the answer
* * MAX VALUE of INT & LONG 2147483647 , unsigned INT & LONG 4294967295
*/
#include "HeaderFile.h"

// Frama-C/Eva: most of these tests incorrectly use the '^' bitwise XOR
// operator as if it were an exponentiation operator, or some sort of
// scientific notation.
// We replace all values with their corresponding values
// (e.g. "10^2" becomes "1e2").
// However, it is also apparent, from the test comments and the errors incurred
// from using those values, that the negative exponents were somehow lost;
// several test cases which mention "very small exponents" were actually
// written as "10^3" instead of "10^-3" (possibly because this kind of error
// was caught by the parser?); which means that it is necessary to manually
// read each comment (hoping there are not too many copy/pasting errors)
// to see which number was meant. Even in that case, it is sometimes necessary
// to adjust the actual values to avoid overflows/underflows.

// Frama-C/Eva: in all of these tests, we replace the calls to pow() with
// calls to titcb_pow(); see the corresponding file in 01_w_Defects for
// more details.
#ifdef __FRAMAC__
#define pow(x,y) titcb_pow(x,y)
#endif


/*
* Types of defects: Errors related to power functions
* Complexity: Very high values of number and exponent results in overflow of the answer
*/

void pow_related_errors_001()
{

	double num=1e2;
	double exponent=1e2;
	double ans;
	ans=pow(num,exponent); /*Tool should not detect this line as error*/ /*No ERROR:Data Overflow*/
        dsink = ans;
}
 
/*
* Types of defects: Errors related to power functions
* Complexity: Number not a double
*/

void pow_related_errors_002()
{
	double num=1.004;
	double exponent=3;
	double ans;
	ans=pow(num,exponent); /*Tool should not detect this line as error*/ /*No ERROR:Data Overflow*/
        dsink = ans;

}

/*
* Types of defects: Errors related to power functions
* Complexity: One of the elements in an array is out of bounds
* which causes the answer to go out of bounds
*/

void pow_related_errors_003()
{
	double arr[]={2.0,1.2,3.9,1e3,4.0};
	int i;
	double exponent=2;
	double ans;

	for(i=0;i<(sizeof(arr)/sizeof(double));i++)
	{
		ans=pow(arr[i],exponent); /*Tool should not detect this line as error*/ /*No ERROR:Data Overflow*/
	}
        dsink = ans;
}

/*
* Types of defects: Errors related to power functions
* Complexity: Usage of double pointers in pow function
*/

void pow_related_errors_004()
{
	double arr[]={2.0,1.2,3.9,1e3,4.0};
	double* arr1=arr;
	double **arr2=&arr1;	
	double exponent=2;
	int i;
	double ans;

	for(i=0;i<(sizeof(arr)/sizeof(double));i++)
	{
		double temp=*(*arr2+i);
		ans=pow(temp,exponent); /*Tool should not detect this line as error*/ /*No ERROR:Data Overflow*/
	}
        dsink = ans;
}

/*
* Types of defects: Errors related to power functions
* Complexity: Usage of pointers to access array elements
*/

void pow_related_errors_005()
{
	double arr[]={2.0,1.2,3.9,1e3,4.0};
	double* arr1=arr;
	double exponent=2;
	int i;
	double ans;

	for(i=0;i<(sizeof(arr)/sizeof(double));i++)
	{
		double temp=arr1[i];
		ans=pow(temp,exponent); /*Tool should not detect this line as error*/ /*No ERROR:Data Overflow*/
	}
        dsink = ans;

}

/*
* Types of defects: Errors related to power functions
* Complexity: Usage of a function which returns a very high value causing the result to overflow
*/

double pow_related_errors_006_func_001()
{
	return 1e3;

}

void pow_related_errors_006()
{
	double exponent=2.0;	
	double ans;
	ans=pow(pow_related_errors_006_func_001(),exponent); /*Tool should not detect this line as error*/ /*No ERROR:Data Overflow*/
        dsink = ans;

}

/*
* Types of defects: Errors related to power functions
* Complexity: Usage of an element in the structure which returns a very high value causing the result to overflow
*/

typedef struct
{
	double arr[1];
}pow_related_errors_007_s;

void pow_related_errors_007()
{
	double exponent=2;
	double ans;
	double ans1;
	pow_related_errors_007_s* newarr = (pow_related_errors_007_s *)malloc(sizeof(pow_related_errors_007_s));
	pow_related_errors_007_s* ptr_newarr =(pow_related_errors_007_s *)malloc(sizeof(pow_related_errors_007_s));
	newarr->arr[0]=1000;
	ptr_newarr->arr[0]=1000;
	ans=pow(newarr->arr[0],exponent);
	ans1=pow(ptr_newarr->arr[0],exponent); /*Tool should not detect this line as error*/ /*No ERROR:Data Overflow*/
	free(newarr);
	free(ptr_newarr);
        dsink = ans + ans1;
}


/*
* Types of defects: Errors related to power functions
* Complexity: When the base is negative and the exponent is positive
*/

void pow_related_errors_008()
{
	double exponent=2;
	double base=-34.50;
	double ans;
	ans=pow(base,exponent); /*Tool should not detect this line as error*/ /*No ERROR:Data Overflow*/
        dsink = ans;

}

/*
* Types of defects: Errors related to power functions
* Complexity: When the base is negative and the exponent is negative
*/

void pow_related_errors_009()
{
	double exponent=-2.4;
	double base=-34.50;
	double ans;
	// Frama-C/Eva: this test is, at the very least, surprising:
	// it generates a NaN. We would expect such cases to be marked as
	// defects, given that infinities are considered so.
	// Frama-C currently does not have a way to signal infinities but
	// not NaNs (the opposite can be done with option
        // "-warn-special-float non-finite"), so we disable this test.
	ans=pow(base,exponent); /*Tool should not detect this line as error*/ /*No ERROR:Data Overflow*//*FC-disabled*/
        dsink = ans;
}

/*
* Types of defects: Errors related to power functions
* Complexity: When the base is a small positive number and the exponent is positive
*/

void pow_related_errors_010()
{
	double exponent=2.4;
	double base=0.565;
	double ans;
	ans=pow(base,exponent); /*Tool should not detect this line as error*/ /*No ERROR:Data Overflow*/
        dsink = ans;
}

/*
* Types of defects: Errors related to power functions
* Complexity: When the base is a small positive number and the exponent is negative
*/

void pow_related_errors_011()
{
	double exponent=-2.4;
	double base=0.565;
	double ans;
	ans=pow(base,exponent); /*Tool should not detect this line as error*/ /*No ERROR:Data Overflow*/
        dsink = ans;
}

/*
* Types of defects: Errors related to power functions
* Complexity: Very small base and even exponent greater than 1
*/

void pow_related_errors_012()
{
	double base=-0.36;
	// Frama-C/Eva: the original value leads to underflow; we fixed it
	//double exponent=20000;
	double exponent=20;

	double ans;
	ans=pow(base,exponent); /*Tool should not detect this line as error*/ /*No ERROR:Data Overflow*/
        dsink = ans;
}

/*
* Types of defects: Errors related to power functions
* Complexity: Very small negative base and odd exponent greater than 1
*/

void pow_related_errors_013()
{
	double base=-0.36;
	// Frama-C/Eva: the original value leads to underflow and does
	// not match the comment; we fixed it
	//double exponent=2000;
	double exponent=21;

	double ans;
	ans=pow(base,exponent); /*Tool should not detect this line as error*/ /*No ERROR:Data Overflow*/
        dsink = ans;
}

/*
* Types of defects: Errors related to power functions
* Complexity: Very small base and odd exponent greater than 1
*/

void pow_related_errors_014()
{
	double base=0.36;
	// Frama-C/Eva: the original value leads to underflow; we fixed it
	//double exponent=21000;
	double exponent=21;

	double ans;
	ans=pow(base,exponent); /*Tool should not detect this line as error*/ /*No ERROR:Data Overflow*/
        dsink = ans;
}

/*
* Types of defects: Errors related to power functions
* Complexity: Very large negative base and odd exponent greater than 1
*/

void pow_related_errors_015()
{
	// Frama-C/Eva: the original value (-10^36) test clearly overflows;
	// the value was adjusted to a smaller number to avoid generating
	// an error.
	double base=-1e6;
	double exponent=21;

	double ans;
	ans=pow(base,exponent); /*Tool should not detect this line as error*/ /*No ERROR:Data Overflow*/
        dsink = ans;
}

/*
* Types of defects: Errors related to power functions
* Complexity: Very large positive base and odd exponent greater than 1
*/

void pow_related_errors_016()
{
	double base=1e3;
	// Frama-C/Eva: the original value is wrong; it does not match the
	// comment and it causes an overflow. We replaced it with the
	// value from the previous test.
	//double exponent=20000;
	double exponent=21;

	double ans;
	ans=pow(base,exponent); /*Tool should not detect this line as error*/ /*No ERROR:Data Overflow*/
        dsink = ans;
}

/*
* Types of defects: Errors related to power functions
* Complexity: Very large positive base and very small negative exponent
*/

void pow_related_errors_017()
{
	double base=1e3;
	double exponent=-1e-3;

	double ans;
	ans=pow(base,exponent); /*Tool should not detect this line as error*/ /*No ERROR:Data Overflow*/
        dsink = ans;
}

/*
* Types of defects: Errors related to power functions
* Complexity: Very small negative base and very small negative exponent
*/

void pow_related_errors_018()
{
	double base=-1e-3;
	double exponent=-8e-3;

	double ans;
	// Frama-C/Eva: this test produces a NaN and has been disabled
	// it generates a NaN. We would expect such cases to be marked as
	// defects, given that infinities are considered so.
	// Frama-C currently does not have a way to signal infinities but

	ans=pow(base,exponent); /*Tool should not detect this line as error*/ /*No ERROR:Data Overflow*/
        dsink = ans;
}

/*
* Types of defects: Errors related to power functions
* Complexity: Very small positive base and very small negative exponent
*/

void pow_related_errors_019()
{
	double base=0.0004;
	double exponent=-1e-3;

	double ans;
	ans=pow(base,exponent); /*Tool should not detect this line as error*/ /*No ERROR:Data Overflow*/
        dsink = ans;
}

/*
* Types of defects: Errors related to power functions
* Complexity: Very small negative base and very small negative exponent
*/

// Frama-C/Eva: the same comment is present in test 018. Because we do do not
// know the exact intended values, we assume this test is supposed to produce
// a NaN, and is therefore disabled for Frama-C/Eva (see comment in test 009).

void pow_related_errors_020()
{
	double base=-0.0004;
	double exponent=-1e-3;

	double ans;
	ans=pow(base,exponent); /*Tool should not detect this line as error*/ /*No ERROR:Data Overflow*//*FC-disabled*/
        dsink = ans;
}

/*
* Types of defects: Errors related to power functions
* Complexity: Positive base and very small odd negative exponent
*/

void pow_related_errors_021()
{
	double base=100;
	double exponent=-1e-3;

	double ans;
	ans=pow(base,exponent); /*Tool should not detect this line as error*/ /*No ERROR:Data Overflow*/
        dsink = ans;
}

/*
* Types of defects: Errors related to power functions
* Complexity: Very small negative base and very small odd negative exponent
*/

// Frama-C/Eva: test disabled (see comment in test 009).

void pow_related_errors_022()
{
	double base=-100;
	double exponent=-1e-3;

	double ans;
	ans=pow(base,exponent); /*Tool should not detect this line as error*/ /*No ERROR:Data Overflow*//*FC-disabled*/
        dsink = ans;
}

/*
* Types of defects: Errors related to power functions
* Complexity: Very small positive base and very small odd negative exponent
*/

void pow_related_errors_023()
{
	double base=0.0004;
	double exponent=-1e-3;

	double ans;
	ans=pow(base,exponent); /*Tool should not detect this line as error*/ /*No ERROR:Data Overflow*/
        dsink = ans;
}

/*
* Types of defects: Errors related to power functions
* Complexity: Very small negative base and very small odd negative exponent
*/

// Frama-C/Eva: test disabled (see comment in test 009).

void pow_related_errors_024()
{
	double base=-0.0004;
	double exponent=-1e-3;

	double ans;
	ans=pow(base,exponent); /*Tool should not detect this line as error*/ /*No ERROR:Data Overflow*//*FC-disabled*/
        dsink = ans;
}

/*
* Types of defects: Errors related to power functions
* Complexity: Very small negative base and very small odd negative exponent
*/

void pow_related_errors_025()
{
	double base=1e3;
	double exponent=0.04;

	double ans;
	ans=pow(base,exponent); /*Tool should not detect this line as error*/ /*No ERROR:Data Overflow*/
        dsink = ans;
}

/*
* Types of defects: Errors related to power functions
* Complexity: Large base and large exponent together can lead to overflow
*/

void pow_related_errors_026()
{
	double base=1e12;
	double exponent=7;

	double ans;
	ans=pow(base,exponent); /*Tool should not detect this line as error*/ /*No ERROR:Data Overflow*/
        dsink = ans;
}

/*
* Types of defects: Errors related to power functions
* Complexity: Small base and large odd exponent together can lead to underflow
*/

void pow_related_errors_027()
{
	double base=-1e10;
	double exponent=7;

	double ans;
	ans=pow(base,exponent); /*Tool should not detect this line as error*/ /*No ERROR:Data Overflow*/
        dsink = ans;
}

/*
* Types of defects: Errors related to power functions
* Complexity: Small base and very small negative exponent together can lead to overflow
*/

void pow_related_errors_028()
{
	double base=-1e2;
	double exponent=-7;

	double ans;
	ans=pow(base,exponent); /*Tool should not detect this line as error*/ /*No ERROR:Data Overflow*/
        dsink = ans;
}

/*
* Types of defects: Errors related to power functions
* Complexity: Very Small negative base and very small exponent together can lead to underflow
*/

// Frama-C/Eva: the comment above is mathematically wrong. Following the
// table of corner cases of the function pow() present in the TITCB
// specification, we see that this case corresponds to "complex numbers",
// which in practice means NaN.
// This test has also been disabled.

void pow_related_errors_029()
{
	double base=-1e-3;
	double exponent=-1e-3;

	double ans;
	ans=pow(base,exponent); /*Tool should not detect this line as error*/ /*No ERROR:Data Overflow*//*FC-disabled*/
        dsink = ans;
}

/*
* Types of defects: Errors related to power functions
* Complexity: power function main
*/
extern volatile int vflag;
void pow_related_errors_main ()
{
	if (vflag ==1 || vflag ==888)
	{
		pow_related_errors_001();
	}

	if (vflag ==2 || vflag ==888)
	{
		pow_related_errors_002();
	}

	if (vflag ==3 || vflag ==888)
	{
		pow_related_errors_003();
	}

	if (vflag ==4 || vflag ==888)
	{
		pow_related_errors_004();
	}

	if (vflag ==5 || vflag ==888)
	{
		pow_related_errors_005();
	}

	if (vflag ==6 || vflag ==888)
	{
		pow_related_errors_006();
	}

	if (vflag ==7 || vflag ==888)
	{
		pow_related_errors_007();
	}

	if (vflag ==8 || vflag ==888)
	{
		pow_related_errors_008();
	}

// Frama-C/Eva: test disabled (see comment near test)
#ifndef __FRAMAC__
	if (vflag ==9 || vflag ==888)
	{
		pow_related_errors_009();
	}
#endif

	if (vflag ==10 || vflag ==888)
	{
		pow_related_errors_010();
	}

	if (vflag ==11 || vflag ==888)
	{
		pow_related_errors_011();
	}

	if (vflag ==12 || vflag ==888)
	{
		pow_related_errors_012();
	}

	if (vflag ==13 || vflag ==888)
	{
		pow_related_errors_013();
	}

	if (vflag ==14 || vflag ==888)
	{
		pow_related_errors_014();
	}

	if (vflag ==15 || vflag ==888)
	{
		pow_related_errors_015();
	}

	if (vflag ==16 || vflag ==888)
	{
		pow_related_errors_016();
	}

	if (vflag ==17 || vflag ==888)
	{
		pow_related_errors_017();
	}

// Frama-C/Eva: test disabled (see comment near test)
#ifndef __FRAMAC__
	if (vflag ==18 || vflag ==888)
	{
		pow_related_errors_018();
	}
#endif

	if (vflag ==19 || vflag ==888)
	{
		pow_related_errors_019();
	}

// Frama-C/Eva: test disabled (see comment near test)
#ifndef __FRAMAC__
	if (vflag ==20 || vflag ==888)
	{
		pow_related_errors_020();
	}
#endif

	if (vflag ==21 || vflag ==888)
	{
		pow_related_errors_021();
	}

// Frama-C/Eva: test disabled (see comment near test)
#ifndef __FRAMAC__
	if (vflag ==22 || vflag ==888)
	{
		pow_related_errors_022();
	}
#endif

	if (vflag ==23 || vflag ==888)
	{
		pow_related_errors_023();
	}

// Frama-C/Eva: test disabled (see comment near test)
#ifndef __FRAMAC__
	if (vflag ==24 || vflag ==888)
	{
		pow_related_errors_024();
	}
#endif

	if (vflag ==25 || vflag ==888)
	{
		pow_related_errors_025();
	}

	if (vflag ==26 || vflag ==888)
	{
		pow_related_errors_026();
	}

	if (vflag ==27 || vflag ==888)
	{
		pow_related_errors_027();
	}

	if (vflag ==28 || vflag ==888)
	{
		pow_related_errors_028();
	}

// Frama-C/Eva: test disabled (see comment near test)
#ifndef __FRAMAC__
	if (vflag ==29 || vflag ==888)
	{
		pow_related_errors_029();
	}
#endif

}
