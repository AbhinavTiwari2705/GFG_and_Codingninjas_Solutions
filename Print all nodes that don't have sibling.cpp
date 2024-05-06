void solve(Node* root, vector<int>&ans){
    if(root==NULL) return;


    if(root->left && !root->right) {
        ans.push_back(root->left->data);
    }
    if(!root->left && root->right){
        ans.push_back(root->right->data);

    }


  solve(root->left, ans);
 solve(root->right, ans);
    return;
}

vector<int> noSibling(Node* node)
{
    // code here
    vector<int>ans;
    solve(node, ans);
    if(ans.size()==0) return {-1};
    sort(ans.begin(), ans.end());
    return ans;
}
