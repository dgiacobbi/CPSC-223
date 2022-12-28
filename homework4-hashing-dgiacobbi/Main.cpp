/**
 * @file Main.cpp
 * @author David Giacobbi
 * @brief Runs the hash table tests to verify that linear and quadratic probing both perform correctly.
 * @version 1.0
 * @date 2022-10-18
 */

#include "Main.h"

int main(){
    
    //visualTestCase();

    //testLinearInsertOneCollision();
    //testLinearInsertMultipleCollisionRehash();
    //testLinearDeleteItem();
    //testLinearSearch();

    //testQuadraticInsertOneCollision();
    //testQuadraticInsertMultipleCollisionRehash();
    //testQuadraticDeleteItem();
    //testQuadraticSearch();
}

//print out the hash table after each operation
//showing your program can resolve collisions and
//rehash properly.
void visualTestCase(){

    //creates a new vector of size 11
    std::vector<std::string> hashTable(11);

    //create a new linearHash object
    LinearProbing* linearHash = new LinearProbing(hashTable);

    //print the empty hash table
    linearHash->printTable(hashTable);

    linearHash->insertItem(hashTable, "megan");
    linearHash->printTable(hashTable);

    linearHash->insertItem(hashTable, "david");
    linearHash->printTable(hashTable);

    linearHash->insertItem(hashTable, "casi");
    linearHash->printTable(hashTable);

    linearHash->insertItem(hashTable, "ganem");
    linearHash->printTable(hashTable);

    linearHash->insertItem(hashTable, "icas");
    linearHash->printTable(hashTable);
}

//sample test case that should check the hashtable changes in size from 11 to 23
void testLinearInsertMultipleCollisionRehash(){

    //creates a new vector of size 11
    std::vector<std::string> hashTable(11);

    //create a new linearHash object
    LinearProbing* linearHash = new LinearProbing(hashTable);

    //print the empty hash table
    linearHash->printTable(hashTable);

    //each of these strings hash to be the same
    linearHash->insertItem(hashTable, "abcdefg");
    linearHash->insertItem(hashTable, "bcdefga");
    linearHash->insertItem(hashTable, "cdefgab");
    linearHash->insertItem(hashTable, "defgabc");
    linearHash->insertItem(hashTable, "efgabcd");
    linearHash->insertItem(hashTable, "fgabcde");
    linearHash->insertItem(hashTable, "gabcdef");

    //print the new hashTable
    linearHash->printTable(hashTable);

    //since load factor increased beyond threshold, table should have been rehashed
    assert(linearHash->getTableSize() == 23);

    delete linearHash;   
}

//simple test case to check that a collision is resolved with linear probing
void testLinearInsertOneCollision(){

    //setup the states of the test
    std::vector<std::string>hashTable(11);

    LinearProbing* linearHash = new LinearProbing(hashTable);

    linearHash->insertItem(hashTable, "abc");
    linearHash->insertItem(hashTable, "bac");

    //check that "abc" and "bac" were placed in the correct locations
    int index = linearHash->hashFunction("abc");
    assert(hashTable.at(index) == "abc" && hashTable.at(index + 1) == "bac");

    std::cout << "test case passed: linear probing insertion one collison" << std::endl;

    delete linearHash;
}

//simple test case to check if different items can be deleted from hash table properly
void testLinearDeleteItem(){

    //creates a new vector of size 11
    std::vector<std::string> hashTable(11);

    //create a new linearHash object
    LinearProbing* linearHash = new LinearProbing(hashTable);

    //each of these strings hash to be the same
    linearHash->insertItem(hashTable, "abcdefg");
    linearHash->insertItem(hashTable, "bcdefga");
    linearHash->insertItem(hashTable, "cdefgab");
    linearHash->insertItem(hashTable, "defgabc");
    linearHash->insertItem(hashTable, "efgabcd");
    linearHash->insertItem(hashTable, "fgabcde");
    linearHash->insertItem(hashTable, "gabcdef");

    //print the hashTable
    linearHash->printTable(hashTable);

    //delete three items in hash table
    linearHash->removeItem(hashTable, "efgabcd");
    linearHash->removeItem(hashTable, "fgabcde");
    linearHash->removeItem(hashTable, "gabcdef");

    //print the new hashTable
    linearHash->printTable(hashTable);

    //since load factor increased beyond threshold, table should have been rehashed
    bool found = linearHash->findItem(hashTable, "fgabcde");
    assert(!found);

    delete linearHash;  
}

//simple test to determine if hash table can search for items correctly
void testLinearSearch(){

    //setup the states of the test
    std::vector<std::string>hashTable(11);

    LinearProbing* linearHash = new LinearProbing(hashTable);

    linearHash->insertItem(hashTable, "abc");
    linearHash->insertItem(hashTable, "bac");

    //check that "abc" and "bac" were identified in hash table
    bool found1 = linearHash->findItem(hashTable, "abc");
    bool found2 = linearHash->findItem(hashTable, "bac");
    assert(found1 && found2);

    std::cout << "test case passed: linear probing find item" << std::endl;

    delete linearHash;
}

//simple test case to check that a collision is resolved with linear probing
void testQuadraticInsertOneCollision(){

    //setup the states of the test
    std::vector<std::string>hashTable(11);

    QuadraticProbing* quadHash = new QuadraticProbing(hashTable);

    quadHash->insertItem(hashTable, "abc");
    quadHash->insertItem(hashTable, "bac");

    //check that "abc" and "bac" were placed in the correct locations
    int index = quadHash->hashFunction("abc");
    assert(hashTable.at(index) == "abc" && hashTable.at(index + 1) == "bac");

    std::cout << "test case passed: linear probing insertion one collison" << std::endl;

    delete quadHash;
}

//sample test case that should check the hashtable changes in size from 11 to 23
void testQuadraticInsertMultipleCollisionRehash(){

    //creates a new vector of size 11
    std::vector<std::string> hashTable(11);

    //create a new quadHash object
    QuadraticProbing* quadHash = new QuadraticProbing(hashTable);

    //print the empty hash table
    quadHash->printTable(hashTable);

    //each of these strings hash to be the same
    quadHash->insertItem(hashTable, "abcdefg");
    quadHash->insertItem(hashTable, "bcdefga");
    quadHash->insertItem(hashTable, "cdefgab");
    quadHash->insertItem(hashTable, "defgabc");
    quadHash->insertItem(hashTable, "efgabcd");
    quadHash->insertItem(hashTable, "fgabcde");
    quadHash->insertItem(hashTable, "gabcdef");

    //print the new hashTable
    quadHash->printTable(hashTable);

    //since load factor increased beyond threshold, table should have been rehashed
    assert(quadHash->getTableSize() == 23);

    delete quadHash;   
}

//simple test case to check if different items can be deleted from hash table properly
void testQuadraticDeleteItem(){

    //creates a new vector of size 11
    std::vector<std::string> hashTable(11);

    //create a new quadHash object
    QuadraticProbing* quadHash = new QuadraticProbing(hashTable);

    //each of these strings hash to be the same
    quadHash->insertItem(hashTable, "abcdefg");
    quadHash->insertItem(hashTable, "bcdefga");
    quadHash->insertItem(hashTable, "cdefgab");
    quadHash->insertItem(hashTable, "defgabc");
    quadHash->insertItem(hashTable, "efgabcd");
    quadHash->insertItem(hashTable, "fgabcde");
    quadHash->insertItem(hashTable, "gabcdef");

    //print the hashTable
    quadHash->printTable(hashTable);

    //delete three items in hash table
    quadHash->removeItem(hashTable, "efgabcd");
    quadHash->removeItem(hashTable, "fgabcde");
    quadHash->removeItem(hashTable, "gabcdef");

    //print the new hashTable
    quadHash->printTable(hashTable);

    //since load factor increased beyond threshold, table should have been rehashed
    bool found = quadHash->findItem(hashTable, "fgabcde");
    assert(!found);

    delete quadHash;  
}

//simple test to determine if hash table can search for items correctly
void testQuadraticSearch(){

    //setup the states of the test
    std::vector<std::string>hashTable(11);

    QuadraticProbing* quadHash = new QuadraticProbing(hashTable);

    quadHash->insertItem(hashTable, "abc");
    quadHash->insertItem(hashTable, "bac");

    //check that "abc" and "bac" were identified in hash table
    bool found1 = quadHash->findItem(hashTable, "abc");
    bool found2 = quadHash->findItem(hashTable, "bac");
    assert(found1 && found2);

    std::cout << "test case passed: quad probing find item" << std::endl;

    delete quadHash;
}