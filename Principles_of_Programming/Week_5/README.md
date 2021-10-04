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
```

## Lesson 3

### Errors in Java
Many errors that occur in Java are caused by __Exceptions__.

In Java, an Exception is an object that will cause the program to crash, and
report some useful information for debugging.

We can write code that causes, or _throws_ an exception, as well as receiving,
or _catching_ it.

In Java there are two types of exceptions: __Checked__ and __Unchecked__.

### Unchecked Exceptions
An `ArrayIndexOutOfBoundsException` is an example of an unchecked exception.

For this type of exception, it is up to the developer to ensure that this
exception will not occur, usually by constructing control flow correctly.

There may be cases where it is not clear if an unchecked exception might be
thrown or not. In these circumstances you can use a `try-catch` statement.

```java
int[] integerArray = {2, 4, -3};

// x is unknown, e.g. user input
int x = ...

int y = 0;
try {
  y = integerArray[x];
} catch(ArrayIndexOutOfBoundException e) {
  y = 0;
}
```

- In the `try` block you put the potentially erroneous code
- In the `catch` block you specify which exception is handled, and the behaviour in the event of that exception

### Checked Exceptions
These require the use of `try-catch` statements. if a method can produce a
checked exception, the code that calls it must declare that it can cause the
exception, or handle it using a `try-catch` statement.

You can cause an exception using the `throw` keyword followed by an exception
object.

### Error Handling
Writing robust code means anticipating runtime issues, such as exceptions and
user error.

Declaring and throwing exceptions can help aid robustness and maintainability.

#### Data Format Errors
A common error where the data is not correct for the operation being performed.
for example, a negative number as an index.

These can arise from user input of function parameters, but also from calculated
variables.

`indexOf` returns `-1` if a character is not found in the string.

`int x = in.indexOf('i');`

If 'x' was used as an index in this case, it would raise an exception.

#### Guarding
You can use conditional statements to protect against errors. This is called
__Guarding__.

### Defensive Programming
Writing software that can cope with both erroneous and malicious use is called
__defensive programming__.

#### API (Application Programming Interface)
Object Oriented Programming is concerned in particular with __encapsulation__;
that direct access to components of a class is restricted.

Details of the public components of a class are communicated via its __API__.
Much of this is automatic by return types, parameters etc. Other details may be
communicated in comments, perhaps using __javadoc__ syntax.

When writing OOP software, consider what the public view of the class is like
(i.e. consider its API). This may be useful for determining names, constructors,
arguements etc.

#### Javadoc

Three typs of comments
- `/* text */` : Compiler ignores text (multiline comment)
- `// text` : Compiler ignores text (singleline comment)
- `/** documentation */`: doc comment. the jdk __javadoc__ tool uses these to automatically generate documentation.

Javadoc allows html tags to be embedded in comments, as well as special javadoc
tags that specify important information

```java
/**
* <h1>Hello, World!</h1>
* This program prints hello world
* <br/>
* putting comments in code makes it more readable
*
* @author Rowan Saunders
* @version 1.0
*/

public class HelloWorld {
  
  /**
  * This is the main method
  * @param args Unused.
  * @return Nothing.
  * @exception IOException On input error.
  * @see IOException
  */
  public static void main(String args[]) throws IOException {
    System.out.println("Hello World");
  }
}
```

for more inforamtion about other tags, see
[this tutorial](https://www.tutorialspoint.com/java/java_documentation.htm)

### Exceptions
Sometimes you can return a boolean value to identify if a method is succesful.
However, this is reliant on the user of the API checking the return value.
Additionally, if the method returns other data, this is not possible.

Instead, the method can throw an exception:
```java
public class Database {
  private ArrayList items;

  public void removeItem(String title) throws Exception {
    for (int i = 0; i < items.size(); i++) {
      if (items.get(i).getTitle().equals(title)) {
        items.remove(i);
        return;
      }
    }
    throw new Exception("Item not found");
  }
}
```

This is a checked exception, so the method must be declared in its signature
with the `throws` keyword.

To raise the exception, we use the throw keyword on the exception object.

Exception has many subclasses which are more descriptive, and you can inherit
the class to create your own.

## Lesson 4: Input/Output

[Exercise in Replit](https://replit.com/@rej696/Week5Exercise4#Main.java)

In Java, most I/O is achieved with streams. A stream is a source of data of
potentially infinite length, and abstracts almost any data source.

There are Java classes for reading from and writing to streams. Streams do not
have indicies, it is just a continuous flow of data.

### Output
It is good practise to keep all user interaction code (like print statements)
seperate from functional code.

Therefore, it is much better practise to return values and results rather than
print them directly from a function.

### System.out and System.in
`System` is a java built-in class. it is part of `java.lang` package with
`String`, `Integer` and other classes like common exceptions. This package is
imported by default.

`System.out` is a public `PrintStream` object. This variable belongs to the
class.

This PrintStream connects to the _standard output_ (stdout), which by default is
the commandline.

There is also `System.err` which prints to the _standard error_ (stderr).

As both `System.err` and `System.out` are `PrintStream` objects, the methods are
the same, including `println` and `printf`

#### System.in
`System.in` is an `InputStream`, which allows us to read bytes from the _standard
input_ (stdin)

We do not normally want to read binary data directly, so we can wrap the input
stream in one of several different I/O classes:
- `BufferedReader` which allows data to be read line by line, with each line as a String
- `Scanner` which can parse data into even smaller chunks

There are other classes that can deal with streams in various different ways.

### BufferedReader
```java
import java.io.*;

public class InputDemo {
  BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

  private void demoInput() {
    do {
      System.out.println("Insert some text: ");
      String userin;
      try {
        userin = br.readLine();
      } catch (IOException e) {
        System.out.println("Something went wrong!");
        return;
      }
      System.out.println("You said: " + userin);
    } while (!userin.equals("quit"));
  }
}
```

It is common to see user input contained in a while loop, the example above
continues until the user types quit.

### Scanner
Scanner can read text in blocks seperated by whitespace, although the delimeter
can be changed.
Additionally, it can automatically convert text to numbers, as well as reading
entire lines like BufferedReader.

Scanner Example similar to BufferedReader:
```java
Scanner s = new Scanner(System.in);

private void demoInput() {
  String userin;
  do {
    System.out.println("Insert some text: ");
    userin = s.nextLine();

    System.out.println("You said: " + userin);
  } while(!userin.equals("quit"));
}
```

More idomatic Scanner usage:
```java
private void demoInput() {
  int total = 0;
  int input = 0;
  do {
    System.out.println("Insert an integer (0 to quit): ");

    input = s.nextInt();
    total += input;

    System.out.println("Running total is: " + total);
  } while(input != 0);
}
```
However, you have to code defensively to ensure that the user input is not
invalid

### File Input and Output
Streams, BufferedReader and Scanner classes also apply to files

- BufferedReader can take a FileReader object when constructing
- Scanner can be constructed with a File Object

#### FileReader
```java
public void processFile(String filename) {
  String line;
  BufferedReader br;
  try {
    br = new BufferedReader(new FileReader(filename));
    line = br.readLine();
  } catch (FileNotFoundException e) {
    // handle exception
  } catch (IOException e) {
    // handle IO exception
  }
}
```
Note when an Exception is thrown, the first catch block that matches the
exception is executed.

As FileNotFoundException is a subclass of IOException, if we put the IOException
catch statement first, the FileNotFoundException catch statement would never be executed.

### Closing Streams
In order to prevent unnessarry resource consumption, it is good practice to
close unused streams. One method is to use a `finally` statement after the
`try-catch` blocks. This will always execute nomatter what (if any) exception
was raised:
```java
//...
} catch (IOException e) {
  // handle IO exception
} finally {
  br.close();
}
```

This is not complete. The br object must have an _initialised_ state.
Additionally, we should check that the object is not null before calling the
`.close()` method.

Additionally, the `.close()` method also declares that it can throw an
IOException. Therefore we must either wrap the entire method in another
`try-catch` block or declare that the our method also __throws__ IOException:

```java
public void processFile(String filename) {
  try {
    String line;
    BufferedReader br = null;
    try {
      br = new BufferedReader(new FileReader(filename));
      line = br.readLine();
    } catch {
      // handle exceptions....
    } finally {
      if (br != null) {
        br.close();
      }
    }
  } catch (IOException e) {
    // close throws an exception
  }
}
```

### File Writing
Similarly, when writing to a file, we can use a `BufferedWriter` object.

Furthermore, Java 7 introduced the `try-with-resources` syntax, similar to
pythons `with` statement. This will automatically close any resource specified
after the `try-catch` block is finished, with no need for a `finally` statement.

```java
try (/* define resources */) {

} catch (...) {// normal catch block if needed

}
```

for example:
```java
public void writeToFile(String file, List lines) {
  try (BufferedWrite bw = new BufferedWriter(new FileWriter(file))) {
    for (int i = 0; i < lines.size(); i++) {
      bw.write(lines.get(i));
      bw.newLine();
    }
  } catch (IOException e) {
    // handle exception
  }
}

```

Note that the parameter lines is of type `List`. `List` is an interface, and we
use _polymorphism_ to allow any kind of list to be input to the method, for
example `ArrayList` or `Vector`.

### Non Blocking IO
[Some explanination of Non Blocking versus Async
IO](https://stackoverflow.com/questions/25099640/non-blocking-io-vs-async-io-and-implementation-in-java)

[Java NIO tutorial](https://www.javatpoint.com/java-nio)

Non Blocking IO will continue the program flow whether the source of information (a
network, file, or other stream) is ready or not.

Java can use the `java.nio` library introduced in Java 7 for non-blocking IO.
This requires a `Path` object. The `Path` object can be obtained from a filename
using the `get` static method on the `Paths` class. Reading and writing are then
carried out by the `readAllLines` and `write` static methods on the `Files`
class. Example Below:
```java
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;

public class NonBlockingIOExample {
  public List<String> readFile(String file) {
    try {
      Path path = Paths.get(file);
      return Files.readAllLines(path, StandardCharsets.UTF_8);
    } catch (IOException e) {
      // handle exception
    }
    return null;
  }

  public void writeToFile(String file, List lines) {
    try {
      Path path = Paths.get(file);
      Files.write(path, lines);
    } catch (IOException e) {
      // handle exception
    }
  }
}
```
