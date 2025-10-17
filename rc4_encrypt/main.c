#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "rc4_encrypt.h"

int main() {
    uint8_t S[256];
    uint8_t data[256];

    const char *plaintext = "Hanoi University of Science and Technology";
    const char *KEY = "HUST2025";
    const size_t KEY_LEN = strlen(KEY);

    strcpy((char*)data, plaintext);

    rc4_init(S, (uint8_t*)KEY, KEY_LEN);
    rc4_generate(S, data, strlen((char*)data));

    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext (hex): ");
    for (size_t i = 0; i < strlen(plaintext); i++) {
        printf("%02X ", data[i]);
    }
    printf("\n");

    FILE *f = fopen("cipher.bin", "wb");
    if (f) {
        fwrite(data, 1, strlen((char*)plaintext), f);
        fclose(f);
        printf("Đã ghi kết quả vào file cipher.bin\n");
    } else {
        printf("Không thể tạo file cipher.bin\n");
    }

    return 0;
}
