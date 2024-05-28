class Solution{
  public:
  void solve(Node* root, int &odd, int &even, int level){
      //Base Case
      if(root == NULL){
          return;
      }
      if(level%2==0){
          even+=root->data;
      }
      if(level%2 !=0){
          odd+=root->data;
      }
      //Recursive Call
      solve(root->left, odd, even, level+1);
      solve(root->right, odd, even, level+1);
      return;
  }
    /*You are required to complete this function*/
    int getLevelDiff(Node *root)
    {
       //Your code here
       int odd = 0;
       int even = 0;
       int ans = 0;
       int level = 1;
       solve(root, odd, even, level);
       ans = odd - even;
       return ans;
    }
