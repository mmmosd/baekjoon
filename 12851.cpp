#include <stdio.h>
#include <queue>
using namespace std;

typedef struct {
	int p, cost;
} pos;

int n, k;

int dir[2] = {-1, 1};

void find() {
	int result_cost = -1;
	int result_cnt = 0;

	int visited[100005] = {0,};

	if (n == k) {
		printf("0\n1");
		return;
	}
	
	queue<pos> q;
	
	q.push({n, 0});

	for (int i = 0; i <= 100000; i++) {visited[i] = 100005;}
	
	while (!q.empty()) {
		pos now = q.front();
		q.pop();
		
		for (int i = 0; i < 3; i++) {
			pos move = {i<2?now.p+dir[i]:now.p*2, now.cost+1};
			
			if (move.p < 0 || move.p > 100000) continue;
			if (result_cost != -1 && move.cost > result_cost) continue;
			
			if (result_cost == -1 && visited[move.p] != 100005 && move.cost > visited[move.p]) continue;
			if (result_cost == -1) visited[move.p] = move.cost;

			if (move.p == k) {
				if (result_cost == -1) {
					result_cost = move.cost;
					result_cnt++;
				}
				else if (move.cost == result_cost) result_cnt++;
			}
			else q.push(move);
		}
	}
	
	printf("%d\n%d", result_cost, result_cnt);
}

int main() {
	scanf("%d%d", &n, &k);
	
	find();
}