//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    vector<int> getPrimes(int n) {
        vector<int> primes(n+1,1);
        primes[0] = 0;
        primes[1] = 0;
        
        for(int i = 2;i<=sqrt(n);i++) {
            for(int j = i*i; j<n;j+=i) {
                primes[j] = 0;
            }
        }
        int a = 1;
        int b = n-1;
        vector<int> ans;
        while(a<=b) {
            if(a+b==n && primes[a]==1 && primes[b] == 1) {
                ans.push_back(a);
                ans.push_back(b);
                break;
            }
            a++;
            b--;
        }
        
        if(ans.size()) return ans;
        
        return {-1,-1};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        vector<int> res = obj.getPrimes(n);

        Array::print(res);
    }
}

// } Driver Code Ends