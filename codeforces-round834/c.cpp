#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <iostream>
#include <vector>

using namespace std;

int solve()
{
    int L, R, X;    // −1e9 ≤ l ≤ r ≤ 1e9 , 1 ≤ x ≤ 1e9
    int A, B;       // l ≤ a, b ≤ r
    cin >> L >> R >> X >> A >> B;
    if (A == B)
        return 0;
}

int main(int argc, char const *argv[])
{
    int T; cin >> T;    // no. test cases
    for (int i = 0; i < T; i++)
        cout << solve() << endl;
    return 0;
}
