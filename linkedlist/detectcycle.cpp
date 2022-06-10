bool detectCycle(Node *head)
{
    if(head==NULL) return false;
	Node *slow=head;
    Node *fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow) return true;
    }
    return false;
}


bool detectCycle(Node *head)
{
    unordered_set<Node*> hashTable;
    while(head != NULL) {
        if(hashTable.find(head) != hashTable.end()) return true;
        hashTable.insert(head);
        head = head->next;
    }
    return false;
}