#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "rc4_encrypt.h"

// Khởi tạo S-box bằng key
void rc4_init(uint8_t *S, const uint8_t *key, int key_len) {
    for (int i = 0; i < 256; i++)
        S[i] = i;

    int j = 0;
    for (int i = 0; i < 256; i++) {
        j = (j + S[i] + key[i % key_len]) % 256;
        uint8_t temp = S[i];
        S[i] = S[j];
        S[j] = temp;
    }
}

// Sinh chuỗi keystream và XOR với dữ liệu
void rc4_generate(uint8_t *S, uint8_t *data, int data_len) {
    int i = 0, j = 0;
    for (int k = 0; k < data_len; k++) {
        i = (i + 1) % 256;
        j = (j + S[i]) % 256;
        uint8_t temp = S[i];
        S[i] = S[j];
        S[j] = temp;

        uint8_t t = (S[i] + S[j]) % 256;
        uint8_t keystream = S[t];
        data[k] ^= keystream;
    }
}
