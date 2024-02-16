#include <stdio.h>
#include <algorithm>
using namespace std;

int ary[100005];

int n, x;

bool cmp(int a, int b) {
	return a < b;
}

int find() {
	int p1 = 0, p2 = n-1;
	int result = 0;
	
	while (p1 < p2) {
		if (ary[p1] + ary[p2] == x) {
			result++;
			p1++;
			p2--;
		}
		else if (ary[p1] + ary[p2] < x) {
			p1++;
		}
		else if (ary[p1] + ary[p2] > x) {
			p2--;
		}
	}
	
	return result;
}

int main() {
	scanf("%d", &n);
	
	for (int i = 0 ; i < n; i++) {
		scanf("%d", &ary[i]);
	}
	
	scanf("%d", &x);
	
	sort(ary, ary+n, cmp);
	
//	for (int i = 0; i < n; i++) {
//		printf("==%d\n", ary[i]);
//	}
	
	printf("%d", find());
}
