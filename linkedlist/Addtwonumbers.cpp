#include <bits/stdc++.h> 


Node *addTwoNumbers(Node *head1, Node *head2)
{
    Node *dummyNode;
    Node *head;
    dummyNode = head =new Node(-1);
    if(!head1)
        return head2;
    if(!head2)
        return head1;
    int carry=0;
    while(head1 || head2){
        int firstVal= head1? head1->data:0;
        int secondVal= head2? head2->data:0;
        int total =firstVal+secondVal +carry;
        carry=total/10;
        total=total%10;
        Node * newNode = new Node (total);
        dummyNode ->next= newNode;
        dummyNode= dummyNode->next;
        head1= head1 ? head1->next : head1;
        head2=head2 ? head2->next : head2;
    }
    if(carry)
        dummyNode ->next= new Node(1);
    return head->next;
}