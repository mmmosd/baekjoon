#include <stdio.h>
#include <algorithm>
using namespace std;

int ary[500005];

int n, m;

bool cmp(int a, int b) {
	return a < b;
}

int find(int left, int right, int target) {
	int mid = (left+right)/2;
	
	if (left == right) return left;
	
	if (left < right) {
		if (ary[left] < target < ary[mid]) return find(left, mid, target);
		else return find(mid, right, target);
	}
}

int main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &ary[i]);
	}
	
	sort(ary, ary+n, cmp);
	
	scanf("%d", &m);
	
	for (int i = 0; i < m; i++) {
		int temp;
		scanf("%d", &temp);
		
		printf("%d ", find(0, n-1, temp));
	}
}
