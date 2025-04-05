//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    public:
        int countIslands(vector<vector<char>>& grid) {
            int count = 0;
            int n = grid.size();
            int m = grid[0].size();

            int dirX[8] = {0, -1, 0, 1, 1, -1, -1, 1};
            int dirY[8] = {1, 0, -1, 0, 1, 1, -1, -1};

            queue<pair<int, int>> q; // {x,y}
            vector<vector<bool>> vis(n, vector<bool>(m, false));

            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(!vis[i][j] && grid[i][j] == 'L') {
                        count++;
                        q.push({i, j});
                        vis[i][j] = true;

                        while(!q.empty()) {
                            int x = q.front().first;
                            int y = q.front().second;
                            q.pop();

                            for(int k = 0; k < 8; k++) {
                                int newX = x + dirX[k];
                                int newY = y + dirY[k];

                                if(newX < 0 || newX >= n || newY < 0 || newY >= m) {
                                    continue;
                                }

                                if(!vis[newX][newY] && grid[newX][newY] == 'L') {
                                    q.push({newX, newY});
                                    vis[newX][newY] = true;
                                }
                            }
                        }
                    }
                }
            }

            return count;
        }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.countIslands(grid);
        cout << ans << '\n';

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends