//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
        vector<vector<char>> mat;
        int n;
        int m;
        vector<vector<bool>> vis;
        string word;

        int dirX[4] = {0, -1, 0, 1};
        int dirY[4] = {1, 0, -1, 0};

        bool dfs(int i, int j, int toFind) {
            if(toFind == word.size()) return true;

            vis[i][j] = true;

            for(int k = 0; k < 4; k++) {
                int newX = i + dirX[k];
                int newY = j + dirY[k];

                if(newX < 0 || newX >= n || newY < 0 || newY >= m) continue;

                if(!vis[newX][newY] && mat[newX][newY] == word[toFind]) {
                    if(dfs(newX, newY, toFind + 1)) return true;
                }
            }

            return false;
        }

    public:
        bool isWordExist(vector<vector<char>>& mat, string& word) {
            this->mat = mat;
            n = mat.size();
            m = mat[0].size();
            vis.resize(n, vector<bool>(m, false));
            this->word = word;

            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(mat[i][j] == word[0]) {
                        if(dfs(i, j, 1)) return true;
                        vis.clear();
                        vis.resize(n, vector<bool>(m, false));
                    }
                }
            }

            return false;
        }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        if(ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends