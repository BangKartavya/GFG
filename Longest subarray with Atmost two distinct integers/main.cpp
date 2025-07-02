class Solution {
    public:
        int totalElements(vector<int>& arr) {
            // code here
            int n = arr.size();

            int s = 0;
            int e = 0;

            unordered_map<int, int> mp;

            int maxi = 0;

            while(e < n) {
                mp[arr[e]]++;

                while(mp.size() > 2) {
                    mp[arr[s]]--;
                    if(mp[arr[s]] == 0) mp.erase(arr[s]);
                    s++;
                }

                maxi = max(maxi, e - s + 1);

                e++;
            }

            return maxi;
        }
};