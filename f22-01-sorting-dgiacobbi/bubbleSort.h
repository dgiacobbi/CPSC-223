/**
 * @file bubbleSort.h
 * @author David Giacobbi
 * @brief This algorithm checks neighboring elements and swaps elements whose left is greater than right.
 * @version 1.1
 * @date 2022-09-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "sort.h"

class BubbleSort : public Sort{

    public:
        BubbleSort(){
            name = "Bubble Sort";
        }

        void doSort(std::vector<int> &vec) {
            
            // Traverse through list
            for (std::size_t i = 0; i < vec.size() - 1; i++)

                for (std::size_t j = 0; j < vec.size() - i - 1; j++)

                    // Swap elements whose right side is less than left side
                    if (vec.at(j) > vec.at(j + 1))
                        std::swap(vec.at(j), vec.at(j + 1));
        }
};