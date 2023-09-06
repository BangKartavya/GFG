//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
	
	void dfs(vector<int>adj[],int V,int start,vector<int>& vis) {
	    vis[start] =1;
	    for(auto it: adj[start]) {
	        if(!vis[it]) {
	            dfs(adj,V,it,vis);
	        }
	    }
	}
	
	int findMotherVertex(int V, vector<int>adj[])
	{
	    vector<int> vis(V,0);
	    int lastnode = 0;
	    for(int i =0;i<V;i++) {
	        if(vis[i]==0) {
	            dfs(adj,V,i,vis);
	            lastnode = i;
	        }
	    }
	    
	    for(int i =0;i<V;i++) {
	        vis[i] = 0;
	    }
	    dfs(adj,V,lastnode,vis);
	    
	    for(int i =0;i<V;i++) {
	        if(vis[i]==0) {
	            return -1;
	        }
	    }
	    return lastnode;
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
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends