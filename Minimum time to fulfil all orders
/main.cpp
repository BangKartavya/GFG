#include <algorithm>
#include <vector>

class Solution {
  private:
    std::vector<int> ranks;
    int n;
    int totalDonuts;

    bool isValid(int minTime) {
        int donutCount = 0;

        for(int i = 0;i<n;i++) {
            int timeTaken = ranks[i];
            int mul = 2;

            while(timeTaken <= minTime) {
                donutCount++;
                timeTaken += (ranks[i]*mul);
                mul++;
            }

            if(donutCount >= totalDonuts) return true;
        }
        return false;
    }

  public:
    int minTime(std::vector<int>& ranks, int totalDonuts) {

        std::sort(std::begin(ranks),std::end(ranks));

        this->ranks = ranks;
        n = size(ranks);
        this->totalDonuts = totalDonuts;

        int s = 0;
        int e = 1e9;
        int ans = -1;

        while(s <= e) {
            int mid = s + (e-s)/2;

            if(isValid(mid)) {
                e = mid-1;
                ans = mid;
            }
            else s = mid+1;
        }

        return ans;
    }
};
