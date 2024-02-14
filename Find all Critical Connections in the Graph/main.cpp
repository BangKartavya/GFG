//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int timer = 1;
    void dfs(int node,int parent,vector<int>&vis,vector<int>&tinsert,vector<int>&lowtime,vector<int> adj[],vector<vector<int>>& bridges) {
        vis[node] = 1;
        tinsert[node] = lowtime[node] = timer++;
        
        for(auto adjNode: adj[node]) {
            if(!vis[adjNode]) {
                dfs(adjNode,node,vis,tinsert,lowtime,adj,bridges);
                lowtime[node] = min(lowtime[node],lowtime[adjNode]);
                
                if(tinsert[node]<lowtime[adjNode]) {
                    if(node<adjNode) bridges.push_back({node,adjNode});
                    else bridges.push_back({adjNode,node});
                }
            }
            else if(adjNode!=parent) {
                lowtime[node] = min(lowtime[node],lowtime[adjNode]);
            }
        }
    }
	vector<vector<int>>criticalConnections(int v, vector<int> adj[]){
	    // Code here
	    vector<int> tinsert(v,0);
	    vector<int> lowtime(v,0);
	    vector<int> vis(v,0);
	    vector<vector<int>> bridges;
	    
	    for(int i =0;i<v;i++) {
	        if(!vis[i]) {
	            dfs(i,-1,vis,tinsert,lowtime,adj,bridges);
	        }
	    }
	    sort(bridges.begin(),bridges.end());
	    return bridges;
	}
};

//{ Driver Code Starts.

int main(){
	int tc;
    cin >> tc;
    while(tc--){
        int V, E;
        cin >> V >> E;
        vector<int>adj[V];
        for(int i = 0; i < E; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<vector<int>>ans = obj.criticalConnections(V, adj);
        
        for(int i=0;i<ans.size();i++)
            cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
	return 0;
}
// } Driver Code Ends