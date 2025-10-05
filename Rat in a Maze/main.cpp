class Solution {
    private:
        vector<vector<int>> maze;
        int n;
        vector<string> result;

        void solve(int i, int j, string curr) {
            if(i == n - 1 && j == n - 1) {
                result.push_back(curr);
                return;
            }

            if(i >= n || j >= n || i < 0 || j < 0) return;

            maze[i][j] = 0;

            if(i + 1 < n && maze[i + 1][j] == 1) solve(i + 1, j, curr + "D");
            if(i - 1 >= 0 && maze[i - 1][j] == 1) solve(i - 1, j, curr + "U");
            if(j + 1 < n && maze[i][j + 1] == 1) solve(i, j + 1, curr + "R");
            if(j - 1 >= 0 && maze[i][j - 1] == 1) solve(i, j - 1, curr + "L");

            maze[i][j] = 1;
        }

    public:
        vector<string> ratInMaze(vector<vector<int>>& maze) {
            this->maze = maze;
            n = maze.size();

            solve(0, 0, "");
            sort(begin(result), end(result));
            return result;
        }
};