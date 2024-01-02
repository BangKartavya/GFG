//{ Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:    
    long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    {
        vector<long long int> prefix(n);
        partial_sum(a,a+n,prefix.begin());
        
        long long maximumSum = INT_MIN, minPrefix = 0;
        
        int i=0, j=k-1;
        
        while(j<n) {
            maximumSum = max(maximumSum,prefix[j++]-minPrefix);
            minPrefix = min(minPrefix,prefix[i++]);
        }
        return maximumSum;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        Solution ob;
        cout << ob.maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends