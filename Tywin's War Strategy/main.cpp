class Solution {
    public:
        int minSoldiers(vector<int>& arr, int k) {
            sort(begin(arr), end(arr), greater<int>());

            int n = arr.size();
            vector<int> mp(k);

            for(int& i : arr) {
                mp[(i % k)]++;
            }

            if(mp[0] >= (n + 1) / 2) return 0;

            int res = 0;
            int lucky = mp[0];

            for(int i = k - 1; i > 0; i--) {
                if(lucky == (n + 1) / 2) return res;

                if(mp[i] <= ((n + 1) / 2 - lucky)) {
                    lucky += mp[i];
                    res += (mp[i] * (k - i));
                } else {
                    res += (((n + 1) / 2 - lucky) * (k - i));
                    lucky += ((n + 1) / 2 - lucky);
                }
            }

            return res;
        }
};