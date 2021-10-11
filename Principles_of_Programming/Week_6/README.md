# Notes

These are notes for University of Bath Online MSc Principles of Programming Week 6:
Object Oriented Classes and Inheritance

This week all code is in Java.

## Lesson 1

[Exercise in replit](https://replit.com/@rej696/Week6Exercise1#Main.java)

### Class/Static Variables/Methods, and Constants
Java uses the `static` keyword to denote variables and methods that belong to 
the class, and not the object.

Java uses the `final` keyword to denote constants, namely named values that are
should not be changed (they are immutable). Constants are normally shown as
ALL_CAPS with underscores.

`final` can also be used to denote general immutable variables (like totalCost in the example below).
These are not constants, as their values are not known at compile time, but they cannot be altered
after a value is assigned.

When applied to a method, the `final` keyword makes a method unable to be overriden
by a subclass.

Example:
```java
public class Contract {
  private final int totalCost;
  private int hoursLeft;
  private int id;
  private String employer;
  private static int hourlyRate;
  private static int nextContractID = 0;
  public static final double HOURS_PER_WEEK = 37.5;

  public Contract(String employer, int hours) {
    this.employer = employer;
    this.hoursLeft = hours;
    this.totalCost = Contract.hourlyRate * hours;
    this.id = Contract.nextContractID++;
  }
  // ...

  public static void changeRate(int newRate) {
    Contract.hourlyRate = newRate;
  }
}
```

This example uses a static variable that maintains and stores a
unique ID for each instance of the Contract, as well as a static method for 
specifying and modifying the hourly rate of the contract worker

Another example of a static method is the main method. This means you do not
need an instance of the class to call the method.

A constant is a named value (like a variable) that we do not expect to change.

## Lesson 2

[Exercise in replit](https://replit.com/@rej696/Week6Exercise2#Main.java)

### The Code Duplication Problem
Badly designed programs often duplicate code. Duplication makes code harder to 
update, and increases the likelihood of bugs occuring due to code being changed 
in one place but not others.

### Inheritence
Inheritence aims to reduce code duplication by introducing a hierarchy of 
classes, where child classes inherit shared attributes and methods from
a parent class.

We can refer to inheriting classes as either _child_ or _subclasses_, and the 
classes being inherited as _parent_ or _superclasses_. Children inherit all 
methods and field from their parents.

The class hierarchy creates one way '_is a_' relationships, i.e. all children
are parents, but not all parents are children. Subclasses can define their own
elements in addtion to those inherited.

__Subtypes__ can be used where in place of code asking for __supertypes__.
This is called substitution. __Substitution__ can be used in variables and 
parameter types, i.e. `List` parameter accepting both `ArrayList` and `Vector`.

### Coding a Media Database

#### Item Class (Superclass)
```java
public class Item {
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
}
```
#### Album Class (Subclass)
```java
public class extends Item {
  private String artist;
  private int numTracks;

  public Album(String title, String artist, int numTracks, double playTime, boolean ownIt, String comment) {
    super(title, playTime, ownIt, comment);

    this.artist = artist;
    this.numTracks = numTracks;
  }

  // ...
}
```
Java uses the `extends keyword to denote inheritence.

The child class constructor calls a `super` method that calls the constructor of 
the superclass to initialise the fields associated with it.

#### Database Class (Collection of Items)
```java
import java.util.ArrayList;

public class Database {
  private ArrayList<Item> items;

  public Database() {
    items = new ArrayList<Item>();
  }

  public void addItem(Item item) {
    items.add(item);
  }

  public void displayContents() {
    // print any shared attributes (i.e. those stored on an Item)
    // to use methods of an Album, you need to cast the Item to an album
    // i.e. ((Album) item).getArtist()
  }
}
```

## Lesson 3: Polymorphism

[Exercise in replit](https://replit.com/@rej696/Week6Exercise3#Main.java)

### A Problem With Inheritance
The Database example in lesson 2 shows a problem with inheritance.
The ArrayList contains a list of `Items`, and so when we loop over the array,
the item we see cannot be used to access subclass specific fields or methods.

A solution might be to remove the logic of the displayContents method out of the 
Database class, i.e. `System.out.println(item.getDescription);`.

This `getDescription` method cannot go in the `Item` class, as then it cannot see
the child class fields. Equally, it cannot go in the child classes, as then the 
Database cannot call it from the list of Items.

This issue demonstrates the difference between static and dynamic types in java.

A static type is the type that is declared.

A dynamic type is the actual run-time type.

In the below example, the dynamic type is Album but the static type is Item:
```java
Item i = new Album(...);
```
The compiler enforces static types, so a method cannot be called if it is not 
declared for the static type.

### Solution: Override
The solution is to make an abstract method on the parent, and have the children
override its implementation.

#### Method Dispatch
In a normal method call without inheritance, the static and dynamic types are 
the same and so the obvious method is called.

In a method call with inheritance, the method is dependant on whether the instance
method in the subclass __overrides__ the instance method in the superclass.

Inheritance with __No Override__, the parent method (from the static type) is called.

Inheritance __and__ overrides, the method called is from the child class (dynamic type)

#### Override
We can use the @Override annotation to indicate a method defined in a parent class
that is overriden in a child class (However, this is not strictly necessary).
```java
public class Item {
  //...
  public String getDescription() {
    // ...
  }
}

public class Video extends Item {
  // ...

  @Override
  public String getDescription() {
    String desc = this.getTitle() + " by "//...
    // ...
    return desc;
  }
}
```
Note that the Video class in the above example has to use the accessors inherited from item
to access the private fields of the superclass. This is because `private` excludes even 
subclasses from accessing it.

To allow subclass access, use the `protected` modifier, and access with `super.field`
(`super` is similar to `this` in this case)

Creating abstract methods, and overriding them in child classes is called __polymorphism__

## Lesson 4: Exceptions Revisited

`RuntimeException` is an important subclass; all _unchecked_ exceptions are subclasses of `RuntimeException`

`Exception` is a subclass of `Throwable`. There is one other subclass: `Error`.
A Java `Error` is like an unchecked Exception, but represents an error that
"a reasonable application should not try to catch". 

SubClasses of `Error` include `OutOfMemoryError` and `StackOverflowError`.

Creating an exception or error is the same as creating a subclass. There are no abstract
methods to override. You can support a constructor that personalises the message.
However, it is not uncommon to find exception classes with no body; the name of the exception
is enough information.
```java
public class ItemNotFoundException extends Exception {
  public ItemNotFoundException(String title) {
    super("Item: " + title + " not found");
  }
}

// example use
try {
  database.removeItem("Titanic");
} catch(ItemNotFoundException e) {
  System.out.println(e.getMessage());
}
```

If callers should be reasonably expected to be able to recover from an error,
then a checked exception should be used to force accountability.

It is common to use an unchecked exception when a user uses a method incorrectly.
The API of your class should document proper use, which users should be expected to follow.
To create an unchecked exception, inherit from `RuntimeException`.