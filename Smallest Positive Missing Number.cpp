//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int missingNumber(vector<int> &arr) {
        int n = arr.size();
        
        // Step 1: Segregate positive numbers and others (place all positive at start)
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] <= 0) {
                swap(arr[i], arr[j]);
                j++;
            }
        }
        
        // Now the array is divided as: [Non-positive numbers] [Positive numbers]
        // Only focus on the positive part of the array.
        int size = n - j;
        arr = vector<int>(arr.begin() + j, arr.end()); 
        
        // Step 2: Mark numbers (indexing starts from 1, so we map `value` to `index-1`).
        for (int i = 0; i < size; i++) {
            int val = abs(arr[i]);
            if (val <= size && arr[val - 1] > 0) {
                arr[val - 1] = -arr[val - 1];
            }
        }
        
        // Step 3: Find the first missing positive number.
        for (int i = 0; i < size; i++) {
            if (arr[i] > 0) {
                return i + 1;
            }
        }
        
        // If all positive numbers are present, the missing number is `size + 1`.
        return size + 1;
    }
};



//{ Driver Code Starts.

// int missingNumber(int arr[], int n);

int main() {

    // taking testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int result = ob.missingNumber(arr);
        cout << result << "\n";
    }
    return 0;
}
// } Driver Code Ends
