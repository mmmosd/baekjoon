#include <stdio.h>

int ary[10005]; //1~n

int n, m;

int find() {
	int p1 = 0, p2 = 0;
	int now = ary[0];
	int result = 0;
	
	while (p1 <= p2) {
//		printf("%d ", now);
		
		if (now == m) {
			result++;
			
			now += ary[++p2];
			now -= ary[p1++];
		}
		
		if (now < m) {
			now += ary[++p2];
		}
		else {
			now -= ary[p1++];
		}
		
		if (p2 >= n) break;
	}
	
	return result;
}

int main() {
	scanf("%d%d", &n, &m);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &ary[i]);
	}
	
	printf("%d", find());
}
