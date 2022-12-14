#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int N; cin >> N;        // length of array 1 ≤ n ≤ 2⋅10^5
    vector<int> A(N);       // the array
    for (int i = 0; i < N; i++)
        cin >> A[i];
    if (N == 1) {
        cout << "YES" << endl;
        return;
    }    
    bool rising = false;
    for (int i = 1; i < N; i++) {
        if ((A[i-1] < A[i]) && (!rising))
            rising = true;
        else if ((A[i-1] > A[i]) && rising) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main(int argc, char const *argv[])
{
    int T; cin >> T;
    for (int i = 0; i < T; i++)
        solve();
    return 0;
}
