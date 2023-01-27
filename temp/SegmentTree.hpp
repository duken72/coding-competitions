#include <vector>

using std::vector;

// TODO meta round2 a2

// https://cp-algorithms.com/data_structures/segment_tree.html
template <typename T>
class SegmentTree {
    static T merge(const T &a, const T &b) { return add(a, b); }
    int length;
    vector<T> values;

    void build(int id, int low, int high, const vector<T>& array) {
        if (low == high) {
            values[id] = array[low];
            return;
        }
        int mid = low + (high - low) / 2;
        build(id * 2 + 1, low, mid, array);
        build(id * 2 + 2, mid + 1, high, array);
        values[id] = merge(values[id * 2 + 1], values[id * 2 + 2]);
    }

    T query(int id, int low, int high, int tgt_low, int tgt_high) const {
        if (low == tgt_low && high == tgt_high)
            return values[id];
        int mid = low + (high - low) / 2;
        if (tgt_high <= mid)
            return query(id * 2 + 1, low, mid, tgt_low, tgt_high);
        if (tgt_low > mid)
            return query(id * 2 + 2, mid + 1, high, tgt_low, tgt_high);
        return merge(
            query(id * 2 + 1, low, mid, tgt_low, mid),
            query(id * 2 + 2, mid + 1, high, mid + 1, tgt_high)); 
    }

    void update(int id, int low, int high, int target, const T &val) {
        if (target < low || target > high)
            return;
        if (low == high) {
            values[id] = val;
            return;
        }
        int mid = low + (high - low) / 2;
        update(id * 2 + 1, low, mid, target, val);
        update(id * 2 + 2, mid + 1, high, target, val);
        values[id] = merge(values[id * 2 + 1], values[id * 2 + 2]);
    }

public:
    SegmentTree(const vector<T>& array)
    : length(array.size()), values(4 * length) {
        build(0, 0, length - 1, array);
    }

    T query(int low, int high) const { return query(0, 0, length - 1, low, high); }
    
    void update(int id, const T &val) { update(0, 0, length - 1, id, val); }
};