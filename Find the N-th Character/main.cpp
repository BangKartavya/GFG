//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    char helper(string s,int r,int n) {
        if(r==0) {
            if(n==1) return s[0];
            else return s[1];
        }
        int min = 1<<r;
        for(auto i: s) {
            if(n>min) n-=min;
            else {
                if(i=='0') return helper("01",r-1,n);
                return helper("10",r-1,n);
            }
        }
        return '-';
    }
    char nthCharacter(string s, int r, int n) {
        return helper(s,r,n+1);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends