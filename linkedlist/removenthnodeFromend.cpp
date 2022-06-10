#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K)
{
    
      LinkedListNode<int>* DummyNode = new LinkedListNode<int>(1);

DummyNode -> next = head;

LinkedListNode<int>* slow_ptr = DummyNode;

LinkedListNode<int>* fast_ptr = DummyNode;

 

if ( head == NULL ||  K==0)

{

 return head;

}

for ( int i = 0 ; i<K ; i++)

{

 fast_ptr = fast_ptr -> next;

}

 

while ( fast_ptr-> next !=NULL)

{

 slow_ptr = slow_ptr -> next ;

 fast_ptr = fast_ptr -> next;

}

   

slow_ptr -> next = slow_ptr -> next ->next;

 

return DummyNode -> next;
}