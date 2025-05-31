class Solution {
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        int n = matrix.size();

        priority_queue<int> maxHeap;
        
        for(int i = 0;i<k;i++) {
            int x = i/n;
            int y = i%n;
            
            maxHeap.push(matrix[x][y]);
        }
        
        for(int i = k;i<n*n;i++) {
            int x = i/n;
            int y = i%n;
            /*
            cout << "x : " << x << endl;
            cout << "y : " << y << endl;
            */
            if(matrix[x][y] < maxHeap.top()) {
                maxHeap.pop();
                maxHeap.push(matrix[x][y]);
            }
        }
        
        return maxHeap.top();
    }
};