class Solution {
    public:
        vector<int> farMin(vector<int>& arr) {
            int n = arr.size();
            vector<int> result(n, -1);
            priority_queue<pair<int, int>> pq;

            for(int i = 0; i < n - 1; i++) {
                pq.push({arr[i], i});
            }

            for(int i = n - 1; i >= 0; i--) {
                while(!pq.empty() && pq.top().first > arr[i]) {
                    if(pq.top().second < i) result[pq.top().second] = i;
                    pq.pop();
                }
            }

            return result;
        }
};