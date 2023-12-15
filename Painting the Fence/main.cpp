{ Driver Code Starts
#include bitsstdc++.h
#includestdio.h
#includemath.h
using namespace std;

 } Driver Code Ends


class Solution{
    public
    long long countWays(int n, int k){
        long long MOD = 1e9+7;
        long long diff = k;
        long long same = 0;
        long long total = k;
        
        if(n==1){
            return total;
        }
        else{
            for(int i=2;i=n;i++){
                same = (diff)%MOD;
                diff = (total(k-1))%MOD;
                total = (same + diff)%MOD;
            }
        }
        return (total)%MOD;
    }
};



{ Driver Code Starts.

int main()
{
	
	int t;
	cint;
	while(t--)
	{
		int n,k;
		cinnk;
		Solution ob;
		coutob.countWays(n,k)endl;
	}
	return 0;
}
 } Driver Code Ends