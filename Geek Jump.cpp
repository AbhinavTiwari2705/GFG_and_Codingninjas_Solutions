//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    int helper(int ind, vector<int>& dp,vector<int>& h){
        
        if(ind==0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        
        int left= helper(ind-1,dp,h)+abs(h[ind]-h[ind-1]);
        int right=INT_MAX;
        if(ind>1){
             right= helper(ind-2,dp,h)+abs(h[ind]-h[ind-2]);
        }
        
        return dp[ind]=min(left,right);
        
    }
  public:
    int minimumEnergy(vector<int>& h, int n) {
        // Code here
        // vector<int> v(n+1,-1);
        // return helper(n-1,v,h);
        
        vector<int> dp(n);
        
        dp[0]=0;
        
        for(int i=1;i<n;i++){
            int f =dp[i-1]+  abs(h[i]-h[i-1]);
            int s = INT_MAX;
            if(i>1){
                s =dp[i-2]+ abs(h[i]-h[i-2]);
            }
            dp[i]=min(f,s);
        }
        return dp[n-1];
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends
