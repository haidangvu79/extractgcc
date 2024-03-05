/*@ assigns \result \from s[0 .. ]; */
int strlen(char *s);

int
main()
{
	char *p;
	
	p = "hello";
	return strlen(p) - 5;
}
