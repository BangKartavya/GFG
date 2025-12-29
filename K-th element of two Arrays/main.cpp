#include <algorithm>
#include <vector>

class Solution {
  public:
    int kthElement(std::vector<int> &a, std::vector<int> &b, int k) {
        // code here
        int s = std::min(a[0],b[0]);
        int e = std::max(a[size(a)-1],b[size(b)-1]);
        int ans = -1;

        while(s <= e) {
            int mid = s + (e-s)/2;

            int l1 = std::upper_bound(std::begin(a),std::end(a),mid)-std::begin(a);
            int l2 = std::upper_bound(std::begin(b),std::end(b),mid)-std::begin(b);

            if(l1 + l2 >= k) {
                ans = mid;
                e = mid-1;
            }
            else s = mid+1;
        }

        return ans;
    }
};
