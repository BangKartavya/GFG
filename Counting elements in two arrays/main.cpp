class Solution {
    public:
        vector<int> countLessEq(vector<int>& a, vector<int>& b) {
            int n = a.size();
            int m = b.size();

            sort(begin(b), end(b));

            vector<int> result;

            for(int& i : a) {
                int justGreater = upper_bound(begin(b), end(b), i) - begin(b);
                result.push_back(justGreater);
            }

            return result;
        }
};