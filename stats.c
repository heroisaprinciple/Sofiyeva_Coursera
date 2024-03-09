/**
 * @file stats.c
 * @brief Functions for statistical analysis of an array
 *
 * This file contains the implementation of functions for statistical
 * analysis of an array, including finding mean, median, maximum, minimum,
 * sorting, and printing statistics.
 *
 * @author Arina Sofiyeva
 * @date 08.03.2024
 *
 */

#include <stdio.h>
#include "stats.h"

#define SIZE (40)

void main() {
    unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                                 114, 88,   45,  76, 123,  87,  25,  23,
                                 200, 122, 150, 90,   92,  87, 177, 244,
                                 201,   6,  12,  60,   8,   2,   5,  67,
                                 7,  87, 250, 230,  99,   3, 100,  90};

}

double findMean(const unsigned char* test, int length) {
}

double findMedian(const unsigned char* test, int length) {
}

int selectDescSort(const void * a, const void * b) {
}

int sortArray(const unsigned char* test, int length) {
}

int findMaximum(const unsigned char* test, int length) {
}

int findMinimum(const unsigned char* test, int length) {
}

void printArray(const unsigned char* test, int length) {
}

void printStatistics(const unsigned char* test, int length) {
}
