class Solution {
    public:
        int missingNumber(vector<int>& arr) {
            // code here
            int n = arr.size();

            for(int i = 0; i < n; i++) {
                if(arr[i] <= 0 || arr[i] > n) {
                    arr[i] = n + 1;
                }
            }

            for(int i = 0; i < n; i++) {
                int num = abs(arr[i]);

                if(num <= n) {
                    arr[num - 1] = -abs(arr[num - 1]);
                }
            }

            for(int i = 0; i < n; i++) {
                if(arr[i] > 0) return i + 1;
            }

            return n + 1;
        }
};