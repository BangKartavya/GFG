class Solution {
    public:
        int minimumCoins(vector<int>& arr, int k) {
            sort(begin(arr), end(arr));
            int n = arr.size();
            vector<int> prefix(n + 1);

            for(int i = 0; i < n; i++) {
                prefix[i + 1] = arr[i] + prefix[i];
            }

            int res = INT_MAX;

            for(int i = 0; i < n; i++) {
                int mini = arr[i];
                int maxAllowed = arr[i] + k;

                int leftRemoved = prefix[i]; // entire piles
                int rightRemoved = 0;
                int cut = upper_bound(begin(arr), end(arr), maxAllowed) - begin(arr);

                if(cut < n) {
                    rightRemoved = prefix[n] - prefix[cut] - (n - cut) * maxAllowed;
                }

                res = min(res, leftRemoved + rightRemoved);
            }

            return res;
        }
};
