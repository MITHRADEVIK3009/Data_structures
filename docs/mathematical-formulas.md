# Mathematical Formulas & Limits Reference

## Overview

This document provides a comprehensive reference for mathematical formulas, limits, and constraints commonly encountered in competitive programming and LeetCode problems.

## Number Theory

### Prime Numbers
- **Prime Check**: A number n is prime if it has no divisors other than 1 and itself
- **Sieve of Eratosthenes**: Find all primes up to n in O(n log log n)
- **Prime Factorization**: Any number can be expressed as product of primes
- **Goldbach's Conjecture**: Every even integer > 2 can be expressed as sum of two primes

### GCD & LCM
```cpp
// Greatest Common Divisor
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Least Common Multiple
int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

// Extended GCD (Bezout's Identity)
int extendedGcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    int x1, y1;
    int g = extendedGcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}
```

### Modular Arithmetic
```cpp
// Modular Exponentiation
long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

// Modular Inverse (Fermat's Little Theorem)
long long modInverse(long long a, long long mod) {
    return power(a, mod - 2, mod);
}

// Modular Factorial
long long factorial(int n, long long mod) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result = (result * i) % mod;
    }
    return result;
}
```

## Combinatorics

### Permutations
- **nPr = n! / (n-r)!**: Number of ways to arrange r objects from n objects
- **n!**: Number of ways to arrange n objects
- **Circular Permutations**: (n-1)! for n objects in a circle

### Combinations
- **nCr = n! / (r! × (n-r)!)**: Number of ways to choose r objects from n objects
- **Pascal's Triangle**: nCr = (n-1)C(r-1) + (n-1)Cr

```cpp
// Combination calculation
long long combination(int n, int r, long long mod) {
    if (r > n) return 0;
    if (r == 0 || r == n) return 1;
    
    long long result = 1;
    for (int i = 0; i < r; i++) {
        result = (result * (n - i)) % mod;
        result = (result * modInverse(i + 1, mod)) % mod;
    }
    return result;
}
```

### Catalan Numbers
- **Formula**: C(n) = (2n)! / ((n+1)! × n!)
- **Recurrence**: C(n) = Σ(C(i) × C(n-1-i)) for i = 0 to n-1
- **Applications**: Binary trees, parentheses matching, polygon triangulation

```cpp
// Catalan number calculation
long long catalan(int n, long long mod) {
    return combination(2 * n, n, mod) * modInverse(n + 1, mod) % mod;
}
```

## Fibonacci & Sequences

### Fibonacci Sequence
- **F(0) = 0, F(1) = 1, F(n) = F(n-1) + F(n-2)**
- **Binet's Formula**: F(n) = (φⁿ - ψⁿ) / √5, where φ = (1+√5)/2, ψ = (1-√5)/2
- **Matrix Exponentiation**: O(log n) time complexity

```cpp
// Matrix exponentiation for Fibonacci
vector<vector<long long>> multiply(vector<vector<long long>> a, vector<vector<long long>> b, long long mod) {
    vector<vector<long long>> result(2, vector<long long>(2));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % mod;
            }
        }
    }
    return result;
}

long long fibonacci(int n, long long mod) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    vector<vector<long long>> base = {{1, 1}, {1, 0}};
    vector<vector<long long>> result = {{1, 0}, {0, 1}};
    
    n--;
    while (n > 0) {
        if (n & 1) result = multiply(result, base, mod);
        base = multiply(base, base, mod);
        n >>= 1;
    }
    
    return result[0][0];
}
```

## Geometric Formulas

### 2D Geometry
- **Distance between points**: d = √((x₂-x₁)² + (y₂-y₁)²)
- **Area of triangle**: A = ½ × base × height
- **Area using coordinates**: A = ½|(x₁(y₂-y₃) + x₂(y₃-y₁) + x₃(y₁-y₂))|
- **Circle area**: A = πr²
- **Circle circumference**: C = 2πr

### 3D Geometry
- **Distance in 3D**: d = √((x₂-x₁)² + (y₂-y₁)² + (z₂-z₁)²)
- **Volume of sphere**: V = (4/3)πr³
- **Surface area of sphere**: A = 4πr²

## Probability & Statistics

### Basic Probability
- **P(A)**: Probability of event A
- **P(A ∪ B) = P(A) + P(B) - P(A ∩ B)**: Union of events
- **P(A ∩ B) = P(A) × P(B)**: Independent events
- **Conditional Probability**: P(A|B) = P(A ∩ B) / P(B)

### Expected Value
- **E[X] = Σ(x × P(x))**: Expected value of random variable X
- **Linearity**: E[aX + bY] = aE[X] + bE[Y]

## Limits & Constraints

### Common Limits in Competitive Programming

#### Array/List Constraints
- **Maximum array size**: 10⁵ to 10⁶ elements
- **Maximum string length**: 10⁴ to 10⁵ characters
- **Maximum matrix size**: 1000 × 1000

#### Integer Limits
- **int**: -2³¹ to 2³¹-1 (-2,147,483,648 to 2,147,483,647)
- **long long**: -2⁶³ to 2⁶³-1
- **unsigned int**: 0 to 2³²-1 (0 to 4,294,967,295)
- **unsigned long long**: 0 to 2⁶⁴-1

#### Time Complexity Limits
- **O(1)**: Constant time - any input size
- **O(log n)**: Logarithmic - up to 10¹⁸ elements
- **O(n)**: Linear - up to 10⁶ elements
- **O(n log n)**: Linearithmic - up to 10⁵ elements
- **O(n²)**: Quadratic - up to 10³ elements
- **O(n³)**: Cubic - up to 500 elements
- **O(2ⁿ)**: Exponential - up to 20 elements
- **O(n!)**: Factorial - up to 10 elements

#### Space Complexity Limits
- **O(1)**: Constant space - any input size
- **O(n)**: Linear space - up to 10⁶ elements
- **O(n²)**: Quadratic space - up to 10³ elements

### Problem-Specific Limits

#### Graph Problems
- **Vertices**: 1 ≤ V ≤ 10⁵
- **Edges**: 0 ≤ E ≤ 2 × 10⁵
- **Weight range**: -10⁹ ≤ weight ≤ 10⁹

#### Tree Problems
- **Nodes**: 1 ≤ N ≤ 10⁵
- **Height**: 1 ≤ height ≤ N

#### String Problems
- **Length**: 1 ≤ |s| ≤ 10⁵
- **Character set**: ASCII (0-127) or lowercase letters (a-z)

#### Dynamic Programming
- **State space**: 1 ≤ states ≤ 10⁶
- **Transition time**: O(1) to O(n)

## Mathematical Constants

### Important Constants
- **π (pi)**: 3.141592653589793
- **e (Euler's number)**: 2.718281828459045
- **φ (Golden ratio)**: 1.618033988749895
- **√2**: 1.414213562373095
- **√3**: 1.732050807568877

### Precision Limits
- **float**: ~7 decimal digits precision
- **double**: ~15 decimal digits precision
- **long double**: ~18 decimal digits precision

## Bit Manipulation Formulas

### Bit Operations
- **Set bit**: n | (1 << i)
- **Clear bit**: n & ~(1 << i)
- **Toggle bit**: n ^ (1 << i)
- **Check bit**: (n >> i) & 1
- **Count set bits**: __builtin_popcount(n)

### Bit Tricks
- **n & (n-1)**: Removes the rightmost set bit
- **n & (-n)**: Isolates the rightmost set bit
- **n | (n-1)**: Sets all bits after the rightmost set bit
- **~n & (n+1)**: Isolates the rightmost unset bit

## Logarithmic Formulas

### Logarithm Properties
- **log(ab) = log(a) + log(b)**
- **log(a/b) = log(a) - log(b)**
- **log(aⁿ) = n × log(a)**
- **logₐ(b) = log(b) / log(a)**: Change of base

### Common Logarithms
- **log₂(10) ≈ 3.3219**
- **log₁₀(2) ≈ 0.3010**
- **ln(2) ≈ 0.6931**
- **ln(10) ≈ 2.3026**

## Series & Summations

### Arithmetic Series
- **Sum**: S = n(a₁ + aₙ)/2
- **General term**: aₙ = a₁ + (n-1)d

### Geometric Series
- **Sum**: S = a₁(1 - rⁿ)/(1 - r) for r ≠ 1
- **Infinite sum**: S = a₁/(1 - r) for |r| < 1

### Common Summations
- **1 + 2 + 3 + ... + n = n(n+1)/2**
- **1² + 2² + 3² + ... + n² = n(n+1)(2n+1)/6**
- **1³ + 2³ + 3³ + ... + n³ = (n(n+1)/2)²**
- **1 + 3 + 5 + ... + (2n-1) = n²**

## Matrix Operations

### Matrix Multiplication
```cpp
vector<vector<long long>> multiply(vector<vector<long long>> a, vector<vector<long long>> b, long long mod) {
    int n = a.size();
    vector<vector<long long>> result(n, vector<long long>(n));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % mod;
            }
        }
    }
    return result;
}
```

### Matrix Exponentiation
```cpp
vector<vector<long long>> matrixPower(vector<vector<long long>> base, long long exp, long long mod) {
    int n = base.size();
    vector<vector<long long>> result(n, vector<long long>(n));
    
    // Initialize as identity matrix
    for (int i = 0; i < n; i++) {
        result[i][i] = 1;
    }
    
    while (exp > 0) {
        if (exp & 1) {
            result = multiply(result, base, mod);
        }
        base = multiply(base, base, mod);
        exp >>= 1;
    }
    
    return result;
}
```

## Approximation Formulas

### Stirling's Approximation
- **n! ≈ √(2πn) × (n/e)ⁿ**
- **log(n!) ≈ n log(n) - n + 0.5 log(2πn)**

### Harmonic Series
- **Hₙ = 1 + 1/2 + 1/3 + ... + 1/n ≈ ln(n) + γ**
- **γ (Euler-Mascheroni constant) ≈ 0.5772**

## Problem-Solving Formulas

### Sliding Window
- **Window size**: right - left + 1
- **Valid window condition**: Check constraints
- **Window expansion**: right++
- **Window contraction**: left++

### Two Pointers
- **Distance between pointers**: right - left
- **Sum of elements**: Use prefix sum or cumulative sum
- **Product of elements**: Handle overflow with modular arithmetic

### Binary Search
- **Midpoint calculation**: mid = left + (right - left) / 2
- **Search space reduction**: O(log n) iterations
- **Lower bound**: First position where condition is true
- **Upper bound**: Last position where condition is true

### Dynamic Programming
- **State transition**: dp[i] = f(dp[i-1], dp[i-2], ...)
- **Base cases**: dp[0], dp[1], etc.
- **Space optimization**: Use rolling array or variables

## Common Mathematical Patterns

### Triangular Numbers
- **T(n) = n(n+1)/2**
- **Applications**: Sum of first n natural numbers

### Square Numbers
- **S(n) = n²**
- **Sum of first n squares**: n(n+1)(2n+1)/6

### Cubic Numbers
- **C(n) = n³**
- **Sum of first n cubes**: (n(n+1)/2)²

### Fibonacci Properties
- **F(n) × F(n+1) = F(2n+1) - (-1)ⁿ**
- **F(n)² + F(n+1)² = F(2n+1)**
- **F(n+k) = F(k) × F(n+1) + F(k-1) × F(n)**

## Optimization Formulas

### Greedy Algorithms
- **Exchange argument**: Prove local optimal choice leads to global optimum
- **Greedy choice property**: Make locally optimal choice at each step
- **Optimal substructure**: Optimal solution contains optimal solutions to subproblems

### Approximation Algorithms
- **Approximation ratio**: ALG/OPT ≤ α
- **PTAS**: Polynomial Time Approximation Scheme
- **FPTAS**: Fully Polynomial Time Approximation Scheme

## Error Handling

### Overflow Prevention
```cpp
// Safe addition
long long safeAdd(long long a, long long b, long long mod) {
    return ((a % mod) + (b % mod)) % mod;
}

// Safe multiplication
long long safeMul(long long a, long long b, long long mod) {
    return ((a % mod) * (b % mod)) % mod;
}

// Safe power
long long safePower(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}
```

### Precision Handling
```cpp
// Compare floating point numbers
bool isEqual(double a, double b, double epsilon = 1e-9) {
    return abs(a - b) < epsilon;
}

// Round to nearest integer
int roundToInt(double x) {
    return (int)(x + 0.5);
}
```

## Quick Reference Tables

### Time Complexity Limits
| Complexity | Max Input Size | Typical Use Case |
|------------|----------------|------------------|
| O(1) | Any | Hash table lookup |
| O(log n) | 10¹⁸ | Binary search |
| O(n) | 10⁶ | Linear scan |
| O(n log n) | 10⁵ | Sorting |
| O(n²) | 10³ | Nested loops |
| O(n³) | 500 | Matrix operations |
| O(2ⁿ) | 20 | Subset generation |
| O(n!) | 10 | Permutation |

### Space Complexity Limits
| Complexity | Max Input Size | Typical Use Case |
|------------|----------------|------------------|
| O(1) | Any | Variables only |
| O(n) | 10⁶ | Array/vector |
| O(n²) | 10³ | 2D matrix |
| O(log n) | 10¹⁸ | Recursion depth |

### Common Modulo Values
- **10⁹ + 7**: Most common in competitive programming
- **10⁹ + 9**: Alternative prime modulo
- **998244353**: FFT-friendly modulo
- **2³¹ - 1**: Mersenne prime

This comprehensive reference covers all the mathematical formulas, limits, and constraints you'll encounter in your DSA problem-solving journey. Keep it handy for quick reference during contests and practice sessions!

