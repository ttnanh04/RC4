#ifndef RC4_DECRYPT_H
#define RC4_DECRYPT_H

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>

void rc4_init(uint8_t *S, const uint8_t *key, size_t key_len);
void rc4_generate(uint8_t *S, uint8_t *data, size_t data_len);

#endif
