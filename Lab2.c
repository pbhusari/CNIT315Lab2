#include <stdio.h>
#include <string.h>

int main() {
  int factorial(int n);
  int fibbonacci(int n);
  void runHanoi(int n, char x, char y, char z);
  void lab2Reverse(char *userString, int start, int end);


  int again = 1;
  int userChoice = 0;
  int userN = 0;
  int i;
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
        printf("Result: %i\n", factorial(userN));
        userN = 0;
        break;
      case 2:
        printf("How many iterations of fibonacci: ");
        scanf("%i", &userN);
        printf("Result: ");

        for(i=0; i<userN; i++){
          printf(" %i", fibbonacci(i));
        }
        printf("\n");
        userN = 0;
        break;
      case 3:
        printf("You have chosen towers of hanoi\n");
        printf("How many iterations of towers of hanoi: ");
        scanf("%i", &userN);
        runHanoi(userN, 'S', 'A', 'D');
        userN =0;
        break;
      case 4:
        printf("Enter the string you want to reverse: ");
        scanf("%s", userString);
        lab2Reverse(userString, 0, strlen(userString) -1);
        printf("Reversed String: %s\n", userString);
        break;
      case 5:
        printf("You have chosen string to ascii\n");
        break;
      case 6:
        printf("You have chosen ascii to string\n");
        break;
      default:
        printf("Invalid Input\n");
    }

    printf("Would you like to perform another calculation? (1 = Yes, 0 = No): ");
		scanf("%i", &again);

  }

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
