#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <iostream>
#include <string>

using namespace std;

void solve()
{
    int N; cin >> N;        // length of the word
    string S; cin >> S;     // the word
    if ((N % 3) == 2) {
        cout << "NO" << endl;
        return;
    }
    int K = N / 3;
    for (int i = 0; i < K; i++) {
        if (S[3*i+1] != S[3*i+2]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main(int argc, char const *argv[])
{
    int T; cin >> T;        // no. test cases 1 ≤ t ≤ 100
    for (int i = 0; i < T; i++)
        solve();
    return 0;
}
