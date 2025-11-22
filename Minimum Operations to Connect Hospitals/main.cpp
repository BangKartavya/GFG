class UnionFind {
    public:
        vector<int> size;
        vector<int> parent;

        UnionFind(int n) {
            size.resize(n, 1);
            parent.resize(n);

            for(int i = 0; i < n; i++)
                parent[i] = i;
        }

        int Find(int u) {
            if(parent[u] == u) return u;

            return parent[u] = Find(parent[u]);
        }

        bool Union(int u, int v) {
            int parU = Find(u);
            int parV = Find(v);

            if(parU == parV) return false;

            if(size[parU] <= size[parV]) {
                parent[parU] = parV;
                size[parV] += size[parU];
            }

            else {
                parent[parV] = parU;
                size[parU] += size[parV];
            }

            return true;
        }
};

class Solution {
    public:
        int minConnect(int V, vector<vector<int>>& edges) {
            UnionFind* uf = new UnionFind(V);
            int redCon = 0;

            for(vector<int>& e : edges) {
                if(!uf->Union(e[0], e[1])) redCon++;
            }

            unordered_set<int> par;

            for(int i = 0; i < V; i++) {
                par.insert(uf->Find(i));
            }

            delete uf;
            if((par.size() - 1) <= redCon) return par.size() - 1;
            return -1;
        }
};
