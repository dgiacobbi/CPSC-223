/**
 * @file standardSort.h
 * @author David Giacobbi
 * @brief This sort is found in the std C++ library. It is a built-in function.
 * @version 1.1
 * @date 2022-09-19
 * 
 */

#include "sort.h"
#include<algorithm>

class StandardSort : public Sort{

    public:
        StandardSort(){
            name = "Std::sort";
        }

        void doSort(std::vector<int> &vec) {
            std::sort(vec.begin(), vec.end());
        }

};