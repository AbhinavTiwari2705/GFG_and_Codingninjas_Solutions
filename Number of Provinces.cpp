class Solution {
  private:
    void bfs(int node, vector<int> &vis, vector<vector<int>> &adjls) {
        vis[node] = 1;
        queue<int> q;
        q.push(node);
        while (!q.empty()) {
            int n = q.front();
            q.pop();
            for (auto it : adjls[n]) {
                if (!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    }

  public:
    int numProvinces(vector<vector<int>> adj, int v) {
        // Create the adjacency list from the adjacency matrix
        vector<vector<int>> adjls(v);
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (adj[i][j] == 1 && i != j) {
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);
                }
            }
        }

        // Visitation array
        vector<int> vis(v, 0);
        int cnt = 0;

        // Perform BFS for each unvisited node
        for (int i = 0; i < v; i++) {
            if (!vis[i]) {
                cnt++;
                bfs(i, vis, adjls);
            }
        }

        return cnt;
    }
};
