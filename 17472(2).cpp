#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
	int i, j;
} pos;

typedef struct {
	int a, b, c;
} graph_info;

int grid[15][15];
vector<pos> island_elements[10];
int island_num;

graph_info ginfo[10];
int island_graph[10][10];
int parent[10];

int n, m;

int dir[4][2] = {
	{1, 0}, {0, 1}, {-1, 0}, {0, -1}
};

bool cmp(graph_info a, graph_info b) {
	return a.c < b.c;
}

void init_parent(int n) {
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}
}

int find(int v) {
	if (v == parent[v]) return v;
	
	return parent[v] = find(parent[v]);
}

void merge(int a, int b) {
	int a_root = find(a), b_root = find(b);
	
	if (a_root == b_root) return;
	
	if (a_root < b_root) {
		parent[b_root] = a_root;
	}
	else {
		parent[a_root] = b_root;
	}
}

void make_island() {
	int visited[15][15] = {0,};
	queue<pos> q;
	
	island_num = 0;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 1 && visited[i][j] == 0) {
				island_num++;
				
				q.push({i, j});
				grid[i][j] = island_num;
				visited[i][j] = 1;
				island_elements[island_num].push_back({i, j});
				
				while (!q.empty()) {
					pos now = q.front();
					q.pop();
					
					for (int i = 0; i < 4; i++) {
						pos move = {now.i + dir[i][0], now.j + dir[i][1]};
						
						if (move.i < 0 || move.j < 0 || move.i >= n || move.j >= m) continue;
						if (grid[move.i][move.j] == 0) continue;
						if (visited[move.i][move.j] == 1) continue;
						
						q.push(move);
						grid[move.i][move.j] = island_num;
						visited[move.i][move.j] = 1;
						island_elements[island_num].push_back(move);
					}
				}
			}
		}
	}
	
	init_parent(island_num);
}

int graph_idx;

void make_bridge() {
	graph_idx = 0;
	
	for (int i = 1; i <= island_num; i++) {
		int size = island_elements[i].size();
		
		for (int j = 0; j < size; j++) {
			pos now = island_elements[i][j];
			
			for (int k = 0; k < 4; k++) {
				int len = 0;
				int target = -1;
				
				pos move = now;
				
				for (int l = 0; l < 10; l++) {
					move = {move.i + dir[k][0], move.j + dir[k][1]};
					
					if (move.i < 0 || move.j < 0 || move.i >= n || move.j >= m) break;
					
					if (grid[move.i][move.j] == i) break;
					else if (grid[move.i][move.j] != 0) {
						target = grid[move.i][move.j];
						break;
					}
					
					len++;
				}
				
				if (target != -1 && len > 1) {
					if (island_graph[i][target] != 0 && island_graph[target][i] != 0) { //이미 이어진 곳이라면 
						if (len < island_graph[i][target]) {
							island_graph[i][target] = len;
							island_graph[target][i] = len;
							ginfo[graph_idx].a = i;
							ginfo[graph_idx].b = target;
							ginfo[graph_idx++].c = len;
						}
					}
					else {
						island_graph[i][target] = len;
						island_graph[target][i] = len;
						ginfo[graph_idx].a = i;
						ginfo[graph_idx].b = target;
						ginfo[graph_idx++].c = len;
					}
				}
			}
		}
	}
	
	sort(ginfo, ginfo+graph_idx, cmp);
}

int find_min_bridge() {
	int result = 0;
	
	for (int i = 0; i < graph_idx; i++) {
//		printf("a: %d | b: %d | cost: %d\n", ginfo[i].a, ginfo[i].b, ginfo[i].c);
		
		if (find(ginfo[i].a) != find(ginfo[i].b)) {
			merge(ginfo[i].a, ginfo[i].b);
			result += ginfo[i].c;
//			printf("merge: %d, %d\n", ginfo[i].a, ginfo[i].b);
//			for (int j = 1; j <= 4; j++) {
//				printf("%d ", find(j));
//			}
//			puts("");
		}
	}
	
	int root = find(1);
	int isConnectedAll = 1;
	for (int i = 1; i <= island_num; i++) {
//		printf("===%d, %d\n", find(i), find(1));
		
		if (find(i) != root) {
			isConnectedAll = 0;
//			break;
		}
	}
	
	if (isConnectedAll) {
		return result;
	}
	else {
		return -1;
	}
}

int main() {
	scanf("%d%d", &n, &m);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &grid[i][j]);
		}
	}
	
	make_island();
	make_bridge();
	printf("%d", find_min_bridge());
}
