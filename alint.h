// Library "alint" - Integer of arbitray length
// alint is a nonnegative integer of arbitrary length (not more than 1000 decimal digits).
// The integer is stored as a null terminated string of ASCII characters.
// String of decimal digits ('0' thru '9') are stored in big endian style.
// That is, the most significant digit is at the head of the string.
// Eg: Integer 25 is stored in str as '2' at str[0], '5' at str[1], and null char at str[2].

// DO NOT modify this header file.
// Your deliverable is the implementation file.
// The implementation file has the definition of the functions decalred here.
// You can write some of your own helper functions, keep them "static".
// Use the sample test file(that has the main function) to test your implementation.

// To generate your own testcases, you can use https://www.omnicalculator.com/math

// Returns the sum of two alints.
char* alint_add(const char* alint1, const char* alint2);

// Returns the comparison value of two alints.
// Returns 0 when both are equal.
// Returns +1 when alint1 is greater, and -1 when alint2 is greater.
int alint_compare(const char* alint1, const char* alint2);

// Returns the difference (obviously, nonnegative) of two alints.
char* alint_diff(const char* alint1, const char* alint2);

// Returns the product of two alints.
char* alint_multiply(const char* alint1, const char* alint2);

// Returns alint1 mod alint2
// The mod value should be in the range [0, alint2 - 1].
// alint2 > 1
// Implement a O(log alint1) time taking algorithm.
// O(alint1 / alint2) time taking algorithm may exceed time limit.
// O(alint1 / alint2) algorithm may repeatedly subtract alint2 from alint1.
// That will take alint1/alint2 iterations.
// You need to design a O(log alint1) time taking algorithm.
// Generate your own testcases at https://www.omnicalculator.com/math/modulo
char* alint_mod(const char* alint1, const char* alint2);

// Returns alint1 ^ alint2.
// Let 0 ^ n = 0, where n is an alint.
// Implement a O(log n) alint multiplications algorithm.
// 2^3000 has less than 1000 decimal digits. 3000 alint multiplications may exceed time limit.
char* alint_pow(const char* alint1, unsigned int n);

// Returns Greatest Common Devisor of alint1 and alint2.
// Let GCD be "0" if both alint1 and alint2 are "0" even though it is undefined, mathematically.
// Use Euclid's theorem to not exceed the time limit.
char* alint_gcd(const char* alint1, const char* alint2);

// Returns nth fibonacci number.
// alint_fibonacci(0) = alint "0".
// alint_fibonacci(1) = alint "1".
char* alint_fibonacci(unsigned int n);

// Returns the factorial of n.
char* alint_factorial(unsigned int n);

// Returns the Binomial Coefficient C(n,k).
// 0 <= k <= n
// C(n,k) < 10^1000 because the returning value is expected to be less than 10^1000.
// Use the Pascal's identity C(n,k) = C(n-1,k) + C(n-1,k-1)
// Make sure the intermediate alint values do not cross C(n,k).
// Use Dynamic Programming. Use extra space of not more than O(k) number of alints. Do not allocate the whole O(nk) DP table.
// Don't let C(1000,900) take more time than C(1000,500). Time limit may exceed otherwise.
char* alint_bincoeff(unsigned int n, unsigned int k);

// Returns the offset of the largest alint in the array.
// Return the smallest offset if there are multiple occurrences.
// 1 <= n <= 1000
int alint_max(char **arr, int n);

// Returns the offset of the smallest alint in the array.
// Return the smallest offset if there are multiple occurrences.
// 1 <= n <= 1000
int alint_min(char **arr, int n);

// Returns the offset of the first occurrence of the key alint in the array.
// Returns -1 if the key is not found.
// 1 <= n <= 1000
int alint_search(char **arr, int n, const char* key);

// Returns the offset of the first occurrence of the key alint in the SORTED array.
// Returns -1 if the key is not found.
// The array is sorted in nondecreasing order.
// 1 <= n <= 1000
// The implementation should be a O(log n) algorithm.
int alint_binsearch(char **arr, int n, const char* key);

// Sorts the array of n alints.
// 1 <= n <= 1000
// The implementation should be a O(n log n) algorithm.
void alint_sort(char **arr, int n);

// Coin-Row Problem - Dynamic Programming Solution
// There is a row of n coins whose values are some positive integers C[0..n-1].
// The goal is to pick up the maximum amount of money subject to the constraint that
// no two coins adjacent in the initial row can be picked up.
// 1 <= n <= 1000
// The implementation should be O(n) time and O(1) extra space even though the DP table may be of O(n) size.
// Eg: Coins = [10, 2, 4, 6, 3, 9, 5] returns 25
char* coin_row_problem(char **arr, int n);
