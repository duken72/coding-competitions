/*
ID: tech.ho1
PROG: concom
LANG: C++20
*/

#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>

using namespace std;

ifstream fin ("concom.in");
ofstream fout ("concom.out");

const int ALPHABET = 26;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl    '\n'
#define all(v)  v.begin(), v.end()
#define ff      first
#define ss      second
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

const int N = 100;

void solve() {
    /* Read input */

    /* Main */

    /* Output */
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    fin.close();
    fout.close();
    return 0;
}

