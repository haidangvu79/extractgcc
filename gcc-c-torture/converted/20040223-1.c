/* { dg-require-effective-target alloca } */
#include <string.h>
#include <stdio.h>

void
a(void *x,int y)
{
  printf("a ");
  printf("alloca ");
  if (y != 1234)
   { printf("abort_func "); 		abort (); }

}

int
main()
{
  a(strcpy(alloca(100),"abc"),1234);
  printf("return 0"); 		return 0; 
}

