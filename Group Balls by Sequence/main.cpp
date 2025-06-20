class Solution {
  public:
    bool validgroup(vector<int> &arr, int k) {
       sort(begin(arr),end(arr));
       int n = arr.size();
       map<int,int> mp;
       
       for(int& i: arr) mp[i]++;
       
       auto it = mp.begin();
       
       while(it != mp.end()) {
           int num = it->first;
           int freq = it->second;
           
           if(freq > 0) {
               for(int i = 0;i<k;i++) {
                   if(mp[num+i] < freq) return false;
                   mp[num+i]-=freq;
               }
           }
           it++;
       }
       
       return true;
    }
};