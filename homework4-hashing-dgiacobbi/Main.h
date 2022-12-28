/**
 * @file Main.h
 * @author David Giacobbi
 * @brief 
 * @version 1.0
 * @date 2022-10-18
 * 
 */

#ifndef MAIN_H
#define MAIN_H

#include<vector>
#include<iostream>
#include<assert.h>

//include files
#include "Hash.h"
#include "LinearProbing.cpp"
#include "QuadraticProbing.cpp"

using namespace std;

//function prototypes
void testLinearInsertOneCollision();
void testLinearInsertMultipleCollisionRehash();
void visualTestCase();
void testLinearDeleteItem();
void testQuadraticInsertMultipleCollisionRehash();
void testQuadraticInsertOneCollision();
void testQuadraticDeleteItem();
void testLinearSearch();
void testQuadraticSearch();


#endif