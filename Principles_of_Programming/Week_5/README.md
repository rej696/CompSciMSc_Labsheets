# Notes

These are notes for University of Bath Online MSc Principles of Programming Week
5: Java Types, Control Flow and Error Handling 

This week all code is in Java.

## Lesson 1

[Exercise in replit](https://replit.com/@rej696/Week5Exercise1#Main.java)

### Primitive Types
Java has eight primitive types

- byte (8-bit integer)
- short (16-bit integer)
- int (32-bit integer)
- long (64-bit integer)
- float (32-bit floating point number)
- double (64-bit floating point number)
- char (16-bit unicode character)
- boolean (true or false)

All integer types in Java are signed.

### Arrays
Java supports similar style arrays to C.
The main differences are the square brackets are written on the type, and the new
keyword is used.

Arrays are set and accessed using the same syntax as C

```java
public class ArrayTest {
  public static void main(String[] args){
    int[] integerArray = new int[10];

    // Setting and accessing Array elements
    integerArray[0] = 5;
    integerArray[1] = integerArray[0] + 10;

    // Get length of array
    System.out.println("Length: " + integerArray.length);
  }
}
```

### ArrayList
ArrayList is a builtin type that acts like a python `List` or a C++ `Vector`; an
array that dynamically resizes itself.

ArrayList must be imported from the `java.util.ArrayList` package.

ArrayList has various methods for modifying the data structure. These include
(but not limited to):
- add
- get
- size
- remove
- contains

ArrayList is also an example of a __Generic__ in java. This is like a template
in C++, where the value in the angle brackets indicates the type of the
ArrayList contents.

```
import java.util.ArrayList

public class ArrayListTest {
  public static void main(String[] args) {
    ArrayList<String> list = new ArrayList<>();

    list.add("Item one");
    list.add("Item two");

    System.out.println("List Size: " + list.size());

    System.out.println(list.get(0));
    System.out.println("Length: " + list.get(0).length);

    list.remove(0);
    System.out.println(list.get(0));
  }
}
```

### Wrapper Classes
ArrayLists can only store objects, not primitive types; `ArrayList<int>` will
produce an error.

__Wrapper Classes__ solve this problem. Wrapper classes allow primitive types to
be represented as an object. For example, `int` is represented as `Integer`.

Integers can be both constructed, as well as automatically converted from an int
literal.

```java
ArrayList<Integer> list = new ArrayList<>();
Integer x = new Integer(1);
Integer y = 2;
list.add(x);
list.add(y);
list.add(x + y + 5);
```

Wrapper classes also contain useful methods. The Integer class contains a method
for converting Strings into `int` Primitives. This is a static method: the
method belongs to the class and not an object.

```java
String s = "100";
int i = Integer.parseInt(s);
```
## Lesson 2

[Exercise in replit](https://replit.com/@rej696/Week5Exercise2#Main.java)

### Control Flow Statements and Loops
Control flow statements are commands that alter the order of execution, such as
conditionals and loops.

Java if statements, for loops, while loops and dowhile loops are all the same
syntax as C.

In addition to those mentioned above, Java also has __for-each__ loops.
This iterates over a collection of items one at a time. It supports most ordered
collections, such as arrays and ArrayLists,  as well as some unordered
collections such as `HashSet`.

This is similar to pythons `for x in y:` loop construct.

The syntax in Java is `for(type name : collection)`. Note that the `:` is
pronounced as "in", similar to python.
```java
int[] nums = {9, 2, 1, 7, 3};
int min = nums[0];

// for num in nums:
for (int num : nums) {
  if (num < min) {
    min = num;
  }
}
```

### Break and Continue Statements
- `break`    : exit the loop immediately
- `continue` : skip the code for this iteration, and continue iterating as normal

`break` is often used when a result is found and there is no need to continue
iterating.

```java
int[] nums = {2, 4, -3, 5, -7};
int firstNegative = 0;
for (int num : nums) {
  if (num < 0) {
    firstNegative = num;
    break;
  }
}
```

`continue` is often used when there is no need to finish processing a particular
item, but more work to do for the rest of the collection
```java
double[] nums = {2, 4, -3, 5, -7}
for (int i = 0; i < nums.length; i++) {
  if (nums[i] < 0) {
    continue;
  }
  nums[i] = Math.sqrt(nums[i]);
}
