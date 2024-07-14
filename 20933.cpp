#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

typedef long long ll;

typedef struct {
    ll left, right;
} Sum;

Sum ary[1000005];
vector<Sum> sumseg;
vector<ll> minseg;

int n, q;

void sumseg_update_left(int now, int left, int right, int idx, ll diff) {
	if (idx < left || right < idx) return;
	
	if (left == right) sumseg[now].left = diff;
	
	if (left < right) {
		int mid = (left + right) / 2;
		
		sumseg_update_left(now*2, left, mid, idx, diff);
		sumseg_update_left(now*2+1, mid+1, right, idx, diff);
		
		sumseg[now].left = sumseg[now*2].left + sumseg[now*2+1].left;
	}
}

void sumseg_update_right(int now, int left, int right, int idx, ll diff) {
	if (idx < left || right < idx) return;
	
	if (left == right) sumseg[now].right = diff;
	
	if (left < right) {
		int mid = (left + right) / 2;
		
		sumseg_update_right(now*2, left, mid, idx, diff);
		sumseg_update_right(now*2+1, mid+1, right, idx, diff);
		
		sumseg[now].right = sumseg[now*2].right + sumseg[now*2+1].right;
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

Sum find_sum(int now, int left, int right, int start, int end) {
	if (start <= left && right <= end) return sumseg[now];
	if (start > right || end < left) return {0, 0};
	
	if (left < right) {
		int mid = (left + right) / 2;
		
		Sum a = find_sum(now*2, left, mid, start, end);
		Sum b = find_sum(now*2+1, mid+1, right, start, end);
		
		return {a.left + b.left, a.right + b.right};
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

ll find(int x, ll m) {
    int rs = -1, re = -1;

    int left = 1, right = x-1, mid = 0;
    ll time = m;

    if (x == 1 || ary[right].left > m) rs = x;
    else {
        while (left < right) { //find left
            mid = (left + right) / 2;
            ll t = find_sum(1, 1, n, mid+1, right).left;

            // printf("1====%lld \\ %lld | %d %d %d\n", time, t, left, mid, right);

            if (t < time) {
                time -= t;
                right = mid;
            }
            else if (t > time) {
                left = mid+1;
            }
            else {
                rs = mid+1;
                break;
            }
        }
        // printf("==%d %d\n", left, right);
        if (rs == -1) rs = left;
    }

    left = x+1, right = n, mid = 0;
    time = m;

    if (x == n || ary[left].right > m) re = x;
    else {
        while (left < right) { // find right
            mid = (left + right) / 2;
            ll t = find_sum(1, 1, n, left, mid).right;

            // printf("2====%lld \\ %lld | %d %d %d\n", time, t, left, mid, right);

            if (t < time) {
                time -= t;
                left = mid+1;
            }
            else if (t > time) {
                right = mid;
            }
            else {
                re = mid;
                break;
            }
        }
        // printf("==%d %d\n", left, right);
        if (re == -1) re = right;
    }

    // printf("==%d %d\n", rs, re);

    return find_min(1, 1, n, rs, re);
}

int main() {
	scanf(" %d", &n);

    sumseg.resize(n*4);
    minseg.resize(n*4);

    for (int i = 0; i < n; i++) {
        ll in;
        scanf(" %lld", &in);

        minseg_update(1, 1, n, i+1, in);
    }

    sumseg_update_left(1, 1, n, n, 0);
    sumseg_update_right(1, 1, n, 1, 0);
    for (int i = 1; i < n; i++) {
        ll in;
        scanf(" %lld", &in);

        sumseg_update_left(1, 1, n, i, in);
        sumseg_update_right(1, 1, n, i+1, in);
        ary[i].left = in;
        ary[i+1].right = in;
    }

    scanf("%d", &q);

    for (int i = 0; i < q; i++) {
        char str[10] = "";
        scanf(" %s", str);

        if (strcmp(str, "UPDATE") == 0) {
            ll x, t;
            scanf(" %lld %lld", &x, &t);

            sumseg_update_left(1, 1, n, x, t);
            sumseg_update_right(1, 1, n, x+1, t);
            ary[x].left = t;
            ary[x+1].right = t;
        }
        else {
            ll x, m;
            scanf(" %lld %lld", &x, &m);

            printf("%lld\n", find(x, m));
        }
    }
}
