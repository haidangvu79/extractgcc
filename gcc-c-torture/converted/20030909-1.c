void abort ();
void exit (int);


void test(int x, int y)
{
  if (x == y)
   { printf("abort_func "); 		abort (); }

}

void foo(int x, int y)
{
  if (x == y)
    goto a;
  else
    {
a:;
      if (x == y)
	goto b;
      else
	{
b:;
	  if (x != y)
	    test (x, y);
	}
    }
}

int main(void)
{
  foo (0, 0);

 { printf("exit_main "); 		exit (0); }
}

