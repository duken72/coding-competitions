// Modular arithmetics
using LL = long long;
const LL MOD = 1'000'000'007;

template <typename T>
T addMod(T a, T b) { return ((a % MOD) + (b % MOD)) % MOD; }

template <typename T>
T subMod(T a, T b) { return ((a - b) % MOD + MOD) % MOD; }

template <typename T>
T mulMod(T a, T b) { return ((a % MOD) * (b % MOD)) % MOD; }

// Greatest Common Divisor (GCD)
template <typename T>
void gcdExtended(T a, T b, T &x, T &y) {
    if (a == 0) {
        x = 0, y = 1;
        return;
    }
    T x1, y1;
    gcdExtended(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
}

// Mod Inverse
// geeksforgeeks.org/multiplicative-inverse-under-modulo-m/
template <typename T>
T modInverse(const T &A) {
    T x, y, out;
    gcdExtended(A, MOD, x, y);
    out = (x % MOD + MOD) % MOD;
    return out;
}
