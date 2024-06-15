
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int cntFresh = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    vis[i][j] = 2;
                    q.push({{i, j}, 0});
                } else {
                    vis[i][j] = 0;
                }
                if (grid[i][j] == 1) cntFresh++;
            }
        }
        
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        
        int time = 0;
        int cnt = 0;
        
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            
            time = max(time, t);
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                int newRow = r + drow[i];
                int newCol = c + dcol[i];
                
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                    vis[newRow][newCol] == 0 && grid[newRow][newCol] == 1) {
                    q.push({{newRow, newCol}, t + 1});
                    vis[newRow][newCol] = 2;
                    cnt++;
                }
            }
        }
        
        if (cnt != cntFresh) return -1;
        
        return time;
    }
};
