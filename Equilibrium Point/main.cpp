//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        if(n == 1) return 1;
        if(n == 0) return 0;
        
        int s1 = 0;
        int s2 = 0;
        
        for(int i =0;i<n;i++) {
            s1+=a[i];
        }
        
        for(int i =0;i<n;i++) {
            s1-=a[i];
            
            if(s1==s2) {
                return i+1;
            }
            s2+=a[i];
        }
        return -1;
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends