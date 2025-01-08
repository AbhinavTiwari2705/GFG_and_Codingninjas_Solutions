//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& arr) {
        vector<int> narr;
        for(auto &it:arr)if(it)narr.push_back(it);
        sort(narr.begin(),narr.end());
        int n=narr.size(),ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x=lower_bound(narr.begin()+j+1,narr.end(),narr[i]+narr[j])-narr.begin();
                ans += x-j-1;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.countTriangles(a) << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends