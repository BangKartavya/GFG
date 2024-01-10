//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	    unordered_map<int,int> prefixSum;
	    prefixSum[0] = -1;
	    int maxLength = 0;
	    int currentSum = 0;
	    
	    for(int i =0;i<n;i++) {
	        currentSum+=arr[i];
	        int rem = (currentSum%k+k)%k;
	        
	        if(rem == 0) maxLength = max(maxLength,i+1);
	        else if(prefixSum.find(rem)!=prefixSum.end()) maxLength = max(maxLength,i-prefixSum[rem]);
	        else prefixSum[rem] = i;
	    }
	    return maxLength;
	}
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}

// } Driver Code Ends