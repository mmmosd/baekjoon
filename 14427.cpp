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
			printf("%d\n", segment[1].idx);
		}
	}
}
