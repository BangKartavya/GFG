//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    public:
        int maxDistance(vector<int>& arr) {
            int n = arr.size();
            unordered_map<int, vector<int>> mp;

            for(int i = 0; i < n; i++) {
                mp[arr[i]].push_back(i);
            }

            int ans = 0;

            for(auto i : mp) {
                int s = i.second.size();

                ans = max(ans, i.second[s - 1] - i.second[0]);
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
        vector<int> arr;
        string input;
        getline(cin, input);

        stringstream s1(input);
        int num;
        while(s1 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.maxDistance(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends