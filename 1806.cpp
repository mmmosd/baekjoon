#include <stdio.h>

int ary[100005];

int n, s;

bool cmp(int a, int b) {
	return a < b;
}

int find() {
	int p1 = 0, p2 = 0;
	int now = ary[0];
	int result = 999999;
	
	while (p1 <= p2 && p2 < n) {
		if (now >= s) {
			if (p2-p1+1 < result) {
				result = p2-p1+1;
//				printf("==%d, %d\n", p1, p2);
			}
		}
		
		if (now < s) {
			now += ary[++p2];
		}
		else if (now > s) {
			now -= ary[p1++];
		}
		else if (now == s) {
			now -= ary[p1++];
			now += ary[++p2];
		}
	}
	
	if (result == 999999) return 0;
	else return result;
}

int main() {
	scanf("%d%d", &n, &s);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &ary[i]);
	}
	
	printf("%d", find());
}
