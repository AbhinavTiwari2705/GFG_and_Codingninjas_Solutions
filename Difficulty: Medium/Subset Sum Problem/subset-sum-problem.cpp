//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n=arr.size();
        vector<bool>prev(sum+1,0);
        vector<bool>curr(sum+1,0);
        prev[0]=curr[0]=true;
        if(arr[0]<=sum)
            prev[arr[0]]=true;
        for(int i=1;i<n;i++)
        {
            for(int target=1;target<=sum;target++)
            {
                bool notTake=prev[target];
                bool take=false;
                if(target>=arr[i])
                    take=prev[target-arr[i]];
                curr[target]=take||notTake;
            }
            prev=curr;
        }
        return prev[sum];
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends