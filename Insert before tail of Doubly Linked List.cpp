/**
 * Definition of doubly linked list:
 *
 * struct Node {
 *      int value;
 *      Node *prev;
 *      Node *next;
 *      Node() : value(0), prev(nullptr), next(nullptr) {}
 *      Node(int val) : value(val), prev(nullptr), next(nullptr) {}
 *      Node(int val, Node *p, Node *n) : value(val), prev(p), next(n) {}
 * };
 *
 *************************************************************************/
Node * insertBeforeTail(Node *head, int k) {

    // Write your code here

    if(head==NULL) return new Node(k);

    Node* temp=head;

    while(temp->next->next){

        temp=temp->next;

    }

    Node* tail=temp->next;

    Node* temp1=new Node(k, temp, tail);

    temp->next=temp1;

    tail->prev=temp1;

    return head;

}
