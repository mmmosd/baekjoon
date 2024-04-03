#include <stdio.h>

int n;

int main() {
	scanf("%d", &n);
	
	int max = 0;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int t = 0;
		scanf("%d", &t);
		
		if (t > max) max = t;
		sum+=t;
	}
	
	printf("%d", sum-max);
}
