//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    public:
        vector<int> calculateSpan(vector<int>& arr) {
            int n = arr.size();
            stack<pair<int, int>> st;
            vector<int> ans;

            for(int i = 0; i < n; i++) {
                int count = 1;

                while(!st.empty() && arr[i] >= st.top().first) {
                    count += st.top().second;
                    st.pop();
                }
                st.push({arr[i], count});
                ans.push_back(count);
            }
            return ans;
        }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while(t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while(ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> ans = obj.calculateSpan(arr);
        for(int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends