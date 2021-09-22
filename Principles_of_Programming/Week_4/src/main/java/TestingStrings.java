package com.example;

public class TestingStrings {
  public static void main(String[] args) {
    String example = "Test String";

    int strLen = example.length();

    System.out.println(example + " has length " +
                       strLen);

    // replace the word Test with Another
    // .replace does not replace original string, only returns modified string
    String newString = example.replace("Test", "Another");

    System.out.println(newString);
  }
}
