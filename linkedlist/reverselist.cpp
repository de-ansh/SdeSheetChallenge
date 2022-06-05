#include<bits/stdc++.h>
using namespace std;
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    if(head==NULL ||head->next==NULL)
        return head;
    LinkedListNode<int> *prev=NULL;
    LinkedListNode<int> *curr=head;
    LinkedListNode<int> *temp;
    while(curr){
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
        
    }
   head= prev;
    return head;
}