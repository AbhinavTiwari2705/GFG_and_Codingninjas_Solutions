//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

//Position this line where user code will be pasted.
class Solution {
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        // code here
          vector<int> combined = arr1;
    combined.insert(combined.end(), arr2.begin(), arr2.end());

    priority_queue<int> maxheap;
    priority_queue<int, vector<int>,greater<int>> minheap; 

    for (int num : combined) {
        minheap.push(num);

        
        if (minheap.size() > maxheap.size()) {
            maxheap.push(minheap.top());
            minheap.pop();
        }
        if (maxheap.size() > minheap.size()) {
            minheap.push(maxheap.top());
            maxheap.pop();
        }
    }


    if (minheap.size() > maxheap.size()) {
        return minheap.top();
    }
    

    return minheap.top() + maxheap.top();
}
};

//{ Driver Code Starts.
//Back-end complete function template in C++

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        Solution ob;
        int res = ob.SumofMiddleElements(arr, brr);
        cout << res << endl;
    }
}
// } Driver Code Ends
