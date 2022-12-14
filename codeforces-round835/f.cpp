#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
using LL = long long;

void solve()
{
    LL N, C, D;         // no. quests, coins needed, days
    cin >> N >> C >> D; // 2 ≤ n ≤ 2e5, 1 ≤ c ≤ 1e16, 1 ≤ d ≤ 2e5
    vector<int> R(N);   // quest rewards 1 ≤ ai ≤ 1e9
    for (int i = 0; i < N; i++)
        cin >> R[i];
    sort(R.begin(), R.end(), greater<int>());
    if ((float)C / D > R[0]) {
        cout << "Impossible" << endl;
        return;
    }
    if (accumulate(R.begin(), R.begin() + min(N, D), 0) >= C) {
        cout << "Infinity" << endl;
        return;
    }
    LL sum_r = accumulate(R.begin(), R.end(), 0);
    if (float(C) / D <= float(sum_r) / N) {
        LL t = C / sum_r;
        D -= N * t;
        C = C % sum_r;
        if (C == 0) {
            cout << D / (t - 1) + (N - 1) << endl;
            return;
        }
        int id = 0;
        while (C > 0) {
            C -= R[id];
            id++;
            D--;
        }
        cout << D / t + (N - 1) << endl;
    } else {    // average coin > average reward
        while ((float)C/D > (float)sum_r/N) {
            sum_r -= R[N-1];
            N--;
        }
        if (D/(N+1)*(sum_r + R[N]) + accumulate(R.begin(), R.begin() + D%(N+1), 0) >= C)
            cout << N << endl;
        else
            cout << N - 1 << endl;
    }    
}

int main(int argc, char const *argv[])
{
    int T; cin >> T;    // no. test cases   1 ≤ t ≤ 10^4
    for (int i = 0; i < T; i++)
        solve();
    return 0;
}
