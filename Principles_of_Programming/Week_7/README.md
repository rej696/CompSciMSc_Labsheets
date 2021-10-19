# Notes

These are notes for University of Bath Online MSc Principles of Programming Week 7:
Abstract Classes and Interfaces

This week all code is in Java.

## Lesson 1

[Exercise in replit](https://replit.com/@rej696/Week7Exercise1#Main.java)

### Abstract Classes

Abstract classes are classes for which you cannot create an instance (object)
They can have fields and methods as normal, as well as __abstract methods__
which are methods with no body.  Note the use of the _abstract_ keyword below.

```java
public abstract class Item {
  private String title;
  private double playTime;
  private boolean ownIt;
  private String comment;

  public Item(String title, double playTime, boolean ownIt, String comment) {
    // ...
  }

  public String getTitle() {
    return title;
  }

  // ...

  public abstract String getDescription();
}
```

#### Extend Abstract Classes
Extending an Abstract Class is very similar to a normal parent class. The key
difference is that any abstract methods on the abstract class __Must__ be
overriden, (or the inheriting class must be declared as abstract itself).

```java
public class Album extends Item {
  private String artist;
  private int numTracks;

  public Album(String title, String artist, int numTracks, double playTime, boolean ownIt, String comment) {
    super(title, playTime, ownIt, comment);

    this.artist = artist;
    this.numTracks = numTracks;
  }

  public String getDescription() {
    // You MUST implement this abstract method
  }
}
```

#### Multiple Inheritance is NOT supported
A Class in Java can only inherit from one superclass. This avoids the
__diamond__ problem:

If class B and C both extend and override a method from class A. A class
inheriting from both B and C does not know which implementation of the overriden
method to inherit.

### Interfaces
Not having multiple inheritance might mean that a class can only have one
supertype, and so has limited ability for polymorphism.

However, Java has another structure called an __Interface__. This is like an
abstract class, in that it provides an outline for a class. However, it is
different from an abstract class in the following way:

- An abstract class is used to generalise the behaviour of your classes
- an interface is used to standardise the behaviour of your classes

An interface is a way to tell a programmer what they __must__ implement.  An
interface acts as a contract, so that every implementation follows the standard
outline of the interface.

An abstract class offers generalised fields and methods. You do not have to
write all methods when extending an abstract class (the exception being abstract
methods), unlike an interface.

#### Interfaces and Inheritance
A class may implement (extend/inherit) as many interfaces as it wants.

Older versions of java did not have method implementations in interfaces, and
therefore no conflicts caused by the diamond problem.

Newer versions of java (8+) allow default (implemented) methods in interfaces.
With hte knowledge of the problem this causes for abstract methods, there are
now a set of rules for resolving conflicts during multiple inheritance with
interfaces. The simplest of these is a compile error, to indicate to the
programmer that they must provide their own implementation for the conflicting
method.

#### Interface Example
Following on from the previous inheritence/class examples, say we want another
class like Item, such as Gift, such that they can both be contained in a
database. We can implement an interface for this called Describable:

Earlier versions of java, methods on an interface must be public. However in
versions 9+, abstract methods can be private.

```java
public interface Describable {
  public abstract String getDescription();
}
```

To inherit from an interface, use the _implements_ keyword, followed by a list
of interfaces seperated by commas:
```java
public class Gift implements Describable {
  @Override
  public String getDescription() {
    return "An unopened box!";
  }
}
```

Finally, the Type used in the Database class is updated to be the Describable
interface type. The interface is being used for substitution _and_ polymorphism
instead of the abstract class.
```java
import java.util.ArrayList;

public class Database {
  private ArrayList<Describable> items;

  public void displayContents() {
    for (Describable item : items) {
      String description = item.getDescription();
      System.out.println(description);
    }
  }

  // ...
}
```

### ArrayList
Looking at the ArrayList documentation, you can see it is a subclass of
AbstractList, an abstract class. This provides methods that are useful for list
structures.

ArrayList also implements several interfaces, such as Clonable (which indicates
copies can be made of objects) and Iterable (which specifies the methods that
allow and object to be the target of a for-each loop)

[Java Docs](https://docs.oracle.com/en/java/javase/11/)

