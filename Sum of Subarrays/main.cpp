class Solution {
  public:
    int subarraySum(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        int last = 0;
        
        for(int i = 0;i<n;i++) {
            if(i == 0) {
                sum += n*arr[i];
                last = n;
            }
            else {
                sum += (last-i + n-i)*arr[i];
                last = (last-i + n-i);
            }
            // cout << "last : " << last << endl;
        }
        
        return sum;
    }
};