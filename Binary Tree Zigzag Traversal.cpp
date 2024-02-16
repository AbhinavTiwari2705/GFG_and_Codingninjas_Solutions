#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

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

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!

        if(root==NULL) return {};
    	// Code here
        vector<int> ans;
        queue<BinaryTreeNode<int>*> q;
        q.push(root);
        int cnt=0;
        while(!q.empty()){
            int size=q.size();
            vector<int> level;
            for(int i=0;i<size;i++){
            BinaryTreeNode<int>* n=q.front();
            q.pop();
                if(n->left){
                    q.push(n->left);
                }
                if(n->right){
                    q.push(n->right);
                }
                level.push_back(n->data);
                
                
            }
            if(cnt%2!=0){
                reverse(level.begin(),level.end());
            for (int val : level) {
            ans.push_back(val);
        }
            }
            else{
            for (int val : level) {
            ans.push_back(val);
        }
            }
            cnt++ ;
    
    
        }
        return ans;
    }


