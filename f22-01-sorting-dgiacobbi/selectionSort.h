/**
 * @file selectionsort.h
 * @author David Giacobbi
 * @brief Selection sort traverses the list and finds the smallest element. The smallest
 *        element is then moved to the back of the sorted subset.
 * @version 1.1
 * @date 2022-09-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include "sort.h"

class SelectionSort : public Sort{

    public:
        SelectionSort(){
            name = "Selection Sort";
        }

        void doSort(std::vector<int> &vec) {
            
            int cur_min, min_idx;

            for (int i = 0; i < vec.size(); i++){

                // Set the minimum element and index to the next element in unsorted subset
                cur_min = vec.at(i);
                min_idx = i;

                // Find the smallest element in list
                for (int j = i; j < vec.size(); j++){

                    if (vec.at(j) < cur_min){

                        cur_min = vec.at(j);
                        min_idx = j;
                    }
                }
                // Swap elements
                std::swap(vec.at(min_idx), vec.at(i));
            }
        }
};

#endif