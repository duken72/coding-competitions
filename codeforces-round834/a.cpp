#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <iostream>
#include <string>

using namespace std;

void solve()
{
    string S; cin >> S;
    if (S[0] != 'Y' && S[0] != 'e' && S[0] != 's') {
        cout << "NO" << endl;
        return;
    }
    int N = S.size();
    for (int i = 1; i < N; i++) {
        if ((S[i-1] == 'Y' && S[i] != 'e') ||
            (S[i-1] == 'e' && S[i] != 's') ||
            (S[i-1] == 's' && S[i] != 'Y')) {
            cout << "NO" << endl;
            return;
        }        
    }
    cout << "YES" << endl;
}

int main(int argc, char const *argv[])
{
    int T; cin >> T;    // no. test cases
    for (int i = 0; i < T; i++)
        solve();
    return 0;
}
