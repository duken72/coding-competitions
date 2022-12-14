#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <thread>

using namespace std;

void is_more(bool &out, const string &s1, const string &s2) {
    int N = s1.size();
    out = false;
    for (int i = 0; i < N; i++) {
        if (s1[i] > s2[i]) {
            out = true;
            break;
        }
    }
}
void is_less(bool &out, const string &s1, const string &s2) {
    int N = s1.size();
    out = false;
    for (int i = 0; i < N; i++) {
        if (s1[i] < s2[i]) {
            out = true;
            break;
        }
    }
}
bool not_same_group(const string &s1, const string &s2) {
    bool b1, b2;
    thread t1(is_more, ref(b1), cref(s1), cref(s2));
    thread t2(is_less, ref(b2), cref(s1), cref(s2));
    t1.join();
    t2.join();
    return b1 && b2;
}
int not_same_group(const string &s_in, string S[], const vector<int> &v) {
    for (int i : v)
        if (not_same_group(s_in, S[i]))
            return true;
    return false;
}
int get_level(const string &s) {
    int result = s.size() + 1;
    for (auto &c : s)
        result -= (c == '1') ? 1 : 0;
    return result;
}

void solve()
{
    int N; cin >> N;            // no. developers   1 ≤ n ≤ 500
    int M; cin >> M;            // no. documents    1 ≤ m ≤ 500
    string access[M];           // access of each doc
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c; cin >> c;
            access[j].push_back(c);
        }
    }
    vector<vector<int>> group;  // access group
    vector<int> doc_id;         // doc's group id
    for (const string &s : access) {
        bool assigned = false;
        for (auto &g : group) {
            if (not_same_group(s, access, g))   continue;
            g.push_back(doc_id.size());
            doc_id.push_back(find(begin(group), end(group), g) - begin(group) + 1);
            assigned = true;
            break;
        }
        if (assigned)   continue;
        group.push_back(vector<int>{static_cast<int>(doc_id.size())});
        doc_id.push_back(group.size());
    }
    
    cout << group.size() << endl;       // no. groups
    for (auto id : doc_id)              // group id of doc
        cout << id << ' ';
    cout << endl;
    for (auto a : access)               // access level for doc
        cout << get_level(a) << ' ';
    cout << endl;
    for (int i = 0, level; i < N; i++) {
        for (auto g : group) {
            level = 1;
            for (int id : g)
                level = (access[id][i] == '1') ? max(level, get_level(access[id])) : level;
            cout << level << ' ';
        }
        cout << endl;        
    }
}

int main()
{
    int T; cin >> T;
    for (int i = 0; i < T; i++) {
        cout << "Case " << i+1 << ":" << endl;
        solve();
    }
    // solve();
    return 0;
}
