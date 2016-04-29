//  main.cpp
//  HashFunctions
//  Created by Benjamin Gutierrez on 4/28/16.
//  Copyright (c) 2016 Benjamin Gutierrez. All rights reserved.

#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>

using namespace std;
int hashValue(int key);
int linearProbing(int hashValue, int key);
int quadraticProbing(int i, int key);
int doubleHashingAux(int key);
int doubleHashing(int i, int key);

int TABLE_SIZE = 17;

int main(int argc, const char * argv[]) {
    srand (time(NULL));
    int hashTable[TABLE_SIZE];
    int hashTable2[TABLE_SIZE];
    int tempArray[TABLE_SIZE];
    int hashTable3[TABLE_SIZE];
    
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        hashTable[i] = -1;
        hashTable2[i]= -1;
        hashTable3[i]= -1;
    }
    int lp = 0;
    int used = 0;
    int i = 0;
    int key;
    int qp = 0;
    int dh = 0;
    for(int j = 0; j < 10; j++)
    {
        key = rand() % 100 + 1;
        tempArray[j] = key;
        
        if(TABLE_SIZE == used)
        {
            cerr << "Cannot insert anymore, 'FULL TABLE'" << endl;
            break;
        }
        if(hashTable[hashValue(key)] == -1)
        {
            hashTable[hashValue(key)] = key;
            used ++;
        }
        else
        {
            lp++;
            while(hashTable[linearProbing(i, key)] != -1)
            {
                lp++;
                i++;
            }
            hashTable[linearProbing(i, key)] = key;
            used ++;
        }
    }
    used = 0;
    for(int j = 0; j < 10; j++)
    {
        key = tempArray[j];
        if(TABLE_SIZE == used)
        {
            cerr << "Cannot insert anymore, 'FULL TABLE'" << endl;
            break;
        }
        if(hashTable2[hashValue(key)] == -1)
        {
            hashTable2[hashValue(key)] = key;
            used ++;
        }
        else
        {
            qp++;
            i = 0;
            while(hashTable2[quadraticProbing(i, key)] != -1)
            {
                qp++;
                i++;
            }
            hashTable2[quadraticProbing(i, key)] = key;
            used ++;
        }
    }
    used = 0;
    for(int j = 0; j < 10; j++)
    {
        key = tempArray[j];
        if(TABLE_SIZE == used)
        {
            cerr << "Cannot insert anymore, 'FULL TABLE'" << endl;
            break;
        }
        if(hashTable3[hashValue(key)] == -1)
        {
            hashTable3[hashValue(key)] = key;
            used ++;
        }
        else
        {
            dh++;
            i = 0;
            while(hashTable3[doubleHashing(i, key)] != -1)
            {
                dh++;
                i++;
            }
            hashTable3[doubleHashing(i, key)] = key;
            used ++;
        }
    }
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        cout <<"[" << i <<"]=       " <<   hashTable[i] <<
        "      " << hashTable2[i] << "       "
        << hashTable3[i] <<  endl;
    }
    cout << "number of linear probing times the function was called " << lp << endl;
    cout << "number of quadratic probing times the function was called " << qp << endl;
    cout << "number of double hashing times the function was called " << dh << endl;
    return 0;
}

int hashValue(int key)
{
    return key % TABLE_SIZE;
}

int linearProbing(int i,int key)
{
    int loc = hashValue(key);
    int newLoc = (loc + (i*1)) % TABLE_SIZE;
    return newLoc;
}

int quadraticProbing(int i, int key)
{
    int loc = hashValue(key);
    int newLoc = (loc + (i*i)) % TABLE_SIZE;
    return newLoc;
}

int doubleHashing(int i, int key)
{
    int loc = doubleHashingAux(key);
    int newLoc = (loc + (i*loc)) % TABLE_SIZE;
    return newLoc;
}

int doubleHashingAux(int key)
{
    return 1 + (key % TABLE_SIZE - 2);
}
