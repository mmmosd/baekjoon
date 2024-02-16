#include <stdio.h>
#include <algorithm>
using namespace std;

typedef struct {
	int x, y;
} Water;

int ary[100005];

int n;

bool cmp(int a, int b) {
	return a < b;
}

Water find() {
	int p1 = 0, p2 = n-1;
	Water result = {ary[p1], ary[p2]};
	
	while (p1 < p2) {
		if (ary[p1] + ary[p2] == 0) {
			result.x = ary[p1];
			result.y = ary[p2];
			return result;
		}
		else if (ary[p1] + ary[p2] < 0) {
			int aA = (ary[p1] + ary[p2])<0?(ary[p1] + ary[p2])*-1:(ary[p1] + ary[p2]);
			int bA = (result.x + result.y)<0?(result.x + result.y)*-1:(result.x + result.y);
			
			if (aA < bA) {
				result.x = ary[p1];
				result.y = ary[p2];
			}
			
			p1++;
		}
		else if (ary[p1] + ary[p2] > 0) {
			int aA = (ary[p1] + ary[p2])<0?(ary[p1] + ary[p2])*-1:(ary[p1] + ary[p2]);
			int bA = (result.x + result.y)<0?(result.x + result.y)*-1:(result.x + result.y);
			
			if (aA < bA) {
				result.x = ary[p1];
				result.y = ary[p2];
			}
			
			p2--;
		}
	}
	
	return result;
}

int main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &ary[i]);
	}
	
	sort(ary, ary+n, cmp);
	
	Water w = find();
	
	printf("%d %d", w.x, w.y);
}
