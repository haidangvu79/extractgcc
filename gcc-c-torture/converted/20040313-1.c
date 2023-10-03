/* PR middle-end/14470 */
/* Origin: Lodewijk Voge <lvoge@cs.vu.nl> */

extern void abort(void);

int main()
{
  int t[1025] = { 1024 }, d;

  d = 0;
  d = t[d]++;
  if (t[0] != 1025)
   { printf("abort_main "); 		abort(); }
  if (d != 1024)
   { printf("abort_main "); 		abort(); }
  printf("return "); 		return 0; 
}

