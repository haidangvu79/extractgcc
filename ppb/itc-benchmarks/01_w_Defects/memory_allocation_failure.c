/********Software Analysis - FY2013*************/
/*
* File Name: memory_allocation_failure.c
* Defect Classification
* ---------------------
* Defect Type: Resource management defects
* Defect Sub-type: Memory allocation failure
* Description: memory_allocation_failure -  Memory could not be allocated / insufficient memory
*  Created on: Oct 14, 2013
*      Author: hemalatha
*/

/*
* MAX VALUE of INT & LONG 2147483647 , unsigned INT & LONG 4294967295
* MAX Heap memory in Windows 7 32 bit 2GB
*/
#include "HeaderFile.h"

#define MAX_VAL UINT_MAX

unsigned int memory_allocation_failure_005_gbl = 65536;

char * memory_allocation_failure_007_str_gbl;
typedef struct {
        int  csr;
        int  data;
}memory_allocation_failure_010_s_001;

memory_allocation_failure_010_s_001 *memory_allocation_failure_010_arr_gbl;

/*
* Type of defect: memory_allocation_failure - Memory could not be allocated / insufficient memory
* Complexity: When using a pointer to long in an infinite for loop
*/
// Frama-C/Eva: this test contains an accidental undefined behavior
// (signed overflow on the loop counter), but the intended error does not
// correspond to an undefined behavior.
// Also, the test should never fail at the indicated line inside the loop
// (if calloc succeeds, then the memory access should be valid).
// For Frama-C/Eva, we fix the unintended UB, but the test remains disabled.
void memory_allocation_failure_001 ()
{
	int i;
	long *buf;
	for (i=0;i<INT_MAX;i++)
	{
		buf=(long*) calloc(5,sizeof(long));
		if(buf !=NULL)
		{
		     buf[1]=1;/*Tool should detect this line as error*/ /*ERROR:Memory allocation failure *//*FC-noUB*/
		}
	}
}

// Frama-C/Eva: some of the errors below are related to *unsigned* overflows
// which, according to the C standard, do NOT constitute undefined behavior
// and are, therefore, not flagged by default by Frama-C.
// However, if the user does so desire, option -warn-unsigned-overflow
// allows them to be reported as errors.
// We annotate the cases below where this option is necessary.

/*
* Type of defect: memory_allocation_failure - Memory could not be allocated / insufficient memory
* Complexity: when using pointers to the type INT
*/
void memory_allocation_failure_002 ()
{
	long long int i=0;
	// Frama-C/Eva: unsigned overflow, requires option -warn-unsigned-overflow
	long long int *ptr=(long long*) malloc(MAX_VAL *sizeof(long long));/*Tool should detect this line as error*/ /*ERROR:Memory allocation failure *//*FC-alarm-but-noUB*/
	if(ptr !=NULL)
	{
	*(ptr+i) = i;
	free(ptr);
	}
}

/*
* Type of defect: memory_allocation_failure - Memory could not be allocated / insufficient memory
* Complexity: when using double pointers to the type INT
*/
 #define MAX 10
void memory_allocation_failure_003 ()
{
	unsigned int **ptr = (unsigned int**) malloc(MAX*sizeof(unsigned int*));
	unsigned int i,j;
	if(ptr!=NULL)
	for(i=0;i<MAX;i++)
		// Frama-C/Eva: unsigned overflow, requires option -warn-unsigned-overflow
		ptr[i]=(unsigned int*) malloc(MAX_VAL*sizeof(unsigned int));/*Tool should detect this line as error*/ /*ERROR:Memory allocation failure *//*FC-alarm-but-noUB*/

	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			*(*(ptr+i)+j)=i;
		}
		free(ptr[i]);
	}
	free(ptr);
}

/*
* Type of defect: memory_allocation_failure - Memory could not be allocated / insufficient memory
* Complexity: When using a pointer to unsigned int based on return value of function
*/
// Frama-C/Eva: the constant is too large for the return type; an unintended
// signed downcast will happen. We changed the return type to avoid it.
//int memory_allocation_failure_004_func_001(int flag)
unsigned memory_allocation_failure_004_func_001(int flag)
{
   //int ret =0;
   unsigned ret =0;
   if (flag ==0)
	   ret = MAX_VAL;
   else
	   ret=1;
   return ret;
}
void memory_allocation_failure_004 ()
{
	// Frama-C/Eva: unsigned overflow, requires option -warn-unsigned-overflow
	unsigned int *ptr = (unsigned int*) malloc(memory_allocation_failure_004_func_001(0)*sizeof(unsigned int));/*Tool should detect this line as error*/ /*ERROR:Memory allocation failure *//*FC-alarm-but-noUB*/
	if(ptr !=NULL)
	{
		*(ptr+1) = 10;
		free(ptr);
	}
}

/*
* Type of defect: memory_allocation_failure - Memory could not be allocated / insufficient memory
* Complexity: When using a void pointer  int based on value of global variable inside a switch case statement
*/
static void *vptr;
int memory_allocation_failure_005_func_001 (int flag)
{
	switch (flag)
	{
		case 1:
		{
			// Frama-C/Eva: unsigned overflow, requires option -warn-unsigned-overflow
			vptr = (int *)calloc(memory_allocation_failure_005_gbl*memory_allocation_failure_005_gbl, sizeof(int));/*Tool should detect this line as error*/ /*ERROR:Memory allocation failure *//*FC-alarm-but-noUB*/
			if(vptr != NULL)
			*((int*)vptr+1) = 10;
			return 1;
		}
		case 2:
		{
			vptr = (char *)calloc(10, sizeof(char));
			if(vptr != NULL)
			*((char*)vptr+2) = 'a';
			return 2;
		}
		case 3:
		{
			vptr = (float *)calloc(10, sizeof(float));
			if(vptr != NULL)
			*((float*)vptr+3) = 5.5;
			return 3;
		}
		default:
			return -1;
	}
}

void memory_allocation_failure_005 ()
{
	int ret;
	ret = memory_allocation_failure_005_func_001 (rand());
	if(ret >= 0)
		if(vptr != NULL)
		free(vptr);
}

/*
* Type of defect: memory_allocation_failure - Memory could not be allocated / insufficient memory
* Complexity: When using a double pointer to char , memory allocated and returned from a function based on return value of function
*/

#define MAX_10 429496730
int **memory_allocation_failure_006_gbl_doubleptr;
int memory_allocation_failure_006_func_001(int flag)
{
   int ret;
   if (flag ==0)
	   ret = 0;
   else
	   ret=1;
   return ret;
}

void memory_allocation_failure_006_func_002()
{
	int i;

	if(memory_allocation_failure_006_func_001(0)==0)
	{
		memory_allocation_failure_006_gbl_doubleptr=(int**) malloc(10*sizeof(int*));
    	for(i=0;i<10;i++)
	    {
    		// Frama-C/Eva: the test is intended for finite
    		// memory, in which successive allocations of very
    		// large memory blocks lead to failure. There is no
    		// undefined behavior here.
    		memory_allocation_failure_006_gbl_doubleptr[i]=(int*) malloc(MAX_10*sizeof(int));/*Tool should detect this line as error*/ /*ERROR:Memory allocation failure *//*FC-noUB*/
    		memory_allocation_failure_006_gbl_doubleptr[i][0] =10;
	    }
	}
}

void memory_allocation_failure_006()
{
	int flag=0,i;

	if(memory_allocation_failure_006_func_001(flag)==0)
	{
		memory_allocation_failure_006_func_002();
	}
    if(memory_allocation_failure_006_func_001(flag)==0)
	{
		for(i=0;i<10;i++)
		{
			if(memory_allocation_failure_006_gbl_doubleptr[i]!=NULL)
			{
     			free (memory_allocation_failure_006_gbl_doubleptr[i]);
			    memory_allocation_failure_006_gbl_doubleptr[i] = NULL;
			}
	    }
	    free(memory_allocation_failure_006_gbl_doubleptr);
	    memory_allocation_failure_006_gbl_doubleptr = NULL;
	}
}

/*
* Type of defect: memory_allocation_failure - Memory could not be allocated / insufficient memory
* Complexity: When using a global pointer to char in a for loop inside if condition
*/

