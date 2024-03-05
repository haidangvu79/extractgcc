/********Software Analysis - FY2013*************/
/*
* File Name: pow_related_errors.c
* Defect Classification
* ---------------------
* Defect Type: Numerical defects
* Defect Sub-type: Power related errors
*
*/

/*
* Types of defects: Errors related to power functions
* Complexity: Very high values of number and exponent results in overflow of the answer
* * MAX VALUE of INT & LONG 2147483647 , unsigned INT & LONG 4294967295
*/
#include "HeaderFile.h"

// Frama-C/Eva: in all of these tests, we replace the calls to pow() with
// calls to titcb_pow(); the only difference between them is an extra ACSL
// specification which reports as errors the cases where the base is non-zero
// and the result is zero ("losing precision", as written in the benchmark
// specification). This allows detecting the cases which are not considered as
// problematic in the Frama-C standard library specification.
#ifdef __FRAMAC__
#define pow(x,y) titcb_pow(x,y)
#endif

/*
* Types of defects: Errors related to power functions
* Complexity: Very high values of number and exponent results in overflow of the answer
*/

void pow_related_errors_001()
{

	// Frama-C/Eva: this test exhibits some misunderstanding of the C
	// syntax: the '^' operator is not "exponentiation", but bitwise XOR.
	// The numbers below are actually 3170 and 47, written in a confusing
	// and surely unintentional way. When given to `pow`, they result in a
	// finite number, without overflow. We fixed them to correspond to
	// large but finite numbers. Note that the original value for `num`
	// does not even fit in a double and would result in positive infinity.
	//double num=10^3700;
	//double exponent=10^37;
	double num=1e307;
	double exponent=1e37;
	double ans;
	ans=pow(num,exponent); /*Tool should detect this line as error*/ /*ERROR:Data Overflow*//*FC-alarm-but-noUB*/
        dsink = ans;

}

/*
* Types of defects: Errors related to power functions
* Complexity: Number not a double
*/

void pow_related_errors_002()
{
	float num=1.004;
	int exponent=3;
	double ans;
	// Frama-C/Eva: there is no undefined behavior here, and to detect this
	// as an error, a tool would just need to obtain typing information,
	// and override the standard C semantics, which states that, when an
	// integer is given to a function expecting a floating-point number,
	// an implicit conversion takes place and, in this case, there is no
	// information loss nor overflow. Note that there _is_ an undefined
	// behavior related to float-integer conversions, but it happens when
	// a floating-point number is converted into an integer, and its
	// truncated value is not representable in the integer range.
	// This is not at all what happens here.
	ans=pow(num,exponent); /*Tool should detect this line as error*/ /*ERROR:Data Overflow*//*FC-noUB*/
        dsink = ans;

}

/*
* Types of defects: Errors related to power functions
* Complexity: One of the elements in an array is out of bounds
* which causes the answer to go out of bounds
*/

 void pow_related_errors_003()
{
	// Frama-C/Eva: we have yet another case of incorrect use of the `^`
	// operator, plus the fact that 1e3800 (the intended number) is too
	// large to even fit on a double. We fix both to ensure the test
	// behaves as intended.
	//double arr[]={2.0,1.2,3.9,10^3800,4.0};
	double arr[]={2.0,1.2,3.9,1e308,4.0};
	int i;
	double exponent=2;
	double ans;

	for(i=0;i<(sizeof(arr)/sizeof(double));i++)
	{
		double temp=arr[i];
		ans=pow(temp,exponent); /*Tool should detect this line as error*/ /*ERROR:Data Overflow*//*FC-alarm-but-noUB*//*FC-adapted*/
	}
        dsink = ans;
}

/*
* Types of defects: Errors related to power functions
* Complexity: Usage of double pointers in pow function
*/

void pow_related_errors_004()
{
	// Frama-C/Eva: same error as in pow_related_errors_001 (see comment).
	//double arr[]={2.0,1.2,3.9,10^3800,4.0};
	double arr[]={2.0,1.2,3.9,1e308,4.0};
	double* arr1=arr;
	double **arr2=&arr1;	
	double exponent=2;
	int i;
	double ans;

	for(i=0;i<5;i++)
	{
		double temp=*(*arr2+i);
		ans=pow(temp,exponent); /*Tool should detect this line as error*/ /*ERROR:Data Overflow*//*FC-alarm-but-noUB*//*FC-adapted*/
	}
        dsink = ans;

}

/*
* Types of defects: Errors related to power functions
* Complexity: Usage of pointers to access array elements
*/

