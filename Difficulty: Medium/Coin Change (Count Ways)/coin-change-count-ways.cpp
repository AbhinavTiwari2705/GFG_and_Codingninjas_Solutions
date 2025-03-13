//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int dp[1005][1005];
    int fn(vector<int>&coins, int sum, int i){
        
        if(sum==0)return 1;
        if(i>=coins.size())return 0;
        if(dp[sum][i]!=-1)return dp[sum][i];
        
        int ans=0;
        ans+=fn(coins,sum,i+1);
        if(coins[i]<=sum)ans+=fn(coins,sum-coins[i],i); 
    
        return dp[sum][i]=ans;
    }
    int count(vector<int>& coins, int sum) { 
        memset(dp,-1,sizeof(dp));
        return fn(coins,sum,0);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends