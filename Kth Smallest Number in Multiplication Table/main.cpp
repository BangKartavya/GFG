class Solution {
    public:
        int kthSmallest(int m, int n, int k) {
            int s = 1;
            int e = m * n;
            int ans = 0;

            while(s <= e) {
                int mid = s + (e - s) / 2;

                int count = 0;

                for(int i = 1; i <= m; i++) {
                    count += min(mid / i, n);
                }

                if(count < k) {
                    s = mid + 1;
                } else {
                    ans = mid;
                    e = mid - 1;
                }
            }

            return ans;
        }
};
