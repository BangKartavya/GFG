//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int min_sprinklers(int gallery[], int n)
    {
        vector<pair<int,int>> v;
        
        for(int i =0;i<n;i++) {
            if(gallery[i]!=-1) {
                v.push_back({i-gallery[i],i+gallery[i]});
            }
        }
        
        int m = v.size();
        
        sort(v.begin(),v.end());
        
        int target = 0;
        int i =0;
        int ans = 0;
        
        while(target<n && i<m) {
            if(v[i].first > target) return -1;
            
            int maxi = v[i].second; i++;
            while(i<m && v[i].first<=target) {
                maxi = max(maxi,v[i].second);
                i++;
            }
            target = maxi+1;
            ans++;
        }
        if(target<n-1) return -1;
        else return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        int gallery[n];
        for(int i=0; i<n; i++)
            cin>> gallery[i];
        Solution obj;
        cout<< obj.min_sprinklers(gallery,n) << endl;
    }
	return 1;
}

// } Driver Code Ends