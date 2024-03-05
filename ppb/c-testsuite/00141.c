// Frama-C/Eva does not allow reading from uninitialized variables, so we
// moved the `int foo, bar, foobar;` declarations inside main to a global
// scope, and added 'volatile' to retain non-deterministic behavior.
// Note that the original code does not prevent the occurrence of signed
// overflows, so we add -no-warn-signed-overflow during the analysis.

#define CAT(x,y) x ## y
#define XCAT(x,y) CAT(x,y)
#define FOO foo
#define BAR bar

volatile int foo, bar, foobar;

int
main(void)
{
	CAT(foo,bar) = foo + bar;
	XCAT(FOO,BAR) = foo + bar;
	return 0;
}
