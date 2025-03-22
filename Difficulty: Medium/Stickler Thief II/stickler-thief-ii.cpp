//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(int index, vector<int>& arr){
        int n=arr.size();
        int prev2=0, prev1=arr[index];
        for(int i=index+1;i<n;i++){
            int curr=max(arr[i]+prev2,prev1);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
    int maxValue(vector<int>& arr) {
        int ans1=solve(1,arr);
        arr.pop_back();
        int ans2=solve(0,arr);
        return max(ans1,ans2);
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends