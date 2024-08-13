//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
            // code here
            vector<int> dis(100000, 1e9);
        int mod = 100000;
    
        queue<pair<int, int>> pq;
        pq.push({start, 0});
        dis[start] = 0;
    
        while (!pq.empty()) {
            int node = pq.front().first;
            int step = pq.front().second;
            pq.pop();
    
            for (auto i : arr) {
                int temp = (i * node) % mod;
                if (step + 1 < dis[temp]) {
                    dis[temp] = step + 1;
                    if (temp == end) return step + 1;
                    pq.push({temp, step + 1});
                }
            }
        }
    
        return dis[end] == 1e9 ? -1 : dis[end];
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends
