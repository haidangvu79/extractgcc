typedef struct { int  i1; float f1; char c1; double d1; } 
  st1;
typedef struct { int  i2; float f2; double d2; char c2; } 
  st2;
int main() {
  st1 s1 = {.i1 = 1, .f1 = 1.0, .c1 = 'a', .d1 = 1.0};
  st2 *p2 = (st2 *) (&s1);// is this free of undef.beh.?
  p2->f2=2.0;             // and this?
  printf("s1.f1=%f  p2->f2=%f\n",s1.f1,p2->f2);
}

