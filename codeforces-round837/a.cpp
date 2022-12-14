#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using LL = long long;

void solve()
{
    LL N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    int min, max;
    min = *min_element(A.begin(), A.end());
    max = *max_element(A.begin(), A.end());
    if (min == max) {
        cout << N * (N-1) << endl;
        return;
    }
    LL c_min = 0, c_max = 0;
    for (int a : A) {
        c_min += (a == min) ? 1 : 0;
        c_max += (a == max) ? 1 : 0;
    }
    cout << c_min * c_max * 2 << endl;
}

int main(int argc, char const *argv[])
{
    int T; cin >> T;    // no. test cases
    for (int i = 0; i < T; i++)
        solve();
    return 0;
}
