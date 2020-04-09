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
 * @file stats.c 
 * @brief analyzes an array of unsigned char items and reports statistical 
 *        parameters of the dataset. Also reorders data set from large to 
 *        small and prints to screen.  
 *
 * @author Jake Michael
 * @date 04/09/2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "stats.h"

// Size of the Data Set
#define SIZE (40)

void main() {
  uint8_t * test2;
  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114,  88,  45,  76, 123,  87,  25,  23,
                              200, 122, 150,  90,  92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  print_statistics(test, SIZE);
  test2 = sort_array(test, SIZE);
  printf("Sorted in Descending Order: \n");
  print_array(test2, SIZE);
  free(test2);
}

void print_statistics(uint8_t *arr, uint8_t len) {
  printf("\n--------------------------\n   Statistics Report   \n--------------------------\n"); 
  printf("Minimum: %u \n", find_minimum(arr,len));
  printf("Maximum: %u \n", find_maximum(arr,len));
  printf("Mean:    %u \n", find_mean(arr,len));
  printf("Median:  %u \n", find_median(arr,len));
}

void print_array(uint8_t *arr, uint8_t len) { 
  uint8_t i; 
  for (i = 0; i < len; i++) { 
    printf("%u \n", arr[i]); 
  }
} // end print_array

uint8_t find_median(uint8_t *arr, uint8_t len) {
  uint8_t * temp;
  uint8_t median; 

  // sort it
  temp = sort_array(arr, len);

  // even number
  if (len % 2 ==0) {
    median = (temp[len/2-1]+temp[len/2])/2;
  }
  // odd number
  else {
    median = temp[len/2];
  } 
  free(temp);
  return median;  
} // edn find_median

uint8_t find_mean(uint8_t *arr, uint8_t len) {
  uint8_t i;
  uint8_t mean;
  uint16_t sum;

  sum = 0; 
  for (i = 0; i < len; i++) {
    sum += arr[i];
  }
  mean = sum/len;
  return mean;
} // end find_mean

uint8_t find_maximum(uint8_t *arr, uint8_t len) {
  uint8_t * temp; 
  uint8_t max;

  temp = sort_array(arr, len);
  max = temp[0];
  free(temp);
  return max;
}

uint8_t find_minimum(uint8_t *arr, uint8_t len) {
  uint8_t * temp; 
  uint8_t min;

  temp = sort_array(arr, len);
  min = temp[len-1];
  free(temp);
  return min;
}

uint8_t* sort_array(uint8_t *arr, uint8_t len) {
  uint8_t i, j;
  uint8_t * copy = malloc(sizeof(uint8_t)*len);
  uint8_t temp;
 
  // copy the array so we don't modify the original
  for (i = 0; i < len; i++) {
    copy[i] = arr[i];
  }

  // use bubble sort
  for (i = 0; i < len-1; i++) {
    for (j = 0; j < len-i-1; j++) {
      if(copy[j] < copy[j+1]) {
        temp = copy[j];
        copy[j] = copy[j+1];
        copy[j+1] = temp;
      }
    }
  }
  // return a pointer to the copy
  return copy;
} // end sort_array
