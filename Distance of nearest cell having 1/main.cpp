class Solution {
    public:
        vector<vector<int>> nearest(vector<vector<int>>& grid) {
            queue<pair<int, int>> q;
            int n = grid.size();
            int m = grid[0].size();
            vector<vector<bool>> vis(n, vector<bool>(m, false));

            int dir[5] = {0, -1, 0, 1, 0};

            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(grid[i][j] == 1) {
                        q.push({i, j});
                        vis[i][j] = true;
                    }
                }
            }
            int lvl = 0;
            while(!q.empty()) {
                int siz = q.size();

                while(siz--) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    grid[x][y] = lvl;

                    for(int i = 0; i < 4; i++) {
                        int newX = x + dir[i];
                        int newY = y + dir[i + 1];

                        if(newX < 0 || newX >= n || newY < 0 || newY >= m) continue;

                        if(!vis[newX][newY] && grid[newX][newY] == 0) {
                            vis[newX][newY] = true;
                            q.push({newX, newY});
                        }
                    }
                }
                lvl++;
            }

            return grid;
        }
};