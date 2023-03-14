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
using ll    = long long;
using pii   = pair<int, int>;

#define endl        '\n'
#define pb          push_back
#define eb          emplace_back
#define all(vect)   vect.begin(), vect.end()
#define ff          first
#define ss          second

// I/O
#define get_arr(a, n)   for(int i = 0; i < n; i++)  cin >> a[i];
#define LOG(x)          cerr << #x << " = " << x << endl;
template <typename T, typename...Ts>
constexpr void print(T&& first, Ts&&... rest) noexcept {
    if constexpr (sizeof...(Ts) == 0)   cout << first << endl;
    else {  cout << first << ' '; print(std::forward<Ts>(rest)...); }
}
template <typename T>
void print(T a[], int n) {
    for(int i = 0; i < n; i++)  cout << a[i] << " \n"[i == n - 1];
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vect) noexcept {
    for (const T& v : vect) { os << v << ' '; } os << endl;
    return os;
}
#endif  // PRECOMPILED_HEADER

const int N = 2e5 + 5;

void solve()
{
    int n;      cin >> n;
    int a[n];   get_arr(a, n);

#if LOCAL
print(a, n);
#endif
}

int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int num_tests = 1; cin >> num_tests;
    while (num_tests--)
        solve();
    return 0;
}
