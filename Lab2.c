#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *asciiToBin(char a);
int factorial(int n);
int fibbonacci(int n);
void runHanoi(int n, char x, char y, char z);
void lab2Reverse(char *userString, int start, int end);
void lab2Ascii(char *userString, int start, int end);
void binaryConversion(char target, int i);

char binary[8];

int main() {

  int functionsExecuted = 0;
  int again = 1;
  int userChoice = 0;
  int userN = 0;
  char userString[256];



  while (again ==1){
    printf("Welcome to Lab 2, would you like to: \n");
    printf("-------------------------------------\n");
    printf("(1). Calculate factorials\n");
    printf("(2). Calculate fibonoacci numbers\n");
    printf("(3). Solve towers of hanoi\n");
    printf("(4). Reverse a String\n");
    printf("(5). Convert a string to int\n");
    printf("(6). Convert int to a string\n");
    printf("Input: ");

    scanf("%i", &userChoice);

    switch(userChoice){
      case 1:
        printf("Please enter your number to find the factorial of: ");
        scanf("%i", &userN);
        printf("The factorial of %i is %i\n", userN, factorial(userN));
        userN = 0;
        functionsExecuted++;
        break;
      case 2:
        printf("How many iterations of fibonacci: ");
        scanf("%i", &userN);
        printf("Result: ");

        int i;

        for(i=0; i<userN; i++){
          printf("%i", fibbonacci(i));
        }
        printf("\n");
        userN = 0;
        functionsExecuted++;
        break;
      case 3:
        printf("You have chosen towers of hanoi\n");
        printf("How many iterations of towers of hanoi: ");
        scanf("%i", &userN);
        runHanoi(userN, 'S', 'A', 'D');
        userN =0;
        functionsExecuted++;
        break;
      case 4:
        printf("Enter the string you want to reverse: ");
        scanf(" %[^\n]", userString);
        printf("%s reveresed is...\n", userString);
        lab2Reverse(userString, 0, strlen(userString) -1);
        printf("Reversed String: %s\n", userString);
        functionsExecuted++;
        break;
      case 5:
        printf("You have chosen string to ascii\n");
        scanf(" %[^\n]", userString);
        lab2Ascii(userString, 0, strlen(userString) - 1);
        functionsExecuted++;
        break;
      case 6:
        printf("You have chosen ascii to string\n");
        functionsExecuted++;
        break;
      default:
        printf("Invalid Input\n");
    }

    printf("Would you like to perform another calculation? (1 = Yes, 0 = No): ");
		scanf("%i", &again);

  }

  return functionsExecuted;

}

int factorial(int n){
  if (n==0) {
      return 1;
  }
  else {
   return n * factorial(n - 1);
  }
}

int fibbonacci(int n) {
   if(n==0){
      return 0;
   } else if(n==1) {
      return 1;
   } else {
      return (fibbonacci(n-1) + fibbonacci(n-2));
   }
}

void runHanoi(int n, char x, char y, char z){
	if (n == 1){
		printf("%c --> %c\n", x, z);
    return;
	}
	else {
    runHanoi(n-1,x,z,y);
		printf("%c --> %c\n", x, z);
		runHanoi(n-1,y,x,z);
	}


}

void lab2Reverse(char *userString, int start, int end) {
  char temp;

  if (start >= end){
    return;
  }

  else {
    temp = *(userString + start);
    *(userString + start) = *( userString + end);
    *(userString + end) = temp;

    start++;
    end--;

    lab2Reverse(userString, start, end);
  }
}

void lab2Ascii(char *userString, int start, int end) {
  int sum = 0;

  if (end < start) {
    printf("\n");
    return;
  }


  binaryConversion(userString[start], 7);
  printf("%s", binary);

  lab2Ascii(userString, ++start, end);
}

void binaryConversion(char target, int i){
  if (target == 0 && i==0) {
    binary[i] = '0';
    return;
  }
  else {
    if (target%2 == 1) {
      binary[i] = '1';
    } else {
      binary[i] = '0';
    }

    binaryConversion(target/2, i-1);
  }
}
