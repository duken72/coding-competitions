#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    vector<int> abc(3);     // 1 ≤ a, b, c ≤ 20
    cin >> abc[0] >> abc[1] >> abc[2];
    sort(begin(abc), end(abc));
    cout << abc[1] << endl;
}

int main(int argc, char const *argv[])
{
    int T; cin >> T;
    for (int i = 0; i < T; i++)
        solve();
    return 0;
}
