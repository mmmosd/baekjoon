#include <stdio.h>
#include <vector>
using namespace std;

typedef long long ll;

typedef struct {
	ll v;
	int idx;
} node;

ll ary[100005];
vector<node> segment;

int n, m;

void update(int now, int left, int right, int idx) {
	if (idx < left || idx > right) return;
	
	if (left == right && left == idx) {
		segment[now] = {ary[left], left};
	}
	
	if (left < right) {
		int mid = (left + right)/2;
	
		update(now*2, left, mid, idx);
		update(now*2+1, mid+1, right, idx);
		
		node a = segment[now*2];
		node b = segment[now*2+1];
		
		if (a.v < b.v) {
			segment[now] = a;
		}
		else if (a.v > b.v) {
			segment[now] = b;
		}
		else {
			if (a.idx < b.idx) {
				segment[now] = a;
			}
			else {
				segment[now] = b;
			}
		}
	}
}

node find(int now, int left, int right, int start, int end) {
	if (start > right || end < left) return {-1, -1};
	if (start < left && right < end) return segment[now];
	if ((start == left || right == end) && left == right) return segment[now];

	if (left < right) {
		int mid = (left + right)/2;
		
		node a = find(now*2, left, mid, start, end);
		node b = find(now*2+1, mid+1, right, start, end);
		
		if (a.v == -1 && a.idx == -1) {
			return b;
		}
		
		if (b.v == -1 && b.idx == -1) {
			return a;
		}
		
		if (a.v < b.v) {
			return a;
		}
		else if (a.v > b.v) {
			return b;
		}
		else {
			if (a.idx < b.idx) {
				return a;
			}
			else {
				return b;
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	
	segment.resize(n*4);
	
	for (int i = 1; i <= n; i++) {
		ll a;
		scanf("%lld", &a);
		ary[i] = a;
		update(1, 1, n, i);
	}
	
	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		int a;
		scanf("%d", &a);
		
		if (a == 1) { // 수열의 i번째의 수를 v로 바꾼다. 
			ll v;
			int idx;
			scanf("%d%lld", &idx, &v);
			
			ary[idx] = v;
			
			update(1, 1, n, idx);
		}
		else { // 크기가 가장 작은 값의 인덱스 출력
			int idx, j;
			scanf("%d%d", &idx, &j);
			 
			printf("%d\n", find(1, 1, n, idx, j).idx);
		}
	}
}
