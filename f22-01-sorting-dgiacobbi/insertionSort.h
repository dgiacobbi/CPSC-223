/**
 * @file insertionSort.h
 * @author David Giacobbi
 * @brief Insertion sort takes individual elements from the unsorted subset and
 *        inserts them into their rightful place in the sorted subset.
 * @version 1.1
 * @date 2022-09-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "sort.h"

class InsertionSort : public Sort{

    public:
        InsertionSort(){
            name = "Insertion Sort";
        }

        void doSort(std::vector<int> &vec) {
            
            int key, j;

            // Traverse through length of list
            for (int i = 1; i < vec.size(); i++){

                // Pick next element in unsorted section
                key = vec.at(i);
                j = i - 1;

                // Insert element in sorted section in rightful place
                while (j >= 0 && vec.at(j) > key){

                    vec.at(j + 1) = vec.at(j);
                    j = j - 1;
                }

                // Assign next element of unsorted section for insertion
                vec.at(j + 1) = key;
            }
        }
};

#endif