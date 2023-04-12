<!-- omit in toc -->
# Number Theory

<!-- omit in toc -->
## Table of Contents

- [Greatest Common Divisor (GCD)](#greatest-common-divisor-gcd)
- [Check Prime number](#check-prime-number)
- [Modular Arithmetic](#modular-arithmetic)

## Greatest Common Divisor (GCD)

```cpp
template <typename T>
T GCD(const T& a, const T& b) {
    if (b==0)   return a;
    return GCD(b, a%b);
}
```

## Check Prime number

```cpp
template <typename T = int>
bool is_prime(T n) {
    if (n <= 1)     return false;
    if (n <= 3)     return true;
    if ((n % 2 == 0) || (n % 3 == 0))   return false;
    // Prime number above 3 must be either (6i + 1) or (6i - 1)
    for (T i = 5; i * i <= n; i = i + 6)
        if ((n % i == 0) || (n % (i + 2) == 0)) return false;
    return true;
}
```

## Modular Arithmetic

```cpp
const long long MOD = 1'000'000'007;
template <typename T>
T addMod(const T& a, const T& b) { return ((a % MOD) + (b % MOD)) % MOD; }
template <typename T>
T subMod(const T& a, const T& b) { return ((a - b) % MOD + MOD) % MOD; }
template <typename T>
T mulMod(const T& a, const T& b) { return ((a % MOD) * (b % MOD)) % MOD; }
template <typename T>
// Greatest Common Divisor extended (GCD)
void gcdExtended(T a, T b, T &x, T &y) {
    if (a == 0) {
        x = 0, y = 1;
        return;
    }
    T x1, y2;
    gcdExtended(b % a, a, x1, y2);
    x = y2 - (b / a) * x1;
    y = x1;
}
template <typename T>
T modInverse(const T &val) {
    T x, y, out;
    gcdExtended(val, MOD, x, y);
    out = (x % MOD + MOD) % MOD;
    return out;
}
```
