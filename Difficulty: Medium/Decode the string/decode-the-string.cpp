//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    string decodedString(string &s) {
        // code here
        
        stack<int> numStack;      // To store repeat counts
            stack<string> strStack;   // To store substrings
            string currStr = "";
            int num = 0;
        
            for (char c : s) {
                if (isdigit(c)) {
                    num = num * 10 + (c - '0'); // Extract the full number
                } else if (c == '[') {
                    numStack.push(num);  // Push number onto stack
                    strStack.push(currStr); // Push current string
                    num = 0;
                    currStr = "";
                } else if (c == ']') {
                    string temp = currStr; // Store the current decoded string
                    int repeatTimes = numStack.top(); numStack.pop(); // Get repeat count
                    currStr = strStack.top(); strStack.pop(); // Get previous string
                    
                    while (repeatTimes--) {
                        currStr += temp; // Append repeated string
                    }
                } else {
                    currStr += c; // Append character to current string
                }
            }
            return currStr;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends