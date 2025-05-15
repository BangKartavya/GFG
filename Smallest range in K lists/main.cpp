//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> findSmallestRange(vector<vector<int>>& arr) {
        int k = arr.size();
        int n = arr[0].size();
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> minHeap;
        
        int left = arr[0][0];
        int right = arr[0][0];
        
        
        for(int i = 0;i<k;i++) {
            left = min(left,arr[i][0]);
            right = max(right,arr[i][0]);
            minHeap.push({arr[i][0],{i,0}});
        }
        vector<int> result = {left,right};
        
        while(!minHeap.empty()) {
            pair<int,pair<int,int>> p = minHeap.top();
            minHeap.pop();
            
            int num = p.first;
            int listNumber = p.second.first;
            int idx = p.second.second;
            
            idx++;
            if(idx >= n) break;
            
            minHeap.push({arr[listNumber][idx],{listNumber,idx}});
            
            if(arr[listNumber][idx] > right) {
                right = arr[listNumber][idx];
            }
            
            left = minHeap.top().first;
            
            if(result[1]-result[0] > right-left) {
                result = {left,right};
            }
        }
        
        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> arr(k, vector<int>(n));

        for (int i = 0; i < k; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];

        Solution obj;
        vector<int> range = obj.findSmallestRange(arr);
        cout << range[0] << " " << range[1] << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends