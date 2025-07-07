class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
        int n = arr.size();
        
        for(int i = 0;i<n;i++) arr.push_back(arr[i]);
        
        stack<int> stk;
        
        vector<int> result(2*n);
        
        for(int i = 2*n-1;i>=0;i--) {
            if(stk.empty()) {
                result[i] = -1;
                stk.push(arr[i]);
            }    
            else {
                if(stk.top() > arr[i]) {
                    result[i] = stk.top();
                    stk.push(arr[i]);
                }
                else {
                    while(!stk.empty() && stk.top() <= arr[i]) {
                        stk.pop();
                    }
                    result[i] = stk.empty() ? -1 : stk.top();
                    stk.push(arr[i]);
                }
            }
        }
        
        vector<int> temp;
        
        for(int i = 0;i<n;i++) temp.push_back(result[i]);
        
        return temp;
    }
};