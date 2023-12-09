//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int SumPrime(int n) {
        int ans=0;
        
        for(int i = 2;i<=sqrt(n);i++) {
            if(n%i==0) {
                int cnt=0;
                while(n%i==0) {
                    cnt++;
                    n/=i;
                }
                int s = sumOfDigits(i);
                for(int j =0;j<cnt;j++) ans+=s;
            }
        }
        if(n>1) ans+=sumOfDigits(n);
        return ans;
    }
    
    bool isPrime(int n) {
        for(int i =2;i*i<=n;i++) {
            if(n%i==0) return false;
        }
        return true;
    }
    
    int sumOfDigits(int n) {
        int s =0;

        while(n>0) {
            s+=n%10;
            n/=10;
        }

        return s;
    }
    
    int smithNum(int n) {
        
        if(isPrime(n)) return 0;
        
        int pf = SumPrime(n);
        
        int d = sumOfDigits(n);

        return pf==d;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.smithNum(n) << endl;
    }
    return 0;
}
// } Driver Code Ends