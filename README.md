<!-- omit in toc -->
# Coding Competitions

This repo is a collection of code for coding competitions.

<!-- omit in toc -->
## Table of Contents

- [Time Complexities](#time-complexities)
- [Useful Functions in C++ STL](#useful-functions-in-c-stl)
- [Type ranges](#type-ranges)
- [Binary Search](#binary-search)
- [Two Pointers Method](#two-pointers-method)
- [Suffix Array](#suffix-array)
- [Depth First Search](#depth-first-search)
- [Problem Types](#problem-types)
  - [Ad Hoc Problems](#ad-hoc-problems)
  - [Complete Search](#complete-search)
  - [Greedy](#greedy)
  - [Flood Fill](#flood-fill)
  - [Heuristic Search](#heuristic-search)
  - [Approximate Search](#approximate-search)
  - [Dynamic Programming](#dynamic-programming)
  - [The Shortest Path](#the-shortest-path)
  - [Recursive Search Techniques](#recursive-search-techniques)
  - [Minimum Spanning Tree](#minimum-spanning-tree)
  - [Knapsack](#knapsack)
  - [Computational Geometry](#computational-geometry)
  - [Network Flow](#network-flow)
  - [Eulerian Path](#eulerian-path)
  - [Two-Dimensional Convex Hull](#two-dimensional-convex-hull)
  - [BigNums](#bignums)

-------

## Time Complexities

- Source [codeforces.com/blog](https://codeforces.com/blog/entry/21344)
- Codeforces can run around `1e8` operations/sec

|  $n ≤ 12$ | $\mathcal{O}(n!)$  | $n ≤ 10^4$ | $\mathcal{O}(n^2)$                        |
|:---------:|--------------------|:----------:|-------------------------------------------|
|  $n ≤ 25$ | $\mathcal{O}(2^n)$ | $n ≤ 10^6$ | $\mathcal{O}(n \log n)$                   |
| $n ≤ 100$ | $\mathcal{O}(n^4)$ | $n ≤ 10^8$ | $\mathcal{O}(n)$                          |
| $n ≤ 500$ | $\mathcal{O}(n^3)$ | $n > 10^8$ | $\mathcal{O}(\log n)$ or $\mathcal{O}(1)$ |

## Useful Functions in C++ STL

- `memset`, `fill`, `fill_n`
- `sort`, `binary_search`, `reverse`
- `__gcd`, `swap`, `move`
- `next_permutation`, `prev_permutation`
- `lower_bound`, `upper_bound`, `equal_range`
- Bit related:
  - `__builtin_clz(x)` - count no. 0 at the beginning
  - `__builtin_ctz(x)` - count no. 0 at the end
  - `__builtin_popcount(x)` - count no. 1
  - `__builtin_parity(x)` - the parity (even or odd) of the no. 1

## Type ranges

Some common types and their ranges:

| Type              |   Range | Type                  |    Range |
|-------------------|--------:|-----------------------|---------:|
| `int8_t`          |    ±127 | `int16_t (short)`     |   ±3.2E4 |
| `int32_t(int)`    |  ±2.1E9 | `int64_t (long long)` |  ±9.2E18 |
| `float (4 bytes)` | 3.4E±38 | `double (8 bytes)`    | 1.7E±308 |

-------

## Binary Search

- Search for an element of specific value or the closest to a value (to the left / right) in a sorted array.
- Search for a value when the function is monotone (if $x$ is good, then $x + 1$ is also good; if $x$ is bad, then $x-1$ is also bad)

    ```cpp
    bool good(int x) {
        // TODO
    }

    int l = -1; // bad
    int r = 1;  // good
    while (!good(r)) {
        l = r;
        r *= 2;
    }

    while (r - l > 1) {
        int m = (l + r) / 2;
        if (good(m))
            r = m;  // as r is good
        else
            l = m;  // as l is bad
    }
    ```

- For `float` or `double` values, instead of `while` loop, use `for` loop to ensure precision
- Mini-max problems: minimize a value that is the maximum of the other values
- Maximum average: choose a subset that has some properties
- Finding the $k^{th}$ ascending element in some set of values: manage to count number of element smaller than a value, that count has to be $≤ k$ to be good

-------

## Two Pointers Method

- Merge sort

    ```cpp
    int n = a.size(), m = b.size();
    vector<int> c(n + m);
    int i = 0, j = 0, k = 0;
    while (i < n || j < m) {
        if (j == m || (i < n && a[i] < b[j])) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }
    ```

- Good segment-related problem

-------

## Suffix Array

- The suffix array is created in $\mathcal{O}(n \log n)$
- The LCP array is created in $\mathcal{O}(n)$
- E.g. tasks:
  - Substring search: create the suffix array, then apply binary search
  - Find the Longest Common Prefix
  - Count number of different substrings: each suffix add $p$ new substrings ($p$ as the length of it), minus the common prefix with the previous suffix
  - Find the longest common substring of two strings: combine the two strings and create the suffix array, LCP array of the combined string, iterate to find the LCP of two consecutive strings from different classes

-------

## Depth First Search

```cpp
bool visited[n];

bool check() {};

void dfs() {
    int id = 0;

    // Find the next unvisited node
    while(visited[id] && id < n) {
        id++;
    }

    // If reach the leaf, check criteria
    if (id == n) {
        if (check()) {}
    }

    // Visit the node and iterate over next possible nodes
    visited[id] = true;
    // TODO
    visited[id] = false;
}
```

-------

## Problem Types

Hal Burch conducted an analysis over spring break of 1999 and made an amazing discovery: there are only 16 types of programming contest problems! Furthermore, the top several comprise almost 80% of the problems seen at the IOI. Here they are:

### Ad Hoc Problems

Are those whose algorithms do not fall into standard categories with well-studied solutions. Each ad hoc problem is different; no specific or general techniques exist to solve them.

### Complete Search

- "Keep it simple, stupid".
- Brute force within the time allowed. Always try this first
- Can search in either the input space or output space

### Greedy

- Constructs a solution by always making a choice that looks the best at the moment
  - Are **FAST**, generally linear to quadratic and require little extra memory
  - Usually aren't correct. But when they do work, easy and fast to implement
- DFS, BFS, DF with Iterative Deepening

### Flood Fill

- Can be done via DF, BF (queue), or BF scanning
  - The first two are faster $\mathcal{O}(N + M)$, but are not good with implicit graph
  - The last one is slower $\mathcal{O}(N*N+M)$, but does not require extra memory

### Heuristic Search

### Approximate Search

### Dynamic Programming

- If the problem depends on a number of variables, consider breaking it down to all of them
- E.g.: use a 2D table `dp[n][m]` if there are 2 variables

### The Shortest Path

### Recursive Search Techniques

### Minimum Spanning Tree

### Knapsack

### Computational Geometry

### Network Flow

### Eulerian Path

### Two-Dimensional Convex Hull

### BigNums

-------
