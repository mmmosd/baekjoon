#include <stdio.h>

int ary[10005];

int n;

int main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &ary[i]);
	}
	
	int result = 0;
	for (int i = 0; i < n; i++) {
		// 3������ ���� 
		int bias = 10005;
		
		for (int j = i; j < i+3; j++) {
			if (j > n) break;
			
			if (ary[j] < bias) bias = ary[j];
		}
		
		for (int j = i; j < i+3; j++) {
			if (j > n) break;
			
			ary[j] -= bias;
		}
		result += bias*7;
	}
	
	for (int i = 0; i < n; i++) {
		// 1������ ����
		int bias = 10005;
		
		for (int j = i; j < i+2; j++) {
			if (j > n) break;
			
			if (ary[j] < bias) bias = ary[j];
		}
		
		for (int j = i; j < i+2; j++) {
			if (j > n) break;
			
			ary[j] -= bias;
		}
		result += bias*5;
	}
	
	for (int i = 0; i < n; i++) {
		// 1������ ���� 
		
		if (ary[i] > 0) {
			result += ary[i]*3;
			ary[i] = 0;
		}
	}
	
	printf("%d", result);
}
