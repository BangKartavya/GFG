class Solution {
  public:
    int maxKPower(int n, int k) {
        if (k == 1) return n;
        
        vector<pair<int, int>> primeFactors;
        int temp = k;
        
        if (temp % 2 == 0) {
            int count = 0;
            while (temp % 2 == 0) {
                count++;
                temp /= 2;
            }
            primeFactors.push_back({2, count});
        }
        
        for (int i = 3; i * i <= temp; i += 2) {
            if (temp % i == 0) {
                int count = 0;
                while (temp % i == 0) {
                    count++;
                    temp /= i;
                }
                primeFactors.push_back({i, count});
            }
        }
        
        if (temp > 1) {
            primeFactors.push_back({temp, 1});
        }
        
        int result = INT_MAX;
        
        for (auto& factor : primeFactors) {
            int prime = factor.first;
            int power = factor.second;
            
            int countInFactorial = 0;
            for (int p = prime; p <= n; p *= prime) {
                countInFactorial += n / p;
                if (p > n / prime) break;
            }
            
            int setsFromThisPrime = countInFactorial / power;
            
            result = min(result, setsFromThisPrime);
        }
        
        return result;
    }
};