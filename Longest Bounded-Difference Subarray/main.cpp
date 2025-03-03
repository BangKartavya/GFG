//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    public:
        vector<int> longestSubarray(vector<int>& a, int x) {
            multiset<int> st;
            int maxi = 0, curr = 0, ind = 0;
            int j = 0, n = a.size();

            for(int i = 0; i < n; i++) {
                st.insert(a[i]);
                curr++;

                while(*st.rbegin() - *st.begin() > x) {
                    st.erase(st.find(a[j++]));
                    curr--;
                }

                if(curr > maxi) {
                    maxi = curr;
                    ind = i;
                }
            }

            return vector<int>(a.begin() + ind - maxi + 1, a.begin() + ind + 1);
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.longestSubarray(arr, k);
        for(auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends