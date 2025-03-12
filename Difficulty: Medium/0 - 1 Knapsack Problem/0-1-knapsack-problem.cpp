//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity.
 
    int knapsack(int capacity, vector<int> &val, vector<int> &wt) {
int n= wt.size();
int W = capacity;
int t[n+1][W+1];
//Initialization(base condition of recursion changed to initialization)
for(int i=0;i<n+1;i++){
    for(int j=0;j<W+1;j++){
        if(i==0 || j==0){
            t[i][j]=0;
        }
    }
}
  //  i,j == n,W
  //choice diagram
    for(int i=1;i<n+1;i++){
    for(int j=1;j<W+1;j++){
        if(j<wt[i-1]){
            t[i][j]=t[i-1][j];
        }
        else if(wt[i-1]<=j){
            t[i][j]=max((val[i-1]+t[i-1][j-wt[i-1]]),t[i-1][j]);
        }
    }
    }
    return t[n][W];
    }
};


//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapsack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends