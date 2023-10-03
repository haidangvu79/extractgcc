char buf[10];

extern void abort (void);
extern int sprintf (char*, const char*, ...);

int main()
{
  int l = sprintf (buf, "foo\0bar");
  if (l != 3)
   { printf("abort_main "); 		abort (); }
  printf("return 0"); 		return 0; 
}

