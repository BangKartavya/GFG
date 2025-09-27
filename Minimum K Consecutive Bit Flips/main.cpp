class Solution {
  public:
    int kBitFlips(vector<int>& arr, int k) {
        int n = arr.size();
        int flips = 0;       
        int flipped = 0;     
        vector<int> isFlipped(n, 0); 
        
        for (int i = 0; i < n; i++) {
            if (i >= k) {
                flipped ^= isFlipped[i - k];
            }

            if ((arr[i] ^ flipped) == 0) {
                if (i + k > n) return -1; 
                flips++;
                flipped ^= 1;             
                isFlipped[i] = 1;         
                
            }
        }
        return flips;
    }
};