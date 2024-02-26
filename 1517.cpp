#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

typedef struct {
	ll value;
	int idx;
} num;

vector<ll> segment;

num ary[500005];
int n;

bool cmp(num a, num b) {
	if (a.value != b.value) {
		return a.value < b.value;
	}
	else {
		return a.idx < b.idx;
	}
}

void init_seg() {
	segment.resize(n*4);
}

void update_seg(int left, int right, ll now, int idx) {
	if (idx < left || right < idx) return;
	
	if (left < right) {
		int mid = (left+right)/2;
		
		update_seg(left, mid, now*2, idx);
		update_seg(mid+1, right, now*2+1, idx);
	}
	
	segment[now]++;
}

ll find_seg(int left, int right, ll now, int start, int end) {
	if (start > right || left > end) return 0;
	if (start <= left && right <= end) return segment[now];
	
	if (left < right) {
		int mid = (left+right)/2;
		
		ll a = find_seg(left, mid, now*2, start, end);
		ll b = find_seg(mid+1, right, now*2+1, start, end);
	
		return a+b;
	}
}

ll find() {
	ll result = 0;
	
	sort(ary, ary+n, cmp);
	init_seg();
	
	for (int i = 0; i < n; i++) {
		if (ary[i].idx+1 <= n-1) {
			result += find_seg(0, n-1, 1, ary[i].idx+1, n-1);
		}
		
		update_seg(0, n-1, 1, ary[i].idx);
	}
	
	return result;
}

int main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%lld", &ary[i].value);
		ary[i].idx = i;
	}
	
	printf("%lld", find());
}
