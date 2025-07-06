06/2class Solution {
    public:
        vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
            int n = a.size();
            vector<int> ans;
            sort(a.begin(), a.end(), greater<int>());
            sort(b.begin(), b.end(), greater<int>());
            priority_queue<pair<int, pair<int, int>>> pq;
            pq.push({a[0] + b[0], {0, 0}});
            map<pair<int, int>, int> mp;
            mp[{0, 0}] = 1;
            while(!pq.empty() && ans.size() < k) {
                auto it = pq.top();
                ans.push_back(it.first);
                pq.pop();
                int i = it.second.first, j = it.second.second;
                if(i + 1 < n && !mp[{i + 1, j}]) {
                    pq.push({a[i + 1] + b[j], {i + 1, j}});
                    mp[{i + 1, j}] = 1;
                }
                if(j + 1 < n && !mp[{i, j + 1}]) {
                    pq.push({a[i] + b[j + 1], {i, j + 1}});
                    mp[{i, j + 1}] = 1;
                }
            }
            return ans;
        }
};