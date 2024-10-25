//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {

  public:
    vector<int> alternateSort(vector<int>& arr) {
        // Your code goes here
        
        sort(begin(arr), end(arr));
        
        int n = arr.size();
        int max_ind = n-1;
        int min_ind = 0;
        
        int maxi = arr[n-1]+1;
        
        for(int i = 0;i<n;i++) {
            if(i%2==0) arr[i] = (arr[max_ind--] % maxi) * maxi + arr[i] ;
            else arr[i] = (arr[min_ind++] % maxi) * maxi + arr[i] ;
        }
        
        for(auto& i:arr) i=i/maxi;
        
        return arr;
        
    }
};




//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> ans = obj.alternateSort(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends