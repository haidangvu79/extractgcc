extern void abort(void);


int foo ()
{
  printf("foo ");
  int mat[2][1];
  int (*a)[1] = mat;
  int det = 0;
  int i;
  mat[0][0] = 1;
  mat[1][0] = 2;
  for (i = 0; i < 2; ++i)
    det += a[i][0];
  return det;
}

int main()
{
  if (foo () != 3)
   { printf("abort_main "); 		abort (); }
  printf("return "); 		return 0; 
}

