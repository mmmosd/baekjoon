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
	
	if (find(n)-1 > 2) {
		printf("%d", (find(n) + find(n)-1)%10007);
	}
	else {
		printf("%d", (find(n)*4-n*2+1)%10007);
	}
}
