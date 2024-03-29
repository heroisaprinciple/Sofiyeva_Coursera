/******************************************************************************
*
* @file data.c
* @brief File contains functions that perform ASCII-to-INT and INT-to-ASCII
*
* @author Arina Sofiyeva
* @date March 28, 2024
*
*****************************************************************************/

#include "../include/common/data.h"
#include <math.h>
#include <stdint.h>

uint8_t my_itoa(int32_t data, uint8_t *ptr, uint32_t base) {
    // Handle negative numbers
    uint8_t negative = 0;
    if (data < 0) {
        negative = 1;
        data = -data;
    }

    uint8_t length = 0;
    int32_t temp = data;
    while (temp > 0) {
        temp /= base;
        length++;
    }

    length += negative + 1;

    ptr += length - 1;
    *ptr = '\0';

    while (data > 0) {
        uint8_t digit = data % base;
        *ptr-- = digit < 10 ? digit + '0' : digit - 10 + 'A';
        data /= base;
    }

    if (negative) {
        *ptr-- = '-';
    }

    return length;
}

int32_t my_atoi(uint8_t *ptr, uint8_t digits, uint32_t base) {
    int32_t result = 0;
    int8_t sign = 1;

    if (*ptr == '-') {
        sign = -1;
        ptr++;
    }

    // Process each digit
    for (uint8_t i = 0; i < digits; i++) {
        uint8_t digit = *ptr++;
        if (digit >= '0' && digit <= '9') {
            digit -= '0';
        } else if (digit >= 'A' && digit < 'A' + base - 10) {
            digit -= 'A' - 10;
        } else {
            return 0;
        }
        result = result * base + digit;
    }

    return result * sign;
}
