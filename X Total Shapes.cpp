//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    private:
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int i, int j, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m || vis[i][j] == 1 || grid[i][j] == 'O') {
            return;
        }
        
        vis[i][j] = 1;
        
        dfs(grid, vis, i - 1, j, n, m);
        dfs(grid, vis, i + 1, j, n, m);
        dfs(grid, vis, i, j - 1, n, m);
        dfs(grid, vis, i, j + 1, n, m);
    }
    
    public:
    // Function to find the number of 'X' total shapes.
    int xShape(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'X' && !vis[i][j]) {
                    dfs(grid, vis, i, j, n, m);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}
// } Driver Code Ends
