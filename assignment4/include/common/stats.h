/**
 * @file stats.h
 * @brief Header file for statistical analysis functions
 *
 * This file contains declarations and function comments for statistical
 * analysis functions, including finding mean, median, maximum, minimum,
 * sorting, and printing statistics.
 *
 * @author Arina Sofiyeva
 * @date 28.03.2024
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief Calculates the median of an array.
 *
 * This function takes an array of unsigned characters and its length
 * as input and returns the median value.
 *
 * @param test Pointer to the array of unsigned characters
 * @param length Length of the array
 *
 * @return Median value of the array
 */
double findMedian(const unsigned char* test, int length);

/**
 * @brief Calculates the mean of an array.
 *
 * This function takes an array of unsigned characters and its length
 * as input and returns the mean value.
 *
 * @param test Pointer to the array of unsigned characters
 * @param length Length of the array
 *
 * @return Mean value of the array
 */
double findMean(const unsigned char* test, int length);

/**
 * @brief Finds the maximum value in an array.
 *
 * This function takes an array of unsigned characters and its length
 * as input and returns the maximum value.
 *
 * @param test Pointer to the array of unsigned characters
 * @param length Length of the array
 *
 * @return Maximum value in the array
 */
int findMaximum(const unsigned char* test, int length);

/**
 * @brief Finds the minimum value in an array.
 *
 * This function takes an array of unsigned characters and its length
 * as input and returns the minimum value.
 *
 * @param test Pointer to the array of unsigned characters
 * @param length Length of the array
 *
 * @return Minimum value in the array
 */
int findMinimum(const unsigned char* test, int length);

/**
 * @brief Sorts an array in descending order.
 *
 * This function takes an array of unsigned characters and its length
 * as input and sorts the array in descending order.
 *
 * @param test Pointer to the array of unsigned characters
 * @param length Length of the array
 */
int sortArray(const unsigned char* test, int length);

/**
 * @brief Prints statistics of an array.
 *
 * This function takes an array of unsigned characters and its length
 * as input and prints the mean, median, maximum, and minimum values.
 *
 * @param test Pointer to the array of unsigned characters
 * @param length Length of the array
 */
void printStatistics(const unsigned char* test, int length);

/**
 * @brief Prints an array.
 *
 * This function takes an array of unsigned characters and its length
 * as input and prints the elements of the array.
 *
 * @param test Pointer to the array of unsigned characters
 * @param length Length of the array
 */
void printArray(const unsigned char* test, int length);

/**
 * @brief Comparison function for descending order sorting.
 *
 * This function is used as a comparison function for sorting the
 * array in descending order.
 *
 * @param a Pointer to the first element
 * @param b Pointer to the second element
 *
 * @return 1 if the first element is less than the second,
 *         -1 if the first element is greater than the second,
 *         0 if both elements are equal
 */
int selectDescSort(const void * a, const void * b);

#endif /* __STATS_H__ */

