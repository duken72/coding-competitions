#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int N; cin >> N;        // no. videos       1 ≤ n ≤ 2⋅10^5
    int M; cin >> M;        // size of harddisk 1 ≤ m ≤ 10^9
    vector<int> S(N, 0);    // sizes of videos
    for (int i = 0; i < N; i++)
        cin >> S[i];
    sort(begin(S), end(S), greater<int>());
    cout << S[0] << endl;
}

int main(int argc, char const *argv[])
{
    int T; cin >> T;
    for (int i = 0; i < T; i++)
        solve();
    // solve();
    return 0;
}
