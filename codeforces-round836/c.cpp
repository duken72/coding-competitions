#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int N; cin >> N;    // 2 ≤ n ≤ 2e5
    int X; cin >> X;    // 1 < x ≤ n
    if (N % X != 0) {
        cout << -1 << endl;
        return;
    }
    for (int i = 1; i <= N; i++) {
        if (i == 1)
            cout << X;
        else if (i == N)
            cout << 1;
        else if (i == X)
            cout << N;
        else
            cout << i;
        if (i != N)
            cout << " ";
    }
    cout << endl;        
}

int main(int argc, char const *argv[])
{
    int T; cin >> T;    // no. test cases
    for (int i = 0; i < T; i++)
        solve();
    return 0;
}
