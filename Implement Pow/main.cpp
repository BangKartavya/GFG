//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    double power(double b, int e) {
        if(e < 0) {
            return power((double)1/b,abs(e));
        }
        double res = 1;
        
        while(e > 0) {
            if(e%2 == 0) {
                b = (b*b);
                e/=2;
            }
            else {
                res *= b;
                e--;
            }
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    cout << fixed << setprecision(5);
    int t;
    cin >> t;
    while (t--) {
        double b;
        cin >> b;
        int e;
        cin >> e;
        Solution ob;
        cout << ob.power(b, e) << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends