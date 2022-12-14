#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <math.h>

using namespace std;

// Find GCD of two numbers (greatest common divisor)
template <typename T>
T findGCD(const T& a, const T& b) {
  if (b == 0) return a;
  return findGCD(b, a%b);
}

vector<int> get_prime_factors(int N)
{
    vector<int> out;
    int m = 2;
    while (m <= sqrt(N)) {
        if (N % m != 0) {
            m++;
            continue;
        }
        out.push_back(m);
        while (N % m == 0) {
            N /= m;
        }
    }
    if (N > 1)
        out.push_back(N);    
    return out;    
}

string solve()
{
    int N; cin >> N;    // 2 ≤ n ≤ 1e5
    vector<int> A(N);   // 1 ≤ ai ≤ 1e9
    for (int i = 0; i < N; i++)
        cin >> A[i];
    unordered_map<int, int> prime_ref;
    for (int a : A) {
        vector<int> P = get_prime_factors(a);
        for (int p : P) {
            if (prime_ref[p] == 1)
                return "YES";
            else
                prime_ref[p] = 1;
        }
    }   
    return "NO";
}

int main(int argc, char const *argv[])
{
    int T; cin >> T;    // no. test cases
    for (int i = 0; i < T; i++)
        cout << solve() << endl;
    return 0;
}
