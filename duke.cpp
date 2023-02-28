#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#ifndef ONLINE_JUDGE
#define PRECOMPILED_HEADER true
#endif

#if PRECOMPILED_HEADER
#include "pch.hpp"
#else   // !PRECOMPILED_HEADER
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

const int ALPHABET = 26;

// Typedefs
using ll    = long long;
using vc    = vector<char>;
using vb    = vector<bool>;
using vi    = vector<int>;
using vl    = vector<ll>;
using pii   = pair<int, int>;

// String
#define YES     cout << "YES\n"
#define Yes     cout << "Yes\n"
#define NO      cout << "NO\n"
#define No      cout << "No\n"
#define endl    '\n'

// Vector / Pair
#define pb              push_back
#define eb              emplace_back
#define all(vect)       vect.begin(), vect.end()
#define ff              first
#define ss              second

// I/O
#define get_arr(a, n)   for(int i = 0; i < n; i++)  cin >> a[i];
#define print_arr(a, n) for(int i = 0; i < n; i++)  cout << a[i] << " \n"[i == n - 1];
#define print_var(x)    cerr << #x << " = " << x << endl;
template <typename T, typename...Ts>
constexpr void print_vars(T&& first, Ts&&... rest) noexcept {
    if constexpr (sizeof...(Ts) == 0)   cout << first;
    else {  cout << first << ' '; print_vars(std::forward<Ts>(rest)...); }
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vect) noexcept {
    for (const T& v : vect)     os << v << ' ';
    return os;
}

// Greatest Common Divisor (GCD)
template <typename T>
T GCD(const T& a, const T& b) {
    if (b==0)   return a;
    return GCD(b, a%b);
}

// Check a number is prime
bool is_prime(int n) {
    if (n <= 1)     return false;
    if (n <= 3)     return true;
    if ((n % 2 == 0) || (n % 3 == 0))           return false;
    // Prime number above 3 must be either (6i + 1) or (6i - 1)
    for (int i = 5; i * i <= n; i = i + 6)
        if ((n % i == 0) || (n % (i + 2) == 0)) return false;
    return true;
}
#endif  // PRECOMPILED_HEADER

/** Useful funcs in C++ STL
 * memset, fill, fill_n
 * sort, binary_search, reverse,
 * gcd, swap, move 
 * next_permutation, prev_permutation
 * int8_t   (1 byte)    ±127
 * int16_t  (2 bytes)   ±3.2E4      short
 * int32_t  (4 bytes)   ±2.1E9      int
 * int64_t  (8 bytes)   ±9.2E18     long long
 * float    (4 bytes)   3.4E±38
 * double   (8 bytes)   1.7E±308
 */

void solve()
{
    
#if LOCAL
#endif
}

int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int num_tests; cin >> num_tests;
    while (num_tests--)
        solve();
    return 0;
}