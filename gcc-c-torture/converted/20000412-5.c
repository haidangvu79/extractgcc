int main( void ) {
    struct {
	int node;
	int type;
    } lastglob[1] = { { 0   , 1  } };

    if (lastglob[0].node != 0 || lastglob[0].type != 1)
     { printf("abort_main "); 		abort (); }
   { printf("exit_main "); 		exit (0); }
}

