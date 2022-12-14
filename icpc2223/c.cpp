#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

using LL = long long;
const LL MOD = 998'244'353;

// Modular Arithmetic
template <typename T>
T subMod(const T& a, const T& b) { return ((a - b) % MOD + MOD) % MOD; }
template <typename T>
T mulMod(const T& a, const T& b) { return (a * b) % MOD; }

// Find GCD of two numbers (greatest common divisor)
template <typename T>
T findGCD(const T& a, const T& b) {
  if (b == 0) return a;
  return findGCD(b, a%b);
}
template <typename T>
T gcdExtended(T a, T b, T* x, T* y) { 
  if (a == 0) {
    *x = 0, *y = 1;
    return b;
  }
  T x1, y1;
  T gcd = gcdExtended(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return gcd;
}

// Simplify a fraction
template <typename T>
void lowestFraction(T& num, T& denom) {
  T GCD = findGCD(num, denom);
  num /= GCD;
  denom /= GCD;
}

// Mod Inverse
// geeksforgeeks.org/multiplicative-inverse-under-modulo-m/
LL modInverse(LL A) {
  LL x, y, out;
  LL g = gcdExtended(A, MOD, &x, &y);
  out = (x % MOD + MOD) % MOD;
  return out;
}

void solve()
{
    // int N; cin >> N;        // no. cards each suit  1 ≤ n ≤ 500
    // int K; cin >> K;        // no. cards remember   1 ≤ k ≤ 4n
    LL x = 5;
    LL y = 4;
    LL out = mulMod(x, modInverse(y));
    cout << out << endl;

}

int main(int argc, char const *argv[])
{
    // int T; cin >> T;
    // for (int i = 0; i < T; i++)
    //     solve();
    solve();
    return 0;
}
