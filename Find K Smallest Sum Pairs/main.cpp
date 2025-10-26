class Solution {
  public:
    vector<vector<int>> kSmallestPair(vector<int> &arr1, vector<int> &arr2, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        int i=0, j=0;
        set<pair<int,int>> vis={{0,0}};
        pq.push({arr1[i]+arr2[j],{i,j}});
        while(!pq.empty()){
            int val=pq.top().first;
            int ci=pq.top().second.first;
            int cj=pq.top().second.second;
            pq.pop();
            // cout<<val<<' '<<ci<<' '<<cj<<'\n';
            ans.push_back({arr1[ci],arr2[cj]});
            if(ans.size()==k) break;
            if(ci+1<arr1.size() && !vis.count({ci+1,cj})) {
                pq.push({arr1[ci+1]+arr2[cj],{ci+1,cj}});
                vis.insert({ci+1,cj});
            }
            if(cj+1<arr2.size() && !vis.count({ci,cj+1})) {
                pq.push({arr1[ci]+arr2[cj+1],{ci,cj+1}});
                vis.insert({ci,cj+1});
            }
        }
        return ans;
    }
};
