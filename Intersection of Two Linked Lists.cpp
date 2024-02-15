/****************************************************************

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

*****************************************************************/
Node* findIntersection(Node *firstHead, Node *secondHead) {
    if (!firstHead || !secondHead) // If either list is empty, no intersection
        return nullptr;

    int len1 = 0, len2 = 0;
    Node *curr1 = firstHead, *curr2 = secondHead;

    // Calculate lengths of both lists
    while (curr1) {
        len1++;
        curr1 = curr1->next;
    }
    while (curr2) {
        len2++;
        curr2 = curr2->next;
    }

    // Reset current pointers to the heads
    curr1 = firstHead;
    curr2 = secondHead;

    // Advance the pointer of the longer list to align with the shorter list
    int diff = abs(len1 - len2);
    if (len1 > len2) {
        while (diff--)
            curr1 = curr1->next;
    } else {
        while (diff--)
            curr2 = curr2->next;
    }

    // Traverse both lists until intersection point is found
    while (curr1 && curr2 && curr1 != curr2) {
        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    // Return the intersection point or nullptr if no intersection
    return curr1;
}

