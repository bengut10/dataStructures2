#include <iostream>
#include <cstdlib>
#include <cassert>
#include "llcpInt.h"
using namespace std;

int FindListLength(Node* headPtr)
{
   int length = 0;

   while (headPtr != 0)
   {
      ++length;
      headPtr = headPtr->link;
   }

   return length;
}

bool IsSortedUp(Node* headPtr)
{
   if (headPtr == 0 || headPtr->link == 0) // empty or 1-node
      return true;
   while (headPtr->link != 0) // not at last node
   {
      if (headPtr->link->data < headPtr->data)
         return false;
      headPtr = headPtr->link;
   }
   return true;
}

void InsertAsHead(Node*& headPtr, int value)
{
   Node *newNodePtr = new Node;
   newNodePtr->data = value;
   newNodePtr->link = headPtr;
   headPtr = newNodePtr;
}

void InsertAsTail(Node*& headPtr, int value)
{
   Node *newNodePtr = new Node;
   newNodePtr->data = value;
   newNodePtr->link = 0;
   if (headPtr == 0)
      headPtr = newNodePtr;
   else
   {
      Node *cursor = headPtr;

      while (cursor->link != 0) // not at last node
         cursor = cursor->link;
      cursor->link = newNodePtr;
   }
}

void InsertSortedUp(Node*& headPtr, int value)
{
   Node *precursor = 0,
        *cursor = headPtr;

   while (cursor != 0 && cursor->data < value)
   {
      precursor = cursor;
      cursor = cursor->link;
   }

   Node *newNodePtr = new Node;
   newNodePtr->data = value;
   newNodePtr->link = cursor;
   if (cursor == headPtr)
      headPtr = newNodePtr;
   else
      precursor->link = newNodePtr;

   ///////////////////////////////////////////////////////////
   /* using-only-cursor (no precursor) version
   Node *newNodePtr = new Node;
   newNodePtr->data = value;
   //newNodePtr->link = 0;
   //if (headPtr == 0)
   //   headPtr = newNodePtr;
   //else if (headPtr->data >= value)
   //{
   //   newNodePtr->link = headPtr;
   //   headPtr = newNodePtr;
   //}
   if (headPtr == 0 || headPtr->data >= value)
   {
      newNodePtr->link = headPtr;
      headPtr = newNodePtr;
   }
   //else if (headPtr->link == 0)
   //   head->link = newNodePtr;
   else
   {
      Node *cursor = headPtr;
      while (cursor->link != 0 && cursor->link->data < value)
         cursor = cursor->link;
      //if (cursor->link != 0)
      //   newNodePtr->link = cursor->link;
      newNodePtr->link = cursor->link;
      cursor->link = newNodePtr;
   }

   ////////////////// commented lines removed //////////////////

   Node *newNodePtr = new Node;
   newNodePtr->data = value;
   if (headPtr == 0 || headPtr->data >= value)
   {
      newNodePtr->link = headPtr;
      headPtr = newNodePtr;
   }
   else
   {
      Node *cursor = headPtr;
      while (cursor->link != 0 && cursor->link->data < value)
         cursor = cursor->link;
      newNodePtr->link = cursor->link;
      cursor->link = newNodePtr;
   }
   */
   ///////////////////////////////////////////////////////////
}

bool DelFirstTargetNode(Node*& headPtr, int target)
{
   Node *precursor = 0,
        *cursor = headPtr;

   while (cursor != 0 && cursor->data != target)
   {
      precursor = cursor;
      cursor = cursor->link;
   }
   if (cursor == 0)
   {
      cout << target << " not found." << endl;
      return false;
   }
   if (cursor == headPtr) //OR precursor == 0
      headPtr = headPtr->link;
   else
      precursor->link = cursor->link;
   delete cursor;
   return true;
}

bool DelNodeBefore1stMatch(Node*& headPtr, int target)
{
   if (headPtr == 0 || headPtr->link == 0 || headPtr->data == target) return false;
   Node *cur = headPtr->link, *pre = headPtr, *prepre = 0;
   while (cur != 0 && cur->data != target)
   {
      prepre = pre;
      pre = cur;
      cur = cur->link;
   }
   if (cur == 0) return false;
   if (cur == headPtr->link)
   {
      headPtr = cur;
      delete pre;
   }
   else
   {
      prepre->link = cur;
      delete pre;
   }
   return true;
}

void ShowAll(ostream& outs, Node* headPtr)
{
   while (headPtr != 0)
   {
      outs << headPtr->data << "  ";
      headPtr = headPtr->link;
   }
   outs << endl;
}

void FindMinMax(Node* headPtr, int& minValue, int& maxValue)
{
   if (headPtr == 0)
   {
      cerr << "FindMinMax() attempted on empty list" << endl;
      cerr << "Minimum and maximum values not set" << endl;
   }
   else
   {
      minValue = maxValue = headPtr->data;
      while (headPtr->link != 0)
      {
         headPtr = headPtr->link;
         if (headPtr->data < minValue)
            minValue = headPtr->data;
         else if (headPtr->data > maxValue)
            maxValue = headPtr->data;
      }
   }
}

double FindAverage(Node* headPtr)
{
   if (headPtr == 0)
   {
      cerr << "FindAverage() attempted on empty list" << endl;
      cerr << "An arbitrary zero value is returned" << endl;
      return 0.0;
   }
   else
   {
      int sum = 0,
          count = 0;

      while (headPtr != 0)
      {
         ++count;
         sum += headPtr->data;
         headPtr = headPtr->link;
      }

      return double(sum) / count;
   }
}

void ListClear(Node*& headPtr, int noMsg)
{
   int count = 0;

   Node *cursor = headPtr;
   while (headPtr != 0)
   {
      headPtr = headPtr->link;
      delete cursor;
      cursor = headPtr;
      ++count;
   }
   if (noMsg) return;
   clog << "Dynamic memory for " << count << " nodes freed"
        << endl;
}
// definition of RemBadSplitGood of Assignment 5 Part 1

void   RemBadSplitGood(Node*& head, Node*& head_LE5, Node*& head_GE7)
{
    assert(head_GE7 == 0);
    assert(head_LE5 == 0);

    Node* current = 0, * current_LE5 = 0, * previous = 0, * temp = 0, *current_GE7 =0;
    int count6 = 0, count_LE5 = 0, count_GE7 = 0;
    
    current = head;
    
    if(head == 0)
    {
        Node *newNodePtr = new Node;
        newNodePtr->data = -99;
        newNodePtr->link = 0;
        head = newNodePtr;
        
        Node *newNodePtr2 = new Node;
        newNodePtr2->data = -99;
        newNodePtr2->link = 0;
        head_LE5 = newNodePtr2;

        Node *newNodePtr3 = new Node;
        newNodePtr3->data = -99;
        newNodePtr3->link = 0;
        head_GE7 = newNodePtr3;
    }

    else
    {
        while(current != NULL)
        {
            int tempHolder = current->data;
            if(tempHolder >= 0 && tempHolder <= 5)
            {
                count_LE5++;
                temp = current;
                if(head_LE5 == 0)
                {
                    head_LE5 = temp;
                    if (count6 == 0)
                    {
                        head = current->link;
                        current = head;
                        temp->link = 0;
                        previous = head;
                    }
                    else
                    {
                        previous->link = current->link;
                        current = previous->link;
                        temp->link = 0;
                    }
                }
                else
                {
                    current_LE5 = head_LE5;
                    while(current_LE5->link!= 0)
                    {
                        current_LE5 = current_LE5->link;
                    }
                    current_LE5->link = current;

                    if(count6 == 0)
                    {
                        head = current->link;
                        current = head;
                        previous = head;
                        temp->link = 0;
                    }
                    else
                    {
                        previous->link = current->link;
                        current = previous->link;
                        temp->link = 0;
                    }
                }
                
            }
            else if(tempHolder >= 7 && tempHolder <= 9)
            {
                count_GE7 ++;
                temp = current;
                
                if(head_GE7 == 0)
                {
                    head_GE7 = temp;
                    
                    if (count6 == 0)
                    {
                        head = current->link;
                        current = head;
                        temp->link = 0;
                        previous = head;
                    }
                    else
                    {
                        previous->link = current->link;
                        current = previous->link;
                        temp->link = 0;
                    }
                }
                else
                {
                    current_GE7 = head_GE7;
                    while(current_GE7->link!= 0)
                    {
                        current_GE7 = current_GE7->link;
                    }
                    current_GE7->link = current;
                    
                    if(count6 == 0)
                    {
                        head = current->link;
                        current = head;
                        previous = head;
                        temp->link = 0;
                        
                    }
                    else
                    {
                        previous->link = current->link;
                        current = previous->link;
                        temp->link = 0;
                    }
                }
            }
            else if(tempHolder == 6)
            {
                count6 ++;
                if(head->link == 0)
                {
                    current = current->link;
                }
                else
                {
                    previous = current;
                    current = current->link;
                }
            }
            else
            {
                if (count6 == 0)
                {
                    if(head->link == 0)
                    {
                        delete head;
                        head = 0;
                        current = head;
                    }
                    else
                    {
                        head = current->link;
                        delete current;
                        current = head;
                    }
                }
                else
                {
                    previous->link = current->link;
                    delete current;
                    current = previous->link;
                }
            }
        }
        
        if(count6 == 0)
        {
            Node *newNodePtr = new Node;
            newNodePtr->data = -99;
            newNodePtr->link = 0;
            head = newNodePtr;
        }
        
        if(count_LE5 == 0)
        {
            Node *newNodePtr2 = new Node;
            newNodePtr2->data = -99;
            newNodePtr2->link = 0;
            head_LE5 = newNodePtr2;
        }
        
        if(count_GE7 == 0)
        {
            Node *newNodePtr3 = new Node;
            newNodePtr3->data = -99;
            newNodePtr3->link = 0;
            head_GE7 = newNodePtr3;
        }
    }
}

