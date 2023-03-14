<!-- omit in toc -->
# Number Theory

<!-- omit in toc -->
## Table of Contents

- [Greatest Common Divisor (GCD)](#greatest-common-divisor-gcd)
- [Check Prime number](#check-prime-number)

## Greatest Common Divisor (GCD)

```cpp
template <typename T>
T GCD(const T& a, const T& b) {
    if (b==0)   return a;
    return GCD(b, a%b);
}
```

## Check Prime number

```cpp
bool is_prime(int n) {
    if (n <= 1)     return false;
    if (n <= 3)     return true;
    if ((n % 2 == 0) || (n % 3 == 0))           return false;
    // Prime number above 3 must be either (6i + 1) or (6i - 1)
    for (int i = 5; i * i <= n; i = i + 6)
        if ((n % i == 0) || (n % (i + 2) == 0)) return false;
    return true;
}
```
