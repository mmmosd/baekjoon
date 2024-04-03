#include <stdio.h>

typedef long long ll;

ll ary[1000005];
ll segment[4000005];

int n;

void update(int now, int left, int right, int idx, ll diff) {
	if (left == right) segment[now] = diff;

	if (left < right) {
		int mid = (left + right) / 2;

		update(now*2, left, mid, idx, diff);
		update(now*2+1, mid+1, right, idx, diff);

		segment[now] = segment[now*2] + segment[now*2+1];
	}
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		
		if (a == 1) { //사탕 꺼내기
			int b;
			//b: 꺼낼 사탕의 순위
			scanf("%d", &b);
			update(1, 1, 1000000, b, -1);
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