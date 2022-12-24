#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    vector<int> vect(4);
    for (int i = 0; i < 4; i++)
        cin >> vect[i];
    int id_max = max_element(begin(vect), end(vect)) - begin(vect);
    int id_min = min_element(begin(vect), end(vect)) - begin(vect);
    if (id_max + id_min == 3)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main(int argc, char const *argv[])
{
    int T; cin >> T;    // no. test cases
    for (int i = 0; i < T; i++)
        solve();
    return 0;
}
