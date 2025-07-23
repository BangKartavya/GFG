class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxi = 0;
        
        for(int& i: right) {
            maxi = max(maxi,n-i);
        }
        
        for(int& i: left) {
            maxi = max(maxi,i);
        }
        
        return maxi;
    }
};