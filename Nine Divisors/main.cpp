class Solution {
  private:
    bool isValid(int n) {
        int factors = 0;
        
        for(int i = 1;i*i<=n;i++) {
            if(n%i) continue;
            
            factors++;
            if(n/i != i) factors++;
            
            if(factors > 9) return false;
        }
        
        return factors == 9;
    }
  public:
    int countNumbers(int n) {
        int count = 0;
        
        for(int i = 1;i<=sqrt(n);i++) {
            if(i * i <= n) {
                if(isValid(i*i)) count++;
            }
        }
        
        return count;
    }
};