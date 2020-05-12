tags: math, prime numbers, primality test, number theory, prime factorization, Primality tests, Asymmetric-key algorithms
# Prime Numbers
* https://en.wikipedia.org/wiki/Prime_number

## Trial division
* https://en.wikipedia.org/wiki/Primality_test
* https://en.wikipedia.org/wiki/Trial_division
This is the simplest method. Trial division was first described by Fibonacci in his book Liber Abaci.

To test if n is prime

Solution 1:
- test whether m evenly divides n
- ignore all even number greater than 2
- test until sqroot(n)

Solution 2:
- test whether number 2, 3, 6k+-1 untill sqroot(n) are evenly divisible by m (because all primes > 3 are of the form 6k+-1)

Pseudocode:
```
function is_prime(n)
    if n ≤ 3 then
        return n > 1
    else if n mod 2 = 0 or n mod 3 = 0
        return false

    let i ← 5

    while i × i ≤ n do
        if n mod i = 0 or n mod (i + 2) = 0
            return false
        i ← i + 6

    return true
```


Solution 3 (sieve_of_eratosthenes):
* primes are of the form: c# * k + i for i < c# where c# are c primorial.
Example:
```
c = 6
c# = 2 * 3 * 5 = 30

30*k + i for i = 1,7,11,13,17,19,23,29
i < 30, such that gdc(i,30) = 1

30 * 2 + 1 = 31
30 * 3 + 1 = 91

30 * 2 + 7 = 67
30 * 2 + 7 = 67

```
Primorial (denoted as Pn#) is product of first n prime numbers. Primorial of a number is similar to factorial of a number. In primorial, not all the natural numbers get multiplied only prime numbers are multiplied to calculate the primorial of a number. It is denoted with P#.
* https://stackoverflow.com/questions/51443158/primorial-of-a-number
* https://en.wikipedia.org/wiki/Primorial#Definition_for_natural_numbers
Example 1:
```
Input: n = 3
Output: 30 
Priomorial = 2 * 3 * 5 = 30
6# = 2 * 3 * 5 = 30
```
Example 2:
```
Input: n = 5
Output: 2310
Primorial = 2 * 3 * 5 * 7 * 11 
12# = 2 * 3 * 5 * 7 * 11 = 2310
```
- 

Exercises: 
* Prime Numbers. Print all prime numbers less than 1000. "" Category: number, array   
  - Solution 1. "Sieve of Eratosthenes. Origin 300BC" [src](#b-alg-c-segw) TODO: implement with constraints of input array size, other wize a stack smash and buffer overflow is guaranteed. (TAGS: array, math, prime, numbers)
* https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes


Sources: 
* https://en.wikipedia.org/wiki/Primality_test
* https://en.wikipedia.org/wiki/Integer_factorization

* Knuth, Donald (1997). "section 4.5.4". The Art of Computer Programming. Volume 2: Seminumerical Algorithms (Third ed.). Addison–Wesley. pp. 391–396.
* Thomas H. Cormen; Charles E. Leiserson; Ronald L. Rivest; Clifford Stein (2001). "Section 31.8: Primality testing". Introduction to Algorithms (Third ed.). MIT Press and McGraw–Hill. pp. 965.
