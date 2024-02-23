#include <stdio.h>
#include <vector>
using namespace std;

typedef long long ll;

ll ary[1000005];
int n, m, k;

vector<ll> segment;

ll init_seg(int left, int right, int now) {
	if (left == right) return segment[now] = ary[left];
	
	if (left < right) {
		int mid = (left+right)/2;
		
		ll a = init_seg(left, mid, now*2)%1000000007;
		ll b = init_seg(mid+1, right, now*2+1)%1000000007;
		
		return segment[now] = (a*b)%1000000007;
	}
}

ll update_seg(int left, int right, int now, int idx) {
	if (idx < left || idx > right) return segment[now];
	
	if (left == right) return segment[now] = ary[left];
	
	if (left < right) {
		int mid = (left+right)/2;
		
		ll a = update_seg(left, mid, now*2, idx)%1000000007;
		ll b = update_seg(mid+1, right, now*2+1, idx)%1000000007;
		
		return segment[now] = (a*b)%1000000007;
	}
}

ll mul_seg(int left, int right, int now, int start, int end) {
	if (right < start || end < left) return 1;
	if (start <= left && right <= end) return segment[now];
	
	if (left < right) {
		int mid = (left+right)/2;
		
		ll a = mul_seg(left, mid, now*2, start, end)%1000000007;
		ll b = mul_seg(mid+1, right, now*2+1, start, end)%1000000007;
	
		return (a*b)%1000000007;
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	
	for (int i = 0; i < n; i++) {
		scanf("%lld", &ary[i]);
	}
	
	segment.resize(n*4);
	init_seg(0, n-1, 1);
	
	for (int i = 0; i < m+k; i++) {
		int a, b;
		ll c;
		
		scanf("%d%d%lld", &a, &b, &c);
		
		if (a == 1) {
			ary[b-1] = c;
			update_seg(0, n-1, 1, b-1);
		}
		else if (a = 2) {
			printf("%lld\n", mul_seg(0, n-1, 1, b-1, c-1));
		}
	}
}
