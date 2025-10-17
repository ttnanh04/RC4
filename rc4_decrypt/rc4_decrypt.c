#include "rc4_decrypt.h"

void rc4_init(uint8_t *S, const uint8_t *key, size_t keylen) {
    int i, j = 0;
    uint8_t temp;

    for (i = 0; i < 256; i++)
        S[i] = i;

    for (i = 0; i < 256; i++) {
        j = (j + S[i] + key[i % keylen]) % 256;
        temp = S[i];
        S[i] = S[j];
        S[j] = temp;
    }
}

void rc4_generate(uint8_t *S, uint8_t *data, size_t datalen) {
    int i = 0, j = 0, k;
    uint8_t temp;

    for (size_t n = 0; n < datalen; n++) {
        i = (i + 1) % 256;
        j = (j + S[i]) % 256;
        temp = S[i];
        S[i] = S[j];
        S[j] = temp;

        k = (S[i] + S[j]) % 256;
        data[n] ^= S[k];
    }
}
