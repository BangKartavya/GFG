//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        vector<int> res;
        unordered_set<int> s;
        int i = 0;
        int j = 0;
        
        int n = a.size();
        int m = b.size();
        
        while(i < n && j < m) {
            if(a[i] <= b[j]) {
                if(s.find(a[i]) == s.end()) {
                    res.push_back(a[i]);
                    s.insert(a[i]);
                }
                i++;
            }
            else {
                if(s.find(b[j]) == s.end()) {
                    res.push_back(b[j]);
                    s.insert(b[j]);
                }
                j++;
            }
        }
        
        while(i < n) {
            if(s.find(a[i]) == s.end()) {
                res.push_back(a[i]);
                s.insert(a[i]);
            }
            i++;
        }
        
        while(j < m) {
            if(s.find(b[j]) == s.end()) {
                res.push_back(b[j]);
                s.insert(b[j]);
            }
            j++;
        }
        
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a, b;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        // Read second array
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            b.push_back(number);
        }

        Solution ob;
        vector<int> ans = ob.findUnion(a, b);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends