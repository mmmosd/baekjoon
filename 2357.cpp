#include <stdio.h>
#include <vector>
using namespace std;

typedef long long ll;

typedef struct {
	ll min, max;
}node;

vector<node> segment;

ll ary[100005];

int n, m;

node init_seg(int left, int right, int now) {
	if (now == 1) segment.resize(n*4);
	
	if (left == right) {
		segment[now].min = ary[left];
		segment[now].max = ary[left];
		
		return segment[now];
	}

	if (left < right) {
		int mid = (left+right)/2;
		
		node a = init_seg(left, mid, now*2);
		node b = init_seg(mid+1, right, now*2+1);
		
		segment[now].min = a.min<b.min?a.min:b.min;
		segment[now].max = a.max>b.max?a.max:b.max;
		
		return segment[now];
	}
}

node find_seg(int left, int right, int now, int start, int end) {
	if (start > right || end < left) return {-1, -1};
	if (start < left && right < end) return segment[now];
	if ((start == left || right == end) && left == right) return segment[now]; // min == max
	
	if (left < right) {
		int mid = (left+right)/2;
		
		node a = find_seg(left, mid, now*2, start, end);
		node b = find_seg(mid+1, right, now*2+1, start, end);
		
		node result = {a.min<b.min?a.min:b.min, a.max>b.max?a.max:b.max};
		
		if (a.min == -1 && a.max == -1) {
			result = b;
		}
		
		if (b.min == -1 && b.max == -1) {
			result = a;
		}
		
		return result;
	}
}

int main() {
	scanf("%d%d", &n, &m);
	
	for (int i = 0; i < n; i++) {
		scanf("%lld", &ary[i]);
	}
	
	init_seg(0, n-1, 1);
	
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		
		node result = find_seg(0, n-1, 1, a-1, b-1);
		printf("%lld %lld\n", result.min, result.max);
	}
}
