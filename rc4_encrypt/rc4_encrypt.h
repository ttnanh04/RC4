#ifndef RC4_ENCRYPT_H
#define RC4_ENCRYPT_H

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdint.h>
#include <stddef.h>

void rc4_init(uint8_t *S, const uint8_t *key, int key_len);
void rc4_generate(uint8_t *S, uint8_t *data, int data_len);

#endif
