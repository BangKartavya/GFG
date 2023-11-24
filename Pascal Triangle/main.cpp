//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// #define ll long long
class Solution{
public:
    int mod = 1e9 + 7;
    vector<long long> nthRowOfPascalTriangle(int n) {
        vector<long long> ans(n,0);
        return solve(ans,n);
    }
    
    vector<long long> solve(vector<long long> &ans,int n){
        if(n == 1){
            return {1};
        }
        vector<long long> prev = solve(ans,n - 1);
        ans[0] = 1;
        ans[n - 1] = 1;
        for(int i =1;i< n - 1;i++){
            ans[i] = (prev[i - 1] + prev[i])%mod;
        }
        return ans;
    }
};


//{ Driver Code Starts.


void printAns(vector<long long> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends