/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node()
    {
        this->data = 0;
        next = NULL;
        prev=NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
        this->next= NULL;
    }
    Node(int data, Node* next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev= prev;
    }
};
*/

Node * deleteHead(Node *head) {
    // Write your code here.
    Node * temp = head;
    head=head->next;

    free(temp);
    return head;



}
