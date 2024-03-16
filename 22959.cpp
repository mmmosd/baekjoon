#include <stdio.h>
#include <vector>
using namespace std;

typedef long long ll;

ll ary[200005];
vector<ll> sumseg;
vector<ll> minseg;

int n, m;

void update(int now, int left, int right, int idx, ll diff) {
	if (idx < left || right < idx) return;
	
	if (left == right) sumseg[now] = diff;
	
	if (left < right) {
		int mid = (left + right) / 2;
		
		update(now*2, left, mid, idx, diff);
		update(now*2+1, mid+1, right, idx, diff);
		
		sumseg[now] = sumseg[now*2] + sumseg[now*2+1];
	}
}

void minseg_update(int now, int left, int right, int idx, ll diff) {
	if (idx < left || right < idx) return;
	
	if (left == right) minseg[now] = diff;
	
	if (left < right) {
		int mid = (left + right) / 2;
		
		minseg_update(now*2, left, mid, idx, diff);
		minseg_update(now*2+1, mid+1, right, idx, diff);
		
		if (minseg[now*2] < minseg[now*2+1]) {
			minseg[now] = minseg[now*2];
		}
		else {
			minseg[now] = minseg[now*2+1];
		}
	}
}

ll find_sum(int now, int left, int right, int start, int end) {
	if (start <= left && right <= end) return sumseg[now];
	if (start > right || end < left) return 0;
	
	if (left < right) {
		int mid = (left + right) / 2;
		
		ll a = find_sum(now*2, left, mid, start, end);
		ll b = find_sum(now*2+1, mid+1, right, start, end);
		
		return a + b;
	}
}

ll find_min(int now, int left, int right, int start, int end) {
	if (start <= left && right <= end) return minseg[now];
	if (start > right || end < left) return 10000000005;
	
	if (left < right) {
		int mid = (left + right) / 2;
		
		ll a = find_min(now*2, left, mid, start, end);
		ll b = find_min(now*2+1, mid+1, right, start, end);
		
		if (a < b) return a;
		else return b;
	}
}

ll find(int idx, ll j) {
	int startP = 0, endP = 0;
	
	// find left
	int left = 1, right = idx, mid = 0;
	while (left <= right) {
		if (left == right) {
			startP = left;
			break;
		}
		
		mid = (left + right) / 2;
		ll leftmin = find_min(1, 1, n, left, mid);
		ll rightmin = find_min(1, 1, n, mid+1, right);
		
//		printf("Left==Lmin: %d, Rmin: %d\n",leftmin, rightmin);
		
		if (rightmin < j) {
			left = mid+1;
		}
		else if (leftmin < j) {
			right = mid;
		}
		else {
			startP = 1;
			break;
		}
	}
	
	if (ary[startP] < j) startP++;
	
	//find right
	left = idx, right = n, mid = 0;
	while (left <= right) {
		if (left == right) {
			endP = left;
			break;
		}
		
		mid = (left + right) / 2;
		ll leftmin = find_min(1, 1, n, left, mid);
		ll rightmin = find_min(1, 1, n, mid+1, right);
		
//		printf("Right==Lmin: %d, Rmin: %d\n",leftmin, rightmin);
		
		if (leftmin < j) {
			right = mid;
		}
		else if (rightmin < j) {
			left = mid+1;
		}
		else {
			endP = n;
			break;
		}
	}
	
	if (ary[endP] < j) endP--;
	
	
//	printf("====%d, %d\n", startP, endP);
	return find_sum(1, 1, n, startP, endP);
}

int main() {
	scanf("%d", &n);
	
	minseg.resize(n*4);
	sumseg.resize(n*4);
	
	for (int i = 1; i <= n; i++) {
		ll v;
		scanf("%lld", &v);
		
		ary[i] = v;
		
		update(1, 1, n, i, v);
		minseg_update(1, 1, n, i, v);
	}
	
	scanf("%d", &m);
	
	for (int i = 0; i < m; i++) {
		int q;
		scanf("%d", &q);
		
		if (q == 1) {
			ll v;
			int idx;
			scanf("%d%lld", &idx, &v);
			
			ary[idx] = v;
			
			update(1, 1, n, idx, v);
			minseg_update(1, 1, n, idx, v);
			
//			printf("%d\n%d\n", minseg[1], sumseg[1]);
		}
		else {
			int a;
			ll b;
			scanf("%d%lld", &a, &b);
			
			printf("%lld\n", find(a, b));
		}
	}
}
