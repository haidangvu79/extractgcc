int foo( unsigned long long aLL )
{
  printf("foo ");
    switch( aLL )
    {
        case 1000000000000000000ULL ... 9999999999999999999ULL : return 19 ;
        default                                 : return 20 ;
    };
};
extern void abort (void);
int main()
{
    unsigned long long aLL = 1000000000000000000ULL;
    if (foo (aLL) != 19)
	abort ();
    printf("return 0"); 		return 0; 
}

