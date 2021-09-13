#include <stdio.h>
#include <math.h>

/* 
 * Lab Sheet 2:
 */

/* Question 1: 
 
 Complete the function below which takes in an integer input between zero and one hundred (1 ≤ n ≤ 100) and prints out the number expressed in English text, with spaces and no dashes (–), e.g. for the number “33”, we would expect to see “thirty three”. Hint: you may want to create additional functions to help.
 
 Call this function from the main to test your program.
 */

void get_first_digit(int value) {
   if (value < 20 || value >= 100)
     return;

   switch (value) {
    case 20:
      printf("twenty ");
      break;
    case 30:
      printf("thirty ");
      break;
    case 40:
      printf("forty ");
      break;
    case 50:
      printf("fifty ");
      break;
    case 60:
      printf("sixty ");
      break;
    case 70:
      printf("seventy ");
      break;
    case 80:
      printf("eighty ");
      break;
    case 90:
      printf("ninety ");
      break;
    default:
      printf("\n");
   }
}

void get_second_digit(int value) {
  if (value >= 10 || value < 0)
    return;

  switch (value) {
    case 1:
      printf("one\n");
      break;
    case 2:
      printf("two\n");
      break;
    case 3:
      printf("three\n");
      break;
    case 4:
      printf("four\n");
      break;
    case 5:
      printf("five\n");
      break;
    case 6:
      printf("six\n");
      break;
    case 7:
      printf("seven\n");
      break;
    case 8:
      printf("eight\n");
      break;
    case 9:
      printf("nine\n");
      break;
    default:
      printf("\n");
  }
}

void get_teens(int value) {
  if (value >= 20 || value < 10)
    return;

  switch (value) {
    case 11:
      printf("eleven\n");
      break;
    case 12:
      printf("twelve\n");
      break;
    case 13:
      printf("thirteen\n");
      break;
    case 14:
      printf("fourteen\n");
      break;
    case 15:
      printf("fifteen\n");
      break;
    case 16:
      printf("sixteen\n");
      break;
    case 17:
      printf("seventeen\n");
      break;
    case 18:
      printf("eighteen\n");
      break;
    case 19:
      printf("nineteen\n");
      break;
    default:
      printf("ten\n");
  }
}

void numberToText(int value){
  if (value <= 0) {
    printf("zero\n");
  } else if (value > 0 && value < 10) {
    get_second_digit(value);
  } else if (value >= 10 && value < 20) {
    get_teens(value);
  } else if (value >= 20 && value < 100) {
    // seperate the first and second digit, and use seperate functions to print them
    int second_digit = value % 10;
    int first_digit = value - second_digit;
    get_first_digit(first_digit);
    get_second_digit(second_digit);
  } else if (value >= 100) {
    printf("One Hundred\n");
  }
}

/* Question 2: 
 
 Complete the function below that calculates, and returns, the distance between two points.
 
 Call this function from the main to test your program. Hint: may wish to use the following print statement in your main function, or similar: 

 printf("%1.2f\n", calculateDistance(0, 0, 4, 3));
 */

double calculateDistance(int x1, int y1, int x2, int y2){
  double x;
  x = x1 - x2;

  double y;
  y = y1 - y2;

  return sqrt(pow(x, 2.0) + pow(y, 2.0));
}

/* Question 3: 
 
 Complete the function below that is given an integer, n, where 1 ≤ n ≤ 9999 and prints whether it is even, odd, or/and prime.  The output should be whole sentences for example, 

 1 is odd and not prime.
 2 is even and prime.
 3 is odd and prime.
 4 is even and not prime.
 5 is odd and prime
 
 Call this function from the main to test your program.
 */

void printOddEven(int n) {
  printf(n % 2 == 0 ? "even" : "odd");
}

void printPrime(int n) {
  int flag = 0;
  if (n != 1) {
    for (int i = 2; i <= n / 2; i++) {
      if (n % i == 0) {
        flag = 1;
        break;
      }
    }
  }
    
  printf(flag ? "not prime\n" : "prime\n");
}


void printOddEvenAndOrPrime(int n){
  // range is 1 <= n <= 9999
  if (n <= 0 || n > 9999)
    return;

  printf("%d is ", n);
  printOddEven(n);
  printf(" and ");
  printPrime(n);
}

int main(void) {
  for (int i = 0; i <= 100; i++) {
    numberToText(i);
  }

  printf("%1.2f\n", calculateDistance(0, 0, 4, 3));
  printf("%1.2f\n", calculateDistance(-1, 2, 4, 3));
  printf("%1.2f\n", calculateDistance(10, 7, 4, 3));
  printf("%1.2f\n", calculateDistance(0, -3, -4, 3));

  printOddEvenAndOrPrime(0);
  printOddEvenAndOrPrime(1);
  printOddEvenAndOrPrime(11);
  printOddEvenAndOrPrime(10);
  printOddEvenAndOrPrime(27);
  printOddEvenAndOrPrime(500);
  printOddEvenAndOrPrime(9998);
  printOddEvenAndOrPrime(9999);
  printOddEvenAndOrPrime(10000);
  return 0;
}
