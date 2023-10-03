//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        int i =1;
        unordered_map<int,char> mp;
        
        for(char c = 'A';c<'Z';c++) {
            mp[i] = c;
            i++;
        }
        
        mp[0] = 'Z';
        
        string res;
        while(n>0) {
            res = mp[n%26]+res;
            
            if(n%26==0) {
                n/=26;
                n--;
            }
            else {
                n/=26;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}

// } Driver Code Ends