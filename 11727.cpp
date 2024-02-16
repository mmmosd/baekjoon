#include <stdio.h>

int ary[1005] = {-1, 1, 2};

int n;

int find(int t) {
	if (ary[t] != 0) { // 이전의 두 수와 더할 수 없다면 
		return ary[t];
	}
	else { //  더할 수 있다면
		ary[t] = find(t-1) + find(t-2);
		return ary[t]%10007;
	}
}

int main() {
	scanf("%d", &n);
	
	printf("%d", find(n));
}
