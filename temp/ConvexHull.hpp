#include <vector>
#include <utility>

using std::vector;
using LL = long long;
using Coord = std::pair<LL, LL>;
#define x first
#define y second

LL sqrDist(const Coord &a, const Coord &b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

LL cross(const Coord &a, const Coord &b, const Coord &o = Coord(0, 0)) {
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

template <class It>
vector<Coord> convex_hull(It lo, It hi) {
    int k = 0;
    if (hi - lo <= 1)
        return vector<Coord>(lo, hi);
    vector<Coord> res(2 * distance(lo, hi));
    sort(lo, hi);
    for (It it = lo; it != hi; ++it) {
        while (k >= 2 && cross(res[k - 1], *it, res[k - 2]) >= 0)
            k--;
        res[k++] = *it;
    }
    int t = k + 1;
    for (It it = hi - 2; it != lo - 1; --it) {
        while (k >= t && cross(res[k - 1], *it, res[k - 2]) >= 0)
            k--;
        res[k++] = *it;
    }
    res.resize(k - 1);
    return res;
}

void test()
{
    int n = 7;
    vector<Coord> pts(n);    // Vector of house coordinates
    vector<Coord> convexPts = convex_hull(pts.begin(), pts.end());
}
