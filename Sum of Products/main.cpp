//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    long long pairAndSum(int n, long long arr[]) {
        long long res = 0;
        
        for(int bit = 0;bit<32;bit++) {
            int cnt = 0;
            for(int i =0;i<n;i++) {
                if(arr[i]&(1LL<<bit)) cnt++;
            }
            res += (cnt*1LL*(cnt-1)/2) * (1LL<<bit);
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        long long Arr[N];
        for (int i = 0; i < N; i++) {
            cin >> Arr[i];
        }
        Solution ob;
        cout << ob.pairAndSum(N, Arr) << endl;
    }
    return 0;
}
// } Driver Code Ends