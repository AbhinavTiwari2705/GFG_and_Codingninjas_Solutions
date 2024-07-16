//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }
 
    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
  bool dfs(int node,int parent,vector<int> adj[],vector<int>& visited)
  {
      visited[node]=1;
      for(auto it:adj[node])
      {
          if(!visited[it])
          {
             if(dfs(it,node,adj,visited))
             {
                 return true;
             }
          }
          else if(it!=parent)
          {
              return true;
          }
      }
      return false;
  }
    int isTree(int n, int m, vector<vector<int>> &adj) {

    vector<int> visited(n,0);
    vector<int> adjls[n];
    for(int i=0;i<adj.size();i++)
    {
        int u=adj[i][0];
        int v=adj[i][1];
        adjls[u].push_back(v);
        adjls[v].push_back(u);
    }
    if(dfs(0,-1,adjls,visited)) 
    {
        return false; 
    }
    for(int i=0;i<visited.size();i++)
    {
        if(visited[i]==0)
        {
            return false; 
        }
    }
    return true;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        int m; 
        scanf("%d",&m);
        
        
        vector<vector<int>> edges(m, vector<int>(2));
        Matrix::input(edges,m,2);
        
        Solution obj;
        int res = obj.isTree(n, m, edges);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
