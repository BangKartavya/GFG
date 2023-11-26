//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    void solve(int n,vector<int>& ans) {
        ans.push_back(n);
        if(n<=0) return;
        solve(n-5,ans);
        ans.push_back(n);
    }

    vector<int> pattern(int N){
        vector<int> ans;
        solve(N,ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends