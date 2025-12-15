class Solution {
    public:
        int cntWays(vector<int>& arr) {
            // code here
            int n = arr.size();
            vector<int> leftEven(n + 2, 0), leftOdd(n + 2, 0), rightEven(n + 2, 0), rightOdd(n + 2, 0);

            for(int i = 1; i <= n; i++) {
                if(i % 2) {
                    leftOdd[i] = leftOdd[i - 1] + arr[i - 1];
                    leftEven[i] = leftEven[i - 1];
                } else {
                    leftOdd[i] = leftOdd[i - 1];
                    leftEven[i] = leftEven[i - 1] + arr[i - 1];
                }
            }

            for(int i = n; i >= 1; i--) {
                if(i % 2) {
                    rightOdd[i] = rightOdd[i + 1] + arr[i - 1];
                    rightEven[i] = rightEven[i + 1];
                } else {
                    rightOdd[i] = rightOdd[i + 1];
                    rightEven[i] = rightEven[i + 1] + arr[i - 1];
                }
            }

            int ans = 0;

            for(int i = 1; i <= n; i++) {
                if(leftOdd[i - 1] + rightEven[i + 1] == leftEven[i - 1] + rightOdd[i + 1]) {
                    ans++;
                }
            }
            return ans;
        }
};
