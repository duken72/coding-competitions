#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <iostream>
#include <string>

using namespace std;

void solve()
{
    int N; cin >> N;    // length of string 1 ≤ n ≤ 100
    string S; cin >> S;
    int result = 0;
    for (char c : S)
        result = (c - 'a' + 1 > result) ? c - 'a' + 1 : result;
    cout << result << endl;
}

int main(int argc, char const *argv[])
{
    int T; cin >> T;    // 1 ≤ t ≤ 1000
    for (int i = 0; i < T; i++)
        solve();
    return 0;
}
