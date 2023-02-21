<!-- omit in toc -->
# String

<!-- omit in toc -->
## Table of Contents

- [Check if multiple substrings exists in a given string](#check-if-multiple-substrings-exists-in-a-given-string)
- [Number of different substrings](#number-of-different-substrings)
- [The Longest common substring of two strings](#the-longest-common-substring-of-two-strings)

-------

## Check if multiple substrings exists in a given string

- Given ONLY 1 string and MANY substrings
- Create suffix array of the given string in $\mathcal{O}(N \log N)$
- Run binary search over the suffix array to find the substring in $\mathcal{O}(|p| \log N)$, with $|p|$ as the substring's length

```cpp
s1 = str1.size();
s2 = str2.size();
vector<int> sa = suffix_array(str1);

// Edge case
if (s2 >= s1) { ... }

// Common case: s2 < s1
int lo = 0, hi = s1 + 1, mi;    // Binary search
int ans;
do {
    mi = (lo + hi) / 2;
    ans = str2.compare(str1.substr(sa[mi], s2));
    if (mi == lo)   break;
    if (ans == 0) {
        break;
    }   else if (ans < 0) {
        hi = mi;
    }   else {
        lo = mi;
    }
}   while (hi - lo >= 1);

if (ans == 0) {
    cout << "Yes\n";
}   else {
    cout << "No\n";
}
```

-------

## Number of different substrings

- Create the suffix array in $\mathcal{O}(N \log N)$
- Create the LCP array in $\mathcal{O}(N)$
- Each suffix add $N$ new substrings, with $N$ as the length of that suffix, minus the common prefix with the previous suffix

-------

## The Longest common substring of two strings

- Combine the two string $s$ and $t$ with a "~" char in the middle: $s\sim t$
- Create the suffix array, then LCP array for the combined string
- Iterate over that array to find the largest common prefix of two consecutive strings from different class
