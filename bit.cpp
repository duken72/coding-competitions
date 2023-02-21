#include <iostream>
#include <bitset>

using namespace std;

// Bit Tricks
// https://www.geeksforgeeks.org/bitwise-hacks-for-competitive-programming/
// https://www.geeksforgeeks.org/bit-tricks-competitive-programming/
// https://developerinsider.co/awesome-bitwise-operations-and-tricks-with-examples/

/**
 * @brief Tricks using bitwise operators
 * 
 * x | (1 << n)                 Set n-th bit of integer
 * x & ~(1 << n)                Unset n-th bit of integer
 * x ^ (1 << n)                 Toggle n-th bit of integer
 * 
 * x & ~((1 << (i+1)) - 1)      Clear from LSB to n-th bit
 * x & ((1 << i) - 1)           Clear from MSB to n-th bit
 * 
 * x >> n                       Divide by the n-th power of 2
 * x << n                       Multiply by the n-th power of 2
 * 
 * x |= ' '                     Upper case to lower case (English)
 * x &= '_'                     Lower case to upper case (English)
 * 
 * (x ^ y) == 0                 Check equality of two integer
 * (x & 1) == 1                 Check an integer is odd
 * 
 * a = a ^ b ^ (b = a)          Swap two integer values
 * (a ^ b) >= 0                 Check if two integers have the same sign
 * 
 * x && !(x & (x - 1))          Check if an integer is power of 2
 * 
 * (b ^ ((a ^ b) & -(a < b)))   Min of two integers
 * (a ^ ((a ^ b) & -(a < b)))   Max of two integers
 */

int clear_from_LSB(int x, int i);
int clear_from_MSB(int x, int i);
int countSetBits(int x);
int log2(int x);
int isPowerof2(int x);
int lastSetBit(int n);

int main(int argc, char const *argv[])
{
    int x = 527;        // 1000001111
    cout << "x \t    = " << x
         << " = " << std::bitset<16>(x).to_string() << endl;
    // Set i-th bit: using shift and OR
    cout << "x | (1<<5)  = " << (x | (1<<5))
         << " = " << std::bitset<16>(x | (1<<5)).to_string()
         << ", set 5th bit" << endl;
    // Unset i-th bit: using shift, bitwise complement and AND
    cout << "x & ~(1<<5) = " << (x & ~(1<<5))
         << " = " << std::bitset<16>(x & ~(1<<5)).to_string()
         << ", unset 5th bit" << endl;
    // Toggle i-th bit: using shift and XOR
    cout << "x ^ (1<<2)  = " << (x ^ (1<<2))
         << " = " << std::bitset<16>(x ^ (1<<2)).to_string()
         << ", toggle 2nd bit" << endl;
    cout << endl;

    cout << "x \t\t\t= " << x
         << ", binary: " << std::bitset<16>(x).to_string() << endl;
    // Clear all bits from LSB to i-th bit
    cout << "clear_from_LSB(x, 2) \t= " << clear_from_LSB(x, 2)
         << ", binary: " << std::bitset<16>(clear_from_LSB(x, 2)).to_string() << endl;
    // Clearing all bits from MSB to i-th bit
    cout << "clear_from_MSB(x, 4) \t= " << clear_from_MSB(x, 4)
         << " , binary: " << std::bitset<16>(clear_from_MSB(x, 4)).to_string() << endl;
    cout << endl;

    // Divide by 2, or power of it
    cout << "(1025 >> 1) = " << (1025 >> 1) << endl;
    cout << "(1025 >> 2) = " << (1025 >> 2) << endl;
    // Multiply by 2, or power of it
    cout << "(5 << 1) = " << (5 << 1) << endl;
    cout << "(5 << 2) = " << (5 << 2) << endl;
    cout << endl;

    char ch = 'D';
    // Upper case English alphabet to lower case
    cout << "ch = " << ch << ", ";
    ch |= ' ';
    cout << "ch |= ' '; ch = " << ch << endl;
    // Lower case English alphabet to upper case
    cout << "ch = " << ch << ", ";
    ch &= '_';
    cout << "ch &= '_'; ch = " << ch << endl;
    cout << endl;

    // Count set bits in integer
    cout << "x = " << x
         << ", binary: " << std::bitset<16>(x).to_string() << endl;
    cout << "countSetBits(x) = " << countSetBits(x) << endl;
    // Find log base 2 of 32 bit integer
    cout << "log2(x) = " << log2(x) << endl;
    // Checking if given 32 bit integer is power of 2
    cout << "isPowerof2(x) = " << isPowerof2(x) << endl;
    // Find the last set bit
    cout << "lastSetBit(x) = " << lastSetBit(x) << endl;

    int a = -145, b = 34;
    int min = (b ^ ((a ^ b) & -(a < b)));
    int max = (a ^ ((a ^ b) & -(a < b)));
    printf("Minimum(-145, 34) => %d\n", min);
    printf("Maximum(-145, 34) => %d\n", max);
    return 0;
}

int clear_from_LSB(int x, int i) {
    return x & ~((1 << (i+1)) - 1);
}

int clear_from_MSB(int x, int i) {
    return x & ((1 << i) - 1);
}

int countSetBits(int x) {
    int count = 0;
    while (x) {
        x &= (x-1);
        count++;
    }
    return count;
}

int log2(int x) {
    int res = 0;
    while (x >>= 1)
        res++;
    return res;
}

int isPowerof2(int x) {
    return x && !(x & (x - 1));
}

int lastSetBit(int n) {
    return log2(n & -n)+1;
}
