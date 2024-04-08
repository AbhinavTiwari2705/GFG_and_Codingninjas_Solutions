void leftViewUtil(Node* root, int level, int& maxLevel, vector<int>& ans) {
    if (root == nullptr) {
        return;
    }

    // If this is the first node of its level, print it
    if (maxLevel < level) {
        ans.push_back(root->data);
        maxLevel = level;
    }

    // Recur for left and right subtrees
    leftViewUtil(root->left, level + 1, maxLevel, ans);
    leftViewUtil(root->right, level + 1, maxLevel, ans);
}

vector<int> leftView(Node* root) {
    vector<int> ans;
    int maxLevel = 0;
    leftViewUtil(root, 1, maxLevel, ans);
    return ans;
}
