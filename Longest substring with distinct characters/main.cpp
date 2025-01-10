//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        int n = s.size();
        int maxi = 0;
        int i = 0;
        int j = 0;
        
        unordered_map<char,int> mp;
        
        while(j < n) {
            mp[s[j]]++;
            
            while(i < j && mp[s[j]] > 1) mp[s[i++]]--;
        
            maxi = max(maxi,j-i+1);
            j++;
        }
        
        
        return maxi;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends