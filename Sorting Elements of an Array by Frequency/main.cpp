//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

bool cmp(pair<int,int> p1,pair<int,int> p2) {
    if(p1.second > p2.second) return p1.second > p2.second;
    else if(p1.second == p2.second) return p1.first < p2.first;
    else return p1.second > p2.second;
}

class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int> arr) {
        map<int,int> mp;
        vector<pair<int,int>> vp;
        
        for(auto i: arr) mp[i]++;
        
        for(auto it: mp) vp.push_back(it);
        
        sort(vp.begin(),vp.end(),cmp);
        int k = 0;
        for(auto i: vp) {
            for(int j = 0;j<i.second;j++) {
                arr[k++] = i.first;
            }            
        }
        return arr;
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends