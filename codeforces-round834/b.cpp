#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

string solve()
{
    int M, S;
    cin >> M >> S;
    vector<int> A(M);
    for (int i = 0; i < M; i++)
        cin >> A[i];
    int N = *max_element(A.begin(), A.end());
    S += accumulate(A.begin(), A.end(), 0);
    while (S > (N+1) * N / 2)
        N++;
    if (S < (N+1) * N / 2)
        return "NO";
    return "YES";
}

int main(int argc, char const *argv[])
{
    int T; cin >> T;    // no. test cases
    for (int i = 0; i < T; i++)
        cout << solve() << endl;
    return 0;
}
