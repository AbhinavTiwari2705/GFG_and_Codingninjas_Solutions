/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* deleteMiddle(Node* head){
    // Write your code here.
        if(head == NULL || head->next == NULL)return NULL ;
        Node * fast = head ;
        Node * slow = head ;
        Node * prev = NULL ;

        while(fast  && fast->next ){
          prev = slow ;
          slow = slow->next ;
          fast = fast->next ;
          fast = fast->next ;
        }
        prev->next = prev->next->next ;
        return head  ;
}
