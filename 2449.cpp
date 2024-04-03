#include <stdio.h>
int main(void) {
	int a = 0;
	scanf("%d", &a);
	
	for (int i = 0 ; i < a ; i++) {
		for (int i1 = 0 ; i1 < a*2-i ; i1++) {
			if (i1 >= i && i1 < a*2-1 - i) {
				printf("*");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
	for (int i = a-2 ; i >= 0 ; i--) {
		for (int i1 = 0 ; i1 < a*2-i ; i1++) {
			if (i1 >= i && i1 < a*2-1 - i) {
				printf("*");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
}