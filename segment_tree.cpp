// https://cp-algorithms.com/data_structures/segment_tree.html
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

template <typename T = int>
class SegmentTree {
    // const ll NO_OPERATION = LLONG_MAX;
    int size;
    vector<T> arr;

    // Associative and communicative operation
    // a ? b) ? c = a ? (b ? c)
    T op(const T& a, const T& b) { return a + b; }
    // Associative but NOT communicative operation
    // T operation(const T& a, const T& b) {
    //     if (b == NO_OPERATION) return a;
    //     return b;
    // }
    // void propagate(const int& x, const int& lx, const int& rx) {
    //     if (rx - lx == 1) return;
    //     arr[2 * x + 1] = operation(arr[2 * x + 1], arr[x]);
    //     arr[2 * x + 2] = operation(arr[2 * x + 2], arr[x]);
    //     arr[x] = NO_OPERATION;
    // }

    void init(const int& n) {
        size = 1;
        while (size < n)    size *= 2;
        arr.assign(2 * size, 0);
    }
    void build(const vector<T>& vect, const int& x, const int& lx, const int& rx) {
        if (rx - lx == 1) {
            if (lx < (int)vect.size())   arr[x] = vect[lx];
            return;
        }
        int mx = (lx + rx) / 2;
        build(vect, 2 * x + 1, lx, mx);
        build(vect, 2 * x + 2, mx, rx);
        arr[x] = op(arr[2 * x + 1], arr[2 * x + 2]);
    }

    // Modify a position
    void set(const int& id, const int& val,
             const int& x, const int& lx, const int& rx) {
        if (rx - lx == 1) {
            arr[x] = val;
            return;
        }
        int mx = (lx + rx) / 2;
        if (id < mx)
            set(id, val, 2 * x + 1, lx, mx);
        else    // i >= mx
            set(id, val, 2 * x + 2, mx, rx);
        arr[x] = op(arr[2 * x + 1], arr[2 * x + 2]);
    }
    // Modify a range
    // void set(const int& l, const int& r, const T& v,
    //          const int& x, const int& lx, const int& rx) {
    //     // With non communicative function
    //     propagate(x, lx, rx);
    //     if (l >= rx || r <= lx) return;
    //     if (lx >= l && rx <= r) {
    //         arr[x] = op(arr[x], v);
    //         return;
    //     }
    //     int mx = (lx + rx) / 2;
    //     set(l, r, v, 2 * x + 1, lx, mx);
    //     set(l, r, v, 2 * x + 2, mx, rx);
    // }

    T get(const int& l, const int& r,
          const int& x, const int& lx, const int& rx) const {
        if (lx >= r || rx <= l) return 0;
        if (lx >= l && rx <= r) return arr[x];
        int mx = (lx + rx) / 2;
        return op(get(l, r, 2 * x + 1, lx, mx),
                  get(l, r, 2 * x + 2, mx, rx));
    }
    // Get position value with range modification
    // T get(const int& id, const int& x, const int& lx, const int& rx) {
    //     // With non communicative function
    //     propagate(x, lx, rx);
    //     if (rx - lx == 1)
    //         return arr[x];
    //     int mx = (lx + rx) / 2;
    //     T res;
    //     if (id < mx)
    //         res = get(id, 2 * x + 1, lx, mx);
    //     else
    //         res = get(id, 2 * x + 2, mx, rx);
    //     return res;
    // }

public:
    SegmentTree(const int& n) { init(n); }
    SegmentTree(const vector<T>& vect) {
        init(vect.size());
        build(vect, 0, 0, size);
    }

    // Modify a position
    void set(const int& id, const int& val) { set(id, val, 0, 0, size); }
    // Modify a range
    // void set(const int& l, const int& r, const T& val) {
    //     set(l, r, val, 0, 0, size);
    // };

    // Range [l, r), NOT [l, r]
    T get(const int& l, const int& r) const { return get(l, r, 0, 0, size); }
    T get(const int& id) const { return get(id, id + 1, 0, 0, size); }
    // Get value of a position, with range modification
    // T get(const int& id) { return get(id, 0, 0, size); }
};

int main(int argc, char const *argv[])
{
    vector<int> v = { 1, 4, 4, 8, 3, 7 };
    SegmentTree<int> st(v);

    for (auto val : v)  cout << val << ' ';
    cout << endl;
    
    cout << "Sum in range [0, 0]: " << st.get(0) << endl;
    cout << "Sum in range [0, 2): " << st.get(0, 2) << endl;
    cout << "Sum in range [2, 6): " << st.get(2, 6) << endl;

    cout << "Setting id=1 to value=9" << endl;
    st.set(1, 9);
    cout << "Sum in range [0, 2): " << st.get(0, 2) << endl;

    cout << "Setting id=2 to value=7" << endl;
    st.set(2, 7);
    cout << "Sum in range [2, 6): " << st.get(2, 6) << endl;

    return 0;
}
