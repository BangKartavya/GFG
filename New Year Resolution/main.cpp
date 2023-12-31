//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    
    public:
    bool helper(int coins[],int n,int i,int s) {
        if(s!=0 && (s%20==0 || s%24==0 || s==2024)) return true;
        if(i>=n) return false;
        return helper(coins,n,i+1,s+coins[i]) || helper(coins,n,i+1,s);
    }
    
    int isPossible(int N , int coins[]) 
    {
        return helper(coins,N,0,0);
    }
    
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int coins[N];
        for(int i=0 ; i<N ; i++)
            cin>>coins[i];

        Solution ob;
        cout << ob.isPossible(N,coins) << endl;
    }
    return 0;
}
// } Driver Code Ends