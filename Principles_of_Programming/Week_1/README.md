# Notes

### Errors
There are three main types of programming errors

- Syntax
- Runtime
- Logical

#### Syntax Errors
These are issues with the structure of the code. These errors are often caught
by the compiler on compilation, for example a missing semi-colon;

#### Runtime Errors
These are errors that will only appear after the program has been compiled and
the binary is run. common examples of runtime errors include:

- Division by zero, where a variable is attempted to be divided by zero
- Segmentation fault, where restricted memory is attempted to be accessed.

A Segmentation fault can be caused by many issues, such as trying to access an
array out of bound, or stack overflow.

Stack Overflow is where the call stack pointer for a program exceeds the stack
bounds. This may be due to a call stack having a restricted size (e.g. in
embedded applications) or due to an very large call stack. Often, the cause of
a very large call stack is due to excessively deep or infinite recursion. Some
languages, such as python, restrict the recursion depth to prevent stack
overflow and undefined behaviour.

#### Logical Errors
These errors are where the computer does what you told it too, not what you
wanted it to do! Often there will be no error messages for these, but just an
incorrect output.

## Useful Links
Tutorial on [Makefiles](https://www3.ntu.edu.sg/home/ehchua/programming/cpp/gcc_make.html)

Labsheet on [repl.it](https://replit.com/@rej696/Week1LabSheet1#main.c)
