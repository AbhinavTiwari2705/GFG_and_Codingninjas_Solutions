   Node* deleteK(Node *head,int k){
        int count=1;
        if(k==1)return NULL;
        Node* prev=NULL;
        Node* temp=head;
        while(temp!=NULL){
            if(count==k){
                prev->next=temp->next;
            // cout<<"a"<<temp->data<<"a"; 
                count=1;
                temp=temp->next;
            }
            else{
            prev=temp;
            temp=temp->next;
            count++;
            }
        }
        return head;
    }
