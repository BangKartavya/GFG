//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/
class Solution {
  public:
    long long max_sum(int a[], int n) {
        long long ans = 0, currentConfig = 0, total = 0;
        for(long long i=0; i<n; i++){
            total += a[i]; // storing total of the array
            currentConfig += i*a[i]; // for initial configuration
        }
        ans = currentConfig;// storing for configuration 1
        for(int i=1; i<n; i++){
            currentConfig = currentConfig + total - (long long)n*a[n-i]; // we are moving from last index of the array to first of the array's index and adjusting likewise
            ans = max(ans, currentConfig);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.max_sum(A, N) << endl;
        /*keeping track of the total sum of the array*/
    }
}

// } Driver Code Ends