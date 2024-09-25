class Solution {
private:
    // Function to reverse a linked list starting from 'head'
    Node* reverse(Node* head) {
        Node* temp = head;
        Node* next = nullptr;
        Node* prev = nullptr;
        
        // Reversing the list
        while (temp) {
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        return prev;
    }

    // Function to get the size of the linked list
    int size(Node* head) {
        Node* temp = head;
        int sizeo = 0;
        while (temp) {
            sizeo += 1;
            temp = temp->next;
        }
        return sizeo;
    }

public:
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head) {
        if (!head || !head->next) {
            return true; // A list with 0 or 1 node is a palindrome
        }

        int n = size(head);
        Node* temp = head;
        
        // Move to the middle of the list
        for (int i = 0; i < (n / 2) - 1; i++) {
            temp = temp->next;
        }

        // Reverse the second half of the list
        Node* rev = reverse(temp->next);
        temp->next = nullptr; // Split the list into two halves

        // Compare the two halves
        Node* firstHalf = head;
        Node* secondHalf = rev;

        for (int i = 0; i < n / 2; i++) {
            if (firstHalf->data != secondHalf->data) {
                return false;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        return true;
    }
};
