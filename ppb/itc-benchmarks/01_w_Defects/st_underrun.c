/********Software Analysis - FY2013*************/
/*
* File Name: data_lost.c
* Defect Classification
* ---------------------
* Defect Type: Stack related defects
* Defect Sub-type: Stack underrun
*
*/

/* (Note) The default stack reservation size used by the linker in windows XP (64bit) is 1 MB(=1048576 bytes)*/
/*	Index starts from zero*/

#include "HeaderFile.h"

/*
 * Types of defects: stack underrun
 * Complexity: When using char array
 */
void st_underrun_001 ()
{
	 char buf[10];
	 strcpy(buf, "my string");
	 int len = strlen(buf) - 1;
         // Frama-C/Eva: the actual undefined behavior happens in the while
         // condition, not in the "len--" line, as indicated in the comment
         // below.
	 while (buf[len] != 'Z') /*Tool should detect this line as error*/ /* Stack Under RUN error *//*FC-adjusted*/
	 {
		 len--;
		 /* if (buf[len] == '\0' )
			 break; */
	 }
}

/*
 * Types of defects: stack underrun
 * Complexity:-	When using structure - passed as function arguments - one function level  _
 */
typedef struct {
	char buf[10];
	char buf1[10];
	char buf2[10];
	char buf3[10];
	char buf4[10];
	char buf5[10];
	char buf6[10];
} st_underrun_002_s_001;

void st_underrun_002_func_001 (st_underrun_002_s_001 s)
{

	 int len = strlen(s.buf) - 1;
	 for (;s.buf[len] != 'Z';len--)/*Tool should detect this line as error*/ /* Stack Under RUN error */
	 {
		 /* if (s.buf[len] == '\0')
			break; */
	 }
}

void st_underrun_002 ()
{
	st_underrun_002_s_001 s;
	strcpy(s.buf,"STRING");
	st_underrun_002_func_001(s);
}

/*
 * Types of defects: stack underrun
 * Complexity: When using structure - passed as function arguments - pointer to structure - 2 function Level
 */
typedef struct {
	char buf[10];
	char buf1[10];
	char buf2[10];
	char buf3[10];
	char buf4[10];
} st_underrun_003_s_001;

void st_underrun_003_func_001 (st_underrun_003_s_001 *s)
{
	char buf[10] = "STRING";
	strcpy(s->buf,buf);
}

void st_underrun_003_func_002 (st_underrun_003_s_001 *s)
{
	 int len = strlen(s->buf) - 1;
	 do
	 {
		 s->buf[len] = 'A';
		 len--;
		 /* if (s->buf[len] == '\0')
			 break; */
	 }while (s->buf[len] != 'Z');/*Tool should detect this line as error*/ /* Stack Under RUN error */
}

void st_underrun_003 ()
{
	st_underrun_003_s_001 s;
	st_underrun_003_func_001(&s);
	st_underrun_003_func_002(&s);
}

/*
 * Types of defects: stack underrun
 * Complexity: When using structure - passed as function arguments - pointer to structure -, return structure -3 function Level
 */
typedef struct {
	char buf[10];
	char buf1[10];
	char buf2[10];
} st_underrun_004_s_001;

void st_underrun_004_func_002 (st_underrun_004_s_001 *s)
{
	char buf[10] = "STRING";
	strcpy(s->buf,buf);
}

st_underrun_004_s_001 st_underrun_004_func_001 (st_underrun_004_s_001 *s)
{
	st_underrun_004_s_001 s1;
	st_underrun_004_func_002(s);
	int len = strlen(s->buf) - 1;
	 do
	 {
		 s->buf[len] = 'B';
		 s1.buf[len] = s->buf[len];
		 len--;
		 /* if (s->buf[len] == '\0')
			 break; */
	 }while (s->buf[len] != 'Z');/*Tool should detect this line as error*/ /* Stack Under RUN error */
	 return s1;
}

void st_underrun_004 ()
{
	st_underrun_004_s_001 s,s2;
	s2 = st_underrun_004_func_001(&s);
}

/*
 * Types of defects: stack underrun
 * Complexity: Stack under run when using	Recursive function	9 Level	__ __ __ __ __ __ __ __ __ __
 */
typedef struct {
	char buf[10];
} st_underrun_005_s_001;

