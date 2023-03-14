<!-- omit in toc -->
# Coding Competitions

Collection of code for coding competitions or random small projects

<!-- omit in toc -->
## Table of Contents

- [Time Complexities](#time-complexities)
- [Useful Functions in C++ STL](#useful-functions-in-c-stl)
- [Type ranges](#type-ranges)

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

## Type ranges

Some common types and their ranges:

| Type              |   Range | Type                  |    Range |
|-------------------|--------:|-----------------------|---------:|
| `int8_t`          |    ±127 | `int16_t (short)`     |   ±3.2E4 |
| `int32_t(int)`    |  ±2.1E9 | `int64_t (long long)` |  ±9.2E18 |
| `float (4 bytes)` | 3.4E±38 | `double (8 bytes)`    | 1.7E±308 |
