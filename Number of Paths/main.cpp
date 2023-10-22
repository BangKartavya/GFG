//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  long long int modInverse(long long int a, long long int m) {
    long long int m0 = m;
    long long int x0 = 0, x1 = 1;

    while (a > 1) {
      long long int q = a / m;
      long long int t = m;

      m = a % m, a = t;
      t = x0;

      x0 = x1 - q * x0;
      x1 = t;
    }

    if (x1 < 0)
      x1 += m0;

    return x1;
  }
  long long int binomialCoefficient(int n, int k) {
    long long int MOD = 1e9 + 7;
    if (k > n - k)
      k = n - k;

    long long int res = 1;
    for (int i = 0; i < k; i++) {
      res = (res * (n - i)) % MOD;
      res = (res * modInverse(i + 1, MOD)) % MOD;
    }

    return res;
  }
  long long numberOfPaths(int m, int n) {
    return binomialCoefficient(m + n - 2, n - 1);
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int N, M;
    cin >> M >> N;
    Solution ob;
    cout << ob.numberOfPaths(M, N) << endl;
  }
  return 0;
}
// } Driver Code Ends