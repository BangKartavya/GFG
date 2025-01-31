//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
        int N = 9;
        bool isPossible(vector<vector<int>>& grid, int curr_row, int curr_col, int val) {
            for(int i = 0; i < N; i++) {
                if(grid[curr_row][i] == val) return false;
                if(grid[i][curr_col] == val) return false;
            }

            for(int i = 0; i < N; i++) {
                if(grid[3 * (curr_row / 3) + i / 3][3 * (curr_col / 3) + i % 3] == val) return false;
            }

            return true;
        }
        bool helper(vector<vector<int>>& grid) {
            for(int i = 0; i < N; i++) {
                for(int j = 0; j < N; j++) {
                    if(grid[i][j] == 0) {
                        for(int index = 1; index <= 9; index++) {
                            if(isPossible(grid, i, j, index)) {
                                grid[i][j] = index;
                                bool nextFunCall = helper(grid);
                                if(nextFunCall) {
                                    return true;
                                } else {
                                    grid[i][j] = 0;
                                }
                            }
                        }
                        if(grid[i][j] == 0) return false;
                    }
                }
            }
            return true;
        }

    public:
        // Function to find a solved Sudoku.
        void solveSudoku(vector<vector<int>>& mat) {
            helper(mat);
        }
};

//{ Driver Code Starts.

vector<int> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    int num;
    vector<int> res;
    while(ss >> num) {
        res.push_back(num);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while(t--) {
        vector<vector<int>> grid;
        for(int i = 0; i < 9; i++) {
            vector<int> v = inputLine();
            grid.push_back(v);
        }

        Solution ob;

        ob.solveSudoku(grid);

        for(auto v : grid) {
            for(auto elem : v) {
                cout << elem << " ";
            }
            cout << endl;
        }

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends