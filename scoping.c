#include<stdio.h>

int main() {
	int a = 10;
	int b = 1, c = 2;
	{
		printf("%d\n", a);
		int a = 8;
		printf("b=%d c=%d\n", b, c);
		int c = b + c;
		printf("b=%d c=%d\n", b, c);
		printf("%d\n", a);
	}
}
