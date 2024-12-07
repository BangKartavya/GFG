//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    int ans = 0;
    int n;
    
    void merge(vector<int>& arr,int s,int mid, int e) {
        vector<int> temp;
        int l = s;
        int r = mid+1;
        
        while(l <= mid && r <= e) {
            if(arr[l] <= arr[r]) {
                temp.push_back(arr[l++]);
            }
            else {
                ans += (mid-l+1);
                temp.push_back(arr[r++]);
            }
        }
        
        while(l <= mid) {
            temp.push_back(arr[l++]);
        }
        
        while(r <= e) {
            temp.push_back(arr[r++]);
        }
        
        for(int i = s;i<=e;i++) {
            arr[i] = temp[i-s];
        }
        
        return;
        
    }
    
    void mergeSort(vector<int>& arr, int s, int e) {
        if(s < e) {
            int mid = s + (e-s)/2;
            
            mergeSort(arr,s,mid);
            mergeSort(arr,mid+1,e);
            merge(arr,s,mid,e);
        }
        
        return;
    }
    
  public:
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        int n = arr.size();
        mergeSort(arr,0,n-1);
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends