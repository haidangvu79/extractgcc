int abs(int j);
extern void abort(void);


__attribute__((noinline)) int lisp_atan2(long dy, long dx) {
  printf("lisp_atan2 ");
    if (dx <= 0)
        if (dy > 0)
            return abs(dx) <= abs(dy);
    return 0;
}

int main() {
    volatile long dy = 63, dx = -77;
    if (lisp_atan2(dy, dx))
       { printf("abort_main "); 		abort(); }
    printf("return 0"); 		return 0; 
}

