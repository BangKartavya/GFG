class Solution {
    public:
        vector<int> asciirange(string& s) {
            // code here
            int n = s.size();
            int first[26];
            int last[26];
            // vector<int> prefixSum(n);

            memset(first, -1, sizeof(first));
            memset(last, -1, sizeof(last));

            for(int i = 0; i < n; i++) {
                char ch = s[i];
                if(first[ch - 'a'] == -1) {
                    first[ch - 'a'] = i;
                }
                last[ch - 'a'] = i;
                // prefixSum[i] = ch + (i > 0 ? prefixSum[i-1] : 0);
            }

            vector<int> result;
            for(int i = 0; i < 26; i++) {
                if(first[i] != -1 && first[i] != last[i] && first[i] != last[i] - 1) {
                    int sum = 0;
                    for(int j = first[i] + 1; j < last[i]; j++)
                        sum += s[j];
                    result.push_back(sum);
                }
            }

            return result;
        }
};