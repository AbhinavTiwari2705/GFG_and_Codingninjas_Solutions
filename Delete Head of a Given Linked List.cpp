Node * deleteHead(Node *head) {
    // Write your code here.
   Node* temp=head->next;
   free(head);
    return temp;
}
