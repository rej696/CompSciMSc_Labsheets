#include <stdio.h>

void printHelloWorld(void);
void printXYTimes(int, int);
void convertMetricToImperialHeights(int);
void fibonacci(int, int, int);
void volumeOfACylinder(double, double);

int main(void) {
  printf("Question 1\n");
  printHelloWorld();

  printf("\nQuestion 2\n");
  printXYTimes(5, 10);

  printf("\nQuestion 3\n");
  // set up array of centimetre values
  int cmArray[5] = {101, 3 , 15, 192, 124};

  // loop over Array by incrementing pointer
  for (int* p = cmArray; p < cmArray + 5; p++) {
    // call conversion function with dereferenced pointer as input
    convertMetricToImperialHeights(*p);
  }

  printf("\nQuestion 4\n");
  fibonacci(0, 0, 14);

  printf("\nQuestion 5\n");
  /* set up 2d array of centimetre values
   * height 7.0cm and radius 4.0cm
   * height 20.0cm and radius 3.0cm
   * height 14.7cm and radius 5.2cm
   */
  double cylinderArray[3][2] = {
    {7.0, 4.0},
    {20.0, 3.0},
    {14.7, 5.2}
  };

  // loop over Array by incrementing pointer
  for (size_t i = 0; i < 3; i++) {
    // call conversion function with dereferenced pointer as input
    volumeOfACylinder(cylinderArray[i][0], cylinderArray[i][1]);
  }
  return 0;
}

/* 
 * Lab Sheet 1:
 */

 /* Question 1: 
 
 Adapt the “HelloWorld” code below to produce a program that defines a variable capable of holding an integer of your choice. The program should add 3 to that number, multiply the result by 2, subtract 4, subtract twice the original number, add 3, then print the result and a new line.
 */
 
void printHelloWorld(void){
  int my_num = 666;
  int result = ((((my_num + 3) * 2) - 4) - (2 * my_num)) + 3;
  printf("My Number is %d\n", result);
}

 /* Question 2: 
 
 Complete the function below so that it prints every integer from x to x + 10.  Do not use loops. 
 
 Call this function from the main to test your program.
 */

void printXYTimes(int x, int y){
  printf("%d\n", x);
  if (y != 0) {
    printXYTimes(x + 1, y - 1);
  }    
}

 /* Question 3: 
 
 Complete the function below so that it converts the height of a person from centimetres to feet and inches. Use integer division (rounding down is acceptable, which is the default for integer division). 
 
 Hint: 254 cm is exactly 100 inches and 12 inches is exactly 1 foot. 
 
 Call this function from the main to test your program.  For example you could test your program with the follow five values, where "?" replaced with the true value.

 101 cm is 3 feet 3 inches to the nearest inch.
 3 cm is 0 feet 1 inches to the nearest inch.
 15 cm is ? feet ? inches to the nearest inch.
 192 cm is ? feet ? inches to the nearest inch.
 124 cm is ? feet ? inches to the nearest inch.
 */

void convertMetricToImperialHeights(int input){
  int inches = (input * 100) / 254;
  int feet = inches / 12;
  inches = inches % 12;
  printf("%d cm is %d feet and %d inches to the nearest inch\n", input, feet, inches);
}

 /* Question 4: 
 
 Complete the function below so that it uses three variables (current, previous, next) to calculate and print out the first ten numbers of the Fibonacci sequence, each on a new line: i.e. the first four lines should be as follows:

 0 
 1 
 1 
 2
 
 Call this function from the main to test your program.
 */

void fibonacci(int previous, int current, int count){
  if (previous == 0 && current == 0) {
    if (count > 1) {
      printf("0\n1\n");
      current = 1;
    } else if (count > 0) {
      printf("0\n");
    }
  }

  int next = current + previous;
  printf("%d\n", next);
  if (count != 0) {
    fibonacci(current, next, count - 1);
  }
}

 /* Question 5: 
 
 Complete the function below so that it uses two variables: height and radius. Use these two variables and print to the screen, the volume of a cylinder. 

 Call this function from the main to test your program.  For example, you could test your program with the following values, 

 height 7.0cm and radius 4.0cm
 height 20.0cm and radius 3.0cm
 height 14.7cm and radius 5.2cm
 
 Which print out, the cylinder with height 7.0cm and radius 4.0cm has a volume of 351.86cm^3
 
*/

void volumeOfACylinder(double height, double radius){
  double pi = 3.14;
  double volume = pi * (radius * radius) * height;
  printf("height %.1fcm and radius %.1fcm equals volume %.2fcm\n", height, radius, volume);
}
