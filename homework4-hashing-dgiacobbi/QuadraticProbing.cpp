/**
 * @file QuadraticProbing.cpp
 * @author David Giacobbi
 * @brief Functions that define a quadratic probing hash table, including insert, delete, rehash, and find.
 * @version 1.0
 * @date 2022-10-31
 */

#include "Hash.h"
#include <iomanip>
#include <math.h>

class QuadraticProbing : public Hash{

    public:

        /*************************************************************
        * Function: QuadraticProbing(std::vector<std::string> & vec)
        * Date Created: 10/18/22
        * Date Last Modified: 10/30/22
        * Description: EVC constructor that sets hash table variables
        *              to specific values
        * Input parameters: vector of hash table
        * Returns: none
        * Pre: hash table vector has been created
        * Post: values are assigned to all variables
        *************************************************************/
        QuadraticProbing(std::vector<std::string> & vec){
            
            setType("Quadratic Probing");
            setTableSize(vec.size());
            setLoadFactor(0.0);
            setItemCount(0);
            setCollisionNum(0);   
        }

        /*************************************************************
        * Function: hashFunction(std::string str)
        * Date Created: 10/18/22
        * Date Last Modified: 10/30/22
        * Description: gives the hash key based on ASCII value of a string
        * Input parameters: string of value being added to table
        * Returns: int of hash key for value in table
        * Pre: string is made up of ascii value characters
        * Post: initial hash key is found prior to probing
        *************************************************************/
        int hashFunction(std::string str){

            int key = 0;

            // Add all ASCII values of the characters in the string
            for (int i = 0; i < str.size(); i++)
                key += str.at(i);

            // Mod by table size to find key within bounds
            key = key % getTableSize();

            return key;
        }

        /*************************************************************
        * Function: insertItem(std::vector<std::string> & vec, std::string str)
        * Date Created: 10/18/22
        * Date Last Modified: 10/30/22
        * Description: use quadratic probing to insert item into hash table
        * Input parameters: string of value being added to table,
        *                   vector of hash table being added to
        * Returns: none
        * Pre: vector has a load factor < 0.5
        * Post: str is added to the hash table, hash table has been rehashed
        *       (if necessary)
        *************************************************************/
        void insertItem(std::vector<std::string> & vec, std::string str){

            // Find hashkey
            int key = hashFunction(str);

            // Quadratic Probe through the rest of the table
            for (int i = 0; i < vec.size(); i++){

                key = (key + int(pow(i, 2))) % getTableSize();

                // Check if current spot is empty; if so, add string to current spot
                if (vec.at(key).compare("") == 0 || vec.at(key).compare("DELETED") == 0){

                    vec.at(key) = str;
                    break;
                }
                // Increase collision number
                setCollisionNum(getCollisionNum() + 1);                 
            }
            // Set item count and load factors
            setItemCount(getItemCount() + 1);
            setLoadFactor(double(getItemCount()) / double(getTableSize()));

            // Check for a rehash
            if(checkRehash(vec))
                rehash(vec);
        }

        /*************************************************************
        * Function: removeItem(std::vector<std::string> & vec, std::string str)
        * Date Created: 10/18/22
        * Date Last Modified: 10/30/22
        * Description: performs a lazy deletion on hash table given a string
        * Input parameters: string of value being deleted from table,
        *                   vector of hash table being deleted from
        * Returns: none
        * Pre: vector has a load factor < 0.5
        * Post: str has been removed from the hash table and replaced
        *       with "DELETED" string, load factor decreased
        *************************************************************/
        void removeItem(std::vector<std::string> & vec, std::string str){

            int key = hashFunction(str);

            // Determine if item being deleted is in the hash table
            if (!findItem(vec, str)){

                std::cout << "\nItem not found.\n" << std::endl;
                return;
            }   
            // Quadratic Probe from hash key until item is reached
            for (int i = 0; i < vec.size(); i++){

                key = (key + int(pow(i, 2))) % getTableSize();

                // Perform a lazy deletion on item
                if (vec.at(key).compare(str) == 0)
                    vec.at(key) = "DELETED";
            }
            // Update Item Count and Load Factor
            setItemCount(getItemCount() - 1);
            setLoadFactor(double(getItemCount()) / double(getTableSize()));
        }

        /*************************************************************
        * Function: findItem(std::vector<std::string> & vec, std::string str)
        * Date Created: 10/18/22
        * Date Last Modified: 10/30/22
        * Description: searches hash table for an item by finding index
        * Input parameters: string of value being searched,
        *                   vector of hash table being searched through
        * Returns: bool value of if item was found
        * Pre: vector has a load factor < 0.5
        * Post: hash table remains the same
        *************************************************************/
        bool findItem(std::vector<std::string> & vec, std::string str){

            int key = hashFunction(str);
            
            // Quadratic Probe hash table until item is found or return false
            for (int i = 0; i < vec.size(); i++){

                key = (key + int(pow(i, 2))) % getTableSize();

                if (vec.at(key).compare(str) == 0)
                    return true;
            }
            return false;
        }

        /*************************************************************
        * Function: rehash(std::vector<std::string> & vec)
        * Date Created: 10/18/22
        * Date Last Modified: 10/30/22
        * Description: rehashes the table by moving all elements from old
        *              hash table to a larger hash table
        * Input parameters: vector of hash table needing rehashing
        * Returns: none
        * Pre: vector has a load factor > 0.5
        * Post: hash table attributes updated accordingly
        *************************************************************/
        void rehash(std::vector<std::string> & vec){

            // Determine the new table size that is a prime number double the size
            // of current table, create new vector with this size
            int newSize = calcNewTableSize(getTableSize());
            std::vector<std::string> newVec(newSize);

            // Traverse through current hash table, moving elements one by one
            for (int i = 0; i < vec.size(); i++){

                int key = hashFunction(vec.at(i));

                // Quadratic probe the new hash table, adding elements to next available spots
                for (int j = 0; j < newVec.size(); j++){

                    key = (key + int(pow(j, 2))) % newVec.size();

                    if (newVec.at(key).compare("") == 0){

                        newVec.at(key) = vec.at(i);
                        break;
                    }           
                }
            }    

            // Assign larger vector to vec
            vec = newVec;

            // Update hash table attributes
            setTableSize(newSize);
            setLoadFactor(double(getItemCount())/double(getTableSize()));
        }

        /*************************************************************
        * Function: printTable(std::vector<std::string> &vec)
        * Date Created: 10/18/22
        * Date Last Modified: 10/30/22
        * Description: prints the stats of the hash table and contents
        * Input parameters: vector of hash table
        * Returns: none
        * Pre: vector is a hash table
        * Post: hash table displayed to terminal
        *************************************************************/
        void printTable(std::vector<std::string> &vec){

            std::cout << "\n---------------HASH TABLE RESULTS---------------\n" << std::endl;

            // Displays hash table stats
            std::cout << "Load Factor: " << getLoadFactor() << std::endl;
            std::cout << "Item Count: " << getItemCount() << std::endl;
            std::cout << "Number of Collisions: " << getCollisionNum() << std::endl << std::endl; 

            // Displays hash table contents
            for (int i = 0; i < vec.size(); i++)
                std::cout << "Index: " << std::setw(2) << i << "    | Value: " << vec.at(i) << std::endl;
            
            std::cout << "\n\n\n";  
        }

        /*************************************************************
        * Function: checkRehash(std::vector<std::string> & vec)
        * Date Created: 10/18/22
        * Date Last Modified: 10/30/22
        * Description: checks load factor to determine a rehash
        * Input parameters: vector of hash table being checked
        * Returns: bool of if rehash is needed
        * Pre: vector is a hash table with load factor
        * Post: hash table is unchanged
        *************************************************************/
        bool checkRehash(std::vector<std::string> & vec){

            if (getLoadFactor() > 0.5)
                return true;

            return false;
        }
};