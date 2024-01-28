/************************************************************

    Following is the linkedList class structure:

    class Node {
    public:
        int data;
        Node *next;

        Node(int val) {
            this->data = val;
            next = NULL;
        }
    };

************************************************************/

Node* insertEnd(Node* head, int k) {
    // Write your code here.
    Node* temp=head;
    if(head==NULL){
        head=new Node(k);
        return head;
    }

    while(head->next){
        head=head->next;
    }
    Node* ptr=new Node(k);
    head->next=ptr;
    ptr->next=NULL;
    return temp;
}
