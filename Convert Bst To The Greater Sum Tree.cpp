#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

void helper(TreeNode<int> *root,int& sum){

    if(root==NULL){

        return ;

    }

    helper(root->right,sum);

 

    int temp=root->val;

    root->val=sum;

    sum+=temp;

 

    helper(root->left,sum);

    return ;

}

 

TreeNode<int> *convertBstToGreaterSum(TreeNode<int> *root)

{

    // Write your code here.

    int sum=0;

    helper(root,sum);

    return root;

}
