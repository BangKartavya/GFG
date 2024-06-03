//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int M = 1e9+7;
    int numberOfConsecutiveOnes(int n) {
        int a = 1;
        int b = 1;
        int ans = 1;
        
        if(n==1 || n==2) return 1;
        
        for(int i = 3;i<=n;i++) {
            int c = (a+b)%M;
            a = b;
            b = c;
            ans = ((ans*2)%M + a)%M;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.numberOfConsecutiveOnes(N) << endl;
    }
    return 0;
}

// } Driver Code Ends