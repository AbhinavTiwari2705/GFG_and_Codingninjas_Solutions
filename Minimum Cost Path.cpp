class Solution {
public:
    // Function to return the minimum cost to reach the bottom-right cell from the top-left cell.
    int minimumCostPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // Min-heap priority queue storing {cost, {row, col}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({grid[0][0], {0, 0}});
        
        // Direction vectors for moving up, down, left, and right
        int dirR[4] = {-1, 1, 0, 0};
        int dirC[4] = {0, 0, -1, 1};
        
        // Visited array to track visited cells
        vector<vector<int>> visited(n, vector<int>(m, 0));
        visited[0][0] = 1;
        
        while (!pq.empty()) {
            int wt = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            
            // If we've reached the bottom-right cell, return the cost
            if (row == n - 1 && col == m - 1) {
                return wt;
            }
            
            // Explore the four possible directions
            for (int i = 0; i < 4; i++) {
                int delRow = row + dirR[i];
                int delCol = col + dirC[i];
                
                // Check if the new position is within the grid and not visited
                if (delRow >= 0 && delRow < n && delCol >= 0 && delCol < m && !visited[delRow][delCol]) {
                    visited[delRow][delCol] = 1;
                    pq.push({wt + grid[delRow][delCol], {delRow, delCol}});
                }
            }
        }
        
        // If the grid is valid, we should have already returned a value by now.
        return -1;
    }
};
