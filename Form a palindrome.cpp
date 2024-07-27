//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
private:
    int helper(int i, int j, string s1, string s2, vector<vector<int>>& dp) {
        if (i == s1.length() || j == s2.length()) {
            return 0;
        }
        if (dp[i][j] != -1) return dp[i][j];
        if (s1[i] == s2[j]) {
            return dp[i][j] = 1 + helper(i + 1, j + 1, s1, s2, dp);
        }
        int l = helper(i, j + 1, s1, s2, dp);
        int r = helper(i + 1, j, s1, s2, dp);
        return dp[i][j] = max(l, r);
    }

public:
    int countMin(string str) {
        int n = str.size();
        vector<vector<int>> dp(n, vector<int>(n, -1)); 
        string s1 = str;
        reverse(str.begin(), str.end());
        int temp = helper(0, 0, s1, str, dp);
        return n - temp;
    }
};




//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends
