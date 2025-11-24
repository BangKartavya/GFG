class Solution {
    public:
        class dsu {
                vector<int> parent, size;

            public:
                dsu(int n) {
                    parent.resize(n + 1);
                    size.resize(n + 1);

                    for(int i = 0; i <= n; i++) {
                        parent[i] = i;
                        size[i] = 1;
                    }
                }

                int findpar(int node) {
                    if(parent[node] == node) {
                        return node;
                    }
                    return parent[node] = findpar(parent[node]);
                }

                void unionbysize(int a, int b) {
                    int pa = findpar(a);
                    int pb = findpar(b);

                    if(pa == pb) return;

                    if(size[pa] > size[pb]) {
                        parent[pb] = pa;
                        size[pa] += size[pb];
                    } else {
                        parent[pa] = pb;
                        size[pb] += size[pa];
                    }
                }

                bool isconnected(int a, int b) {
                    return findpar(a) == findpar(b);
                }
        };

        int secondMST(int V, vector<vector<int>>& edges) {
            // code here

            dsu ds(V);
            int cnt = 0, tot = 0;

            vector<pair<int, pair<int, int>>> arr;

            for(auto& it : edges) {
                arr.push_back({it[2], {it[0], it[1]}});
            }

            sort(arr.begin(), arr.end());

            set<pair<int, int>> st;

            for(auto& it : arr) {
                int wt = it.first, u = it.second.first, v = it.second.second;
                if(!ds.isconnected(u, v)) {
                    cnt++;
                    ds.unionbysize(u, v);
                    tot += wt;
                    st.insert({u, v});
                }
            }

            if(cnt != V - 1) {
                return -1;
            }

            int sec = INT_MAX;

            for(auto& it : st) {
                int u = it.first, v = it.second;
                int cur = 0, cnt = 0;
                dsu ds1(V);

                for(auto& it1 : arr) {
                    int wt = it1.first, u1 = it1.second.first, v1 = it1.second.second;

                    if(u == u1 && v == v1) {
                        continue;
                    }

                    if(!ds1.isconnected(u1, v1)) {
                        cnt++;
                        ds1.unionbysize(u1, v1);
                        cur += wt;
                    }
                }

                if(cnt == V - 1 && cur > tot) {
                    sec = min(sec, cur);
                }
            }

            if(sec != INT_MAX) {
                return sec;
            }
            return -1;
        }
};