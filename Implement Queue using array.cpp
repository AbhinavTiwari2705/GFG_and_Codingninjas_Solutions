void MyQueue :: push(int x)
{
        // Your Code
        if(rear==100005) return;
        else{
            arr[rear]=x;
            rear++;
        }
}

//Function to pop an element from queue and return that element.
int MyQueue :: pop()
{
        // Your Code    
        if(front==rear) return -1;
        else{
            int x = arr[front];
            front++;
            return x;
        }
}
