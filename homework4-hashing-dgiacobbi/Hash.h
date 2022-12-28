/**
 * @file Hash.h
 * @author David Giacobbi
 * @brief Makes up the basic variables and functions of any type of hash table.
 * @version 1.0
 * @date 2022-10-18
 */

#ifndef HASH_H
#define HASH_H

#include<string>
#include<vector>
#include<iostream>
#include<cmath>

class Hash{

    public:

        int calcNewTableSize(int prevSize){
            
            int newSize = prevSize * 2;

            while(!isPrime(newSize))
                newSize += 1;

            return newSize;
        }

        int getTableSize(){
            return tableSize;
        }

        double getLoadFactor(){
            return loadFactor;
        }

        std::string getType(){
            return type;
        }

        void setTableSize(int size){
            this->tableSize = size;
        }

        void setLoadFactor(double loadFactor){
            this->loadFactor = loadFactor;
        }

        void setType(std::string type){
            this->type = type;
        }

        int getItemCount(){
            return this->itemCount;
        }

        void setItemCount(int count){
            this->itemCount = count;
        }

        int getCollisionNum(){
            return this->collisionNum;
        }

        void setCollisionNum(int num){
            this->collisionNum = num;
        }

        bool isPrime(int number){
            
            for (int i = 2; i < sqrt(number); i++){

                if ((number % i) == 0)
                    return false; 
            }
            return true;
        }

        virtual ~Hash(){

        }

        virtual int hashFunction(std::string) = 0;
        virtual void insertItem(std::vector<std::string> & vec, std::string str) = 0;
        virtual void removeItem(std::vector<std::string> & vec, std::string str) = 0;
        virtual bool findItem(std::vector<std::string> & vec, std::string str) = 0;
        virtual void rehash(std::vector<std::string> & vec) = 0;
        virtual void printTable(std::vector<std::string> & vec) = 0;
        virtual bool checkRehash(std::vector<std::string> & vec) = 0;

    private:

        std::string type;
        int tableSize;
        int itemCount;
        int collisionNum;
        double loadFactor;

};

#endif