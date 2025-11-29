class Solution {
  public:
    int countSetBits(int n) {
        int count = 0;
        int powerOfTwo = 1;
        while (powerOfTwo <= n) {
            int completeCycles = n / (2 * powerOfTwo);
            int rem = n % (2 * powerOfTwo); 
            count += completeCycles * powerOfTwo;
    
            count += max(0, rem - powerOfTwo + 1);
    
            powerOfTwo *= 2;
        }
    
        return count;
    }
};
