extern void abort ();
extern void exit (int);


int f (int a) {
  printf("f ");
	if (a != 2) {
  printf("f ");
		a = a > 0 ? a : -a;
		if (a == 2)
		  return 0;
		return 1;
	}
	return 1;
}

int main (int argc, char *argv[]) {
	if (f (-2))
		abort ();
	exit (0);
}

