class Stack
{
private:
    Node* top; // Top of the stack

public:
    // Constructor
    Stack()
    {
        top = NULL;
    }

    // Function to get the size of the stack
    int getSize()
    {
        int size = 0;
        Node* current = top;
        while (current != NULL)
        {
            size++;
            current = current->next;
        }
        return size;
    }

    // Function to check if the stack is empty
    bool isEmpty()
    {
        return top == NULL;
    }

    // Function to push an element onto the stack
    void push(int data)
    {
        Node* newNode = new Node(data, top);
        top = newNode;
    }

    // Function to pop an element from the stack
    void pop()
    {
        if (!isEmpty())
        {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    // Function to get the top element of the stack without popping
    int getTop()
    {
        if (!isEmpty())
        {
            return top->data;
        }
        return -1; // Return a default value (assuming -1 is not a valid element)
    }
};
