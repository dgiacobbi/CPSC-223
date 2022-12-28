/**
 * @file mergeSort.h
 * @author David Giacobbi
 * @brief The merge sort is a recursive sorting algorithm that breaks up the list
 *        into smaller sectors, until the sector is only 1 element large. Then, moving
 *        back up the tree, the smaller sectors are sorted as they are combined.
 * @version 1.1
 * @date 2022-10-3
 * 
 */

#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include "sort.h"

class MergeSort : public Sort{

    public:

        MergeSort(){
            name = "Merge Sort";
        }

        void doSort(std::vector<int> &vec) {

            mergeSort(vec);
        }

        /*************************************************************
        * Function: mergeSort(vector<int>)
        * Date Created: 9/28/22
        * Date Last Modified: 9/28/22
        * Description: This function declares and sets the variables
        * needed for the merge sort.
        * Input parameters: integer vector to be sorted
        * Returns: void
        * Pre: vector has to be a pass by reference to remember order
        * Post: vector is sorted
        *************************************************************/
        void mergeSort(std::vector<int> &a) {

            // Declare variables to sort vector given
            std::vector<int> tmpArray(a.size());
            int left, right;

            // Set left and right to position bounds of vector
            left = 0;
            right = a.size() - 1;

            // Call recursive function
            mergeSort(a, tmpArray, left, right);
        }

        /*************************************************************
        * Function: mergeSort(vector<int>, vector<int>, int, int)
        * Date Created: 9/28/22
        * Date Last Modified: 9/28/22
        * Description: This function recursively splits array into
        * singular elements. It also calls the merge function to sort.
        * Input parameters: Vector to be sorted, temporary vector as a 
        * work space, ints of furthest left and right positions
        * Returns: void
        * Pre: Both vectors must be pass by reference
        * Post: The vector is merged sorted
        * Reference: Byran Fischer CPSC 223 Lecture 8
        *************************************************************/
        void mergeSort(std::vector<int> &a, std::vector<int> &tmpArray, int left, int right) {

            // Check to make sure current vector has size of at least 1
            if (right > left){

                // Find middle of vector a
                int middle = (right + left) / 2;

                // Call mergeSort to recursively divide vector in half 
                // until each call consists of only one element
                mergeSort(a, tmpArray, left, middle);
                mergeSort(a, tmpArray, middle + 1, right);

                // Merge the calls of the divided array back together, sorted
                merge(a, tmpArray, left, middle + 1, right);
            }
        }

        /*************************************************************
        * Function: merge(vector<int>, vector<int>, int, int, int)
        * Date Created: 9/28/22
        * Date Last Modified: 9/28/22
        * Description: This function utilizes the vector workspace to
        * sort elements as they merge back up the recursion tree.
        * Input parameters: Vector to be sorted, temporary vector as a
        * work space, furthest left position of first vector being sorted,
        * furthest right position of second sort vector, position of furthest
        * right end of the second vector
        * Returns: void
        * Pre: The vectors are split and are merging back up recursion tree
        * Post: The elements between the two vectors are sorted together
        * Reference: Byran Fischer CPSC 223 Lecture 8
        *************************************************************/
        void merge(std::vector<int> &a, std::vector<int> &tmpArray, int leftPos, int rightPos, int rightEnd) {

            // Determine the position indicies of the current vector bounds and size
            int leftEnd = rightPos - 1;
            int tempPos = leftPos;
            int elemNum = rightEnd - leftPos + 1;

            // Loop used to sort the two subsections until both sections have been sorted
            while (leftPos <= leftEnd && rightPos <= rightEnd) {

                // Compare first elements in two subsections, moving 
                // lower element into front of sorted section
                if (a.at(leftPos) <= a.at(rightPos))
                    tmpArray.at(tempPos++) = std::move(a.at(leftPos++));
                else
                    tmpArray.at(tempPos++) = std::move(a.at(rightPos++));
            }

            // Move the rest of the left half back over
            while (leftPos <= leftEnd)
                tmpArray.at(tempPos++) = std::move(a.at(leftPos++));

            // Move the rest of the right half back over
            while (rightPos <= rightEnd)
                tmpArray.at(tempPos++) = std::move(a.at(rightPos++));

            // Move the rest of elements back into the temp array   
            for (int i = 0; i < elemNum; ++i, --rightEnd)
                    a.at(rightEnd) = std::move(tmpArray.at(rightEnd));
        }
};

#endif