//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
        int n = arr.size();
        stack<int> st,st1;
        st.push(arr[0]);
        vector<int> small(n,0);
        for(int i = 1;i<n;i++) {
            while(!st.empty() && arr[i] <= st.top()) st.pop();
            
            if(!st.empty()) small[i] = st.top();
            st.push(arr[i]);
        }
        int maxi = small[n-1];
        st1.push(arr[n-1]);
        for(int i = n-1;i>=0;i--) {
            while(!st1.empty() && arr[i] <= st1.top()) st1.pop();
            if(!st1.empty()) maxi = max(abs(st1.top()-small[i]),maxi);
            else maxi = max(maxi,small[i]);
            st1.push(arr[i]);
        }
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends