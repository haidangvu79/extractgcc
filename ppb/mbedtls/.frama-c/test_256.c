#include "mbedtls/sha256.h"

#define LEN 128

/*@ assigns \result \from x; */
uint32_t __builtin_bswap32(uint32_t x);

extern unsigned char inbuf[LEN];

extern unsigned char outbuf[32];

int main() {
  mbedtls_sha256_context ctx;
  mbedtls_sha256_init(&ctx);
  mbedtls_sha256_starts(&ctx,0);
  mbedtls_sha256_update(&ctx,inbuf,LEN);
  mbedtls_sha256_finish(&ctx,outbuf);
  mbedtls_sha256_free(&ctx);
}
