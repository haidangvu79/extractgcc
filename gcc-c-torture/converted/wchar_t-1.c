/* { dg-options "-finput-charset=utf-8" } */
typedef __WCHAR_TYPE__ wchar_t;
wchar_t x[] = L"Ã";
wchar_t y = L'Ã';
extern void abort (void);
extern void exit (int);

int main (void)
{
  if (sizeof (x) / sizeof (wchar_t) != 2)
   { printf("abort_main "); 		abort (); }
  if (x[0] != L'Ã' || x[1] != L'\0')
   { printf("abort_main "); 		abort (); }
  if (y != L'Ã')
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

