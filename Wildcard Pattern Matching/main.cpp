//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int n1,n2;
    vector<vector<int>> dp;
    
    int helper(int i,int j,string p,string s) {
        if(j == n2) {
            while(1 < n1 && p[i] == '*') i++;
            return i == n1;
        }
        
        if(i == n1) return j == n2;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(p[i] == s[j] && helper(i+1,j+1,p,s)) return 1;
        else if(p[i] == '?' && helper(i+1,j+1,p,s)) return 1;
        else if(p[i] == '*') {
            if(helper(i+1,j,p,s) || helper(i,j+1,p,s) || helper(i+1,j+1,p,s)) return 1;
        }
        
        return dp[i][j] = 0;
    }
    /*You are required to complete this method*/
    int wildCard(string pattern, string str) {
        n1 = pattern.size();
        n2 = str.size();
        dp.assign(n1,vector<int>(n2,-1));
        
        return helper(0,0,pattern,str);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends