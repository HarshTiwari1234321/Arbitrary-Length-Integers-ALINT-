# ALINT - Arbitrary Length Integers
Big Integer Library for C langauge for operations on integer exceeding 20 digit length.

Introduction:
An ALINT is a non negative integer of arbitrary length, but in case of my implementation it has a limit of 1000 digits. Alint is stored as a null terminated string of ASCII format in a big endian format for convenience sake.

The difference between this method of storing numbers and regular integers is the limit of storage. All integer datatypes have a limit within which the numbers must be present to store it in those datatypes. alint is more like a custom datatype which can store data limitlessly and can include special characters with special meanings in order to maintain compression. Eg : We could use '1e07' as exponential raised to the power seven and have an internal conversion of it.

Applications:
In case of storing amount values in a column and need to maintain the commas in between the integer values (10,000) you can use string column, as integer ignores commas.
Storing in strings is convenient when we intend to transfer these alints across a network in a TCP connection which only allows transfer of strings / JSON objects.


Approaches:
1) alint_add: Used the basic school addition technique by  iterating both the strings backwards ie from units place onwards till the minimum one of them lengthwise while storing the sum%10 and transferring the sum/10 further as carry and went on till we iterate the maximum one of them while handling the carry appropratiely. 

2) alint_compare: Used length as a comparison metric for alints of unequal length and returned 1 if first one was longer or -1 if second was longer. For the case where both were equal in length, took difference for each i where 0<i<len(alint)-1 and returned 1 if first one was greater, -1 if second one was greater. If alints pass all the above cases, return 0.

3) alint_diff: Used compare function to set the first one as greater one for convenience. Starting from the units place subtracted position wise and stored the result while propagating the carry if we get a negative result at any point. 

4) alint_multiply: First we check if any of the numbers is 0. If it is,then the product is 0. If not we start from last digit of second number multiply it with first number. Then we multiply second digit of second number with first number, and so on. We add all these multiplications. While adding, we put i-th multiplication shifted.We remove any 0s in the starting. 

5) alint_mod: We first call the compare function.If the first number is smaller then we return the first number.If both are equal we return 0.
We then repeatedly subtact the smaller number from the larger number until it becomes less than the smaller number.This number is the mod and is returned.

6) alint_pow: Used the idea -> a^n = (a^2)^n/2 if 'n' is even and a^n = (a^2)^n/2 * a in case 'n' is odd. Iterate through the number 'n' as many times depending on the condition calculated above and multiply the value of alint1 to the result variable which contains an initial value of "1" and we use the alint_multiply(alint1, ans) and repeatedly store it in ans only.



7) alint_gcd: Used euclid's method for gcd(a,b). In this method, gcd(a,b)=gcd(b,a%b) is done repeatedly until the second parameter, b equals 0. I used the modulus operator from alint_mod for a%b.



8) alint_fibonacci: Used the iterative method of generating fiboanacci numbers by setting initial values a="0", b="1" and returned 'a' and 'b' for n==0 and n==1 respectively. If 'n'>=2 use a variable to hold sum of 'a' and 'b' using c=alint_add(a,b) and move 'a' and 'b' till we reach the nth fibonacci number.

9) alint_factorial: Used the basic definition of factorial for this. Iterated from n to 1 and kept multiplying the results into a result alint using alint_multiply and reducing value of the alint iterator by one for each iteration using alint_diff until it reached 1.

10) alint_bincoeff: Used the Pascal's identity C(n,k) = C(n-1,k) + C(n-1,k-1) and created a DP table of size k+1 and iterated through all the n's from 1 to n and calculated value of nCk while iterating inwards from min(i,k) to 1 and using Pascal's identity here. Used alint_add(C(n-1,k) , C(n-1,k-1)) to perform this addition.

11) alint_max: Set the first value of the array as maximum and iterated through the entire array while comparing the first value with the others using alint_compare and updated the maximum value as we find a new maximum. 

12) alint_min: Set the first value of the array as minimum and iterated through the entire array while comparing the first value with the others using alint_compare and updated the minimum value as we find a new minimum. 

13) alint_search: Used linear search to iterate through the entire while comparing arr[i] with key and returned whenever the result of alint_compare(arr[i], key)==0. If none of the elements match, returned a -1.

14) alint_binsearch: Used the regular iterative method of binary search on the array and compared the key to the arr[mid] element using the alint_compare method and returned the offset if it gave result as 0. If result was 1 looked for key in left half of array. If -1 looked in right half . Returned -1 if none of the keys match the array elements.

15) alint_sort: Used quick sort technique.Created static functions for quicksort and partition.

16) alint_coin_row_problem: We maintain a DP table of size n+1 strings where each element in DP table tells us the maximum amount if there were i coins and set the DP[0]='0' as there is no way to select coins fi there aren't any and DP[1] = arr[0] if there is just a coin and DP[2] = max(arr[0],arr[1]). Then for each i from 3 to n, we calculate DP[i] by recurrence, DP[i] = max(DP[i-2]+arr[i],DP[i-1]). To implement the max function, we use alint_compare and return what is necassary. Finally the result is stored in DP[n] which is returned.

Future Work:
1) We could add the functionality of division which could be useful.
2) Bitwise operations like AND, OR, NOT, XOR
3) Factorization of alints

If you had no restrictions, how would you implement a library to handle integers of arbitrary length?
We could use an approach where we use an array to store individual digits of the alint and perform operations on it.
An alternative would be to use a linked list as a storage mechanism for alint. Each digit of an alint could be a node of the linked list. We could also attach a field that could hold the sign of the number in the head node.


