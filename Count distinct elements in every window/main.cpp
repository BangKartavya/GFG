//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        int s = 0;
        int e = k-1;
        vector<int> res;
        unordered_map<int,int> mp;
        int n = arr.size();
        for(int i = s;i<=e;i++) mp[arr[i]]++;
        
        while(e < n) {
            // cout << "s : " << s << " e : " << e << endl;
            
            res.push_back(mp.size());
            mp[arr[s]]--;
            
            if(mp[arr[s]] == 0) mp.erase(arr[s]);
            s++;
            e++;
            
            // cout << "s : " << s << " e : " << e << endl;
            
            mp[arr[e]]++;
            
            /*for(auto it: mp) {
                cout << "first : " << it.first << endl;
                cout << "second : " << it.second << endl;
            }*/
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
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
        int k = stoi(ks);
        Solution obj;
        vector<int> res = obj.countDistinct(arr, k);
        for (auto it : res)
            cout << it << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends