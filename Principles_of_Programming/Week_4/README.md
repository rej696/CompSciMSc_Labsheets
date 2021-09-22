# Notes

These are notes for University of Bath Online MSc Principles of Programming Week
4: Java and Object Oriented Programming

This week all code is in Java.

## Lesson 1

### Hello World

```java
public class HelloWorld {
  public static void main(String[] args) {
    // print Hello World to the terminal
    System.out.println("Hello World");
  }
}
```
### Object Oriented Paradigm

C is generally suited to Procedural Programming, where
code is structured as separate functions (or procedures)

Java uses Object Oriented paradigm, where code and data are grouped together

### Classes and Objects

A Class is a specification, or blueprint.

An Object is an instance of a class. One class may have multiple instances.

Objects are combinations of code and data (methods and data structures)

The functions on a class are called methods

The data (variables) on a class are called fields (attributes)

## Lesson 2

[Exercise in replit](https://replit.com/@rej696/Week4Exercise1#Main.java)

### Java Syntax

```java
public class BusTicket {
  // Fields
  private int journeys;

  // Constructor
  public BusTicket(int initialJourneys) {
    journeys = initialJourneys;
  }

  // Accessor (Getter)
  public int getJourneys() {
    return journeys;
  }

  // Mutator (Setter)
  public void setJourney(int newJourneys) {
    journeys = newJourneys;
  }
    
  // Other Methods
  public void rideTheBus() {
    journeys = journeys - 1;
  }

  // boolean is built in
  public boolean canRide() {
    // local variable
    boolean moreThanOne = journeys >= 1;

    if (moreThanOne) {
      return true;
    } else {
      return false;
    }
  }
}
```

Public keyword is an access modifier, or visibility. Public classes can be used
by any other classes.

Private keyword indicates that other classes/objects cannot access this data directly. It is standard practice that fields are private.

A class is saved in a file with the classes name, i.e. BusTicket.java

It is convention that fields are listed first in java.

A Constructor is a special method that has the same name as the class, and no
return type. It can take parameters and carries our functionality when the class
is instantiated.

The getJourneys method allows the value of the private field to be retrieved,
this is called an Accessor.

The setJourneys method allows the value of the private field to be modified,
this is called a Mutator.

Local variables can be assigned that can only be accessed within the set of
curly braces they were defined in, otherwise known as the scope of the variable.

### Creating Objects

To actually use the BusTicket class, we need to create an object. This calls the
constructor:
```java
BusTicket myTicket = new BusTicket(10);
```
The `new` keyword always comes before a constructor

To run the code, this must be called inside the main function:
```java
public class BusTicketMain {
  public static void main(String[] args) {
    BusTicket myTicket = new BusTicket(10);
    myTicket.rideTheBus();
    myTicket.rideTheBus();
    System.out.println("Journeys remaining: " + myTicket.getJourneys());
  }
}
```

If a private field is attempted to be modified directly by a different class,
rather than through the accessor and mutators, then it will produce an error.

### OOP Principles
#### Abstraction
The ability to ignore details of parts and focus attention on a higher level of
the problem.

#### Modularisation
The process of dividing a whole into well-defined parts, which can be build and
examined separately, and which interact in well-defined ways.

#### Encapsulation
The idea that individual parts should be responsible for their own state. Hence
Java's use of private modifiers.

### Clock Display Example
What features does the program need?

How can we break it down into parts?

#### NumberDisplay Class

```java
public class NumberDisplay {
  // set a default value for value
  private int value = 0;
  private int limit;

  public NumberDisplay(int limit) {
    // 'this' keyword is pointer to current object
    this.limit = limit;
  }

  public int getValue() {
    return value;
  }

  public void setValue(int value) {
    if (value >= 0 && value < limit) {
      this.value = value;
    }
  }

  public int getLimit() {
    return limit;
  }

  public void tick() {
    value = (value + 1) % limit;
  }

  public String getDisplayValue() {
    if (value < 10) {
      return "0" + value;
    } else {
      return "" + value;
    }
  }
}
```

#### ClockDisplay Class
```java
public class ClockDisplay {
  private NumberDisplay hours;
  private NumberDisplay minutes;
  private char separator = ':';

  public ClockDisplay() {
    hours = new NumberDisplay(24);
    minutes = new NumberDisplay(60);
  }

  public void tick() {
    minutes.tick();
    if (minutes.getValue() == 0) {
      hours.tick();
    }
  }

  public String getTimeDisplay() {
    return hours.getDisplayValue() + separator + minutes.getDisplayValue();
  }
}
```

#### ClockMain
```java
public class ClockMain {
  public static void main(String[] args) {
    ClockDisplay clock = new ClockDisplay();
    for (int i = 0; i < 2*60; i++) {
      System.out.println("The time is: " +
                         clock.getTimeDisplay());
      clock.tick();
    }
  }
}
```

## Lesson 3

Java uses 2 stage compilation, called just-in-time compilation.

The stages are as follows:
- Compilation into bytecode (non-hardware specific low level instructions)
- bytecode compiled and executed at runtime on Java Virtual Machine (JVM)

This technique means syntax errors can be discovered before execution, unlike a
purely interpreted language.

Additionally, execution can be optimised based on the code currently running,
rather than the entire program like a traditional compiler.

### Compiling in java
- Source files : `.java`
- Bytecode     : `.class`
- Archive for running on JRE : `.jar`

Compile to bytecode:
```
javac HelloWorld.java
```

Compile multiple files
```
javac *.java
```

Executing Bytecode using Java just-in-time compiler
```
java HelloWorld
```

Create `.jar`
```
javac YourApp.java
jar -cf YourJar.jar YourApp.class
```

Java packages
```
java my.package.HelloWord
```

### Managing a Java Project
```
Project
|
|-README.md
|-src/
  |-com/
    |-package/
      |-Main.java
      |-Second.java
|-lib/
  |-Library.jar
|-build.sh

```

[Java build script `build.sh`](https://alvinalexander.com/blog/post/java/unix-shell-script-i-use-for-compiling-java-programs/)
```bash
#!/bin/bash
THE_CLASSPATH=
PROGRAM_NAME=<main>.java
cd src
for i in `ls ../lib/*.jar` do
  THE_CLASSPATH=${THE_CLASSPATH}:$i
done

javac -classpath ".:${THE_CLASSPATH}" $PROGRAM_NAME

if [ $? -eq 0 ] then
  echo "Compilation Complete"
fi
```

Also can use build tools such as [ant](https://www.codejava.net/tools/ant/java-ant-tutorial-for-beginner)

[Java Naming Conventions](https://www.oracle.com/java/technologies/javase/codeconventions-namingconventions.html)
