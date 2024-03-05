typedef struct { uint16_t u; char c; } st;
int x;
void f(st* s2p, st* s1p) {
  *s2p=*s1p;
}
int main() {
  // check there is a padding byte between c and u
  size_t offset_padding = offsetof(st,c)+sizeof(char);
  assert(sizeof(st)>offset_padding);
  st s1 = { .u = 0x1234, .c = 'A' };
  unsigned char *padding1 = 
    (unsigned char*)(&s1) + offset_padding;
  //  printf("*padding1=0x%x\n",(int)*padding1);
  *padding1 = 0xBA; 
  printf("*padding1=0x%x\n",(int)*padding1);
  st s2;
  unsigned char *padding2 = 
    (unsigned char*)(&s2) + offset_padding;
  // can this print something other than 0xBA then the
  // last line print 0xBA ?
  printf("*padding2=0x%x\n",(int)*padding2);//warn 
  f(&s2,&s1);   //s2 = s1;
  printf("*padding2=0x%x\n",(int)*padding2);
}
