//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    public:
        int orangesRotting(vector<vector<int>>& mat) {
            int n = mat.size();
            int m = mat[0].size();

            int dirX[4] = {0, -1, 0, 1};
            int dirY[4] = {1, 0, -1, 0};

            queue<pair<int, int>> q;
            vector<vector<bool>> vis(n, vector<bool>(m, false));

            bool anyFresh = false;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(mat[i][j] == 2) {
                        q.push({i, j});
                        vis[i][j] = true;
                    }
                    if(mat[i][j] == 1) anyFresh = true;
                }
            }

            if(!anyFresh) return 0;

            int t = 0;
            while(!q.empty()) {
                int siz = q.size();
                bool anyConverted = false;
                while(siz--) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for(int k = 0; k < 4; k++) {
                        int newX = x + dirX[k];
                        int newY = y + dirY[k];

                        if(newX < 0 || newX >= n || newY < 0 || newY >= m) continue;

                        if(!vis[newX][newY] && mat[newX][newY] == 1) {
                            q.push({newX, newY});
                            mat[newX][newY] = 2;
                            anyConverted = true;
                            vis[newX][newY] = true;
                        }
                    }
                }
                t += anyConverted;
            }

            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(mat[i][j] == 1) return -1;
                }
            }

            return t;
        }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends