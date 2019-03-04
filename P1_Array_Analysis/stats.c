/******************************************************************************
 * Copyright (C) 2019 by Joseph George
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. Joseph George is not liable for any misuse of this material.
 *
 *****************************************************************************/

/**
 * @file stats.c
 * @brief Simple program that performs statistical analytics on a dataset.
 *
 * Analyzes an array of unsigned data char items and and reports
 * analytics on the maximum, minimum, mean, and median of the dataset while reordering
 * it from large to small.  All statistics are rounded to the nearest integer.
 *
 * @author Joseph George
 * @date 3/3/19
 *
 */

#include <stdio.h>
#include <math.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  unsigned int test_size = sizeof(test)/sizeof(test[0]);

  //sort the array first and verify by printing contents
  sort_array(test, test_size);
  print_array(test, test_size);

  //perform statistics and print them
  unsigned char median = find_median(test, test_size);
  unsigned char mean = find_mean(test, test_size);
  unsigned char maximum = find_maximum(test, test_size);
  unsigned char minimum = find_minimum(test, test_size);

  print_statistics(median, mean, maximum, minimum);

}

 void print_statistics(unsigned char median, unsigned char mean,
                       unsigned char maximum, unsigned char minimum) {
  printf("Printing array statistics...\n");
  printf("The median value is: %d\n", median);
  printf("The mean value is: %d\n", mean);
  printf("The max value is: %d\n", maximum);
  printf("The min value is: %d\n", minimum);

}

void print_array(unsigned char* number_array, unsigned int size) {

  if(size == 0) {
    printf("ERR: Empty array.\n");
    return;
  }

  printf("Printing array...\n");
  for (int index = 0; index < size; index++) {
    printf("Item number %d is: %d\n", index + 1, number_array[index]);
  }
  printf("\n");

}

unsigned char find_median(unsigned char* number_array, unsigned int size) {

  if(size == 0) {
    printf("ERR: Empty array.\n");
    return -1;
  }

  return floor(number_array[(size/2) - 1]);
}

unsigned char find_mean(unsigned char* number_array, unsigned int size) {

  if(size == 0) {
    printf("ERR: Empty array.\n");
    return -1;
  }

  unsigned int sum = 0;
  for(int i = 0; i < size; i++) {
    sum += number_array[i];
  }

  return floor(sum/size);
}

unsigned char find_maximum(unsigned char* number_array, unsigned int size) {

  if(size == 0) {
    printf("ERR: Empty array.\n");
    return -1;
  }

  unsigned char max = 0;

  for(int i = 0; i < size; i++) {
    if(number_array[i] > max) max = number_array[i];
  }

  return max;
}

unsigned char find_minimum(unsigned char* number_array, unsigned int size) {

  if(size == 0) {
    printf("ERR: Empty array.\n");
    return -1;
  }

  unsigned char min = number_array[0];

  for(int i = 1; i < size; i++) {
    if(number_array[i] < min) min = number_array[i];
  }

  return min;
}

/* Utilizes bubble sort for descending order */
void sort_array(unsigned char* number_array, unsigned int size) {

  if(size == 0) {
    printf("ERR: Empty array.\n");
    return;
  }

  for(int i = 0; i < size; i++) {
    for(int j = i + 1; j < size; j++) {

      if(number_array[i] < number_array[j]) {
        unsigned char temp = number_array[i];
        number_array[i] = number_array[j];
        number_array[j] = temp;
      }

    }
  }

}