// The static initializer below contains an unsigned overflow.
// This is not UB according to the C standard,
// but if the user so desires, it can be flagged as an error by Frama-C, using
// option -warn-unsigned-overflow.
// However, in this case, unlike what the test expects, the error happens
// during initialization of global variables, and not during the call to
// malloc(). We remove the "*2" to ensure the error happens when the test
// expects it.
//
//static unsigned int static_var = MAX_VAL*2;
static unsigned int static_var = MAX_VAL;

static char * memory_allocation_failure_007_func_001 (char *str1)
{
    int j;
    if (str1 != NULL) {
      // Frama-C/Eva: unsigned overflow, requires option -warn-unsigned-overflow
      memory_allocation_failure_007_str_gbl = (char *) malloc(static_var+1);/*Tool should detect this line as error*/ /*ERROR:Memory allocation failure *//*FC-alarm-but-noUB*/
      if(memory_allocation_failure_007_str_gbl!=NULL) {
        for (j = 0; j < static_var; j++) {
          memory_allocation_failure_007_str_gbl[j] = str1[static_var-j-1];
        }
        memory_allocation_failure_007_str_gbl[static_var] = '\0';
      }
      return memory_allocation_failure_007_str_gbl;
    } else {
      return NULL;
    }
}

void memory_allocation_failure_007 ()
{
     int j;
    char buf[][25]={"This is a String",
    		     "Second String"};
    for(j = 0; j <= 1; j++)
    {
        if(buf[j]!= NULL)
    	{
        	memory_allocation_failure_007_str_gbl = memory_allocation_failure_007_func_001(buf[j]);
        }
    }
}

/*
* Type of defect: memory_allocation_failure - Memory could not be allocated / insufficient memory
* Complexity: When using a pointer to char in an infinite for loop
*/

// Frama-C/Eva: the definition below causes an unsigned overflow in the
// enumeration constant. Option -warn-unsigned-overflow allows Frama-C to
// report it. Since this is not the intended error in the test, we modify
// its value.
//enum {max_buffer = MAX_VAL*2};
enum {max_buffer = MAX_VAL};
char * memory_allocation_failure_008_func_001 (const char *msg) {
  const char *error_log = msg;
  char * buffer = 0;
  int i;
  for(i=0;i<max_buffer;i++)
  {
	   // Frama-C/Eva: there is no actual undefined behavior here.
	   // The C standard ensures that sizeof(char) == 1, so there is
	   // no overflow (signed or unsigned) here.
	   // Some tools may decide that allocating a buffer of size UINT_MAX
	   // is likely an error, or include a specific hardware model with
	   // limited memory capacity, but this is tool-specific and not a
	   // semantic property.
	   buffer = (char*) malloc(max_buffer * sizeof(char));/*Tool should detect this line as error*/ /*ERROR:Memory allocation failure *//*FC-noUB*/
       break;
  }
  if(buffer!=NULL)
    snprintf(buffer, max_buffer * sizeof(char), "Error: %s", error_log);
  return buffer;
}
void memory_allocation_failure_008 ()
{
	char *str = "STRINGMEM";
	memory_allocation_failure_008_func_001(str);
}

/*
* Type of defect: memory_allocation_failure - Memory could not be allocated / insufficient memory
* Complexity: When using a pointer to char in a do ~ while loop and memory allocate and returned to another function ,
*/
#define MAX_BUFFER (429496728UL)

void memory_allocation_failure_009_func_001 (char * buf)
{
    int i=0;
    do
    {
    	// Frama-C/Eva: there is no actual undefined behavior here,
    	// just like in the previous case. However... (see comment below)
    	buf = (char*) malloc(MAX_BUFFER * sizeof(char));/*Tool should detect this line as error*/ /*ERROR:Memory allocation failure *//*FC-noUB*/
    	// Frama-C/Eva: ... there is an undefined behavior in the loop, even though
    	// it is completely irrelevant for the test: since MAX_VAL > INT_MAX,
    	// the loop counter leads to a signed overflow.
    	// To avoid it, we change the loop exit condition.
    	i++;
    //}while (i<MAX_VAL);
    }while (i<MAX_VAL/2);
}

void memory_allocation_failure_009_func_002 (void * vptr)
{
	/* cast void pointer to a pointer of the appropriate type */
    char * * cptr = (char * *)vptr;
    char * buf =NULL;
    memory_allocation_failure_009_func_001 (buf);
    buf = (*cptr);
    printf("%s",buf);
}

void memory_allocation_failure_009 ()
{
    void *buf1;
	buf1 = "String Test123";
    memory_allocation_failure_009_func_002(&buf1);
}

/*
* Type of defect: memory_allocation_failure - Memory could not be allocated / insufficient memory
* Complexity: When using a pointer to volatile structure in a do while loop and bit manipulations and global variable
*/
#define ERROR   0x1
#define READY   0x2
#define RESET   0x4

#define NDEVS   4

void memory_allocation_failure_010_func_001(int devno)
{
	int i=0;
	if (devno <= NDEVS)
	{
	    do
	    {
			// Frama-C/Eva: test disabled due to the absence of
			// undefined behavior:
			// memory_allocation_failure_010_s_001 defines a
			// struct containing two ints, so its size is
			// 80 bytes (assuming a 32-bit int); no overflow.
			memory_allocation_failure_010_arr_gbl = (memory_allocation_failure_010_s_001 *) malloc (10*sizeof(memory_allocation_failure_010_s_001));/*Tool should detect this line as error*/ /*ERROR:Memory allocation failure *//*FC-noUB*/
            i++;
	    // Frama-C/Eva: modified loop exit condition below
	    //(see comment inside memory_allocation_failure_009_func_001)
	    //}while( i<=MAX_VAL);
	    }while( i<=MAX_VAL/2-1);
	}
}

void memory_allocation_failure_010_func_002(int devno)
{
    memory_allocation_failure_010_func_001(1);
	memory_allocation_failure_010_arr_gbl->csr = READY;
    do
    {
        memory_allocation_failure_010_arr_gbl->data = READY;
        if(memory_allocation_failure_010_arr_gbl->csr & ERROR)
        {
    	    memory_allocation_failure_010_arr_gbl->csr = RESET;
        }
    }while( (memory_allocation_failure_010_arr_gbl->csr & (READY | ERROR)) == 0);
}

void memory_allocation_failure_010 ()
{
	memory_allocation_failure_010_func_002(1);
	++memory_allocation_failure_010_arr_gbl->data;
}

/*
* Type of defect: memory_allocation_failure - Memory could not be allocated / insufficient memory
* Complexity: When using a pointer to union , with structure as element , memory allocated from other function
*/
typedef struct {
	int *a;
	int b;
} memory_allocation_failure_011_s_001;

typedef struct {
	int a;
	int b;
} memory_allocation_failure_011_s_002;

typedef struct {
	int a;
	int b;
} memory_allocation_failure_011_s_003;

typedef union {
	memory_allocation_failure_011_s_001 *s1;
	memory_allocation_failure_011_s_002 *s2;
	memory_allocation_failure_011_s_003 *s3;
} memory_allocation_failure_011_uni_001;

// Frama-C/Eva: the constant is too large for the return type; an unintended
// signed downcast will happen. We changed the return type to avoid it.
//int memory_allocation_failure_011_func_001(int flag)
unsigned memory_allocation_failure_011_func_001(int flag)
{
   //int ret =0;
   unsigned ret =0;
   if (flag ==0)
	   ret = MAX_VAL;
   else
	   ret=5;
   return ret;
}
memory_allocation_failure_011_uni_001 * memory_allocation_failure_011_gbl_u1;
void memory_allocation_failure_011_func_002(void)
{
	// Frama-C/Eva: unsigned overflow: the -1 is converted to unsigned
	// before the call to malloc, so no actual UB;
	// option -warn-unsigned-overflow warns about it
	memory_allocation_failure_011_gbl_u1 = (memory_allocation_failure_011_uni_001 * )malloc(memory_allocation_failure_011_func_001(0)*sizeof( memory_allocation_failure_011_uni_001 )); /*Tool should detect this line as error*/ /*ERROR:Memory allocation failure *//*FC-alarm-but-noUB*/
	memory_allocation_failure_011_gbl_u1->s1 = (memory_allocation_failure_011_s_001 *) malloc(sizeof(memory_allocation_failure_011_s_001));
	memory_allocation_failure_011_gbl_u1->s1->a = (int *) calloc ( 5,sizeof(int));
}
void memory_allocation_failure_011 ()
{
	memory_allocation_failure_011_uni_001 *p =NULL;
	memory_allocation_failure_011_func_002();

	if( memory_allocation_failure_011_gbl_u1 != NULL)
	{
	p = memory_allocation_failure_011_gbl_u1;
	p->s1->a[1] = 10;

	free(memory_allocation_failure_011_gbl_u1->s1->a);
	free(memory_allocation_failure_011_gbl_u1->s1);
	free(memory_allocation_failure_011_gbl_u1);
	}
}

/*
* Type of defect: memory_allocation_failure - Memory could not be allocated / insufficient memory
* Complexity: When using a pointer array of int , memory allocated in another function based on return value of a function in a ternary statement
*/
int *memory_allocation_failure_012_buf2_gbl;
// Frama-C/Eva: the constant is too large for the return type; an unintended
// signed downcast will happen. We changed the return type to avoid it.
//int memory_allocation_failure_012_func_001(int flag)
unsigned memory_allocation_failure_012_func_001(int flag)
{
   //int ret =0;
   unsigned ret =0;
   if (flag ==0)
	   ret = MAX_VAL;
   else
	   ret=5;
   return ret;
}

void memory_allocation_failure_012_func_002 (int *pbuf[])
{
	int buf1[5] = {1,2,3,4,5};
	// Frama-C/Eva: there is no UB here; the excessively large arguments
	// to calloc() make it fail, but cause no UB, except later when the
	// memory is dereferenced (and no check for failure of calloc was
	// performed). To better match the test intent, we replace it with a
	// call to malloc(), so that the multiplication causes an unsigned
	// overflow, which is reported by option -warn-unsigned-overflow.
	//memory_allocation_failure_012_buf2_gbl = (int *) calloc (memory_allocation_failure_012_func_001(0),sizeof(int));
	memory_allocation_failure_012_buf2_gbl = (int *) malloc (memory_allocation_failure_012_func_001(0)*sizeof(int));/*Tool should detect this line as error*/ /*ERROR:Memory allocation failure *//*FC-adapted*//*FC-alarm-but-noUB*/
	int buf3[5] = {1,2,3,4,5};
	int buf4[5] = {1,2,3,4,5};
	int buf5[5] = {1,2,3,4,5};
	pbuf[0] = buf1;
	pbuf[1] = memory_allocation_failure_012_buf2_gbl;
	pbuf[2] = buf3;
	pbuf[3] = buf4;
	pbuf[4] = buf5;
	int ret;
	ret = pbuf[1][1];
	printf("%d",ret);
}

void memory_allocation_failure_012 ()
{
	int *ptr[5], a;
	int flag=10;

    (flag == 10)? (memory_allocation_failure_012_func_002(ptr)) : ( a =20);
    (flag == 10)? (ptr[1][1] = 200):(a=100);

    if(flag == 10){
    	if(memory_allocation_failure_012_buf2_gbl!=NULL)
    	{
    		a = ptr[1][1];
    	    free(memory_allocation_failure_012_buf2_gbl);
    	}
    }
}

/*
* Type of defect: memory_allocation_failure - Memory could not be allocated / insufficient memory
* Complexity: When using a double pointer to char in an if condition and memory allocated based on return value of function
*/
static int staticflag=1;
// Frama-C/Eva: the constant is too large for the return type; an unintended
// signed downcast will happen. We changed the return type to avoid it.
//int memory_allocation_failure_013_func_001(int flag)
unsigned memory_allocation_failure_013_func_001(int flag)
{
   //int ret =0;
   unsigned ret =0;
   if (flag ==0)
	   ret = MAX_VAL;
   else
	   ret=5;
   return ret;
}

