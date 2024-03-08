//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool sameFreq(string s)
	{
	    int n = s.size();
	    
	    unordered_map<char,int> mp;
	    
	    for(auto i: s) mp[i]++;
	    
	    int m = mp.size();
	    int k = mp[s[0]];
	    int c = 0;
	    
	    for(auto it: mp) if(it.second==k) c++;
	    
	    if(c==m) return true;
	    
	    for(auto i: s) {
	        mp[i]--;
	        int p = mp[i];
	        int cnt=0;
	        for(auto j : mp) if(j.second==p) cnt++;
	        
	        if(cnt==m) return true;
	        else mp[i]++;
	    }
	    return false;
	}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends