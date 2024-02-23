#include <stdio.h>
#include <vector>
using namespace std;

typedef long long ll;

ll ary[1000005];
vector<ll> segment;

int N, M, K;

ll init_segment(int left, int right, int now) {
	if (now == 1) segment.resize(4*N);
	
	int mid = (left+right)/2;
	
	if (left == right) return segment[now] = ary[left];
	
	if (left < right) {
		ll a = init_segment(left, mid, now*2);
		ll b = init_segment(mid+1, right, now*2+1);
		
		return segment[now] = a+b;
	}
}

void update_segment(int left, int right, int now, int idx, ll diff) {
	if (idx < left || right < idx) return;
	
	if (left < right) {
		int mid = (left+right)/2;
		
		update_segment(left, mid, now*2, idx, diff);
		update_segment(mid+1, right, now*2+1, idx, diff);
	}
	
	segment[now] += diff;
}

ll sum(int left, int right, int now, int start, int end) {
	if (right < start || end < left) return 0;
	if (start <= left && right <= end) return segment[now];
	
	if (left < right) {
		int mid = (left+right)/2;
		
		ll a = sum(left, mid, now*2, start, end);
		ll b = sum(mid+1, right, now*2+1, start, end);
		
		return a+b;
	}
}

int main() {
	scanf("%d%d%d", &N, &M, &K);
	
	for (int i = 0 ; i < N; i++) {
		scanf("%lld", &ary[i]);
	}
	
	init_segment(0, N-1, 1);
	
	for (int i = 0; i < M+K; i++) {
		int a, b;
		ll c;
		scanf("%d%d%lld", &a, &b, &c);
		
		if (a == 1) {
			ll diff = c-ary[b-1];
			ary[b-1] = c;
			update_segment(0, N-1, 1, b-1, diff);
		}
		else if (a == 2) {
			printf("%lld\n", sum(0, N-1, 1, b-1, c-1));
		}
	}
}
