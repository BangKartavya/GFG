//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
	{
	    vector<int> v1;
	    vector<int> v2;
	    
	    for(int i =0;i<n;i++) {
	        for(int j =0;j<n;j++) {
	            v1.push_back(mat1[i][j]);
	            v2.push_back(mat2[i][j]);
	        }
	    }
	    
	    int ans = 0;
	    for(int i =0;i<v1.size();i++) {
    	    int s = 0;
    	    int e = v2.size()-1;
    	    int t = x-v1[i];
    	    
    	    while(s<=e) {
    	        int mid = s+(e-s)/2;
    	        
    	        if(t==v2[mid]) break;
    	        if(t>v2[mid]) s = mid+1;
    	        else e = mid-1;
    	    }
    	    if(s<=e) ans++;
	    }
	    
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
    while (t--)
    {
        int n, x;
        cin >> n >> x;

        vector<vector<int>> mat1(n, vector<int>(n, -1));
        vector<vector<int>> mat2(n, vector<int>(n, -1));

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat1[i][j];
        	}
        }

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat2[i][j];
        	}
        }

        Solution ob;

        cout << ob.countPairs(mat1, mat2, n, x) << "\n";

    }

    return 0;
}
// } Driver Code Ends