# Notes

These are notes for University of Bath Online MSc Principles of Programming Week
2: Functions and Parameters.

This week all code is in C.

## Lesson 1

[Code Exercise on replit](https://replit.com/@rej696/Week2Exercise1#main.c)

### printf and Format Specifiers
- %d : int
- %f : float/double
- %c : char
- %u : unsigned int (decimal)
- %x/%X : unsigned int as Hex (upper or lower case)
- %o : unsigned int (octal)
- %% : print % sign
- \n : newline
- \\ : print \ sign (\ is escape character)

### Arithmetic operators
- = : assignment
- + : addition
- - : subtraction
- * : multiply
- / : divide

Arithmetic operators have precidence, using BIDMAS, and are performed from left
to right.

### Math Library
C has a math library with common mathematical functions. for example the
`sqrt()` function which calculates a square root of its input. e.g:

```c
#include <math.h>

int main() {
  double a = sqrt(4.0);
  return 0;
}
```

The sqrt function has a prototype in the `math.h` header.
```c
double sqrt(double n);
```

the prototype allows the main code to use the function, and when the code is
compiled the linker can connect that function prototype to its
implementation/object code in the `math.o` file.

### Arguments and Parameters
A parameter is what appears in the definition of the function.

An argument is the instance passed to the function at runtime.

These definitions are outlined in the following (python) code block:
```python
def function(parameter1: int, parameter2: int) -> int:
  return parameter1 + parameter2

def main():
  argument1 = 5
  argument2 = 10
  assert function(parameter1=argument1, parameter2=argument2) == 15
```

a more detailed explanation can be found
[here](https://www.baeldung.com/cs/argument-vs-parameter).

### Types
#### Describing type systems

[A good stack overflow post on type systems](https://stackoverflow.com/questions/34287668/is-haskell-a-strongly-typed-programming-language#34288753)

##### Statically Typed Languages
These have types fixed at compile time. Most statically typed languages require
variables to be declared with their types before they can be used.

Examples of these include C, Java, Rust, Ada...

Some statically typed languages have what is called type inference. A good
example of this is Haskell. Haskell (most of the time) does not require the
programmer to define any types, the compiler can do that for them!

##### Dynamically Typed Languages
These have types which are discovered at exectution time - the opposite of
statically typed.

Examples of these include Python, Javascript, Lisps such as Clojure, Ruby...

Some dynamically typed languages can emulate the feel of statically typed
languages. As you can see in the python code block in "Arguments and Parameters"
python has a idiom known as type hinting. This allows types in python to be
specified in the code to increase readibility and understanding, However the
interpreter ignores these hints and the type system remains dynamic.
Some modern linters can read these hints and
alert the programmer to any inconsitencies between types.

Furthermore, Python uses what is known as duck typing. Essentially, if it walks
like a duck and quacks like a duck, its a duck!

##### Strongly Typed Language
A strongly typed language is where types are always enforced. You cannot treat
an int like a string or float and vice versa.

Examples include Java and Python.

Some languages like Python and C are considered strongly typed, but allow for
implicit conversions. For example in python, `x = float * int` is allowable, the
variable x will be implicitly converted into a float.

However, languages like Ada do not allow this, and require all type conversions to be
explicit. Ada calls this "very strong typing". This may seems annoying at first,
but it makes the code much more understandable, as the compiler isn't doing any
sort of type trickery under the hood. This can prevent some very hard to find
errors.
[Ada Strong
Typing](https://learn.adacore.com/courses/intro-to-ada/chapters/strongly_typed_language.html#strong-typing)

##### Weakly Typed Language
A weakly typed language is where types may be ignored - the opposite of strongly
typed.

Examples include Perl and VBScript.

Additionally, even though C has a static and seemingly strong type system. Often
it can be considered to have weak typing due to its use of pointers and the
ability to reinterpret memory. A pointer in C is a memory address, and so the
value held by the memory address can be reinterpreted as a different type.
```c
char * myChar;

int myInt = 65;

myChar = (char *)&myInt;

printf("Character is : %c\n", *myChar);
```
This example will take the bits held in myInt (65) and reinterpret those bits as
a char (the value 65 is 'A' in Ascii/UTF-8)

#### Type Conversion
Implicit conversion is called type coercion

Explicit conversion is called type casting

## Lesson 2

[Code Exercise on Replit](https://replit.com/@rej696/Week2Exercise2#main.c)

### Scope
Variables are declared in a given scope, in C this is determined by braces `{}`.
- Local variables are declared within a certain scope, such as a function, loop, or other code block
- Global variables are declared outside a certain scope.

The following outlines the use of scope in C.
```c
int myGlobal = 0;

int main() {
  int myLocal = 1;
  {
    int myInnerScope = 2;
    int myInnerResult = myGlobal + myLocal + myInnerScope;
  }
  int myLocalResul = myGloabl + myLocal;
}
```

As well as global scope within a code file, in some languages like python the
file is involved with scoping. (A python file is known as a module containing
code within the scope of that module).

Additionally, the directory structure of a code project can have an impact on
scoping. A python directory with an `__init__.py` file can be used as a package
by other files/packages in the project, and all the modules in that package are
in the package scope
```
project_dir
  - __init__.py
  - package1
    - __init__.py
    - module1.py
    - module2.py
  - package2
    - __init.py
    - modulex.py
    - moduley.py
  - module.py
```

Different languages have other different ways of using scope. C++ for example
has namespaces, which allow the same scope to be accessed in different code
files.

In object oriented programming, often the scope of a variable/attribute/function/method is the
class that it is related to.

## Lesson 3

### Booleans
Booleans are data types with one of two data types, usually True or False

### Logical Operators in C
Logical Operators connect booleans together to identify whether a statement is True or False.

- && : and
- || : or
- !  : not

### Bitwise Operators in C
Bitwise operators compare each bit of the two variables individually to produce
an output.
- & : bitwise and
- | : bitwise or
- ! : bitwise not

For example
```c 
// 5 is 0000 0101 in binary
int x = 5;

// 11 is 0000 1011 in binary
int y = 11;

// x & y is 0000 0001 in binary, so prints a value of 1
printf("bitwise and: %d", x & y);

// x | y is 0000 1111 in binary, so prints a value of 15
printf("bitwise or: %d", x | y);

// !x is 1111 1010 in binary, so should print a value of 250.
// Note that this may not be the case depending on the size of the int used
printf("bitwise not: %d", x!);
```

### Conditional Operators
Many languages include `true` and `false`, or varients of them, as built-in
types.

In C, booleans are represented as integers as either 1 (true) or 0 (false)

The following conditional operators output 1 or 0 depending on the truthyness
of the condition
```
>  : greater than
<  : less than
>= : greater than or equal to
<= : less than or equal to
== : equality
!= : not equal
```

### Control Flow

If statment example
```c
int x = 15;
if (x >= 15) {
  printf("Amazing!\n");
} else if (x >= 10) {
  printf("Good Job!\n");
} else {
  printf("Try harder next time\n");
}
```

### stdbool.h
C has a standard bool library which allows you to use boolean literals (`true`,
`false`)

standard bool does not have a format specifier for printf

```c
#include <stdbool.h>

if (x > 3) {
  return true;
} else {
  return false;
}
```

### Ternary Operators
```
int x = <boolean expression> ? <true path> : <false path>;
```

## Lesson 4

### Recursion
Functions can call themselves. This is known as recursion. Functions which
perform recursion are recursive.

#### The Base Case
All correctly constructed recursive functions have a base case that can be
solved without recursion.

If a recursive function does not reach a base case it is called infinite
recursion, and eventually the program will crash due to consuming too much of
the finite memory available.

#### Structure
Recursive functions are normally structured such that:
```
If base case reached:
  Solve
Else:
  Recursively call function
```

#### Problem Size
The number of reduction steps a problem is away from the base case is the
problem size.

#### Defensive programming
This is the technique of protecting our code against unwanted inputs, such that
all inputs can be handled by the function without error.

### Stacks
Stacks are a LIFO data structure.

Every time you call a function, memory is allocated to the call stack to
parameters and local variables

#### Recursive Fibonacci
```c
/* The Fibonacci Sequence*/

int fibonacci (int n)
{
    if(n == 0)
    {
    return 0;
    } else if(n == 1)
    {
    return 1;

    }else
    {
    return fibonacci(n-1) + fibonacci(n-2);
    }
}
```

This recursive implementation of the fibonacci sequence has two base cases, as
there are two inputs for which the function does not recurse.

## Lesson 5

### Iteration

Iteration is often faster than recursion as you don't need to maintain a call
stack, and so does not use as much memory.

#### While loop
```c
while (condition is true) {
  statement1;
  statement2;
}

int count = 0;
while (count < 10) {
  count = count + 1;
}
```

To avoid infinite loops, make sure the condition eventually becomes false.

#### Do While loop
C has do while loops, where the condition is checked after the body of the loop
is executed
```c
int count = 0;
do {
  count = count + 1;
} while (count < 10);
```

#### For loops

```
for (initialisation; termination; increment) {
  statments;
}
```

you can declare the increment variable before the loop or in the initialisation
section
```c
// variable declared in initialisation section
for (int i = 0; i < 10; i++) {
  printf("%d\n", i);
}

// variable declared before loop
int i;
for (i = 0; i < 10; i++) {
  printf("%d\n", i);
}
```





