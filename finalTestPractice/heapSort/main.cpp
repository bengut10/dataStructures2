//
//  main.cpp
//  heapSort
//
//  Created by Benjamin Gutierrez on 4/28/16.
//  Copyright (c) 2016 Benjamin Gutierrez. All rights reserved.

#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>

using namespace std;

void heapifySemiheap(int* data, int root, int used);
bool is_leaf(int i, int used);
void heapSort(int* data, int root, int used);

int main(int argc, const char * argv[]) {

    srand (time(NULL));
    int heapSize = 15;
    int data[heapSize];
    int* dataArray;
    dataArray = data;
    int used = 0 ;
    for(int i = 0; i < heapSize; i++)
    {
        data[i] = rand() % 100 + 1;
        used++;
    }
    for(int i = 0; i < heapSize; i++)
    {
        cout << data[i] << "  ";
    }
    
    cout << endl;

    heapSort(dataArray, 0, used);
    
    for(int i = 0; i < heapSize; i++)
    {
        cout << data[i] << "  ";
    }
    return 0;
}

void heapSort(int* data, int root, int used)
{
    //Step 1: Build max heap applying Rehapification Downward (Heapify SemiHeap / Dequing)
    for(int i = (used/2); i >= 0; i --)
    {
        heapifySemiheap(data, i, used);
    }
    cout << endl;
    for(int i = 0; i < used; i++)
    {
        cout << data[i] << "  ";
    }
    cout << endl;
    
    //Step 2: Swap nodes from last to root to separate sorted regions.
    for(int i = used-1; i >= 2; i--)
    {
        int temp = data[i];
        data[i] = data[0];
        data[0] = temp;
    //Step 3: Heapify Semiheap on region that is not sorted only
        heapifySemiheap(data, 0, i-1);
    }
}

void heapifySemiheap(int* data, int root, int used)
{
    if(is_leaf(root, used))
    {
        return;
    }
    int leftChild = (2*root) + 1;
    int rightChild = (2*root) + 2;
    int largestChild;
    int temp;
    if(rightChild >= used)
    {
        largestChild = leftChild;
    }
    data[leftChild] > data[rightChild] ?
    largestChild = leftChild : largestChild = rightChild;

    if(data[largestChild] > data[root])
    {
        temp = data[largestChild];
        data[largestChild] = data[root];
        data[root] = temp;
    }
    heapifySemiheap(data, largestChild, used);
}

bool is_leaf(int i, int used)
{
    return (2*i)+1 >= used;
}


