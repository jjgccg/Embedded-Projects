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
 * @file stats.h
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

#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief Prints array statistics
 *
 * A function that prints the statistics of an array, including
 * the minimum, maximum, mean, and median.
 *
 * @param median Calculated median value
 * @param mean Calculated mean value
 * @param maximum Calculated maximum value
 * @param minimum Calculated minimum value
 */
 void print_statistics(unsigned char median, unsigned char mean,
                       unsigned char maximum, unsigned char minimum);

/**
 * @brief Prints an array
 *
 * Given an array of data an a length, prints the array
 * to the screen.
 *
 * @param number_array The data to perform statistics on
 * @param size The size of the array
 */
 void print_array(unsigned char* number_array, unsigned int size);

/**
 * @brief Finds the median in an array
 *
 * Given an array of data an a length, returns the median value
 *
 * @param number_array The data to perform statistics on
 * @param size The size of the array
 * @return The median value of the data, or -1 if empty
 */
 unsigned char find_median(unsigned char* number_array, unsigned int size);

/**
 * @brief Finds the mean in an array
 *
 * Given an array of data an a length, returns the mean value
 *
 * @param number_array The data to perform statistics on
 * @param size The size of the array
 * @return The mean value of the data, or -1 if empty
 */
 unsigned char find_mean(unsigned char* number_array, unsigned int size);

/**
 * @brief Finds the maximum in an array
 *
 * Given an array of data an a length, returns the maximum value
 *
 * @param number_array The data to perform statistics on
 * @param size The size of the array
 * @return The maximum value of the data, or -1 if empty
 */
 unsigned char find_maximum(unsigned char* number_array, unsigned int size);

/**
 * @brief Finds the minimum in an array
 *
 * Given an array of data an a length, returns the minimum value
 *
 * @param number_array The data to perform statistics on
 * @param size The size of the array
 * @return The minimum value of the data, or -1 if empty
 */
 unsigned char find_minimum(unsigned char* number_array, unsigned int size);

/**
 * @brief Sorts an array
 *
 * Given an array of data an a length, sorts the array from
 * largest to smallest.
 *
 * @param number_array The data to sort
 * @param size The size of the array
 */
 void sort_array(unsigned char* number_array, unsigned int size);

#endif /* __STATS_H__ */
