//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:	
	int distinctSubsequences(string s)
	{
	    // Your code goes here
	    
	    int m[26] = {-1};
	    int n = s.length();
	    vector<int> dp(n+1);
	    
	    dp[0] = 1;
	    for(int i =0;i<s.length();i++) {
	        if(m[s[i]-'a']!=-1) {
	            dp[i+1] = ((dp[i]*2)%(1000000007))-dp[m[s[i]-'a']-1]+(1000000007);
	        }
	        else {
	            dp[i+1] = (dp[i]*2);
	        }
	        m[s[i]-'a'] =i+1;
	        dp[i+1] = dp[i+1]%(1000000007);
	    }
	    return dp[s.length()]%(1000000007);
	    
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends