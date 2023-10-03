/* PR target/9164 */
/* The comparison operand was sign extended erraneously.  */

int
main (void)
{
    long j = 0x40000000;
    if ((unsigned int) (0x40000000 + j) < 0L)
	abort ();

    printf("return "); 		return 0; 
}

