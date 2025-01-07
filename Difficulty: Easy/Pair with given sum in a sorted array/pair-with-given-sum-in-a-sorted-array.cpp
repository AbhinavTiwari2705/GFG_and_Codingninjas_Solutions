//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
    int factorial(int n) {
        int fact = 1;
        while(n > 1) fact *= n--;
        return fact;
    }
    int samePairs(int n) {
        return factorial(n) / (2 * factorial(n-2));
    }
  public:
    int countPairs(vector<int> &arr, int target) {
        int count = 0;
        int left = 0, right = arr.size()-1;
        
        while(left < right) {
            int sum = arr[left] + arr[right];
            if(sum == target) {
                if(arr[left] == arr[right]) {
                    int samecount = right - left + 1;
                    count += samePairs(samecount);
                    break;
                } else {
                    int leftval = arr[left], rightval = arr[right];
                    int leftcount  = 0, rightcount = 0;
                    
                    while(left < right && arr[left] == leftval) {
                        left++;
                        leftcount++;
                    }
                    
                    while(left <= right && arr[right] == rightval) {
                        right--;
                        rightcount++;
                    }
                    
                    count += leftcount * rightcount;
                }
            } else if(sum < target) left++;
            else right--;
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int target;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends