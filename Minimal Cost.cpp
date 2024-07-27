//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  private:
    int helper(vector<int>& arr, int k,int i,vector<int>&dp){
        if(i==0){
            return 0;
            
        }
        if(dp[i]!=-1) return dp[i];
        int mini=INT_MAX;
        
        for(int j=1;j<=k;j++){
            
            if (i - j >= 0){
                int fs= helper(arr,k,i-j,dp)+abs(arr[i]-arr[i-j]);
                mini=min(mini,fs);
            }
            
        }
        return dp[i]=mini;
    }
  public:
    int minimizeCost(vector<int>& arr, int& k) {
        // Code here
        int n=arr.size();
        vector<int>dp(n,-1);
        
        return helper(arr,k,n-1,dp);
    }
};



//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(arr, k);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends
