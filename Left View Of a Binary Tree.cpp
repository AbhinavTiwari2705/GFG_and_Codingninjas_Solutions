vector<int> getLeftView(TreeNode<int> *root)

{

    vector<int> ans;

    if (root == NULL)
        return ans;

    queue<TreeNode<int> *> q;

    q.push(root);

    while (!q.empty())
    {

        int size = q.size();

        vector<int> level;

        while (size != 0)
        {

            root = q.front();

            if (root->left != NULL)
                q.push(root->left);

            if (root->right != NULL)
                q.push(root->right);

            q.pop();

            if (level.empty())
            {

                ans.push_back(root->data);
            }

            level.push_back(root->data);

            size--;
        }
    }

    return ans;
}
