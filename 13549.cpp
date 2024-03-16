#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

typedef struct {
	int p, cost;
} pos;

struct cmp {
	bool operator()(pos a, pos b) {
		return a.cost > b.cost;
	}
};

int n, k;

int dir[2] = {-1, 1};

int find() {
	int result = 0;
	
	int dist[100005] = {0,};
	
	for (int i = 0; i <= 100000; i++) {
		dist[i] = 1987654321;
	}
	
	priority_queue<pos, vector<pos>, cmp> pq;
	
	pq.push({n, 0});
	dist[n] = 0;
	
	while (!pq.empty()) {
		pos now = pq.top();
		pq.pop();
		
		for (int i = 0; i < 3; i++) {
			pos move;
			int cost = i<2?1:0;
			
			if (i == 0) {
				move.p = now.p+1;
			}
			else if (i == 1) {
				move.p = now.p-1;
			}
			else {
				move.p = now.p*2;
			}
			
			if (move.p < 0 || move.p > 100000) continue;
			if (dist[move.p] <= cost+dist[now.p]) continue;
			
			dist[move.p] = cost+dist[now.p];
			pq.push({move.p, dist[move.p]});
		}
	}
	
//	for (int i = n; i <= k; i++) {
//		printf("==%d\n", dist[i]);
//	}
//	
	return dist[k];
}

int main() {
	scanf("%d%d", &n, &k);
	
	printf("%d", find());
}
