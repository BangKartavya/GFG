class Solution {
  public:
    vector<int> topKFreq(vector<int> &arr, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        unordered_map<int,int> mp;
        
        for(int& i: arr) mp[i]++;
        
        int n = arr.size();
        vector<int> result;
        
        auto it = mp.begin();
        
        for(;it!=mp.end();it++) {
            pq.push({it->second,it->first});
            if(pq.size() >= k) break;
        }
        
        it++;
        
        for(;it!=mp.end();it++) {
            if(pq.top().first < it->second) {
                pq.pop();
                pq.push({it->second,it->first});
            }
            
            else if(pq.top().first == it->second) {
                if(pq.top().second < it->first) {
                    pq.pop();
                    pq.push({it->second,it->first});
                }
            }
        }
        
        while(!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        
        reverse(begin(result),end(result));
        
        return result;
    }
};
