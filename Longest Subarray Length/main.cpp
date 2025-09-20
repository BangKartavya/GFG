class Solution {
  public:
    int longestSubarray(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> left(n,-1);
        vector<int> right(n,n);
        stack<int> stk;
        
        for(int i = 0;i<n;i++) {
            while(!stk.empty() && arr[stk.top()] <= arr[i]) stk.pop();
            if(!stk.empty()) left[i] = stk.top();
            stk.push(i);
        }
        
        while(!stk.empty()) stk.pop();
        
        for(int i = n-1;i>=0;i--) {
            while(!stk.empty() && arr[stk.top()] < arr[i]) stk.pop();
            
            if(!stk.empty()) right[i] = stk.top();
            stk.push(i);
        }
        
        int ans = 0;
        for(int i = 0;i<n;i++) {
            int len = right[i] - left[i] - 1;
            if(arr[i] <= len) ans = max(ans,len);
        }
        
        return ans;
        
    }
};