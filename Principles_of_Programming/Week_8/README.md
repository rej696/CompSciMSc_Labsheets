# Notes

These are notes for University of Bath Online MSc Principles of Programming Week 8:
Code Quality, Refactoring, Testing and Final Assignment

This week all code is in Java.

## Lesson 1

[Exercise in replit](https://replit.com/@rej696/Week7Exercise1#Main.java)

### Code Quality
Software Maintenance is often carried out by many different people over long
periods of time.

In programming, there are often many ways to solve a problem. Often, different
rules of code style are prescribed, with the aim of improving code quality. 

Code style guides are intended to make a codebase easier to understand, maintain
and adapt for people who are new to the system.

### Implementing Quality Code
- Consider the API of your code
  - Use descriptive variable and method names
  - Use comments only to describe code where the code itself is unclear
- Avoid code duplication using sensible structure

## Lesson 2

### Refactoring
When designing software, we must try to anticipate how it might need to adapt or
change in the future. Many OOP principles are designed with the aim to make
future code changes as easy as possible.

However, sometimes existing code structure does not support the new features,
and we have to __refactor__ the code.

Refactoring is the process of improving quality _without_ changing any
functionality. I.e. renaming a method or modifying the class hierarchy.

Some IDEs can automatically perform refactoring tasks (such as renaming).
However, whether it is done automatically or by hand, it is important to
refactor separately and before new features are added to the code.

### Testing
It is important to __test__ code before and afterwards to make sure that no
functionality has changed.

Testing is a systematic approach to check whether code gives the correct result.

If you are testing a method, you should check a range of inputs to make sure
they give the expected output:
- Normal data
- Boundary data - edge cases or unusual values
- Data which produces errors

Many languages allow the ability to write unit tests. These are short specific
tests which are written in code and can be run repeatedly. For Java, there are
many libraries that support this, such as JUnit.

#### JUnit
__Test Driven Development__ means writing unit tests before you write code.

Example set of JUnit tests:
```java
public class DatabaseTest {
  Database d;
  @Before
  public void setUpObject() {
    d = newDatabase();
    d.addItem(new Album("Abbey Road", ...));
    d.addItem(new Video("Titanic", ...));
  }

  @Test
  public void addVideoNumber() {
    d.addItem(new Video("Your Name", ...));
    Assert.assertEquals(d.numItems(), 3);
  }

  @Test
  public void removeBadTitle() {
    try {
      d.removeItem("Yeezus");
      Assert.fail("Expected exception");
    } catch (ItemNotFoundException e) { return; }
  }
}
```
