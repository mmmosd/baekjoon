#include <stdio.h>

int ary[1005] = {-1, 1, 2};

int n;

int find(int t) {
	if (ary[t] != 0) { // ������ �� ���� ���� �� ���ٸ� 
		return ary[t];
	}
	else { //  ���� �� �ִٸ�
		ary[t] = find(t-1) + find(t-2);
		return ary[t]%10007;
	}
}

int main() {
	scanf("%d", &n);
	
	printf("%d", find(n));
}
