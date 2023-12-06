//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int count(int n,int x) {
        int cnt=0;
        while(n!=0) {
            if(n%10==x) cnt++;
            n/=10;
        }
        return cnt;
    }
    int countX(int L, int R, int X) {
        int cnt=0;
        for(int i =L+1;i<R;i++) {
            cnt+=count(i,X);
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int L, R, X;
        cin >> L >> R >> X;
        Solution ob;
        int ans = ob.countX(L, R, X);
        cout << ans << "\n";
    }
}

// } Driver Code Ends