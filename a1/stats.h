/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.h 
 * @brief header file for statistical analysis
 *
 *
 * @author Jake Michael
 * @date 04/09/2020
 */

#ifndef __STATS_H__
#define __STATS_H__
#include <stdint.h>
/**
 * @brief - prints statistics
 *
 * prints minimum, maximum, mean and median
 *
 * @param arr - a pointer to the character array
 * @param len - the length of the array
 *
 * @return - none
 */
void print_statistics(uint8_t *arr, uint8_t len);

/**
 * @brief - prints a character array
 * 
 * prints a character array in increasing order by index
 *
 * @param arr - a pointer to the character array
 * @param len - the length of the array
 *
 * @return - none
 */
void print_array(uint8_t *arr, uint8_t len);

/**
 * @brief - finds the median of a char array
 *
 * finds median, assumes all positive 8 bit integers
 * in the input array 
 *
 * @param arr - a pointer to the character array
 * @param len - the length of the array
 *
 * @return - the median rounded down to nearest integer
 */
uint8_t find_median(uint8_t *arr, uint8_t len);

/**
 * @brief - finds the mean of a char array
 *
 * finds mean and rounds down to nearest integer
 *
 * @param arr - a pointer to the character array
 * @param len - the length of the array
 *
 * @return the median
 */
uint8_t find_mean(uint8_t *arr, uint8_t len);

/**
 * @brief - finds the maximum of a char array
 * 
 * @param arr - a pointer to the character array
 * @param len - the length of the array
 *
 * @return - the maximum
 */
uint8_t find_maximum(uint8_t *arr, uint8_t len);

/**
 * @brief - finds the minimum of a char array
 *
 * @param arr - a pointer to the character array
 * @param len - the length of the array
 *
 * @return - the minimum 
 */
uint8_t find_minimum(uint8_t *arr, uint8_t len);

/**
 * @brief - sorts array in descending order
 *
 * sorts the array in descending order 
 * (largest to smallest) 
 *
 * @param arr - a pointer to the character array
 * @param len - the length of the array
 *
 * @return - a pointer to the sorted character array 
 */
uint8_t* sort_array(uint8_t *arr, uint8_t len);


#endif // __STATS_H__ 
