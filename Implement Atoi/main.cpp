//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        int num = 0;
        int factor = s.size()-1;
        if(s[0] == '-') {
            factor--;
            for(int i = 1;i<s.size();i++) {
                if(s[i]-'0'<0 || s[i]-'0'>9) return -1;
                num+= pow(10,factor)*(s[i]-'0');
                factor--;
            }
            return -num;
        }
        else {
            for(int i = 0;i<s.size();i++) {
                if(s[i]-'0'<0 || s[i]-'0'>9) return -1;
                num+= pow(10,factor)*(s[i]-'0');
                factor--;
            }
        }
        
        return num;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends