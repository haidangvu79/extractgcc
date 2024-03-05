static volatile char nd_char;
static volatile int nd_int;
static volatile long nd_long;
static volatile unsigned char nd_uchar;
static volatile short nd_short;

char nondet_char(void) {
  return nd_char;
}

int nondet_int(void) {
  return nd_int;
}

long nondet_long(void) {
  return nd_long;
}

unsigned char nondet_unsigned_char(void) {
  return nd_uchar;
}

short nondet_short(void){
  return nd_short;
}