void memory_allocation_failure_013 ()
{
	char  **dptr,a;
	double *ptr,b = 0.0;
	int i;


    if (staticflag == 10)
    {
    	  	ptr= (double*) malloc(10*sizeof(double));
    }
    else
    {
    	  	dptr=(char**) malloc(10*sizeof(char*));
    	  	if(1)
    	  	{
            	for(i=0;i<10;i++)
        	    {
            		// Frama-C/Eva: the test seems intended for finite
            		// memory, in which successive allocations of very
            		// large memory blocks lead to failure. There is no
            		// undefined behavior here; for Frama-C/Eva, we adapt
            		// the test to create a signed overflow, leading
            		// to an alarm.
#ifndef __FRAMAC__
            		dptr[i]=(char*) malloc(memory_allocation_failure_013_func_001(0)*sizeof(char));/*Tool should detect this line as error*/ /*ERROR:Memory allocation failure *//*FC-noUB*/
#else
            		dptr[i]=(char*) malloc((memory_allocation_failure_013_func_001(0)+1)*sizeof(char));/*Tool should detect this line as error*/ /*ERROR:Memory allocation failure *//*FC-adapted*//*FC-alarm-but-noUB*/
#endif
        	    }
    	  	}
    }

    if  (staticflag == 10)
    		(*(ptr+1) = 10.5);
    else
    	   strcpy( dptr[1],"STRING TEST" );

    if(staticflag == 10)
    	b = *(ptr+1);
    else
    	a = dptr[1][1];

    if(staticflag == 10)
    {
    	free(ptr);
    	ptr = NULL;
    }
    else
    {
    	for(i=0;i<10;i++)
    		free(dptr[i]);
    	free(dptr);
    	dptr = NULL;
    }
    printf("%d",a);
    sink = b;
}

/*
* Type of defect: memory_allocation_failure - Memory could not be allocated / insufficient memory
* Complexity: When using a pointer to an array of integer in if condition and
* memory allocated and return from another function based on value of array
*/
// Frama-C/Eva: the original value of the initializer in arr_value below was
// MAX_VAL (UINT_MAX), which is larger than the maximum value for a
// (signed) int. The initializer below therefore put "-1" in arr_value[1].
// This is not undefined behavior, but such uninituitive situations can be
// warned about on Frama-C/Eva by using option -warn-signed-downcast.
// Since the tests in other files (such as data_overflow.c) require this flag
// to be enabled (the intended errors correspond to such situations, which are
// not undefined according to the standard), the initializer below was modified
// to contain -1 directly.
//const int arr_value[2] = {1,MAX_VAL};
const int arr_value[2] = {1,-1};
int (*memory_allocation_failure_014_func_001())[4]
{
	int (*p)[4];
	int arr[4][4] = {{1,2,3,4},
			         {11,22,33,44},
			         {33,44,55,66},
			         {55,66,77,88}};
	int i,j;
	// Frama-C/Eva: unsigned overflow: the -1 in arr_value[1] is converted
	// to unsigned when calling malloc, so no actual UB;
	// option -warn-unsigned-overflow warns about it
	p= (int (*)[]) malloc (arr_value[1] *1 );/*Tool should detect this line as error*/ /*ERROR:Memory allocation failure *//*FC-alarm-but-noUB*/
	if(p!=NULL)
	{
	memcpy(p, arr, sizeof(arr));
	for (i = 0;i< 4; i++)
	{
		for ( j=0 ;j<4; j++)
		{
			*(p[i]+j) += *(p[i]+j);
		}
	}
	}
	return p;
}

