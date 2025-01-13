//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int maxWater(vector<int> &A) {
        // code here
        int max_area = 0;
        int len =A.size();
    // Two Pointer Approach
    int i = 0; int j = len - 1;
    while(i<j){
        // Area of the container is the product of vertical length and horizontal length
        // Horizontal Length = Difference in X-Coordinates = j - i
        // Vertical Length = Minimum of the two Vertical lines because Water above that height flows away
        max_area = max(max_area, (j-i) * min(A[i], A[j]));
        // We need maximum area
        // Greedy Approach, try to maximize Vertical line height
        if(A[i] < A[j])
            i++;
        else
            j--;
    }
    return max_area;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends