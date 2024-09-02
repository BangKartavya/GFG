//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    
    bool isValid(int tx,int ty,int& n) {
        if(tx < 0 || ty < 0 || tx >= n || ty >= n) {
            return false;
        }
        return true;
    }
    
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        
        int n = grid.size();
        pq.push({grid[0][0],{0,0}});
        grid[0][0] = -1;
        
        while(!pq.empty()) {
            auto z = pq.top();
            pq.pop();
            
            int ans = z.first;
            int ii = z.second.first;
            int jj = z.second.second;
            
            if(ii == n-1 && jj == n-1) return ans;
            
            for(int i =0;i<4;i++) {
                int tx = ii + dx[i];
                int ty = jj + dy[i];
                
                if(isValid(tx,ty,n) && grid[tx][ty] != -1) {
                    pq.push({grid[tx][ty]+ans,{tx,ty}});
                    grid[tx][ty] = -1;
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends