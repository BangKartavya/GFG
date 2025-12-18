class Solution {
  public:
    void sortIt(vector<int>& arr) {
        // code here
        sort(begin(arr),end(arr),[](const int& a, const int& b) {
           if(a%2 == 0 && b%2 == 0) return a<b;
           if(a%2 == 1 && b%2 == 1) return a>b;
           
           return a%2==1;
        });
    }
};