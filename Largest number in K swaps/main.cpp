/09//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    private:
        void solve(int idx, int k, string s, string& ans) {
            if(k == 0 || idx == s.size()) {
                if(s > ans) ans = s;
                return;
            }
            for(int i = idx; i < s.length(); i++) {
                if(s[i] > s[idx]) {
                    swap(s[i], s[idx]);
                    solve(idx + 1, k - 1, s, ans);
                    swap(s[i], s[idx]);
                }
                solve(i + 1, k, s, ans);
            }
        }

    public:
        string findMaximumNum(string& s, int k) {
            // code here.
            string ans = s;
            solve(0, k, s, ans);
            return ans;
        }
};

//{ Driver Code Starts.

int main() {
    int t, k;
    string str;

    cin >> t;
    while(t--) {
        cin >> k >> str;
        Solution ob;
        cout << ob.findMaximumNum(str, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends