/**
 * @file sort.h
 * @author David Giacobbi
 * @brief 
 * @version 1.1
 * @date 2022-09-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef SORT_H
#define SORT_H

#include<vector>
#include<string>
#include<iostream>
#include<cassert>

class Sort{

    public:
        std::string name;
        double sortTime;
        clock_t time_begin;
        clock_t time_end;

        /**
         *  Converts the results of a sorting algorithm's run to a string
         */
        std::string toString() {
            std::string str = "Sort type: " + name;
            return str;
        }

        // General API for getters and setters
        std::string getName() {
            return name; 
        }

        double getSortTime() {
            return sortTime; 
        }

        void checkSorted(std::vector<int> &vec){
            if(vec.size() > 1){
                for(std::size_t i = 1; i < vec.size(); i++){
                    assert (vec.at(i - 1) <= vec.at(i));
                }
            }
        }

        void sortVector(std::vector<int> & vec){

            sortTime = 0.0;
            time_begin = clock();

            doSort(vec);

            time_end = clock();
            sortTime = (time_end - time_begin) / (double)CLOCKS_PER_SEC;
     
        }

        // doSort should be implemented by each sorting class implementations
        virtual void doSort(std::vector<int> & vec) = 0;

};

#endif