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

Node * insertAtTail(Node *head, int k) {
    if(!head) return new Node(k,nullptr,nullptr);
    // Write your code here
    Node* temp=head;
    while(head->next){
        head=head->next;

    }
    Node* ptr=new Node(k);
    head->next=ptr;
    ptr->prev=head;
    // ptr->next=nullptr;
    return temp;
}
