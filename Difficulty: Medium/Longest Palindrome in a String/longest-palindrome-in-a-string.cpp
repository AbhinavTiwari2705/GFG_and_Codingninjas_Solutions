//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string longestPalindrome(string &s) {
          int n=s.size();
       vector<vector<int>>dp(n,vector<int>(n));
       int S=-1,E=-1;
       for(int i=0;i<n;i++){
           for(int j=0,k=i;k<n;k++,j++){
               if(j==k) dp[j][k]=1;
               else if(i==1){
                   dp[j][k]=s[j]==s[k]?2:0;
               }
               else{
                   dp[j][k]=s[j]==s[k] and dp[j+1][k-1]?2+dp[j+1][k-1]:0;
               }
               if(k-j+1>E and dp[j][k]){
                   E=k-j+1;
                   S=j;
               }
            }
       }
       return string(begin(s)+S,begin(s)+S+E);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestPalindrome(S) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends