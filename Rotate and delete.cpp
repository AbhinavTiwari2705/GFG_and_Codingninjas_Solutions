//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
private:
    void clockwise(vector<int>& arr) {
        int last = arr.back(); 
        arr.insert(arr.begin(), last); 
        arr.pop_back();   
    }

public:
    int rotateDelete(vector<int> &arr) {
        int sz = arr.size()/2;
        
        for (int k = 1; k <= sz; k++) {
            clockwise(arr);
            int n=arr.size();
            arr.erase(arr.begin() + (n - k)); 
        }

        return arr[0]; 
    }
};



//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.rotateDelete(arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends
