//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        vector<int> v;
        vector<int> w;
        int n =0;
        while(!q.empty()) {
            if(n==k) {
                w.push_back(q.front());
                q.pop();
            }
            else {
                v.push_back(q.front());
                q.pop();
                n++;
            }
        }
        reverse(v.begin(),v.end());
        
        
        
        for(auto i:v) q.push(i);
        for(auto i:w) q.push(i);
        
        return q;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        queue<int> ans = ob.modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends