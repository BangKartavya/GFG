//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        long maxi = INT_MIN;
        long sum = 0;
        int i=0,j=K+i-1;
        
        for(int m=0;m<=j;m++) sum+=Arr[m];
        
        while(i<N && j<N) {
            if(sum>maxi) maxi = sum;
            sum-=Arr[i];
            i++;
            j++;
            sum+=Arr[j];
        }
        return maxi;
        
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends