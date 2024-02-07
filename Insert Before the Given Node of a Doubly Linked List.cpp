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

void insertAtGivenNode(Node *node, int val) {

    // Write your code here.

 

    Node * newNode = new Node(val);

 

    if(node->next == NULL && node->prev == NULL){

        newNode->next = node;

        node->prev = newNode;

    }

 

    Node* back = node->prev;

    back->next = newNode;

    newNode->prev = back;

    newNode->next = node;

    node->prev = newNode;

}
