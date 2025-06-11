class Solution {
  public:
    int findLength(vector<int> &color, vector<int> &radius) {
        int n = color.size();
        vector<pair<int,int>> vp;
        
        for(int i = 0;i<n;i++) {
            if(vp.empty()) {
                vp.push_back({color[i],radius[i]});
            }
            else {
                pair<int,int> curr = {color[i],radius[i]};
                if(vp.back() == curr) {
                    vp.pop_back();
                }
                else {
                    vp.push_back(curr);
                }
            }
        }
        
        return vp.size();
    }
};