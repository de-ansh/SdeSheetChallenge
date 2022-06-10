Node<int>* sortTwoLists(Node<int>* l1, Node<int>* l2)
{
    if(l1==NULL) return l2;
    if(l2==NULL) return l1;
   if(l1->data<=l2->data){
    l1->next= sortTwoLists(l1->next,l2);
    return l1;
}
else{
    l2->next=sortTwoLists(l1,l2->next);
    return l2;
}
    
}
