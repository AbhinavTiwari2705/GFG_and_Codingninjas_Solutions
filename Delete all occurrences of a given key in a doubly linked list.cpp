/**
 * Definition of doubly linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this->data = data;
 *          this->prev = prev;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node * deleteAllOccurrences(Node* head, int k) {
    // Write your code here
            Node* q=head;
        
        while(q){
            if(q->data==k){
                if(q==head){
                    head=q->next;
                    
                }
                Node* nextptr=  q->next;
                Node* prevptr=  q->prev;
                
                if(nextptr) nextptr->prev=prevptr;
                if(prevptr) prevptr->next=nextptr;
                
                free(q);
                q=nextptr;
            }
            else{
                q=q->next;
            }
        }
        return head;
        
}
