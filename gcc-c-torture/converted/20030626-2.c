char buf[40];

extern int sprintf (char*, const char*, ...);
extern void abort (void);

int main()
{
  int i = 0;
  int l = sprintf (buf, "%s", i++ ? "string" : "other string");
  if (l != sizeof ("other string") - 1 || i != 1)
   { printf("abort_main "); 		abort (); }
  printf("return "); 		return 0; 
}

