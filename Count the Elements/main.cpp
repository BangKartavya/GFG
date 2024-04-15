//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query,
                              int q) {
        int mx = 0;  
        for(int i = 0; i < n; i++) {
            mx = max(mx, max(a[i], b[i])); 
        }
        
        int pre[mx + 1] = {0};  
        for(int i = 0; i < n; i++) {
            pre[b[i]] += 1; 
        }
        
        for(int i = 1; i <= mx; i++) {
            pre[i] += pre[i - 1]; 
        }
        
        
        vector<int> ans; 
        for(int i = 0; i < q; i++) {
            int ind = query[i]; 
            int val = a[ind]; 
            ans.push_back(pre[val]); 
        }
        return ans; 
    }
};


//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {

        int n;
        cin >> n;
        vector<int> a, b, ans;
        int input;
        for (int i = 0; i < n; i++) {
            cin >> input;
            a.push_back(input);
        }
        for (int i = 0; i < n; i++) {
            cin >> input;
            b.push_back(input);
        }
        int q;
        cin >> q;
        vector<int> query;
        for (int i = 0; i < q; i++) {
            cin >> input;
            query.push_back(input);
        }
        Solution obj;
        ans = obj.countElements(a, b, n, query, q);
        for (int i = 0; i < q; i++) {
            cout << ans[i] << endl;
        }
    }
    return 0;
}
// } Driver Code Ends