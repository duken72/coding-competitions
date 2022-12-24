#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
#define health first
#define damage second

string solve()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> monster(n);
    for (int i = 0; i < n; i++)
        cin >> monster[i].health;    // health
    for (int i = 0; i < n; i++)
        cin >> monster[i].damage;   // damage

    while (k > 0 && monster.size() > 0) {
        n = monster.size();
        for (int i = n - 1; i >= 0; i--) {
            if (monster[i].health <= k)
                monster.erase(monster.begin() + i);
            else
                monster[i].health = monster[i].health - k;            
        }
        auto result = *std::min_element(monster.cbegin(), monster.cend(), [](const auto& lhs, const auto& rhs) {
            return lhs.damage < rhs.damage;
        });
        k -= result.damage;
    }
    if (monster.size())
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
