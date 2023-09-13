//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        // code here
        
        if(S>9*N || (S==0 && N!=1)) {
            return "-1";
        }
        

        
        string number = "";
        if(S < 9) {
            number+= to_string(S);
            for(int i =number.length();i<N;i++) {
                number+="0";
            }
            
        }
        else {
            while(S>9) {
                number+= "9";
                S-=9;
            }
            if(S > 0) {
                number+= to_string(S);
            }
            if(number.length()<N) {
                for(int i = number.length();i<N;i++) {
                    number+= "0";
                }
            }
            
        }
        return number;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends