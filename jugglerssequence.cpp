//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

#define ll long long
class Solution {
    public:
    vector<long long> jugglerSequence(long long n) {
        vector<ll> v;
        v.push_back(n);
        while(n!=1)
        {
            if(n&1)
            {
                double temp=sqrt(n);
                n=(temp*temp*temp);
            }
            else
            {
                double temp=sqrt(n);
                n=temp;
            }
            v.push_back(n);
        }
        return v;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        Solution ob;
        vector<long long> ans = ob.jugglerSequence(n);
        for (long long u : ans)
            cout << u << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
