#include <vector>

class Solution {
  public:
    int kthMissing(std::vector<int> &arr, int k) {
        int n = size(arr);

        int s = 0;
        int e = n-1;

        while(s <= e) {
            int mid = s + (e-s)/2;

            if(arr[mid] - mid <= k) s = mid+1;
            else e = mid-1;
        }

        return s + k;
    }
};