void memory_allocation_failure_014 ()
{
	int (*ptr1)[4];
	char  **dptr,a = 0;
	double *ptr,b;
	int i,j;
	// Frama-C/Eva: patched as in https://github.com/dwightguth/itc-benchmarks
	// to ensure the else branch (containing the intended error) is taken.
	// Note that another way of patching this would be to change the test
	// "staticflag == 10" to "staticflag != 10", but this leads to issues
	// later: the "then" branches seem to be related to the same code.
	// Overall, whatever branch is taken, UB happens afterwards.
	//static int staticflag=10;
	static int staticflag=1;
    if (staticflag == 10)
    {
    	  	ptr= (double*) malloc(10*sizeof(double));
    }
    else
    {
    	  	dptr=(char**) malloc(10*sizeof(char*));
    	  	if(1)
    	  	{
            	for(i=0;i<10;i++)
        	    {
            		dptr[i]=(char*) malloc(10*sizeof(char));
        	    }
            	ptr1 = memory_allocation_failure_014_func_001();
    	  	}
    }

    if  (staticflag == 10)
    {
    		(*(ptr+1) = 10.5);
    }
    else
    {
    	   // Frama-C/Eva: there is an unintended UB here: the string
    	   // is too large for the allocated memory (dptr[1] points to the
    	   // pointer allocated via a call to malloc(10)).
    	   // We patched it avoid the overflow.
    	   //strcpy( dptr[1],"STRING TEST" );
    	   strcpy( dptr[1],"STRING TE" );
    	   if(1)
    	   {
        	   for (i = 0;i< 4; i++)
               	{
               		for ( j=0 ;j<4; j++)
               		{
               			*(ptr1[i]+j) += *(ptr1[i]+j);
               		}
               	}
    	   }


    }

    if(staticflag == 10)
    {
    	b = *(ptr+1);
    }
    else
    {
	  	if(1)
	  	{
	  		a = *(ptr1[1]+1);
	  	}
    }

    if(staticflag == 10)
    {
    	free(ptr);
    	ptr = NULL;
    }
    else
    {
    	for(i=0;i<10;i++)
    		free(dptr[i]);
    	free(dptr);
    	if(1)
    	{
    		free(ptr1);
    	}
    }
    // Frama-C/Eva: variable b is uninitialized unless the "then" branch was
    // taken previously (staticflag == 10). Our patch to fix the test
    // (to ensure the intended error path is reachable) leads to an error here.
    // We add the extra 'if' to prevent UB (reading an indeterminate value)
    // from happening, since it is not intended in this test case.
    if (staticflag == 10) {
      printf("%d %lf",a,b);
    }
}

/*
* Type of defect: memory_allocation_failure - Memory could not be allocated / insufficient memory
* Complexity: When using a pointer to int in a goto statement  based on return value function , structure element
*/
// Frama-C/Eva: this initializer is too large for type int, so the test
// causes an unintended signed downcast during initialization. The constant
// was changed to avoid this.
//#define MAX_V 4294967295UL
#define MAX_V (4294967295UL/2)
typedef struct {
	int a;
	int b;
} memory_allocation_failure_015_s_001;

int * memory_allocation_failure_015_gbl_ptr;

int memory_allocation_failure_015_func_001 ()
{
	memory_allocation_failure_015_s_001 s = {MAX_V,20};
	return s.a;
}

void memory_allocation_failure_015_func_002 ()
{
	// Frama-C/Eva: unsigned overflow: the -1 is converted
	// to unsigned during the multiplication, so no actual UB;
	// option -warn-unsigned-overflow warns about it
	memory_allocation_failure_015_gbl_ptr = (int *) malloc (memory_allocation_failure_015_func_001()*sizeof(int));/*Tool should detect this line as error*/ /*ERROR:Memory allocation failure *//*FC-alarm-but-noUB*/
}

int memory_allocation_failure_015_func_003 (int flag)
{
	int ret = 0;
	if (flag == 1)
	{
		goto my_label;
	}
	return ret;
my_label:
    if (flag == 1)
	{
        memory_allocation_failure_015_func_002();
	}
	*(memory_allocation_failure_015_gbl_ptr+1) = 7;
	ret ++;
	return ret;
}

void memory_allocation_failure_015 ()
{
    int flag;
    flag = memory_allocation_failure_015_func_003(1);
    printf("%d",flag);
}

/*
* Type of defect: memory_allocation_failure - Memory could not be allocated / insufficient memory
* Complexity: When using a pointer to int 4 pointers
*/
int * memory_allocation_failure_016_gbl_ptr1;
int * memory_allocation_failure_016_gbl_ptr2;

// Frama-C/Eva: value patched to prevent the test from failing too early
#define MAX_VAL_4 (1073741824-1)
int memory_allocation_failure_016_func_001(int flag)
{
   int ret =0;
   if (flag ==0)
	   ret = MAX_VAL_4;
   else
	   ret=5;
   return ret;
}

void memory_allocation_failure_016_func_002(int flag)
{
   // Frama-C/Eva: test condition inversed, otherwise the intended error site
   // is unreachable
   if (flag !=0)
   {
	   ;
   }
   else
   {
	   memory_allocation_failure_016_gbl_ptr1 = (int *) malloc (memory_allocation_failure_016_func_001(0)*sizeof(int));
	   memory_allocation_failure_016_gbl_ptr2 = (int *) malloc ((memory_allocation_failure_016_func_001(0)+1)*sizeof(int));/*Tool should detect this line as error*/ /*ERROR:Memory allocation failure *//*FC-adapted*//*FC-alarm-but-noUB*/
   }

}

void memory_allocation_failure_016 ()
{
	// Frama-C/Eva: unsigned overflow in the multiplication: no actual UB;
	// option -warn-unsigned-overflow warns about it
	// Note: this test seems intended to be cause two successive allocations
	// of huge memory blocks, so that, assuming a finite memory, the second
	// one will fail. However, the C standard does not deal with finiteness
	// of memory, and each call to malloc may always succeed or fail,
	// without causing undefined behavior.
	// Another issue is that the value chosen for MAX_VAL_4 (INT_MAX/4)
	// leads to an unsigned overflow when allocating the first memory block,
	// so the error happens much earlier than intended in the test.
	// In the end, two changes are required for the test to fail where
	// intended: lower MAX_VAL_4 and increase the memory requested during
	// the allocation intended to fail.
	int * ptr1 = (int *) malloc (memory_allocation_failure_016_func_001(0)*sizeof(int));
	int * ptr2 = (int *) malloc (memory_allocation_failure_016_func_001(0)*sizeof(int));
    // Frama-C/Eva: note that, if the previous unsigned overflow is not
    // reported and execution proceeds, then UB may happen here
    // (ptr1 may point to a 0-sized block).
    *(ptr1+1) = 10;
    memory_allocation_failure_016_func_002(0);

    free(memory_allocation_failure_016_gbl_ptr1);
    free(memory_allocation_failure_016_gbl_ptr2);
    free(ptr1);
    free(ptr2);

}

/*
* Type of defect: memory_allocation_failure - Memory could not be allocated / insufficient memory
* Complexity:Memory allocation failure main function
*/
extern volatile int vflag;
void memory_allocation_failure_main ()
{
	if (vflag == 1 || vflag ==888)
	{
		memory_allocation_failure_001();
	}

	if (vflag == 2 || vflag ==888)
	{
		memory_allocation_failure_002();
	}

	if (vflag == 3 || vflag ==888)
	{
		memory_allocation_failure_003();
	}

	if (vflag == 4 || vflag ==888)
	{
		memory_allocation_failure_004();
	}

	if (vflag == 5 || vflag ==888)
	{
		memory_allocation_failure_005();
	}

	if (vflag == 6 || vflag ==888)
	{
		memory_allocation_failure_006();
	}

	if (vflag == 7 || vflag ==888)
	{
		memory_allocation_failure_007();
	}

	if (vflag == 8 || vflag ==888)
	{
		memory_allocation_failure_008();
	}

	if (vflag == 9 || vflag ==888)
	{
		memory_allocation_failure_009();
	}

	if (vflag == 10 || vflag ==888)
	{
		memory_allocation_failure_010();
	}

	if (vflag == 11 || vflag ==888)
	{
		memory_allocation_failure_011();
	}

	if (vflag == 12 || vflag ==888)
	{
		memory_allocation_failure_012();
	}

	if (vflag == 13 || vflag ==888)
	{
		memory_allocation_failure_013();
	}

	if (vflag == 14 || vflag ==888)
	{
		memory_allocation_failure_014();
	}

	if (vflag == 15 || vflag ==888)
	{
		memory_allocation_failure_015();
	}

	if (vflag == 16 || vflag ==888)
	{
		memory_allocation_failure_016();
	}
}

