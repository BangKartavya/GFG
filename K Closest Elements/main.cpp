{ Driver Code Starts
 Initial template for C++

#include bitsstdc++.h
using namespace std;


 } Driver Code Ends
 User function template for C++

struct comp
{
      bool operator()(pairint,inta,pairint,intb)
      {
          if(a.first==b.first)
          {
              return a.second  b.second;
          }
          return a.firstb.first;
      }
};

class Solution {
  public
    vectorint printKClosest(vectorint arr, int n, int k, int x) {
        priority_queuepairint,int,vectorpairint,int,comppq;
        for(int i=0;in;i++)
        {
            if(arr[i]!=x)
            {
                pq.push({abs(arr[i]-x),arr[i]});
            }
            while(pq.size()k)
            pq.pop();
        }
        vectorintv;
        while(!pq.empty())
        {
            v.push_back(pq.top().second);
            pq.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
};


{ Driver Code Starts.

int main() {
    int t;
    cin  t;
    while (t--) {
        int n, k, x;
        cin  n;
        vectorint arr(n);
        for (int i = 0; i  n; i++) {
            cin  arr[i];
        }
        cin  k  x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e  ans) {
            cout  e   ;
        }
        cout  n;
    }
    return 0;
}

 } Driver Code Ends