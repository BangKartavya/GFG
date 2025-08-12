class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        // Code here
        sort(begin(prices),end(prices));
        
        int n = prices.size();
        int siz = n;
        int mini = 0;
        int maxi = 0;
        
        int i = 0;
        int j = n-1;
        
        while(i <= j) {
            mini += prices[i];
            i++;
            j-=k;
        }
        
        i = 0;
        j = n-1;
        
        while(i <= j) {
            maxi += prices[j];
            j--;
            i+=k;
        }
        
        return {mini,maxi};
    }
};