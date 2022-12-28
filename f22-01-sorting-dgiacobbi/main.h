/**
 * @file main.h
 * @author David Giacobbi
 * @brief Function declaration for the testing program in main.
 * @version 1.1
 * @date 2022-09-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef MAIN_H
#define MAIN_H

#include<iostream>
#include "sort.h"
#include "bubbleSort.h"
#include "bubblesort_optimized.h"
#include "insertionSort.h"
#include "selectionSort.h"
#include "standardSort.h"
#include "mergeSort.h"

using namespace std;

void printVector(vector<int> &vec);
void fillVectorRandom(vector<int> &vec, int count);
void fillVectorAsc(vector<int> &vec, int count);
void fillVectorDsc(vector<int> &vec, int count);
void testSort(Sort* sort, vector<int> &vec, string initialCondition, int size, int iterationCount);

#endif