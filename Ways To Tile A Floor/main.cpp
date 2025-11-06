class Solution {
  public:
    int numberOfWays(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        
        int a = 1;
        int b = 2;
        
        int c = 0;
        
        while((n--)-2) {
            c = a + b;
            a = b;
            b = c;
        }
        
        return c;
    }
};