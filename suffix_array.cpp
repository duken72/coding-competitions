#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define ff              first
#define ss              second

void count_sort(int p[], int c[], int n)
{
    int cnt[n] = { 0 };         // bucket's sizes
    for (int i = 0; i < n; i++)     cnt[c[i]]++;
    int p_new[n], pos[n];       // each bucket iter positions
    pos[0] = 0;
    for (int i = 1; i < n; i++)     pos[i] = pos[i - 1] + cnt[i - 1];
    for (int i = 0; i < n; i++) {
        p_new[pos[c[p[i]]]] = p[i];
        pos[c[p[i]]]++;
    }
    swap_ranges(p, p + n, p_new);
}

void suffix_array(string &s)
{
    s += "$";
    int n = s.size();
    int sa[n], cls[n];
    int k = 0;
    {
        vector<pair<char, int>> a(n);
        for(int i = 0; i < n; i++)  a[i] = {s[i], i};
        sort(a.begin(), a.end());
        for(int i = 0; i < n; i++)  sa[i] = a[i].ss;
        cls[sa[0]] = 0;
        for(int i = 1; i < n; i++)
            cls[sa[i]] = cls[sa[i-1]] + int(a[i-1].ff != a[i].ff);
    }
    
    while((1 << k) < n && cls[sa[n-1]] < n-1) {
        // k -> k + 1
        // Shift to get the sorted array by second halves
        for (int i = 0; i < n; i++)
            sa[i] = (sa[i] - (1 << k) + n) % n;
        count_sort(sa, cls, n);       // Count sort for the 1st halves
        int cls_new[n];
        cls_new[sa[0]] = 0;
        pair<int, int> prev = {cls[sa[0]], cls[(sa[0] + (1 << k)) % n]};
        for (int i = 1; i < n; i++) {
            pair<int, int> curr = {cls[sa[i]], cls[(sa[i] + (1 << k)) % n]};
            cls_new[sa[i]] = cls_new[sa[i - 1]] + !(curr == prev);
            prev = curr;
        }
        swap_ranges(cls, cls + n, cls_new);
        k++;
    }
    
    int lcp[n];             // Longest Common Prefix array
    for (int i = 0, k = 0, pi, j; i < n - 1; i++) {
        pi = cls[i];        // position of the i-th suffix in the suffix array
        j = sa[pi - 1];     // previous suffix in the suffix array
        // lcp[i] = lcp(s[i..], s[j..])
        while (s[i + k] == s[j + k])    k++;
        lcp[pi] = k;
        k = max(k - 1, 0);
    }

    for (int i = 0; i < n; i++) {
        cout << lcp[i] << ' ' << sa[i] << ' '
             << s.substr(sa[i]) << endl;
    }
}

int main(int argc, char const *argv[])
{
    string s = "ababba";
    suffix_array(s);
    return 0;
}