void pow_related_errors_005()
{
	// Frama-C/Eva: same error as in pow_related_errors_001 (see comment).
	//double arr[]={2.0,1.2,3.9,10^3800,4.0};
	double arr[]={2.0,1.2,3.9,1e308,4.0};
	double* arr1=arr;
	double exponent=2;
	int i;
	double ans;

	for(i=0;i<(sizeof(arr)/sizeof(double));i++)
	{
		double temp=arr1[i];
		ans=pow(temp,exponent); /*Tool should detect this line as error*/ /*ERROR:Data Overflow*//*FC-alarm-but-noUB*//*FC-adapted*/
	}
        dsink = ans;
}

/*
* Types of defects: Errors related to power functions
* Complexity: Usage of a function which returns a very high value 
* causing the result to overflow
*/


double pow_related_errors_006_func_001()
{
	// Frama-C/Eva: same error as in pow_related_errors_001 (see comment).
	//return 10^3800;
	return 1e308;

}

void pow_related_errors_006()
{
	double exponent=2;	
	double ans;
	ans=pow(pow_related_errors_006_func_001(),exponent); /*Tool should detect this line as error*/ /*ERROR:Data Overflow*//*FC-alarm-but-noUB*//*FC-adapted*/
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

	// Frama-C/Eva: same error as in pow_related_errors_001 (see comment).
	// Note that, from the error message below, we reverse-engineer that
	// the first call to pow() must _not_ fail, so we provide a suitable
	// alue for newarr->arr[0].
	//newarr->arr[0]=10^3800;
	newarr->arr[0]=1e154;
	// Frama-C/Eva: same error as in pow_related_errors_001 (see comment).
	//ptr_newarr->arr[0]=10^3800;
	ptr_newarr->arr[0]=1e308;

	 ans=pow(newarr->arr[0],exponent);
	 ans1=pow(ptr_newarr->arr[0],newarr->arr[0]);/*Tool should detect this line as error*/ /*ERROR:Data Overflow*//*FC-alarm-but-noUB*//*FC-adapted*/
	free(newarr);
	free(ptr_newarr);
        dsink = ans + ans1;
}

/*
* Types of defects: Errors related to power functions
* Complexity: Large positive base and exponent greater than 1
*/

void pow_related_errors_008()
{
	// Frama-C/Eva: same error as in pow_related_errors_001 (see comment).
	//double base=10^3700;
	double base=1e307;
	double exponent=2;

	double ans;
	ans=pow(base,exponent);/*Tool should detect this line as error*/ /*ERROR:Data Overflow*//*FC-alarm-but-noUB*//*FC-adapted*/
        dsink = ans;
}

/*
* Types of defects: Errors related to power functions
* Complexity: When the base is negative and the exponent is negative
*/

void pow_related_errors_009()
{
	double base=-0.0000000000000000000000000000000000036;
	// Frama-C/Eva: there is no actual error here: the resulting value
	// is large (~1e70) but finite. We increased the exponent to force an
	// actual overflow.
	//double exponent=-2;
	double exponent=-20;

	double ans;
	ans=pow(base,exponent);/*Tool should detect this line as error*/ /*ERROR:Data Overflow*//*FC-alarm-but-noUB*//*FC-adapted*/
        dsink = ans;
}

/*
* Types of defects: Errors related to power functions
* Complexity: Very small base and exponent greater than 1
*/

void pow_related_errors_010()
{
	double base=0.0000000000000000000000000000000000036;
	double exponent=20000;

	double ans;
	ans=pow(base,exponent);/*Tool should detect this line as error*/ /*ERROR:Data Overflow*//*FC-alarm-but-noUB*/
        dsink = ans;
}

/*
* Types of defects: Errors related to power functions
* Complexity: Very small base and exponent greater than 1
*/

void pow_related_errors_011()
{
	double base=-0.0000000000000000000000000000000000036;
	double exponent=20000;

	double ans;
	ans=pow(base,exponent);/*Tool should detect this line as error*/ /*ERROR:Data Overflow*//*FC-alarm-but-noUB*/
        dsink = ans;
}

/*
* Types of defects: Errors related to power functions
* Complexity: Very small base and even exponent greater than 1
*/

void pow_related_errors_012()
{
	double base=-0.0000000000000000000000000000000000036;
	double exponent=20000;

	double ans;
	ans=pow(base,exponent);/*Tool should detect this line as error*/ /*ERROR:Data Overflow*//*FC-alarm-but-noUB*/
        dsink = ans;
}

/*
* Types of defects: Errors related to power functions
* Complexity: Very small negative base and odd exponent greater than 1
*/

void pow_related_errors_013()
{
	double base=-0.0000000000000000000000000000000000036;
	double exponent=2000;

	double ans;
	ans=pow(base,exponent);/*Tool should detect this line as error*/ /*ERROR:Data Overflow*//*FC-alarm-but-noUB*/
        dsink = ans;
}

/*
* Types of defects: Errors related to power functions
* Complexity: Very small base and odd exponent greater than 1
*/

void pow_related_errors_014()
{
	double base=0.0000000000000000000000000000000000036;
	double exponent=21000;

	double ans;
	ans=pow(base,exponent);/*Tool should detect this line as error*/ /*ERROR:Data Overflow*//*FC-alarm-but-noUB*/
        dsink = ans;
}

/*
* Types of defects: Errors related to power functions
* Complexity: Very large negative base and odd exponent greater than 1
*/

void pow_related_errors_015()
{
	// Frama-C/Eva: same error as in pow_related_errors_001 (see comment).
	//double base=-10^3600;
	double base=-1e306;
	double exponent=21;

	double ans;
	ans=pow(base,exponent);/*Tool should detect this line as error*/ /*ERROR:Data Overflow*//*FC-alarm-but-noUB*//*FC-adapted*/
        dsink = ans;
}

/*
* Types of defects: Errors related to power functions
* Complexity: Very large positive base and odd exponent greater than 1
*/

void pow_related_errors_016()
{
	// Frama-C/Eva: same error as in pow_related_errors_001 (see comment).
	//double base=10^36;
	double base=1e36;
	double exponent=20000;

	double ans;
	ans=pow(base,exponent);/*Tool should detect this line as error*/ /*ERROR:Data Overflow*//*FC-alarm-but-noUB*//*FC-adapted*/
        dsink = ans;
}

/*
* Types of defects: Errors related to power functions
* Complexity: Very large positive base and very small negative exponent
*/

void pow_related_errors_017()
{
	// Frama-C/Eva: same error as in pow_related_errors_001 (see comment).
	//double base=10^36;
	double base=1e36;
	//double exponent=-10^36;
	double exponent=-1e36;

	double ans;
	ans=pow(base,exponent);/*Tool should detect this line as error*/ /*ERROR:Data Overflow*//*FC-alarm-but-noUB*/
        dsink = ans;
}

/*
* Types of defects: Errors related to power functions
* Complexity: Very small negative base and very small negative exponent
*/

void pow_related_errors_018()
{
	// Frama-C/Eva: same error as in pow_related_errors_001 (see comment).
	double base=-1e36;
	//double base=-10^36;
	double exponent=-1e36;
	//double exponent=-10^36;

	double ans;
	ans=pow(base,exponent);/*Tool should detect this line as error*/ /*ERROR:Data Overflow*//*FC-alarm-but-noUB*//*FC-adapted*/
        dsink = ans;
}

/*
* Types of defects: Errors related to power functions
* Complexity: Very small positive base and very small negative exponent
*/

void pow_related_errors_019()
{
	double base=0.0004;
	// Frama-C/Eva: same error as in pow_related_errors_001 (see comment).
	//double exponent=-10^3600;
	double exponent=-1e306;

	double ans;
	ans=pow(base,exponent);/*Tool should detect this line as error*/ /*ERROR:Data Overflow*//*FC-alarm-but-noUB*//*FC-adapted*/
        dsink = ans;
}

/*
* Types of defects: Errors related to power functions
* Complexity: Very small negative base and very small negative exponent
*/

void pow_related_errors_020()
{
	double base=-0.0004;
	// Frama-C/Eva: same error as in pow_related_errors_001 (see comment).
	//double exponent=-10^3600;
	double exponent=-1e306;

	double ans;
	ans=pow(base,exponent);/*Tool should detect this line as error*/ /*ERROR:Data Overflow*//*FC-alarm-but-noUB*//*FC-adapted*/
        dsink = ans;
}

/*
* Types of defects: Errors related to power functions
* Complexity: Positive base and very small odd negative exponent
*/

void pow_related_errors_021()
{
	double base=100;
	// Frama-C/Eva: same error as in pow_related_errors_001 (see comment).
	//double exponent=-10^3500;
	double exponent=-1e305;

	double ans;
	ans=pow(base,exponent);/*Tool should detect this line as error*/ /*ERROR:Data Overflow*//*FC-alarm-but-noUB*//*FC-adapted*/
        dsink = ans;
}

/*
* Types of defects: Errors related to power functions
* Complexity: Very small negative base and very small odd negative exponent
*/

void pow_related_errors_022()
{
	double base=-100;
	// Frama-C/Eva: same error as in pow_related_errors_001 (see comment).
	//double exponent=-10^35000;
	double exponent=-1e305;

	double ans;
	ans=pow(base,exponent);/*Tool should detect this line as error*/ /*ERROR:Data Overflow*//*FC-alarm-but-noUB*//*FC-adapted*/
        dsink = ans;
}

/*
* Types of defects: Errors related to power functions
* Complexity: Very small positive base and very small odd negative exponent
*/

void pow_related_errors_023()
{
	double base=0.0004;
	// Frama-C/Eva: same error as in pow_related_errors_001 (see comment).
	//double exponent=-10^35000;
	double exponent=-1e305;

	double ans;
	ans=pow(base,exponent);/*Tool should detect this line as error*/ /*ERROR:Data Overflow*//*FC-alarm-but-noUB*//*FC-adapted*/
        dsink = ans;
}

/*
* Types of defects: Errors related to power functions
* Complexity: Very small negative base and very small odd negative exponent
*/

void pow_related_errors_024()
{
	double base=-0.0004;
	// Frama-C/Eva: same error as in pow_related_errors_001 (see comment).
	//double exponent=-10^35000;
	double exponent=-1e305;

	double ans;
	ans=pow(base,exponent);/*Tool should detect this line as error*/ /*ERROR:Data Overflow*//*FC-alarm-but-noUB*//*FC-adapted*/
        dsink = ans;
}

// Frama-C/Eva: note that the comment below is wrong (copy-pasted from the
// previous one), and because the original value "10^3300" is meaningless,
// it is not trivial to find out what was the original intent of this test.
/*
* Types of defects: Errors related to power functions
* Complexity: Very small negative base and very small odd negative exponent
*/

void pow_related_errors_025()
{
	// Frama-C/Eva: same error as in pow_related_errors_001 (see comment).
	//double base=10^3300;
	double base=1e303;
	double exponent=0.000004;

	double ans;
	// Frama-C/Eva: no actual UB here, and the test comment is wrong, so we
	// did not try to reverse engineer which values should have been used.
	ans=pow(base,exponent);/*Tool should detect this line as error*/ /*ERROR:Data Overflow*//*FC-adapted*//*FC-noUB*/
        dsink = ans;
}

/*
* Types of defects: Errors related to power functions
* Complexity: Large base and large exponent together can lead to overflow
*/

void pow_related_errors_026()
{
	// Frama-C/Eva: same error as in pow_related_errors_001 (see comment).
	//double base=10^10;
	double base=1e10;
	double exponent=7000;

	double ans;
	ans=pow(base,exponent);/*Tool should detect this line as error*/ /*ERROR:Data Overflow*//*FC-alarm-but-noUB*//*FC-adapted*/
        dsink = ans;
}

/*
* Types of defects: Errors related to power functions
* Complexity: Small base and large odd exponent together can lead to underflow
*/

void pow_related_errors_027()
{
	// Frama-C/Eva: same error as in pow_related_errors_001 (see comment).
	//double base=-100^10;
	double base=-1e100;
	double exponent=7000;

	double ans;
	ans=pow(base,exponent);/*Tool should detect this line as error*/ /*ERROR:Data Overflow*//*FC-alarm-but-noUB*//*FC-adapted*/
        dsink = ans;
}

/*
* Types of defects: Errors related to power functions
* Complexity: Small base and very small negative exponent together can lead to overflow
*/

void pow_related_errors_028()
{
	// Frama-C/Eva: same error as in pow_related_errors_001 (see comment).
	//double base=-10^10;
	double base=-1e10;
	double exponent=-7100;

	double ans;
	ans=pow(base,exponent);/*Tool should detect this line as error*/ /*ERROR:Data Overflow*//*FC-alarm-but-noUB*//*FC-adapted*/
        dsink = ans;
}

/*
* Types of defects: Errors related to power functions
* Complexity: Very Small negative base and very small exponent together can lead to underflow
*/

void pow_related_errors_029()
{
	// Frama-C/Eva: same error as in pow_related_errors_001 (see comment).
	//double base=-10^30;
	double base=-1e30;
	//double exponent=-10^3000;
	double exponent=-1e300;

	double ans;
	ans=pow(base,exponent);/*Tool should detect this line as error*/ /*ERROR:Data Overflow*//*FC-alarm-but-noUB*//*FC-adapted*/
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

	if (vflag ==9 || vflag ==888)
	{
		pow_related_errors_009();
	}

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

	if (vflag ==18 || vflag ==888)
	{
		pow_related_errors_018();
	}

	if (vflag ==19 || vflag ==888)
	{
		pow_related_errors_019();
	}

	if (vflag ==20 || vflag ==888)
	{
		pow_related_errors_020();
	}

	if (vflag ==21 || vflag ==888)
	{
		pow_related_errors_021();
	}

	if (vflag ==22 || vflag ==888)
	{
		pow_related_errors_022();
	}

	if (vflag ==23 || vflag ==888)
	{
		pow_related_errors_023();
	}

	if (vflag ==24 || vflag ==888)
	{
		pow_related_errors_024();
	}

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

	if (vflag ==29 || vflag ==888)
	{
		pow_related_errors_029();
	}

}
