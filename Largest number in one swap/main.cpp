class Solution {
    public:
        string largestSwap(string& s) {
            int n = s.size();
            int dig[10];

            memset(dig, -1, sizeof(dig));

            for(int i = n - 1; i >= 0; i--) {
                int d = s[i] - '0';
                if(dig[d] == -1) dig[d] = i;
            }

            for(int i = 0; i < n; i++) {
                int d = s[i] - '0';
                for(int j = 9; j >= 0; j--) {
                    if(dig[j] != -1 && dig[j] > i && j > d) {
                        swap(s[i], s[dig[j]]);
                        return s;
                    }
                }
            }

            return s;
        }
};