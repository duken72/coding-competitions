#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <bitset>

using namespace std;

void solve()
{
    int N; cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    for (int a : arr)
        cout << a << " ";
    cout << endl;

    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    cout << max << " " << min << endl;
    cout << bitset<10>(max).to_string() << endl;
    cout << bitset<10>(min).to_string() << endl;

    for (int i = 9; i >= 0; i--) {
        if (pow(2, i) > max)
            continue;
        if ((max / (int)pow(2, i)) % 2 == 0) {
            cout << i << endl;
        }
    }
    

}

int main(int argc, char const *argv[])
{
    int T; cin >> T;    // no. test cases
    for (int i = 0; i < T; i++)
        solve();
    return 0;
}
