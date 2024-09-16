//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxLength(string str) {
        int open = 0;
        int close = 0;
        int maxi = 0;
        
        for(auto c: str) {
            if(c == '(') open++;
            else close++;
            
            if(open == close) maxi = max(maxi,open+close);
            
            else if(close > open) {
                open = 0;
                close = 0;
            }
        }
        open = 0;
        close = 0;
        
        for(int i = str.size() -1;i >=0;i--) {
            if(str[i] == ')') close++;
            else open++;
            
            if(open == close) maxi = max(maxi,open+close);
            
            else if(open > close) {
                open = 0;
                close = 0;
            }
        }
        
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";
    }
    return 0;
}
// } Driver Code Ends