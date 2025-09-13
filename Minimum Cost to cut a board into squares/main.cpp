class Solution {
    public:
        int minCost(int n, int m, vector<int>& x, vector<int>& y) {
            //  code here
            sort(rbegin(x), rend(x));
            sort(rbegin(y), rend(y));

            int horCount = 1;
            int verCount = 1;

            int totalCost = 0;

            int i = 0;
            int j = 0;

            while(i < m - 1 && j < n - 1) {
                if(x[i] >= y[j]) {
                    totalCost += (x[i] * horCount);
                    verCount++;
                    i++;
                } else {
                    totalCost += (y[j] * verCount);
                    horCount++;
                    j++;
                }
            }

            while(i < m - 1) {
                totalCost += (x[i] * horCount);
                verCount++;
                i++;
            }
            while(j < n - 1) {
                totalCost += (y[j] * verCount);
                horCount++;
                j++;
            }

            return totalCost;
        }
};
