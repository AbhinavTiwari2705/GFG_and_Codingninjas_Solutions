//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {

        // your code here
        int n=arr.size();
       int totalsum=0;
       int maxsofar=0;
       int minsofar=0;
       int maxsum=INT_MIN;
       int minsum=INT_MAX;
       for(int num:arr){
           totalsum+=num;
           maxsofar+=num;
           minsofar+=num;
           maxsum=max(maxsofar,maxsum);
           minsum=min(minsofar,minsum);
           if(maxsofar<0){
               maxsofar=0;
           }
           if(minsofar>0){
               minsofar=0;
           }
           
       }
       return max(totalsum-minsum,maxsum);
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
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends
