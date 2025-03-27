//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    unordered_set<string>st;
    int n;
    vector<int>dp;
    int solve(int i,string &s){
        if(i==n)return 1;
        if(dp[i]!=-1)return dp[i];
        int res=0;
        for(string curr:st){
            int sz=curr.size();
            if(sz+i>n || s.substr(i,sz)!=curr)continue;
            if(solve(i+sz,s))res = 1;
        }
        return dp[i] = res;
    }
    bool wordBreak(string &s, vector<string> &dictionary) {
        // code here
        for(string &str:dictionary)st.insert(str);
        n=s.size();
        dp.resize(n,-1);
        return solve(0,s);
    }
};


//{ Driver Code Starts.

vector<string> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    vector<string> res;
    while (ss >> str) {
        res.push_back(str);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        cin >> s;
        cin.ignore();
        vector<string> dictionary = inputLine();

        Solution ob;
        if (ob.wordBreak(s, dictionary)) {
            cout << "true\n";
        } else
            cout << "false\n";
        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends