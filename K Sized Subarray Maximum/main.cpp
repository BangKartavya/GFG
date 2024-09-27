//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int k, vector<int> &arr) {
        deque<int>dq;
        vector<int>ans;
        int i=0,j=0,n=arr.size();
        while(j < n){
            while(dq.size() > 0 and arr[dq.front()] < arr[j]){
                dq.pop_front();
            }
            dq.push_front(j);
            if(j-i+1 < k){
                j++;
            }
            else{
                ans.push_back(arr[dq.back()]);
                if(i == dq.back()){
                    dq.pop_back();
                }
                i++;j++;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> res = obj.max_of_subarrays(k, arr);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends