//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
// #define long long ll;

class Solution {
public:
    vector<long long int> productExceptSelf(vector<long long int>& nums) {
        long long prod = 1;
        int zeroCount = 0;

        for (auto i : nums) {
            if (i != 0) {
                prod *= i;
            } else {
                zeroCount++;
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (zeroCount > 1) {
                nums[i] = 0; 
                }
                else if (zeroCount == 1) {
                nums[i] = (nums[i] == 0) ? prod : 0; 
            } else {
                nums[i] = prod / nums[i]; 
            }
        }

        return nums;
    }
};


//{ Driver Code Starts.
int main() {
    int t; // number of test cases
    cin >> t;
    while (t--) {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
