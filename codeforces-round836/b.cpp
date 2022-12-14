#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

void solve()
{
    int N; cin >> N;
    if (N % 2 == 1) {
        for (int i = 0; i < N; i++) {
            cout << 1;
            if (i != N-1)
                cout << " ";
        }
        cout << endl;
    } else {
        for (int i = 0; i < N-2; i++)
            cout << "2 ";
        cout << "3 1" << endl;
    }
}

int main(int argc, char const *argv[])
{
    int T; cin >> T;    // no. test cases
    for (int i = 0; i < T; i++)
        solve();
    return 0;
}
