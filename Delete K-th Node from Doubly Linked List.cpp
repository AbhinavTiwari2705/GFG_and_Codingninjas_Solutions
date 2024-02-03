/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int val;
 *		Node *next;
 * 		Node *prev;
 *		Node() : val(0), next(nullptr), prev(nullptr){};
 *		Node(int x) : val(x), next(nullptr), prev(nullptr) {}
 *		Node(int x, Node *next, Node *prev) : val(x), next(next), prev(prev) {}
 * };
 */
Node* deleteNode(Node* head, int k) {
    if (head == nullptr) {
        return nullptr;
    }

    if (k == 1) {
        Node* newHead = head->next;
        delete head;
        return newHead;
    }

    Node* current = head;
    for (int i = 0; i < k - 2 && current != nullptr; i++) {
        current = current->next;
    }

    if (current == nullptr || current->next == nullptr) {
        return head;  
    }

    Node* nodeToDelete = current->next;
    current->next = nodeToDelete->next;
    delete nodeToDelete;

    return head;
}
