#include <stdio.h>

typedef long long ll;

ll segment[4000005];

int n;

void update(int now, int left, int right, int idx, ll diff) {
	if (idx < left || idx > right) return;

	if (left == right) {
		segment[now] += diff;
		if (segment[now] < 0) segment[now] = 0;
	}

	if (left < right) {
		int mid = (left + right) / 2;

		update(now*2, left, mid, idx, diff);
		update(now*2+1, mid+1, right, idx, diff);

		segment[now] = segment[now*2] + segment[now*2+1];
		if (segment[now] < 0) segment[now] = 0;
	}
}

ll sum(int now, int left, int right, int start, int end) {
	if (left > end || right < start) return 0;
	if (start <= left && right <= end) return segment[now];

	if (left < right) {
		int mid = (left+right)/2;
		ll a = sum(now*2, left, mid, start, end);
		ll b = sum(now*2+1, mid+1, right, start, end);

		return a+b;
	}
}

int find(int t) {
	int s = 1, e = 1000000, m = 0;
	ll a = 0;

	while (s < e) {
		m = (s+e)/2;
		a = sum(1, 1, 1000000, s, m);

		if (a >= t) { // s ~ m 의 구간합이 뽑으려는 순위보다 크거나 같음 => 해당 구간 내에 찾고자 하는 순위 존재
			e = m;
		}
		else {
			s = m+1;
			t -= a;
		}
	}

	return s;
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		
		if (a == 1) { //사탕 꺼내기, 꺼낼 맛의 번호 출력
			int b;
			//b: 꺼낼 사탕의 순위
			scanf("%d", &b);
			int t = find(b);
			update(1, 1, 1000000, t, -1);

			printf("%d\n", t);
		}
		else { //사탕 넣기
			int b, c;
			//b: 넣을 사탕의 맛
			//c: 그러한 사탕의 갯수, 음수면 사탕을 뺀다. 
			scanf("%d%d", &b, &c);
			update(1, 1, 1000000, b, c);
		}
	}
}