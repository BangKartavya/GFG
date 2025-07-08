class Solution {
    public:
        vector<int> findGreater(vector<int>& arr) {
            unordered_map<int, int> mp;
            stack<int> stk;
            int n = arr.size();

            for(int& i : arr)
                mp[i]++;

            vector<int> result(n);

            for(int i = n - 1; i >= 0; i--) {
                if(stk.empty()) {
                    result[i] = -1;
                    stk.push(arr[i]);
                }

                else {
                    while(!stk.empty() && mp[stk.top()] <= mp[arr[i]]) {
                        stk.pop();
                    }

                    if(stk.empty()) result[i] = -1;
                    else result[i] = stk.top();

                    stk.push(arr[i]);
                }
            }

            return result;
        }
};
