/*************************************************************
 
    Following is the Binary Tree node structure:

    template <typename T>

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void DFS(BinaryTreeNode<int>* root, std::vector<int>& ans, int depth, int& maxDepth) {
    if (!root) return;
    
    if (depth >= maxDepth) {
        ans.push_back(root->data);
        maxDepth = depth + 1;
    }
    
    DFS(root->right, ans, depth + 1, maxDepth);
    DFS(root->left, ans, depth + 1, maxDepth);
}

std::vector<int> printRightView(BinaryTreeNode<int>* root) {
    std::vector<int> ans;
    int maxDepth = 0;
    DFS(root, ans, 0, maxDepth);
    return ans;
}
