/************************************************************

    Following is the LinkedList class structure:

    class Node {
    public:
        int data;
        Node *next;

        Node(int val) {
            this->data = val;
            next = NULL;
        }
        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
};

************************************************************/
Node * insert(Node * head, int n, int pos, int val) {

    // Write your code here

     Node* newNode= new Node(val);

    if(!head){

        return newNode;

    }

    if(!pos){

        newNode->next=head;

        return newNode;

    }

    Node* temp=head;

    int count=1;

    while(temp!=NULL){

        if(count==pos){

         newNode->next=temp->next;

         temp->next=newNode;

        }

        temp=temp->next;

        count++;

    }

     return head;

}
