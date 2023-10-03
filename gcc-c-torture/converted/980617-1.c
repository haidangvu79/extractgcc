void foo (unsigned int * p)
{
  if ((signed char)(*p & 0xFF) == 17 || (signed char)(*p & 0xFF) == 18)
    return;
  else
   { printf("abort_func "); 		abort (); }

}

int main ()
{
  int i = 0x30011;
  foo(&i);
 { printf("exit_main "); 		exit (0); }
}

