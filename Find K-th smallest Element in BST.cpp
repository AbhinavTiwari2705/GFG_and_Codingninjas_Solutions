int kthSmallest(BinaryTreeNode<int>* root, int k) {
    stack<BinaryTreeNode<int>*> st;
    BinaryTreeNode<int>* current = root;
    int count = 0;
    
    while (current != NULL || !st.empty()) {
        while (current != NULL) {
            st.push(current);
            current = current->left;
        }
        
        current = st.top();
        st.pop();
        count++;
        if (count == k) {
            return current->data;
        }
        current = current->right;
    }
    
    // If k is greater than the number of nodes in the tree
    return -1; // Or any other suitable value to indicate k is out of range
}
