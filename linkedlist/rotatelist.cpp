
Node *rotate(Node *head, int k) {
     if(!head) return head;
        
        int len=1;
        Node *newH, *tail;
        newH=tail=head;
        
        while(tail->next)  
        {
            tail = tail->next;
            len++;
        }
        tail->next = head; 

        if(k %= len) 
        {
            for(auto i=0; i<len-k; i++) tail = tail->next;
        }
        newH = tail->next; 
        tail->next = NULL;
        return newH;
}