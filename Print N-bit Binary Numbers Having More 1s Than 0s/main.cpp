//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    void solve(int n,int zero,int one,string temp,vector<string>& ans) {
        if(n==0 && one>=zero) {
            ans.push_back(temp);
            return;
        }
        if(zero>one) return;
        
        solve(n-1,zero,one+1,temp+'1',ans);
        solve(n-1,zero+1,one,temp+'0',ans);
    }
	vector<string> NBitBinary(int n)
	{
	    vector<string> ans;
	    string temp;
	    solve(n,0,0,temp,ans);
	    
	    return ans;
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
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends