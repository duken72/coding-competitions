#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int n, m;
const int N = 3e5 + 10;
struct Node {
    int xmin, xmax;
    int cnt;
};
int p[N];
int cnt[N];
Node arr[N];

int get(int a) { return p[a] = (p[a] == a ? a : get(p[a])); }

void union_set(int a, int b) {
    if ((a = get(a)) == (b = get(b))) return;
    if (cnt[a] >= cnt[b]) swap(a, b);
    p[a] = b;
    cnt[b] += cnt[a];
    // arr[b].xmin = min(arr[a].xmin, arr[b].xmin);
    // arr[b].xmax = max(arr[a].xmax, arr[b].xmax);
    // arr[b].cnt += arr[a].cnt;
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n + 1; i++) {
        p[i] = i;
        arr[i] = {i, i, 1};
    }
    for (int i = 0; i < m; i++) {
        string s;;
        cin >> s;
        if (s == "union") {
            int u, v; cin >> u >> v;
            union_set(u, v);
        }   else {
            int v; cin >> v;
            int id = get(v);
            cout << arr[id].xmin << arr[id].xmax << arr[id].cnt << endl;
        }
    }
}

int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}