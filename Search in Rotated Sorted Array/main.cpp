//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    vector<int> arr;
    int n;
    int key;
    int pivot(int s,int e) {
        if(arr[s] <= arr[e]) return s;
        
        int mid = s + (e-s)/2;
        
        if(arr[mid] >= arr[s]) {
            return pivot(mid+1,e);
        }
        
        return pivot(s,mid);
    }
    int binS(int s, int e) {
        if(s > e) return -1;
        
        int mid = s + (e-s)/2;
   
        if(arr[mid] == key) return mid;
        else if(arr[mid] < key) return binS(mid+1,e);
        else return binS(s,mid-1);
    }
  public:
    int search(vector<int>& arr, int key) {
        this->arr = arr;
        n = arr.size();
        this->key = key;
        int piv = pivot(0,n-1);
        
        int bs1 = binS(0,piv-1);
        int bs2 = binS(piv,n-1);
        // cout << "piv : " << piv << endl;
        // cout << "bs1 : " << bs1 << endl;
        // cout << "bs2 : " << bs2 << endl;
        
        return bs1 != -1 ? bs1 : bs2;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends