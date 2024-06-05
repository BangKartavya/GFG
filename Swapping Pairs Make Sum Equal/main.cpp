//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        long long sum1=0, sum=0;
        for(int i=0; i<n; i++) sum += a[i];
        for(int i=0; i<m; i++) sum1 += b[i];
        sort(a, a+n); sort(b, b+m);
        long long d = sum1 - sum;
        if (d%2 == 1){
            return -1;
        }
        for(int i=0; i<n; i++){
            long long x = d/2 + a[i];
            if (binary_search(b, b+m, x)){
                sum -= a[i];
                sum1 -= x;
                sum1 += a[i];
                sum += x;
                if(sum == sum1) return 1; 
            } 
        }
        return -1;
        
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends