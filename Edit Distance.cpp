//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

    private:
        int helper(string s1, string s2, int i, int j, vector<vector<int>>& dp) {
            if (i == s1.length()) {
                return s2.length() - j;
            }
            if (j == s2.length()) {
                return s1.length() - i;
            }
            if (dp[i][j] != -1) {
                return dp[i][j];
            }
            if (s1[i] == s2[j]) {
                return dp[i][j] = helper(s1, s2, i + 1, j + 1, dp);
            } else {
                int insert = helper(s1, s2, i, j + 1, dp);
                int deleto = helper(s1, s2, i + 1, j, dp);
                int replace = helper(s1, s2, i + 1, j + 1, dp);
                
                return dp[i][j] = 1 + min(insert, min(deleto, replace));
            }
        }
    public:
        int editDistance(string str1, string str2) {
            vector<vector<int>> dp(str1.length(), vector<int>(str2.length(), -1));
            return helper(str1, str2, 0, 0, dp);
        }
};



//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
