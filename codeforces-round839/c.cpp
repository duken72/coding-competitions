#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <iostream>

using namespace std;

void solve()
{
    int k, n;
    cin >> k >> n;      // 2 ≤ k ≤ n ≤ 40
    int sum = 0, val = 0;
    for (int i = 1; i <= k; i++) {
        cout << i + sum << " ";
        if (k + sum + val <= n) {
            sum += val;
            val++;
        }
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
