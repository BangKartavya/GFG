//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &a, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &a[i]);
        }
    }

    template <class T>
    static void print(vector<T> &a) {
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

struct Order {
    int a_tip;
    int b_tip;
    int diff;
    
    Order(int a_tip,int b_tip) {
        this->a_tip = a_tip;
        this->b_tip = b_tip;
        this->diff = abs(a_tip-b_tip);
    }
};

class Solution {
  public:
    static long long optimum(vector<int>& arr,vector<int>& brr,int x,int y,int n) {
        vector<Order> orders;
        for(int i =0;i<n; ++i) orders.emplace_back(arr[i],brr[i]);
        
        sort(begin(orders),end(orders),[](Order& o1,Order& o2) {return o1.diff > o2.diff;});
        
        long ans = 0;
        for(int i =0;i<n;++i) {
            Order& o = orders[i];
            
            if((o.a_tip>=o.b_tip && x > 0) || y <=0) {
                ans+=o.a_tip;
                x--;
            }
            else {
                ans+=o.b_tip;
                y--;
            }
            
        }
        return ans;
    } 
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
        return optimum(arr,brr,x,y,n);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        vector<int> arr(n);
        Array::input(arr, n);

        vector<int> brr(n);
        Array::input(brr, n);

        Solution obj;
        long long res = obj.maxTip(n, x, y, arr, brr);

        cout << res << endl;
    }
}

// } Driver Code Ends