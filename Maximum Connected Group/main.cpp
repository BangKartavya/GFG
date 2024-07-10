//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class DSU {
public:
    vector<int> parent, size;

    DSU(int n) : parent(n), size(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionbysize(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (size[rootX] < size[rootY]) {
                swap(rootX, rootY);
            }
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }
    }
};

class Solution {
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        int dx[] ={-1,0,1,0};
        int dy[] ={0,1,0,-1};
        int n =grid.size();
        DSU dsu(2*n*n);
        auto id =[&](int x,int y){return n*x + y;};
        
        for(int i =0;i< n;i++){
            for(int j =0;j< n;j++){
                if(grid[i][j]){
                    for(int k =0;k< 4;k++){
                        int adjx =i +dx[k];
                        int adjy =j +dy[k];
                        if(adjx < n && adjy < n && adjx>=0 && adjy >=0 && grid[adjx][adjy]){
                            dsu.unionbysize(id(i,j),id(adjx,adjy));
                        }
                    }
                }
            }
        }
        int maxi =0;
        for(int i =0;i< n;i++){
            for(int j =0;j< n;j++){
                if(grid[i][j]){
                    maxi =max(maxi,dsu.size[id(i,j)]);
                }
            }
        }
        for(int i =0;i< n;i++){
            for(int j =0;j< n;j++){
                if(grid[i][j] == 0){
                    unordered_set<int> s;
                    for(int k =0;k< 4;k++){
                        int adjx =i +dx[k];
                        int adjy =j +dy[k];
                        if(adjx < n && adjy < n && adjx>=0 && adjy >=0 && grid[adjx][adjy]){
                            s.insert(dsu.find(id(adjx,adjy)));
                        }
                    }
                    
                    int temp =1;
                    for(auto x: s){
                        temp+=dsu.size[x];
                    }
                    maxi=max(maxi,temp);
                }
            }
        }
        return maxi;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout << obj.MaxConnection(grid) << "\n";
    }
}

// } Driver Code Ends