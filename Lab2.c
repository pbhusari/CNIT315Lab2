# include <stdio.h>

int factorial (int n) {
	if (n==0) {
		return 1;
	}
	else {
		return n * factorial (n-1)
	}
}

int fibonacci(int n) {
	if (n==0){
		return 0;
	}
	if (n==1) {
		return 1;
	}
	else {
		return fibonacci(n-1) + fibonacci(n-2);
	}

}

void runHanoi(int n, char x, char y, char z){
	if (n == 1){
		printf("%s --> %s\n", x, z);
	}
	else {
		runHanoi(n-1,x,z,y);
		runHanoi(1,x,y,z);
		runHanoi(n-1,y,x,z);
	}
}

void reverse(char str[], int start, int end) {

	printf("Input: %s\n", str);

	if (start < end) {
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;
	} else {
		printf("Output: %s\n", str);
	}

}



