//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    static bool comp(pair<int, int>& a, pair<int, int>& b) {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second > b.second;
    }

    vector<int> sortByFreq(vector<int>& arr) {
        map<int, int> freqMap;

        for (auto i : arr) {
            freqMap[i]++;
        }

        vector<pair<int, int>> freqVector;
        for (auto i : freqMap) {
            freqVector.push_back(i);
        }

        sort(freqVector.begin(), freqVector.end(), comp);

        vector<int> result;
        for (auto i : freqVector) {
            for (int j = 0; j < i.second; j++) {
                result.push_back(i.first);
            }
        }

        return result;
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
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends
