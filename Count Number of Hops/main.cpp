//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        
        if(n==1) return 1;
        if(n==2) return 2;
        
        long long f = 1, s= 1, t= 2,mod = 1e9 + 7;
        for(int i = 3;i<=n;i++) {
            long long cur = (f+s+t)%mod;
            f = s;
            s = t;
            t = cur;
        }
        return t;
        
        
        // your code here
        
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends