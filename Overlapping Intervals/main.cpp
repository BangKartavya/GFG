//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        sort(begin(arr),end(arr));
        
        vector<vector<int>> ans;
        
        int i = 0;
        int j = 1;
        int n = arr.size();
        
        while(j < n) {
            vector<int> interval = arr[i];
            
            while(j < n && interval[1] >= arr[j][0]) {
                interval[1] = max(interval[1],arr[j][1]);
                j++;
            }
            
            ans.push_back(interval);
            i = j;
            j++;
        }
        
        if(i < n) ans.push_back(arr[i]);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }
        Solution obj;
        vector<vector<int>> ans = obj.mergeOverlap(arr);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends