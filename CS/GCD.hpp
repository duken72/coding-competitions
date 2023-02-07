// Find GCD of two numbers (greatest common divisor)
template <typename T>
T findGCD(const T& a, const T& b) {
  if (b == 0) return a;
  return findGCD(b, a%b);
}

// Greatest Common Divisor (GCD)
template <typename T>
void gcdExtended(T a, T b, T &x, T &y) {
    if (a == 0) {
        x = 0, y = 1;
        return;
    }
    T x1, y1;
    gcdExtended(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
}
