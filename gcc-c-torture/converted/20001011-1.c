extern void abort(void);

extern int strcmp(const char *, const char *);

int foo(const char *a)
{
  printf("foo ");
    return strcmp(a, "main");
}

int main(void)
{
    if(foo(__FUNCTION__))
       { printf("abort_main "); 		abort(); }
    printf("return "); 		return 0; 
}

