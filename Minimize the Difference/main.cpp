//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int minimizeDifference(int n, int k, vector<int> &arr) {
        deque<int>dqMax;
        deque<int>dqMin;
        
        int remK = n-k;
        int mindif = INT_MAX;
        
        for(int i = 0;i<remK-1; i++){
             
            while(!dqMax.empty()&& dqMax.back()<arr[i+k]){
                dqMax.pop_back();
            }
            dqMax.push_back(arr[i+k]);
            
            
            while(!dqMin.empty()&& dqMin.back()>arr[i+k]){
                dqMin.pop_back();
            }
            dqMin.push_back(arr[i+k]);
        }
        int indexS = n-1;
        int indexL = k;
        for(int i = k-1; i<n; i++,indexS++,indexL++){
            
            
            
            while(!dqMax.empty()&& dqMax.back()<arr[indexS%n]){
                dqMax.pop_back();
            }
            dqMax.push_back(arr[indexS%n]);
            
            
            while(!dqMin.empty()&& dqMin.back()>arr[indexS%n]){
                dqMin.pop_back();
            }
            dqMin.push_back(arr[indexS%n]);
            
         
            
            mindif = min(mindif, abs(dqMax.front()-dqMin.front()) );
            
           
            if(arr[indexL%n] == dqMax.front()){
                dqMax.pop_front();
            }
             
            if(arr[indexL%n] == dqMin.front()){
                dqMin.pop_front();
            }
            
        }
        
        return mindif;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        int k;
        scanf("%d",&k);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        Solution obj;
        int res = obj.minimizeDifference(n, k, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends