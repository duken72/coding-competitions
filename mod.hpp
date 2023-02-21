// Modular arithmetics
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
