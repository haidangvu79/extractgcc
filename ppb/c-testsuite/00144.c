// Frama-C/Eva does not allow reading from uninitialized variables, so we
// moved the `int i;` declaration inside main to a global scope, and
// added 'volatile' to retain non-deterministic behavior.
volatile int i;

int
main(void)
{
	int *q;
	void *p;

	i = i ? 0 : 0l;
	p = i ? (void *) 0 : 0;
	p = i ? 0 : (void *) 0;
	p = i ? 0 : (const void *) 0;
	q = i ? 0 : p;
	q = i ? p : 0;
	q = i ? q : 0;
	q = i ? 0 : q;

	return (int) q;
}
