/**
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Arina Sofiyeva
 * @date March 28 2024
 *
 */
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include "memory.h"

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length) {
    // Allocate temporary buffer
    uint8_t tempBuffer[length];
    uint8_t *holdArrayPtr = tempBuffer;

    // Check for identical pointers (no copy needed)
    if (src == dst) {
        return dst;
    }

    // Copy data from source to temporary buffer
    for (size_t i = 0; i < length; i++) {
        *holdArrayPtr = *src;
        src++;
        holdArrayPtr++;
    }

    holdArrayPtr = tempBuffer;

    // Check for overlap scenarios and copy accordingly
    if (src < dst && src + length > dst) {
        // Risky copy: source overlaps or after destination (copy in reverse)
        for (size_t i = length - 1; i >= 0; i--) {
            *dst = *holdArrayPtr;
            dst++;
            holdArrayPtr++;
        }
    } else {
        // Safe copy: source before destination or no overlap
        for (size_t i = 0; i < length; i++) {
            *dst = *holdArrayPtr;
            dst++;
            holdArrayPtr++;
        }
    }
    return dst;
}

uint8_t *my_memcopy(uint8_t *src, uint8_t *dst, size_t length) {
    if (src == dst) {
        return dst;
    }

    uint8_t *src_ptr = src;
    uint8_t *dest_ptr = dst;

    for (int i = 0; i < length; i++) {
        *dest_ptr++ = *src_ptr++;
    }
    return dst;
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value) {
    for (int i = 0; i < length; i++) {
        *src = value;
        src++;
    }
    return src;
}

uint8_t * my_memzero(uint8_t * src, size_t length) {
    for (size_t i = 0; i < length; i++) {
        *(src + i) = 0;
    }
    return src;
}

uint8_t *my_reverse(uint8_t *src, size_t length) {
    if (length <= 1) {
        return src;
    }

    uint8_t *left = src;
    uint8_t *right = src + length - 1;

    while (left < right) {
        uint8_t temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }
    return src;
}

int32_t *reserve_words(size_t length) {
    size_t total_size = length * sizeof(int32_t);
    int32_t *ptr = (int32_t *)malloc(total_size);

    if (ptr == NULL) {
        return NULL;
    }
    return ptr;
}

void free_words(int32_t * src) {
    if (src == NULL) {
        return;
    }

    free(src);
}
