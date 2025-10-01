class Solution {
    private:
        string bin(int n) {
            if(n == 0) return "0";
            if(n == 1) return "1";

            string s;

            while(n > 1) {
                int dig = n % 2;

                s += (dig + '0');

                n /= 2;
            }

            if(n) s += '1';

            reverse(begin(s), end(s));

            return s;
        }

    public:
        vector<string> binstr(int n) {
            vector<string> result;
            int last = pow(2, n);

            for(int i = 0; i < last; i++) {
                string s = bin(i);
                if(s.size() == n) result.push_back(s);
                else {
                    string t;

                    for(int _ = 0; _ < n - s.size(); _++)
                        t += '0';

                    result.push_back((t + s));
                }
            }

            return result;
        }
};