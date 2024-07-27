#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
private:
    int helper(vector<int>& arr, int k, int i, vector<int>& dp) {
        if (i == 0) {
            return 0;
        }
        if (dp[i] != -1) return dp[i];
        int mini = INT_MAX;

        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                int fs = helper(arr, k, i - j, dp) + abs(arr[i] - arr[i - j]);
                mini = min(mini, fs);
            }
        }
        return dp[i] = mini;
    }

    int minimizeCostMemoization(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return helper(arr, k, n - 1, dp);
    }

    int minimizeCostTabulation(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, 0);

        for (int i = 1; i < n; i++) {
            int mini = INT_MAX;

            for (int j = 1; j <= k; j++) {
                if (i - j >= 0) {
                    int step = dp[i - j] + abs(arr[i] - arr[i - j]);
                    mini = min(mini, step);
                }
            }
            dp[i] = mini;
        }
        return dp[n - 1];
    }

public:
    int minimizeCost(vector<int>& arr, int k, bool useMemoization) {
        if (useMemoization) {
            return minimizeCostMemoization(arr, k);
        } else {
            return minimizeCostTabulation(arr, k);
        }
    }
};

// Main function to demonstrate usage
int main() {
    Solution sol;
    vector<int> heights = {10, 30, 40, 50, 20};
    int k = 3;
    bool useMemoization = true; // Set to false to use tabulation

    int result = sol.minimizeCost(heights, k, useMemoization);
    printf("Minimum cost: %d\n", result);
    return 0;
}
