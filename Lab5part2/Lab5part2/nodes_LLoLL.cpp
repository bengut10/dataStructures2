#include "nodes_LLoLL.h"
#include "cnPtrQueue.h"
#include <iostream>
using namespace std;

namespace CS3358_SP16_A5P2
{
   void Destroy_cList(CNode*& cListHead)
   {
      int count = 0;
      CNode* cNodePtr = cListHead;
      while (cListHead != 0)
      {
         cListHead = cListHead->link;
         delete cNodePtr;
         cNodePtr = cListHead;
         ++count;
      }
      cout << "Dynamic memory for " << count << " CNodes freed"
           << endl;
   }

   void Destroy_pList(PNode*& pListHead)
   {
      int count = 0;
      PNode* pNodePtr = pListHead;
      while (pListHead != 0)
      {
         pListHead = pListHead->link;
         Destroy_cList(pNodePtr->data);
         delete pNodePtr;
         pNodePtr = pListHead;
         ++count;
      }
      cout << "Dynamic memory for " << count << " PNodes freed"
           << endl;
   }

   // do depth-first traversal and print data
   void ShowAll_DF(PNode* pListHead, ostream& outs)
   {
      while (pListHead != 0)
      {
         CNode* cListHead = pListHead->data;
         while (cListHead != 0)
         {
            outs << cListHead->data << "  ";
            cListHead = cListHead->link;
         }
         pListHead = pListHead->link;
      }
   }

   // do breadth-first (level) traversal and print data
   void ShowAll_BF(PNode* pListHead, ostream& outs)
   {
       if(pListHead == 0)
       {
           return;
       }
       else
       {
           cnPtrQueue s1;
           CNode* current = 0;
           while(pListHead != 0)
           {
               if(pListHead->data != 0)
               {
                   s1.push(pListHead->data);
               }
               pListHead = pListHead->link;
           }

           while(!s1.empty())
           {
               current = s1.front();
               outs << current->data << " " ;
               s1.pop();
               
               if(current->link != 0)
               {
                   current = current->link;
                   s1.push(current);
               }
           }
       }
   }
}