#include <stdio.h>
#include <algorithm>
using namespace std;

int ary[100005];

int n, s;

bool cmp(int a, int b) {
	return a < b;
}

int find() {
	int p1 = 0, p2 = n-1;
	int t = 0;
	int result = 999999;
	
	while (p1 < p2) {
		
	}
	
	if (result == 999999) return 0;
	else return result;
}

int main() {
	scanf("%d%d", &n, &s);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &ary[i]);
	}
	
	sort(ary, ary+n, cmp);
	
	printf("%d", find());
}
