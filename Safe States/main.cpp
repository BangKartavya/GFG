class Solution {
  public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        vector<int> outDegree(V);
        
        for(vector<int>& e: edges) {
            adj[e[1]].push_back(e[0]);
            outDegree[e[0]]++;
        }
        
        queue<int> q;
        vector<int> result;
        
        for(int i = 0;i<V;i++) {
            if(outDegree[i] == 0) {
                q.push(i);
            }
        } 
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            result.push_back(node);
            
            for(int& it: adj[node]) {
                outDegree[it]--;
                
                if(outDegree[it] == 0) q.push(it);
            }
        }
        sort(begin(result),end(result));
        return result;
    }
};