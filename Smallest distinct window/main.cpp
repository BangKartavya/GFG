///{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    public:
        int findSubString(string& str) {
            int n = str.size();
            int i = 0;
            int j = 0;

            unordered_set<char> s;

            for(int i = 0; i < n; i++) {
                s.insert(str[i]);
            }

            unordered_map<char, int> mp;

            int result = INT_MAX;

            while(j < n) {
                mp[str[j]]++;

                while(mp.size() == s.size()) {
                    result = min(result, j - i + 1);
                    mp[str[i]]--;

                    if(mp[str[i]] == 0) mp.erase(str[i]);

                    i++;
                }

                j++;
            }

            return result;
        }
};

//{ Driver Code Starts.
//      Driver code
int main() {
    int t;
    cin >> t;
    while(t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends