//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    public:
        int minIncrements(vector<int> arr) {
            int n = arr.size();
            int ans = 0;
            unordered_set<int> s;
            map<int, int> mp;

            for(auto i : arr) {
                mp[i]++;
                s.insert(i);
            }
            int j = 0;
            while(s.find(j) != s.end())
                j++;

            for(auto& it : mp) {
                while(it.second > 1) {
                    while(s.find(j) != s.end() || j < it.first)
                        j++;
                    it.second--;
                    s.insert(j);
                    ans += j - it.first;
                    j++;
                }
            }
            return ans;
        }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while(t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while(ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        int ans = ob.minIncrements(a);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends