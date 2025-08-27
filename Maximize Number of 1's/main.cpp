class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        int n = arr.size();
        int i = 0;
        int j = 0;
        int maxi = 0;
        
        int zeros = 0;
        
        while(j < n) {
            zeros += (arr[j] == 0);
            
            while(i <= j && zeros > k) {
                zeros -= (arr[i] == 0);
                i++;
            }
            
            maxi = max(maxi,j-i+1);
            
            j++;
        }
        
        return maxi;
    }
};
