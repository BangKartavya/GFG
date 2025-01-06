//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        int n = arr.size();
        
        if(n == 1) return {};
        
        sort(begin(arr),end(arr));
        
        int i = 0;
        int j = n-1;
        
        int first;
        int second;
        
        int diff = INT_MAX;
        
        while(i < j) {
            int temp = arr[i] + arr[j];
            
            if(diff > abs(target-temp)) {
                diff = abs(target-temp);
                first = i;
                second = j;
            }
            
            if(temp >= target) j--;
            
            else i++;
            
        }
        
        return {arr[first],arr[second]};
        
        
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
        string ks;
        getline(cin, ks);
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends