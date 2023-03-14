#ifndef CODEFORCES__PCH_HPP_
#define CODEFORCES__PCH_HPP_

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
#endif  // CODEFORCES__PCH_HPP_
