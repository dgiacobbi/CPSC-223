/**
 * @file bubblesort_optimized.h
 * @author David Giacobbi
 * @brief The optimized bubble sort runs the same algorithm as the bubble sort; however,
 *        a parameter is added that checks to see if the list is already sorted on the first
 *        pass of the program.
 * @version 1.1
 * @date 2022-09-19
 * 
 */

#include "sort.h"

class BubbleSortOptimized : public Sort{

    public:
        BubbleSortOptimized(){
            name = "Bubble Sort (Optimized)";
        }

        void doSort(std::vector<int> &vec) {
            
            // Parameter to check if list is already sorted
            bool full_pass = false;

            for (std::size_t i = 0; (full_pass == false && i < vec.size() - 1); i++){

                // Assume list is already sorted until two elements are swapped
                full_pass = true;

                // Swaps neighboring elements where the left element is greater than the right
                for (std::size_t j = 0; j < vec.size() - i - 1; j++){

                    if (vec.at(j) > vec.at(j + 1)){

                        std::swap(vec.at(j), vec.at(j + 1));
                        full_pass = false;
                    }
                }
            }
        }
};