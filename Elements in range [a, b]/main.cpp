class Solution {
  public:
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        sort(begin(arr),end(arr));
        
        vector<int> res;
        
        for(vector<int>& q: queries) {
            int a = q[0];
            int b = q[1];
            
            int startIdx = lower_bound(begin(arr),end(arr),a) - begin(arr);
            int endIdx = upper_bound(begin(arr),end(arr),b) - begin(arr);
            
            res.push_back(endIdx-startIdx);
        }
        
        return res;
    }
};