void st_underrun_005_func_001 (st_underrun_005_s_001 s, int cnt)
{
	while (s.buf[cnt] != 'Z' )
	{
		cnt--;
		if(cnt>0)
		{
			st_underrun_005_func_001(s, cnt);
		}
	    else
	    {
	    	/*break;*/ /*Tool should detect this line as error*/ /* Stack Under RUN error *//*FC-disabled*/
			s.buf[cnt] = 'C';
		}
	}
}

// Frama-C/Eva: test skipped due to recursive call
void st_underrun_005 ()
{
	char buf[10];
	st_underrun_005_s_001 s;
	strcpy(s.buf,"STRING !");
	st_underrun_005_func_001(s,8);
	buf[0] = s.buf[1];
}

/*
 * Types of defects: stack underrun
 * Complexity:-	Stack under run when using Function pointer	Level 1	__
 */
typedef struct {
	char buf[10];
	char buf1[10];
	char buf2[10];
	char buf3[10];
	char buf4[10];
	char buf5[10];
	char buf6[10];
} st_underrun_006_s_001;

void st_underrun_006_func_001 (st_underrun_006_s_001 s)
{

	 int len = strlen(s.buf) - 1;
	 char c;
	 for (;s.buf[len] != 'Z';len--) /*Tool should detect this line as error*/ /* Error: Stack Under RUN error */
	 {
         c = s.buf[len];
		 /*if (0)
			 break;*/
	 }
}

void st_underrun_006 ()
{
	st_underrun_006_s_001 s;
	strcpy(s.buf,"STRING !!!!");
	void (*func)(st_underrun_006_s_001);
	func = st_underrun_006_func_001;
	func(s);
}

/*
 * Types of defects: stack underrun
 * Complexity: Stack under run in a function called form else condition
 */
typedef struct {
	char buf[10];
	char buf1[10];
	char buf2[10];
	char buf3[10];
	char buf4[10];
	char buf5[10];
} st_underrun_007_s_001;

// Frama-C/Eva: the test below is modified since it contains possible undefined
// behavior which happens before the line where an error is expected:
// s->buf is declared in the stack _without initialization_ and its first
// character is initialized to 1.
// The call to strlen(s->buf) thus potentially triggers undefined behavior:
// there is no guarantee any of the characters in the buffer will contain a
// `\0'. Our patch ensures its length is exactly 1.
// Finally, note that the error happens in the for condition, and not in the
// indicated line: len (initially 0) is tested, then c = s->buf[0] happens,
// then len is decremented and _tested_ before entering the loop body, and
// that is where the underrun takes place.
void st_underrun_007_func_001 (st_underrun_007_s_001 *s)
{
#ifdef __FRAMAC__
	 // Frama-C/Eva: fix to avoid undefined behavior (see comment above)
	 s->buf[1] = 0;
#endif
	 int len = strlen(s->buf) - 1;
	 char c;
	 // Frama-C/Eva: the actual undefined behavior happens when testing the
	 // loop condition, just after decrementing len, and not inside the
	 // loop, as in the original comment
	 for (;s->buf[len] != 'Z';len--) /*Tool should detect this line as error*/ /* Stack Under RUN error *//*FC-adjusted*/
	 {
        c = s->buf[len];
		 /*if (s->buf[len] == '\0')
			 break;*/
	 }
}

void st_underrun_007_func_002 (st_underrun_007_s_001 s)
{
	s.buf[0] = 1;
}

void st_underrun_007 ()
{
	int flag = 0;
	st_underrun_007_s_001 s;
	s.buf[0] = 1;
	if (flag >1 )
	{
		st_underrun_007_func_002(s);
	}
	else
	{
		st_underrun_007_func_001(&s);
	}
}

/*
 * Types of defects: stack underrun
 * Complexity: stack underrun main function
 */

extern volatile int vflag;
void st_underrun_main ()
{
	if (vflag == 1 || vflag ==888)
	{
		st_underrun_001();
	}

	if (vflag == 2 || vflag ==888)
	{
		st_underrun_002();
	}

	if (vflag == 3 || vflag ==888)
	{
		st_underrun_003();
	}

	if (vflag == 4 || vflag ==888)
	{
		st_underrun_004();
	}

        // Frama-C/Eva: test skipped due to usage of recursive call;
        // Eva does not yet support recursive functions.
#ifndef __FRAMAC__
	if (vflag == 5 || vflag ==888)
	{
		st_underrun_005();
	}
#endif

	if (vflag == 6 || vflag ==888)
	{
		st_underrun_006();
	}

	if (vflag == 7 || vflag ==888)
	{
		st_underrun_007();
	}
}
