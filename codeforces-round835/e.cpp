#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using LL = long long;
int C0[200'000];

LL solve()
{
    int N; cin >> N;        // no. element  1 ≤ n ≤ 2e5
    C0[0] = 0;              // vect of 0 counts
    int id = -1;            // id of first 0
    vector<int> id1;        // indices of 1
    for (int i = 0, ai; i < N; i++) {
        cin >> ai;
        if (i > 0)
            C0[i] = C0[i-1];
        if (ai == 1) {
            id1.push_back(i);
            continue;
        }
        C0[i]++;
        if (id == -1)
            id = i;
    }
    if (id == -1)   // edge case: no 0, change the last 1
        return N - C0[N-1] - 1;
    LL result = max((LL)0, (LL)C0[N-1] - (id + 1)); // change 1st 0
    if (id1.size())
        result = max(result, (LL)id1.back() - C0[N-1]);// change last 1
    for (int id : id1)
        result += C0[N-1] - C0[id];
    return result;
}

int main(int argc, char const *argv[])
{
    int T; cin >> T;    // no. test cases
    for (int i = 0; i < T; i++)
        cout << solve() << endl;
    return 0;
}
