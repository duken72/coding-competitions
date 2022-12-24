#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <iostream>

using namespace std;

int solve()
{
    int n; cin >> n;    // 2 ≤ n ≤ 2e5
    int var1 = 0, var2 = 0;
    int lowbound = 0, upbound = 1'000'000'000;
    cin >> var2;
    for (int i = 1, sum; i < n; i++) {
        var1 = var2;
        cin >> var2;
        sum = var1 + var2;
        if (var1 < var2) {
            upbound = (2 * upbound > sum) ? sum / 2 : upbound;
        } else if (var1 > var2) {
            sum++;
            lowbound = (2 * lowbound < sum) ? sum / 2 : lowbound;
        }
    }
    if (lowbound > upbound)
        return -1;
    return lowbound;
}

int main(int argc, char const *argv[])
{
    int T; cin >> T;    // no. test cases
    for (int i = 0; i < T; i++)
        cout << solve() << endl;
    return 0;
}
