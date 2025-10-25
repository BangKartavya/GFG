class Solution {
  public:
    int minOperations(vector<int>& arr) {
        priority_queue<double> pq;
        
        double totalSum = accumulate(begin(arr),end(arr),0);
        double sum = totalSum;
        int n = arr.size();
        int operations = 0;
        
        for(int i = 0;i<n;i++) pq.push(arr[i]);
        
        while(sum > totalSum * 0.5) {
            double val = pq.top();
            pq.pop();
            
            sum -= val*0.5;
            pq.push(val*0.5);
            
            operations++;
        }
        
        return operations;
    }
};