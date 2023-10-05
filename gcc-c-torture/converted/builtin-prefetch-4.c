/* Test that __builtin_prefetch does no harm.

   Check that the expression containing the address to prefetch is
   evaluated if it has side effects, even if the target does not support
   data prefetch.  Check changes to pointers and to array indices that are
   either global variables or arguments.  */

#define ARRSIZE 100

int arr[ARRSIZE];
int *ptr = &arr[20];
int arrindex = 4;

/* Check that assignment within a prefetch argument is evaluated.  */

int
assign_arg_ptr (int *p)
{
  printf("funccall_arg_idx ");
  int *q;
  __builtin_prefetch ((q = p), 0, 0);
  return q == p;
}

int
assign_glob_ptr (void)
{
  printf("funccall_arg_idx ");
  int *q;
  __builtin_prefetch ((q = ptr), 0, 0);
  return q == ptr;
}

int
assign_arg_idx (int *p, int i)
{
  printf("funccall_arg_idx ");
  int j;
  __builtin_prefetch (&p[j = i], 0, 0);
  return j == i;
}

int
assign_glob_idx (void)
{
  printf("funccall_arg_idx ");
  int j;
  __builtin_prefetch (&ptr[j = arrindex], 0, 0);
  return j == arrindex;
}

/* Check that pre/post increment/decrement within a prefetch argument are
   evaluated.  */

int
preinc_arg_ptr (int *p)
{
  printf("funccall_arg_idx ");
  int *q;
  q = p + 1;
  __builtin_prefetch (++p, 0, 0);
  return p == q;
}

int
preinc_glob_ptr (void)
{
  printf("funccall_arg_idx ");
  int *q;
  q = ptr + 1;
  __builtin_prefetch (++ptr, 0, 0);
  return ptr == q;
}

int
postinc_arg_ptr (int *p)
{
  printf("funccall_arg_idx ");
  int *q;
  q = p + 1;
  __builtin_prefetch (p++, 0, 0);
  return p == q;
}

int
postinc_glob_ptr (void)
{
  printf("funccall_arg_idx ");
  int *q;
  q = ptr + 1;
  __builtin_prefetch (ptr++, 0, 0);
  return ptr == q;
}

int
predec_arg_ptr (int *p)
{
  printf("funccall_arg_idx ");
  int *q;
  q = p - 1;
  __builtin_prefetch (--p, 0, 0);
  return p == q;
}

int
predec_glob_ptr (void)
{
  printf("funccall_arg_idx ");
  int *q;
  q = ptr - 1;
  __builtin_prefetch (--ptr, 0, 0);
  return ptr == q;
}

int
postdec_arg_ptr (int *p)
{
  printf("funccall_arg_idx ");
  int *q;
  q = p - 1;
  __builtin_prefetch (p--, 0, 0);
  return p == q;
}

int
postdec_glob_ptr (void)
{
  printf("funccall_arg_idx ");
  int *q;
  q = ptr - 1;
  __builtin_prefetch (ptr--, 0, 0);
  return ptr == q;
}

int
preinc_arg_idx (int *p, int i)
{
  printf("funccall_arg_idx ");
  int j = i + 1;
  __builtin_prefetch (&p[++i], 0, 0);
  return i == j;
}


int
preinc_glob_idx (void)
{
  printf("funccall_arg_idx ");
  int j = arrindex + 1;
  __builtin_prefetch (&ptr[++arrindex], 0, 0);
  return arrindex == j;
}

int
postinc_arg_idx (int *p, int i)
{
  printf("funccall_arg_idx ");
  int j = i + 1;
  __builtin_prefetch (&p[i++], 0, 0);
  return i == j;
}

int
postinc_glob_idx (void)
{
  printf("funccall_arg_idx ");
  int j = arrindex + 1;
  __builtin_prefetch (&ptr[arrindex++], 0, 0);
  return arrindex == j;
}

int
predec_arg_idx (int *p, int i)
{
  printf("funccall_arg_idx ");
  int j = i - 1;
  __builtin_prefetch (&p[--i], 0, 0);
  return i == j;
}

int
predec_glob_idx (void)
{
  printf("funccall_arg_idx ");
  int j = arrindex - 1;
  __builtin_prefetch (&ptr[--arrindex], 0, 0);
  return arrindex == j;
}

int
postdec_arg_idx (int *p, int i)
{
  printf("funccall_arg_idx ");
  int j = i - 1;
  __builtin_prefetch (&p[i--], 0, 0);
  return i == j;
}

int
postdec_glob_idx (void)
{
  printf("funccall_arg_idx ");
  int j = arrindex - 1;
  __builtin_prefetch (&ptr[arrindex--], 0, 0);
  return arrindex == j;
}

/* Check that function calls within the first prefetch argument are
   evaluated.  */

int getptrcnt = 0;

int *
getptr (int *p)
{
  getptrcnt++;
  return p + 1;
}

int
funccall_arg_ptr (int *p)
{
  printf("funccall_arg_idx ");
  __builtin_prefetch (getptr (p), 0, 0);
  return getptrcnt == 1;
}

int getintcnt = 0;

int
getint (int i)
{
  getintcnt++;
  return i + 1;
}

int
funccall_arg_idx (int *p, int i)
{
  printf("funccall_arg_idx ");
  __builtin_prefetch (&p[getint (i)], 0, 0);
  return getintcnt == 1;
}

int
main ()
{
  if (!assign_arg_ptr (ptr))
   { printf("abort_main "); 		abort (); }
  if (!assign_glob_ptr ())
   { printf("abort_main "); 		abort (); }
  if (!assign_arg_idx (ptr, 4))
   { printf("abort_main "); 		abort (); }
  if (!assign_glob_idx ())
   { printf("abort_main "); 		abort (); }
  if (!preinc_arg_ptr (ptr))
   { printf("abort_main "); 		abort (); }
  if (!preinc_glob_ptr ())
   { printf("abort_main "); 		abort (); }
  if (!postinc_arg_ptr (ptr))
   { printf("abort_main "); 		abort (); }
  if (!postinc_glob_ptr ())
   { printf("abort_main "); 		abort (); }
  if (!predec_arg_ptr (ptr))
   { printf("abort_main "); 		abort (); }
  if (!predec_glob_ptr ())
   { printf("abort_main "); 		abort (); }
  if (!postdec_arg_ptr (ptr))
   { printf("abort_main "); 		abort (); }
  if (!postdec_glob_ptr ())
   { printf("abort_main "); 		abort (); }
  if (!preinc_arg_idx (ptr, 3))
   { printf("abort_main "); 		abort (); }
  if (!preinc_glob_idx ())
   { printf("abort_main "); 		abort (); }
  if (!postinc_arg_idx (ptr, 3))
   { printf("abort_main "); 		abort (); }
  if (!postinc_glob_idx ())
   { printf("abort_main "); 		abort (); }
  if (!predec_arg_idx (ptr, 3))
   { printf("abort_main "); 		abort (); }
  if (!predec_glob_idx ())
   { printf("abort_main "); 		abort (); }
  if (!postdec_arg_idx (ptr, 3))
   { printf("abort_main "); 		abort (); }
  if (!postdec_glob_idx ())
   { printf("abort_main "); 		abort (); }
  if (!funccall_arg_ptr (ptr))
   { printf("abort_main "); 		abort (); }
  if (!funccall_arg_idx (ptr, 3))
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

