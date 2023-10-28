//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:

    int countSetBits(int x) {
        int setbits = 0;
        
        while(x) {
            if(x&1) setbits++;
            x/=2;
        }
        return setbits;
    }    
    
    int ceilLog2(int x) {
        int c = 0;
        x--;
        
        while(x>0) {
            x= x>>1;
            c++;
        }
        return c;
    }

	int is_bleak(int n)
	{
	    if(n==0) return 1;
	    
	    for(int i =n-ceilLog2(n);i<n;i++) {
	        if(i+countSetBits(i)==n) return 0;
	    }
	    
	    return 1;
	}
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    }
	return 0;
}

// } Driver Code Ends