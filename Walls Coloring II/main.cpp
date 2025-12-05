class Solution {
    public:
        int minCost(vector<vector<int>>& c) {
            // code here
            int n = c.size(), k = c[0].size();
            if(k == 1 and n > 1) return -1;
            vector<int> dp = c[0];
            for(int i = 1; i < n; i++) {
                int mi = -1, smi = -1;
                for(int j = 0; j < k; j++) {
                    if(mi == -1 || dp[j] < dp[mi]) smi = mi, mi = j;
                    else if(smi == -1 || dp[j] < dp[smi]) smi = j;
                }
                int val_mi = dp[mi], val_smi = dp[smi];
                for(int j = 0; j < k; j++) {
                    if(j != mi) dp[j] = c[i][j] + val_mi;
                    else dp[j] = c[i][j] + val_smi;
                }
            }
            return *min_element(dp.begin(), dp.end());
        }
};