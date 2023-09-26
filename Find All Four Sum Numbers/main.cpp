//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k){
        set<vector<int>> s;
        int n = arr.size();
        sort(arr.begin(),arr.end());
        unordered_map<int, vector<pair<int,int>>> umap;
        for(int b =n-1;b>=0;b--) {
            for(int a=b-1;a>=0;a--) {
                if(umap.find(k-arr[b]-arr[a])!=umap.end()) {
                    for(auto it: umap[k-arr[b]-arr[a]]) {
                        s.insert({arr[a],arr[b],arr[it.first],arr[it.second]});
                    }
                }
            }
            
            for(int c=b+1;c<n;c++) {
                umap[arr[b]+arr[c]].push_back({b,c});
            }
        }
        
        vector<vector<int>> ans;
        for(auto it : s) {
            ans.push_back(it);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends