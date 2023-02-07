#include <vector>

// TODO: meta round2 d1

using std::vector;
using LL = long long;

template<typename T>
inline T LSB(const T& i) { return i & -i; }

struct FenwickTree {
    vector<LL> A, T;                // Original array A and the tree T
    FenwickTree(int N) : A(N + 1), T(N + 1) {}

    LL at(int id) const { return A[id]; }

    LL query(int id) const
    {
        LL sum = 0;
        for (; id > 0; id -= LSB(id))
            sum += T[id];
        return sum;
    }
    LL query(int low, int high) const { return query(high) - query(low - 1); }

    // Update by increment
    void update(int id, LL val)
    {
        A[id] += val;
        int N = T.size();
        for (; id < N; id += LSB(id))
            T[id] += val;
    }
    // Update by setting
    void set(int id, LL val) { update(id, val - A[id]); }
};