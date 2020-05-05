# Stack
## Pushdown Stack
Implemented: push, pop, top, size, isempty. 

[src1](#alg_java_gtg)

## Real World Application
* Arithmetic expression evaluation. An important application of stacks is in parsing. For example, a compiler must parse arithmetic expressions written using infix notation. For example the following infix expression evaluates to 212.
``` 
( 2 + ( ( 3 + 4 ) * ( 5 * 6 ) ) )
```
* Function-call abstraction. Most programs use stacks implicitly because they support a natural way to implement function calls, as follows: at any point during the execution of a function, define its state to be the values of all of its variables and a pointer to the next instruction to be executed. The natural way to implement the function-call abstraction is to use a stack. To call a function, push the state on a stack. To return from a function call, pop the state from the stack to restore all variables to their values before the function call and resume execution at the next instruction to be executed. 

## Problems / Exercises
* Evaluate arithmetic expressions from reverse Polish notation/postfix. [src1](#b-alg-c-segw) page 26
* [src](#link3)

## Sources
* [src1](#alg_java_gtg) page 238 
* [src2](#b-alg-c-segw) page 30
* <a name="link1" href="https://introcs.cs.princeton.edu/java/43stack/">link1</a>
