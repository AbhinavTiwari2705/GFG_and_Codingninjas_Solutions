//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
private:
    Node* lastNode(Node* head) {
        Node* temp = head;
        
        while (temp->next != NULL) {
            temp = temp->next;
        }
        return temp;
    }

public:
    // Function to rotate a linked list.
    Node* rotate(Node* head, int k) {
        // Handle edge cases
        if (head == NULL || head->next == NULL || k == 0) {
            return head;
        }
        
        
        int length = 1;
        Node* temp = head;
        while (temp->next != NULL) {
            length++;
            temp = temp->next;
        }
        
        
        k = k % length;
        if (k == 0) {
            return head;
        }
        
       
        Node* oldHead = head;
        Node* last_Node = lastNode(oldHead);
        Node* newTail = head;
        
        for (int i = 1; i < k; i++) {
            newTail = newTail->next;
        }
        
        Node* newHead = newTail->next;
        newTail->next = NULL;
        last_Node->next = oldHead;
        
        return newHead;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }

        Node* head = nullptr;

        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node* tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.rotate(head, k);
        printList(head);
    }
    return 1;
}

// } Driver Code Ends