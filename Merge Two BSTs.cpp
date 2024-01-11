/*************************************************************

    Following is the Binary Tree node structure:

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/


void inOrder(TreeNode *root, vector<int> &ans){

    if(root==nullptr){

        return;

    }

    inOrder(root->left,ans);

    ans.push_back(root->data);

    inOrder(root->right,ans);

}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2)

{

    // Write your code here.

    vector<int> ans;

    inOrder(root1,ans);

    inOrder(root2,ans);

    sort(ans.begin(),ans.end());

    return ans;

 

    

 

}
