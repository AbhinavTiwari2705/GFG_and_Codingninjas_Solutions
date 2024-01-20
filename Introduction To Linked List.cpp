/**
 * Definition of linked list
 * class Node {
 *
 * public:
 *     int data;
 *     Node* next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node* next) : data(x), next(next) {}
 * };
 */

Node* constructLL(vector<int>& arr) {
    // Write your code here
    Node * head= new Node();
    head->data=arr[0];
    Node* temp=head;
    for(int i=1;i<arr.size();i++){
        Node * nem= new Node();
        nem->data=arr[i];
        temp->next=nem;
        temp=nem;
    }
    return head;
}


