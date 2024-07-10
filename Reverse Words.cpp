//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here  
        if(S.length()==0){
            return S;
        }
        //solution
        reverse(S.begin(), S.end());
        S.insert(S.end(), '.');
        //reverse;
        int j=0;
        int size= S.length();
        for(int i=0; i<=size; i++){
            if(S[i]=='.'){
                reverse(S.begin()+j, S.begin()+i);
                j= i+1;
                
            }
        }
        S.pop_back();
        return S;
        
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends
