#include <stdio.h>

int check_age(){

  int age;
  // This will print a long hex number representing
  // where the variable age is stored
  printf("age memory address: %p\n", &age);

  // This will print the value in the memory location
  // specified above
  // age has yet to be initialised with value, so the
  // value that is printed is undefined.
  printf("age value: %d\n", age);

  age = 16;

	if ( age > 16){
		return 1;
	}
	else if (age < 16){
		return 0;
	}
}

int defined_function() {
  return 2112;
}

int undefined_function() {
}

int main(void) {
  printf("Check Age: %d\n", check_age());

  printf("Undefined Function (Before): %d\n", undefined_function());
  printf("Defined Function: %d\n", defined_function());
  printf("Undefined Function (After): %d\n", undefined_function());

  return 0;
}
