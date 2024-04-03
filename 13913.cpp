#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

typedef struct {
	int p, cost;
} pos;

int n, k;

int dir[2] = {-1, 1};

void find() {
	int result = 0;
	
	int check[100005] = {0,};
	
	for (int i = 0; i <= 100000; i++) {
		check[i] = -1;
	}
	
	int result_cost = 0;
	int result_pos = 0;

	queue<pos> q;
	
	q.push({n, 0});
	check[n] = 0;
	
	while (!q.empty()) {
		pos now = q.front();
		q.pop();

		if (now.p == k) {
			result_cost = now.cost;
			result_pos = now.p;
			break;
		}
		
		for (int i = 0; i < 3; i++) {
			pos move = {i<2?now.p+dir[i]:now.p*2, now.cost+1};
			
			if (move.p < 0 || move.p > 200000) continue;
			if (check[move.p] != -1) continue;

			check[move.p] = now.p;
			
			q.push(move);
		}
	}

	printf("%d\n", result_cost);

	int route[100005] = {0,};
	int idx = result_pos;
	
	route[result_cost + 1] = result_pos;
	for (int i = result_cost; i >= 0; i--) {
		route[i] = check[idx];
		idx = route[i];
	}

	for (int i = 1; i <= result_cost+1; i++) {
		printf("%d ", route[i]);
	}
}

int main() {
	scanf("%d%d", &n, &k);

	find();
}