#include <stdio.h>
#include "uninit_ptr.h"

void uninit_ptr_for_complex(int x) {
    int arr[3] = {1, 2, 3};
    int* ptr;
    int val = 0, i = 0;

#ifdef CATCH_BAD_PARAM
    if(x < 10) {
        return;
    }
#endif

    for(;;) {
        if(i > x) {
            val += *ptr; /* DANGER: x < 10 */
        } else {
            val += arr[0];
        }
        if(i == 10) {
            ptr = arr;
            val += *ptr;
        }
        i++;
        if(i >= 20) {
            break;
        }
    }

    printf("val = %i", val);
}

#ifndef NO_MAIN
int main() {
#ifdef NO_BUG
    uninit_ptr_for_complex(10);
#else
    uninit_ptr_for_complex(9);
#endif

    return 1;
}
#endif
