#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int N; cin >> N;            // no. participants 2 ≤ n ≤ 2⋅10^5
    vector<int> S(N);           // strengths of participants 1 ≤ si ≤ 10^9
    for (int i = 0; i < N; i++)
        cin >> S[i];
    int S1 = (S[0] >= S[1]) ? S[0] : S[1];  // max strength
    int S2 = (S[0] >= S[1]) ? S[1] : S[0];  // 2nd max strength
    for (int i = 2; i < N; i++) {
        if (S[i] > S1) {
            S2 = S1;
            S1 = S[i];
            continue;
        }
        if (S[i] > S2) {
            S2 = S[i];
        }                
    }
    for (int i = 0; i < N; i++) {
        if (S[i] < S1)
            cout << S[i] - S1 << " ";
        else
            cout << S[i] - S2 << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int T; cin >> T;    // no. test cases 1 ≤ t ≤ 1000
    for (int i = 0; i < T; i++)
        solve();
    return 0;
}
