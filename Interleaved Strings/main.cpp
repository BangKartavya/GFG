class Solution {
    private:
        bool isSub(string& s1, string& s2) {
            int n = s1.size();
            int m = s2.size();

            if(n < m) return false;

            int i = 0;
            int j = 0;

            while(i < n && j < m) {
                if(s1[i] == s2[j]) {
                    i++;
                    j++;
                } else i++;
            }

            return j == m;
        }

    public:
        bool isInterleave(string& s1, string& s2, string& s3) {
            return isSub(s3, s1) && isSub(s3, s2);
        }
};