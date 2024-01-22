#include <bits/stdc++.h> 

// Function to get the final modified grid
vector<vector<int>> getFinalGrid(vector<vector<int>> &a, int n) {
    // Reverse each row of the matrix
    for(int i = 0; i < n; i++){
        reverse(a[i].begin(), a[i].end());
    }

    // Invert the values in the matrix
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] == 1)
                a[i][j] = 0;
            else
                a[i][j] = 1;
        }
    }

    // Return the modified matrix
    return a;
}
