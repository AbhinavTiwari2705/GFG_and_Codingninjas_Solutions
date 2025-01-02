//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj) {
        int N = adj.size();
        vector<int> inDegree(N,0);
        // create InDegree Array
        for(int i=0;i<adj.size();i++){
            for(int j=0;j<adj[i].size();j++){
                inDegree[adj[i][j]]++;
            }
        }
        // Insert 0 indegree elements inside queue;
        queue<int> q;
        // vector<int> P;
        for(int i=0;i<inDegree.size();i++){
            if(inDegree[i]==0){
                 q.push(i);
                //  P.push_back(i);
            }
        }
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(int i=0;i<adj[front].size();i++){
                inDegree[adj[front][i]]--;
                if(inDegree[adj[front][i]] == 0){
                    q.push(adj[front][i]);
                    // P.push_back(adj[front][i]);
                }
            }
        }
        // if any element is having nonZero inDegree that means 
        // there was cycle inside that graph
        for(int i=0;i<inDegree.size();i++){
            if(inDegree[i] != 0) return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends