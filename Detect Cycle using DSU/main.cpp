//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Disjoint_Set {
    vector<int> parent,rank;
    
    public:
        Disjoint_Set(int n) {
            parent.resize(n+1);
            rank.resize(n,0);
            for(int i =0;i<n;++i) parent[i] = i;
        }
        
        int FindUparent(int u) {
            if(parent[u]!=u) return parent[u] = FindUparent(parent[u]);
            return parent[u];
        }
        void Union(int u,int v) {
            int u_parent = FindUparent(u);
            int v_parent = FindUparent(v);
            
            if(u_parent!=v_parent) {
                if(rank[u_parent]<rank[v_parent]) parent[u_parent] = v_parent;
                else if(rank[u_parent]>rank[v_parent]) parent[v_parent] = u_parent;
                else {
                    parent[v_parent]= u_parent;
                    rank[u_parent]++;
                }
            }
        }
};

class Solution
{
    public:
    //Function to detect cycle using DSU in an undirected graph.
	int detectCycle(int V, vector<int>adj[])
	{
	    Disjoint_Set DS(V);
        set<pair<int,int>> coveredEdge;
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            {
                if(coveredEdge.find({i,it})!=coveredEdge.end() || coveredEdge.find({it,i})!=coveredEdge.end()) continue;
                if(DS.FindUparent(it)!=DS.FindUparent(i))
                {
                    DS.Union(it,i);
                    coveredEdge.insert({it,i});
                }
                else
                {
                    return true;
                }
            }
    
        }
        return false;
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
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends