//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    void solve(int ind, vector<int>& arr, vector<vector<int>>& ans, vector<int>&ds, int target,int k){
        
        if(ind==arr.size()){
            if(ds.size()==k&&target==0){
                ans.push_back(ds);
            }
            return ;
        }
        if(arr[ind]<=target) {
            ds.push_back(arr[ind]);
            solve(ind+1,arr,ans,ds,target-arr[ind],k);
            ds.pop_back();
        }
        solve(ind+1,arr,ans,ds,target,k);
    }
  public:
    vector<vector<int>> combinationSum(int K, int N) {
        // code here
       vector<int>arr;
       vector<int>ds;
       vector<vector<int>>ans;
       for(int i=1;i<=9;i++) {
          arr.push_back(i);
       }
       solve(0,arr,ans,ds,N,K);
       return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K >> N;

        Solution obj;
        vector<vector<int>> ans = obj.combinationSum(K, N);
        sort(ans.begin(), ans.end());
        for (auto &arr : ans) {
            for (auto it : arr) cout << it << ' ';
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends
