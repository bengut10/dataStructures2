#ifndef LLCP_INT_H
#define LLCP_INT_H

#include <iostream>

struct Node
{
   int data;
   Node *link;
};

int    FindListLength(Node* headPtr);
bool   IsSortedUp(Node* headPtr);
void   InsertAsHead(Node*& headPtr, int value);
void   InsertAsTail(Node*& headPtr, int value);
void   InsertSortedUp(Node*& headPtr, int value);
bool   DelFirstTargetNode(Node*& headPtr, int target);
bool   DelNodeBefore1stMatch(Node*& headPtr, int target);
void   ShowAll(std::ostream& outs, Node* headPtr);
void   FindMinMax(Node* headPtr, int& minValue, int& maxValue);
double FindAverage(Node* headPtr);
void   ListClear(Node*& headPtr, int noMsg = 0);

// prototype of SortedMergeRecur
void SortedMergeRecur(Node*& xHead, Node*& yHead, Node*& zHead);

#endif

/*

This part of the assignment aims at providing you with a programming exercise involving recursion and linked list.
(Supplied Files)
Let xHead, yHead and zHead be the head pointers of 3 linked lists of integers (called X-list, Y-list and Z-list, respectively, from here). X-list and Y-list are each sorted (in non-decreasing order) in itself and each may be empty. Z-list is initially empty (i.e., zHead initially contains the null pointer). Develop and test a recursive C++ function called SortedMergeRecur that combines the nodes in X-list and Y-list into Z-list such that, after calling the function, Z-list is a sorted list (in non-decreasing order) containing all the nodes initially contained in X-list and Y-list  –  X-list and Y-list should both be empty after the call.
Other specifications/requirements:
Each node of the list has the following structure:
struct Node
{
    int data;
    Node *link;
};
The function should:
Have only three parameters (pointers to head nodes) and no return value (be a void function).
Not use any global variables or static local variables.
Not use any looping constructs (for, while, do-while, ...).
Be directly (not indirectly) recursive.
Not create any new nodes, destroy any existing nodes or copy/replace the data item of any node.
Not make temporary copies of the data involved using any other storage structures (arrays, stacks, queues, etc.).
Use (if ever needed) no more than a small number of pointers to hold certain link addresses.
Not make temporary copies of the entire list's link addresses wholesale.
Z-list should be sorted at all times as it "grows" from an empty list to one that contains all the nodes originally contained in X-list and Y-list.
What this means is that you should not, for instance, attempt to first append all the nodes in X-list to Z-list, then append all the nodes in Y-list to Z-list, and finally use a sorting algorithm of some kind to sort the nodes in Z-list.
*/
