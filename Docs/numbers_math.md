# Fibonacci Numbers 
tags: recursion, sequence

Definition:
Each number is the sum of the two preceding ones, starting from 0 and 1.

First ten:
|0|1|2|3|4|5|6|7|8|9|10|
|--|--|--|--|--|--|--|--|--|--|--|
|0|1|1|2|3|5|8|13|21|34|55|89|

[src](#wiki_fibonacci)

## Applications
* The Fibonacci numbers are important in the computational run-time analysis of Euclid's algorithm to determine the greatest common divisor of two integers: the worst case input for this algorithm is a pair of consecutive Fibonacci numbers. [src](#book_d_knuth1) page 343
)
* Fibonacci numbers are used by some pseudorandom number generators.
* Fibonacci numbers are used in a polyphase version of the merge sort algorithm in which an unsorted list is divided into two lists whose lengths correspond to sequential Fibonacci numbers – by dividing the list so that the two parts have lengths in the approximate proportion φ. A tape-drive implementation of the polyphase merge sort was described in The Art of Computer Programming.
* Fibonacci numbers arise in the analysis of the Fibonacci heap data structure.
* The Fibonacci cube is an undirected graph with a Fibonacci number of nodes that has been proposed as a network topology for parallel computing.
* A one-dimensional optimization method, called the Fibonacci search technique, uses Fibonacci numbers.[24]
* The Fibonacci number series is used for optional lossy compression in the IFF 8SVX audio file format used on Amiga computers. The number series compands the original audio wave similar to logarithmic methods such as μ-law.
[src](#wiki_fibonacci)

## Implementation / Solution



* https://medium.com/@syedtousifahmed/fibonacci-iterative-vs-recursive-5182d7783055

# Euclidean Algorithm / GCD (Greatest Common Divisor)
tag
Reduce a given fraction to its lowest terms "fr_low_terms("
Is based on gcd.

## Implementation / Solution
1. Euclidean algorithm by subtraction. Classic - Origin 300BC. 
  if u > v, then gcd of u and v, is same as gcd of v and u-v.  
  If using classic: count of steps for _ _ is 11, and for _ _ is 58.  
2. Modulo: 
  gcd of u and v is same as gcd of v and u % v.  
  If using modulo: count of steps for _ _ is 4. And for _ _ is 7.  
[src](#b-alg-c-segw)  
* https://codility.com/media/train/10-Gcd.pdf

# Convert a decimal to binary 
"d_to_b"

## Implementation / Solution
Algorithm:
  1. Store the remainder when the number is divided by 2 in an array.
  2. Divide the number by 2
  3. Repeat the above two steps until the number is greater than zero.
  4. Print the array in reverse order now.
  [src](https://www.geeksforgeeks.org/program-decimal-binary-conversion/)


## Sources
* <a name="book_d_knuth1"></a>[book] Knuth, Donald E (1997), The Art of Computer Programming, 1: Fundamental Algorithms (3rd ed.)
* <a name="wiki_fibonacci"></a>[online] https://en.wikipedia.org/wiki/Fibonacci_number
