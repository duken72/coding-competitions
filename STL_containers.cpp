#include <bits/stdc++.h>
#include <math.h>
using namespace std;

#define PRIORITY_QUEUE true

void out(const auto& what, int n = 1) { while (n-- > 0) std::cout << what; }
void print(std::string_view text, std::vector<int> const& v = {});
void draw_heap(auto const& v);
template<typename Q>
void print_queue(std::string_view name, Q q);

int main(int argc, char const *argv[])
{
#if LIST
    std::list<int> l = {7, 5, 16, 8};
    l.push_front(25);
    l.push_back(13);
 
    // Insert value before a key by searching
    auto it = std::find(l.begin(), l.end(), 16);
    if (it != l.end())
        l.insert(it, 42);
 
    for (int n : l)
        std::cout << n << " ";
#endif  // LIST

#if STACK
    stack<int> st;
	st.push(21); st.push(22); st.push(24); st.push(25); st.push(27);
    for (; !st.empty(); st.pop())
		cout << st.top() <<" ";
#endif  // STACK

#if QUEUE
    std::queue<int> q;
    q.push(7); q.push(5); q.push(16); q.push(8); q.push(13);
    for (; !q.empty(); q.pop())
        cout << q.front() << " ";    
#endif  // QUEUE

#if DEQUE   // Double Ended Queue
    // fast insertion and deletion at both its beginning and end
    deque<int> d = {7, 5, 16, 8};
    d.push_front(13);
    d.push_back(25);
    for(int n : d)      std::cout << n << ' ';
    std::cout << "\n";
#endif  // DEQUE

#if PRIORITY_QUEUE
    const auto data = {1, 8, 5, 6, 3, 4, 0, 9, 7, 2};
    print("Data", data);

    // Max priority queue
    priority_queue<int> q1;
    for (int n : data)
        q1.push(n);
    print_queue("maxq1", q1);
 
    // Min priority queue with std::greater<int>
    priority_queue<int, vector<int>, greater<int>>
        minq1(data.begin(), data.end());
 
    print_queue("minq1", minq1);
 
    // Second way to define a min priority queue
    priority_queue minq2(data.begin(), data.end(), std::greater<int>()); 
    print_queue("minq2", minq2);
 
    // Using a custom function object to compare elements.
    struct {
        bool operator() (const int l, const int r) const { return l > r; }
    } customLess;
    priority_queue minq3(data.begin(), data.end(), customLess);
    print_queue("minq3", minq3);
 
    // Using lambda to compare elements.
    auto cmp = [](int left, int right) { return (left ^ 1) < (right ^ 1); };
    priority_queue<int, vector<int>, decltype(cmp)> q5(cmp);
    for (int n : data)
        q5.push(n);
    print_queue("q5", q5);
#endif  // PRIORITY_QUEUE

#if HEAP
    // https://en.cppreference.com/w/cpp/algorithm/ranges/make_heap
    // https://en.cppreference.com/w/cpp/algorithm/push_heap
    vector h {1, 6, 1, 8, 0, 3, 3, 9, 8, 8, 7, 4, 9, 8, 9};
    print("Ini vect", h);

    // Min heap
    make_heap(h.begin(), h.end(), std::greater<>{});
    print("Min heap", h);
    draw_heap(h);

    // Max heap
    if (!std::is_heap(h.begin(), h.end())) {
        std::cout << "\nChecking with is_heap...\n";
        make_heap(h.begin(), h.end());
    }
    print("Max heap", h);
    draw_heap(h);

    // Pop heap: swap the top elem to the last
    // then bubbling down to meet the heap invariant
    print("\nUsing pop_heap");
    pop_heap(h.begin(), h.end());
    draw_heap(h);
    h.pop_back();
    draw_heap(h);

    // Push heap: add a new elem to the heap
    print("\nUsing push_heap");
    h.push_back(14);
    draw_heap(h);
    push_heap(h.begin(), h.end());
    draw_heap(h);

    // Sort heap: 
    print("\nUsing sort_heap h", h);
    sort_heap(h.begin(), h.end());
#endif  // HEAP

    cout << endl;
}

void print(std::string_view text, std::vector<int> const& v) {
    std::cout << text << ":\t";
    for (const auto& e : v) std::cout << e << ' ';
    std::cout << '\n';
}

void draw_heap(auto const& v)
{
    auto bails = [](int n, int w) {
        auto b = [](int w) { out("┌"), out("─", w), out("┴"), out("─", w), out("┐"); };
        if (!(n /= 2)) return;
        for (out(' ', w); n-- > 0; ) b(w), out(' ', w + w + 1);
        out('\n');
    };
    auto data = [](int n, int w, auto& first, auto last) {
        for(out(' ', w); n-- > 0 && first != last; ++first)
            out(*first), out(' ', w + w + 1);
        out('\n');
    };
    auto tier = [&](int t, int m, auto& first, auto last) {
        const int n {1 << t};
        const int w {(1 << (m - t - 1)) - 1};
        bails(n, w), data(n, w, first, last);
    };
    const int m {static_cast<int>(std::ceil(std::log2(1 + v.size())))};
    auto first {v.cbegin()};
    for (int i{}; i != m; ++i) { tier(i, m, first, v.cend()); }
}

template<typename Q>
void print_queue(std::string_view name, Q q)
{
    // q is passed by value because there is no way to traverse
    // priority_queue's content without erasing the queue.
    for (std::cout << name << ": \t"; !q.empty(); q.pop())
        std::cout << q.top() << ' ';
    std::cout << '\n';
}