//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> maxCombinations(int n, int k, vector<int> &a, vector<int> &b) {
        // code here
        sort(a.begin(),a.end(),greater<int>());
        sort(b.begin(),b.end(),greater<int>());
        set<pair<int,int>> s;
        priority_queue<pair<int,pair<int,int>>> pq;
        
        pq.push({a[0]+b[0],{0,0}});
        
        s.insert({0,0});
        vector<int> ans;
        while(!pq.empty() && k--){
            int sum=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
            
            ans.push_back(sum);
            
            if(i<n-1 && s.find({i+1,j})==s.end()){
                pq.push({a[i+1]+b[j],{i+1,j}});
                s.insert({i+1,j});
            }
             if(j<n-1 && s.find({i,j+1})==s.end()){
                pq.push({a[i]+b[j+1],{i,j+1}});
                s.insert({i,j+1});
            }
        
        }
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
