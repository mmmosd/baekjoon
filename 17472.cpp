#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

typedef struct {
	int i, j;
} pos;

int grid_map[15][15];
pos grid_parent[15][15];

int parent[105];

int n, m;

int dir[4][2] = {
	{1, 0}, {-1, 0}, {0, 1}, {0, -1}
};

struct compare {
	bool operator()(pos a, pos b) {
		return grid_map[a.i][a.j] > grid_map[b.i][b.j];
	}
};

void make_island(priority_queue<pos, vector<pos>, compare> pq) {
	int visited[15][15] = {0,};
	
	while (!pq.empty()) {
		pos now = pq.top();
		pq.pop();
		
		for (int i = 0; i < 4; i++) {
			pos move = {now.i+dir[i][0], now.j+dir[i][1]};
			
			if (move.i < 0 || move.j < 0 || move.i >= n || move.j >= m) continue;
			if (grid_map[move.i][move.j] == 0) continue;
			if (grid_map[move.i][move.j] <= grid_map[now.i][now.j]) continue;
			
			visited[move.i][move.j] = 1;
			grid_map[move.i][move.j] = grid_map[now.i][now.j];
			pq.push(move);
		}
	}
}

void find_island_distance() {
	
}

int find_in_graph(int v) {
	if (v == parent[v]) return v;
	
	return parent[v] = find_in_graph(parent[v]);
}

void merge_in_graph(int a, int b) {
	int a_root = find_in_graph(a), b_root = find_in_graph(b);
	
	if (a_root == b_root) return;
	
	if (a_root < b_root) {
		parent[b] = a_root;
	}
	else {
		parent[a] = b_root;
	}
}

int main() {
	scanf("%d%d", &n, &m);
	
	priority_queue<pos, vector<pos>, compare> pq;
	int N = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &grid_map[i][j]);
			if (grid_map[i][j] == 1) pq.push({i, j}), grid_map[i][j] = N++, grid_parent[i][j] = {i, j};
		}
	}
	
	
	//�� ���鸶�� �ֻ��� ��带 ���ϱ� (�Ϸ�) 
	//�� ���鸶�� �ִܰŸ��� ���� ���ο� �׷����� ������ ����ġ�� ���ϱ� (�ϴ� �ٸ������)
	//�׷��� ���� ����ġ�� ���� �ּ� ���д� Ʈ�� �����
	//�ּ� ���д� Ʈ���� ��� ����ġ ���ϱ�
	
	//���� �����ϴ� ���հ� ���� ���� ������ ���� �����ؾ� ��  
}
