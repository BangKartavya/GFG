//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    unordered_set<string> s;
    string str;
    int n;
    vector<string> answer;
    vector<bool> vis;
    
    void genPerm(string result,int i) {
        if(result.size() == n) {
            if(s.find(result) == s.end()) {
                s.insert(result);
                answer.push_back(result);
            }
            return;
        }
        
        vis[i] = true;
        for(int j = 0;j<n;j++) {
            if(!vis[j]) {
                genPerm(result+str[j],j);
            }
        }
        vis[i] = false;
    }
    
  public:
    vector<string> findPermutation(string &s) {
        this->str = s;
        n = s.size();
        
        vis.resize(n,false);
        
        for(int i = 0;i<n;i++) {
            string temp = s.substr(i,1);
            genPerm(temp,i);
        }
        
        return answer;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends