//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int firstElement(int n) {
        // code here
        int MOD = 1e9+7;
        if(n<=2) return 1;
        int one = 1;
        int two = 1;
        int sum = 0;
        
        for(int i =0;i<n-2;i++) {
            sum = (one+two)%MOD;
            one = two;
            two = sum;
        }
        return sum%MOD;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}

// } Driver Code Ends