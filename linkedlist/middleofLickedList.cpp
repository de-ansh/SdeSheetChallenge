Node *findMiddle(Node *head) {
    int n=0;
    Node*temp=head;
    while(temp){
        n++;
        temp=temp->next;
    }
    temp=head;
    for(int i=0;i<n/2;i++){
        temp=temp->next;
    }
    return temp;
}
Node *findMiddle(Node *head) {
    Node *fast=head;
    Node *slow=head;
    while(fast &&fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}