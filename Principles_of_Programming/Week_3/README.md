# Notes

These are notes for University of Bath Online MSc Principles of Programming Week
3: Encapsulation and Generalisation.

This week all code is in C.

## Lesson 1

[Exercise in replit](https://replit.com/@rej696/Week3Exercise1#main.c)

### Encapsulation
Encapsulation usually means wrapping some code in a function.

### Generalisation
Generalisation means taking something specific and making it more general.

## Lesson 2

[Exercise in replit](https://replit.com/@rej696/Week3Exercise2#main.c)

### Arrays
In c, arrays must be declared with the number of elements in the array to
allocate the correct amount of memory

```c
int first_array[7];
double second_array[16];
```

Any `int` type can be used as an array index.
However, other types, such as floats, will give compilation errors.

Additionally, you can use the type `size_t`.

You will also get errors if the index is out of the allocated range. These
errors may become runtime errors.

### Multi-dimensional Arrays
You can create arrays of multiple dimensions as by specifying the size in square
brackets.

```c
int array2d[2][2];

array2d[0][0] = 1;
```

## Lesson 3

[Exercise in replit](https://replit.com/@rej696/Week3Exercise3#main.c)

### Strings
In C, a string is a one dimensional array of `char`, terminated by a null
character `'\0'`

### String Initialisation
```c
// Initialise each entry in the char array
char string[4];
string[0] = 'h';
string[1] = 'e';
string[2] = 'y';
string[3] = 0; // don't forget the null terminator

// Using curly brace array notation
char string2[5] = {'f', 'o', 'u', 'r', 0};

// Using a string literal (the compiler handles the array size and the null
// character
char string3[] = "hello";
```

You cannot initialise an array with string literals or curly braces after the
array has been declared
```c 
char string[6];
// both of the following will fail
string = "hello";
string = {'h', 'e', 'l', 'l', 'o', 0};
```

## Lesson 4

[Exercise in replit](https://replit.com/@rej696/Week3Exercise4#main.c)

### String functions

The standard C library has lots of common functions for manipulating strings.
```c
#include <string.h>

// string copy
// Copy the contents of the second argument into the first.
// enables assignment of string after declaration
char str[6];

strcpy(str, "hello");

// string concatenate
// Link the contents of one string onto the end of the first string
char str1[12] = "hello";
char str2[12] = "world";

strcat(str1, str2);
// Note how the array size of the string to be concatenated must be large enough
// to fit the concatenated string

// string length
// Does not include the null terminator in the count
len = strlen(str);
```

### Using strlen
You can use strlen as a while/for loop termination condition.

Going through a collection one item at a time is called traversal.

### Command Line Arguments
```c
#include <stdio.h>

int main(int argc, char* argv[]) {
  // argv is an array of strings.
  // argv[0] is the name of the program
  // argc is an integer that states how large the string array is (it is always
  // at least 1
}
```

## Lesson 5

[Exercise in replit](https://replit.com/@rej696/Week3Exercise5#main.c)

### Structs and Abstract Data Types
```c
// declare a struct
struct Date {
  int day;
  char month[4];
  int year;
};

// create a Date variable
int main() {
  struct Date today;
  today.day = 10;
  strcpy(today.month, "OCT");
  today.year = 2017;
}
```

Using ADT (abstract data types) allows similar/related data to be collated
together.

Using ADT makes code easier to read, and easier to develop and maintain.

c structs can be used as parameters and returns for functions, so you can write
functions specific to that struct.

Structs can be nested, so a struct can hold another struct as a field.

In c, you can use `typedef` to define a struc as a new type. For example:

```c
// declare a struct
typedef struct Dates {
  int day;
  char month[4];
  int year;
} Date;

// create a Date variable
int main() {
  Date today;
  today.day = 10;
  strcpy(today.month, "OCT");
  today.year = 2017;
}
```

## Lesson 6

### ADT Stack Example
Stack is LIFO

```c
typedef struct Stack {
  int head;
  int max_size;
  int lifo[10];
} Stack_t;

Stack_t stack;

void initialise() {
  // head is set to 0 and max_size hard-coded to 10
  s.head = 0;
  s.max_size = 10;
}

int isEmpty() {
  // Stack is empty if the head is zero
  return (s.head == 0);
}

void push(int data) {
  // push only pushes data if stack is not full
  if (s.head < s.max_size) {
    s.lifo[s.head] = data;
    s.head++;
  }
}

void pop() {
  if (!isEmpty()) {
    s.head --;
    return s.lifo[s.head];
  }
  // if stack is empty, -1 is returned
  return -1;
}

void peek() {
  if (!isEmpty()) {
    return s.lifo[s.head - 1];
  }
  return -1;
}
```

### ADT Dictionary Example
Dictionary (or map) is a set of key/value pairs

A tuple is an ordered collection of values, but may contain many different
types.

A tuple of 2 elements is called a pair.

```c
struct KeyValuePair {
  char key[10];
  int value;
};

struct Dictionary {
  int size;
  struct KeyValuePair kvp[1000];
};

struct Dictionary d;

void put(char key[], int value) {
  if (strlen(key) > 10) {
    // key is too long
    return -1
  }
  
  int existing_key = contains(key);
  if (existing_key != -1) {
    d.kvp[existing_key].value = value;
  } else {
    int next = d.size;

    struct KeyValuePair x;
    strcpy(x.key, key);
    x.value = value;

    d.kvp[next] = x;
    d.size++;
  }
}

int contains(char find[]) {
  for (int i = 0; i < d.size; i++) {
    if (d.kvp[i].key == find) {
      return i;
    }
  }
  return -1;
};

int get(char find[]) {
  // get implements a linear search
  for (int i = 0; i < d.size; i++) {
    if (d.kvp[i].key == find) {
      return d.kvp[i].value;
    }
  }
  return 0;
}
```
