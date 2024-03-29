/**
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Arina Sofiyeva
 * @date March 28 2024
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

/**
 * @brief Copies a block of memory from one location to another
 *
 * This function copies a block of memory from the source location `src`
 * to the destination location `dst` with the specified length `length`.
 * It handles overlap of source and destination and ensures that the copy
 * occurs without data corruption.
 *
 * @param src Pointer to the source memory location
 * @param dst Pointer to the destination memory location
 * @param length Number of bytes to copy
 *
 * @return Pointer to the destination memory location `dst`
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Copies a block of memory from one location to another
 *
 * This function copies a block of memory from the source location `src`
 * to the destination location `dst` with the specified length `length`.
 * The behavior is undefined if there is overlap of source and destination,
 * which may corrupt the data.
 *
 * @param src Pointer to the source memory location
 * @param dst Pointer to the destination memory location
 * @param length Number of bytes to copy
 *
 * @return Pointer to the destination memory location `dst`
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Sets a block of memory to a specified value
 *
 * This function sets a block of memory starting from the source location `src`
 * to the specified value `value` for the specified length `length`.
 *
 * @param src Pointer to the source memory location
 * @param length Number of bytes to set
 * @param value Value to set in each byte of the memory block
 *
 * @return Pointer to the source memory location `src`
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief Clears a block of memory (sets all bytes to zero)
 *
 * This function sets a block of memory starting from the source location `src`
 * to zero for the specified length `length`.
 *
 * @param src Pointer to the source memory location
 * @param length Number of bytes to clear
 *
 * @return Pointer to the source memory location `src`
 */
uint8_t * my_memzero(uint8_t * src, size_t length);

/**
 * @brief Reverses the order of bytes in a block of memory
 *
 * This function reverses the order of bytes in a block of memory starting
 * from the source location `src` for the specified length `length`.
 *
 * @param src Pointer to the source memory location
 * @param length Number of bytes in the memory block
 *
 * @return Pointer to the source memory location `src`
 */
uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @brief Reserves memory for a specified number of words
 *
 * This function dynamically allocates memory for the specified number
 * of words (`length`). It returns a pointer to the allocated memory
 * if successful, or a Null Pointer if not successful.
 *
 * @param length Number of words to allocate
 *
 * @return Pointer to the allocated memory if successful, or a Null Pointer
 */
int32_t * reserve_words(size_t length);

/**
 * @brief Frees dynamically allocated memory
 *
 * This function frees the dynamically allocated memory pointed to by `src`.
 *
 * @param src Pointer to the dynamically allocated memory to free
 *
 * @return void
 */
void free_words(int32_t * src);

#endif /* __MEMORY_H__ */
