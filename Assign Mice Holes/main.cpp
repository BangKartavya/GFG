class Solution {
    public:
        int assignHole(vector<int>& mices, vector<int>& holes) {
            // code here
            int n = mices.size();

            sort(begin(mices), end(mices));
            sort(begin(holes), end(holes));

            int count = 0;

            for(int i = 0; i < n; i++) {
                count = max(count, abs(mices[i] - holes[i]));
            }

            return count;
        }
};