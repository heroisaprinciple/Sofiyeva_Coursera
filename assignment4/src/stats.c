/**
 * @file stats.c
 * @brief Functions for statistical analysis of an array
 *
 * This file contains the implementation of functions for statistical
 * analysis of an array, including finding mean, median, maximum, minimum,
 * sorting, and printing statistics.
 *
 * @author Arina Sofiyeva
 * @date 28.03.2024
 *
 */

#include <stdio.h>
#include "stats.h"
#include <stdlib.h>
#include <math.h>

#define SIZE (40)

void main() {
    unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                                 114, 88,   45,  76, 123,  87,  25,  23,
                                 200, 122, 150, 90,   92,  87, 177, 244,
                                 201,   6,  12,  60,   8,   2,   5,  67,
                                 7,  87, 250, 230,  99,   3, 100,  90};

    sortArray(test, SIZE);
    printArray(test, SIZE);
    printStatistics(test, SIZE);
}

double findMean(const unsigned char* test, int length) {
    double sum = 0;
    for (int i = 0; i < length; i++) {
        sum += test[i];
    }
    return sum / length;
}

double findMedian(const unsigned char* test, int length) {
    if (length % 2 == 1) {
        return test[length / 2];
    }
    else {
        int mid1 = test[length / 2];
        int mid2 = test[(length / 2) - 1];
        return (mid1 + mid2) / 2.0;
    }
}

int selectDescSort(const void * a, const void * b) {
    unsigned char unsignedA = *(const unsigned char *)a;
    unsigned char unsignedB = *(const unsigned char *)b;

    if (unsignedA < unsignedB) {
        return -1;
    } else if (unsignedA > unsignedB) {
        return 1;
    } else {
        return 0;
    }
}

int sortArray(const unsigned char* test, int length) {
    qsort(test, length, sizeof(unsigned char), selectDescSort);
}

int findMaximum(const unsigned char* test, int length) {
    int max = test[0];
    for (int i = 1; i < length; i++) {
        if (max < test[i]) {
            max = test[i];
        }
    }
    return max;
}

int findMinimum(const unsigned char* test, int length) {
    int min = test[0];
    for (int i = 1; i < length; i++) {
        if (min > test[i]) {
            min = test[i];
        }
    }
    return min;
}

void printArray(const unsigned char* test, int length) {
    #ifdef VERBOSE
        for (int i = length - 1; i >= 0; i--) {
            printf("attempt1\n");
            PRINTF("El: %d\n", test[i]);
        }
    #endif
}

void printStatistics(const unsigned char* test, int length) {
    PRINTF("The mean is: %f\n", floor((findMean(test, length))));
    PRINTF("The median is: %f\n", floor(findMedian(test, length)));
    PRINTF("The max is: %d\n", findMaximum(test, length));
    PRINTF("The min is: %d\n", findMinimum(test, length));
}
