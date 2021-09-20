#include <stdio.h>
#include <string.h>

  /* 
  * Lab Sheet 3
  */

  /* Question 1
  
  Complete the function below which converts a hexadecimal string into its decimal value. (Do not use a C standard library function.) 

  The main function calls this function with an example hexadecimal value. Change this value to test your program.
  */

struct HexDec {
  char hex;
  int dec;
};

struct HexDec hexDecMap[] = {
  {'0', 0},
  {'1', 1},
  {'2', 2},
  {'3', 3},
  {'4', 4},
  {'5', 5},
  {'6', 6},
  {'7', 7},
  {'8', 8}, 
  {'9', 9},
  {'A', 10},
  {'B', 11},
  {'C', 12},
  {'D', 13},
  {'E', 14},
  {'F', 15}
};

int getDecfromHex(char hex) {
  for (int i = 0; i <= 15; i++) {
    if (hexDecMap[i].hex == hex) {
      return hexDecMap[i].dec;
    }
  }
  return -1;
}


int hexToDec(char hex[]){
  int total = 0;
  int mult = 1;
  for (char * c = (hex + strlen(hex) - 1); c != hex - 1; c--) {
    int dec = getDecfromHex(*c);
    
    // ensure that hex is valid
    if (dec == -1) {
      printf("\nInvalid Hex character %c\n", *c);
      return -1;
    }

    total += dec * mult;

    mult *= 16;
  }

  return total;
}

/* Question 2
 Complete the function below that print out a tree shape such as the following: 

    *
   ***
  *****
 *******
*********
   ***
   ***
   ***
   ***

  Note you can (and probably should) implement additional functions to help.

  You can assume that the width of the tree will be odd and hence every line will have an odd number of asterisks. The trunk will always have a width of three.

  Call this function from the main to test your program.
*/

void printStar(int pos, int offset, int centre) {
  // Identify if a star can be printed 
  if (pos >= (centre - offset) && pos <= (centre + offset)) {
    printf("*");
  } else {
    printf(" ");
  }
}


void printTree(int width, int trunkLength) {

  // Handle incorrect inputs
  if (width % 2 == 0) {
    printf("Width of %d is not an odd number\n", width);
    return;
  }

  // find total height of tree
  int height = trunkLength + ((width + 1) / 2);
  
  // find centre of tree
  int centre = ((width + 1) / 2) - 1;

  // loop over area
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {

      // handle trunk part
      if (i >= (height - trunkLength)) {
        printStar(j, 1, centre);
      } else {
        printStar(j, i, centre);
      }
    }
    printf("\n");
  }
}

int main(void) {
  char hex[4] = "FF3";
  printf("The hex value %s is %d in decimal\n", hex, hexToDec(hex));
  printf("The hex value %s is %d in decimal\n", "X01", hexToDec("X01"));
  printf("The hex value %s is %d in decimal\n", "10", hexToDec("10"));
  printf("The hex value %s is %d in decimal\n", "FFFF", hexToDec("FFFF"));

  printTree(5, 2);

  printf("\n");
  printTree(15, 4);
  
  printf("\n");
  printTree(16, 4);
  return 0;
}
