#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

typedef struct {
	int i, j;
} pos;

typedef struct {
	int a, b, len;
} bridge;

int grid_map[15][15];
pos grid_parent[15][15];

int parent[105];
bridge bridges[105];
int bridges_count;

int n, m;

int dir[4][2] = {
	{1, 0}, {-1, 0}, {0, 1}, {0, -1}
};

struct compare {
	bool operator()(pos a, pos b) {
		return grid_map[a.i][a.j] > grid_map[b.i][b.j];
	}
};

bool cmp(bridge a, bridge b) {
	return a.len < b.len;
}

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
	// ����, ���η� �� �پ� �˻�
	// �� �ٿ� ���� ������ 2�� �̻��̶�� �� ���� ���̸� �޲�
	// �� �� ���̸� �޲� ĭ�� ������ 1����� �ٽ� ����.
	// �� �� ���̸� �޲� ĭ�� ������ ����� �� ���� ����ġ���� �۴ٸ� ����ġ ����
	
	bridges_count = 0;
	
	for (int i = 0; i < n; i++) { // ���� 
		vector<int> islands_num;
		vector<int> islands_dist;
		int dist = 0;
		for (int j = 0; j < m; j++) {
			if (grid_map[i][j] != 0) {
				islands_num.push_back(grid_map[i][j]);
				islands_dist.push_back(dist);
				dist = 0;
			}
			else dist++; 
		}
		
		int len = islands_num.size();
		int before_island = -1;
		
		for (int j = 0; j < len; j++) {
			if (islands_dist[j] <= 1) {
				before_island = islands_num[j];
				continue;
			}
			if (before_island == -1) {
				before_island = islands_num[j];
				continue;
			}
			
			bridges[bridges_count++] = {before_island, islands_num[j], islands_dist[j]};
			before_island = islands_num[j];
		}
	}
	
	for (int i = 0; i < m; i++) { // ���� 
		vector<int> islands_num;
		vector<int> islands_dist;
		int dist = 0;
		for (int j = 0; j < n; j++) {
			if (grid_map[j][i] != 0) {
				islands_num.push_back(grid_map[j][i]);
				islands_dist.push_back(dist);
				dist = 0;
			}
			else dist++;
		}
		
		int len = islands_num.size();
		int before_island = -1;
		int num = 0;
		
		for (int j = 0; j < len; j++) {
			if (islands_dist[j] <= 1) {
				before_island = islands_num[j];
				continue;
			}
			if (before_island == -1) {
				before_island = islands_num[j];
				continue;
			}
			
			bridges[bridges_count++] = {before_island, islands_num[j], islands_dist[j]};
			before_island = islands_num[j];
		}
	}
	
	sort(bridges, bridges+bridges_count, cmp);
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
	
	make_island(pq);
	int visited_island[105] = {0,};
	vector<int> islands;
//	puts("===================");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
//			printf("%3d", grid_map[i][j]);
			if (grid_map[i][j] != 0 && !visited_island[grid_map[i][j]]) {
				visited_island[grid_map[i][j]] = 1;
				islands.push_back(grid_map[i][j]);
			}
		}
//		puts("");
	}
	
	find_island_distance();
	
	for (int i = 0; i <= 100; i++) {
		parent[i] = i;
	}
	
	int result = 0;
	int visited[105][105] = {0,};
	int count = 0;
//	puts("===================");
	for (int i = 0; i < bridges_count; i++) {
		if (find_in_graph(bridges[i].a) == find_in_graph(bridges[i].b)) continue;
		if (visited[bridges[i].a][bridges[i].b] && visited[bridges[i].b][bridges[i].a]) continue;
		
//		printf("%d => %d, len: %d\n", bridges[i].a, bridges[i].b, bridges[i].len);
		
		merge_in_graph(bridges[i].a, bridges[i].b);
		visited[bridges[i].a][bridges[i].b] = 1;
		visited[bridges[i].b][bridges[i].a] = 1;
		
		result += bridges[i].len;
		count++;
	}
	
	int root = find_in_graph(islands[0]);
	int temp = 0;
	for (int i = 0; i < islands.size(); i++) {
		if (find_in_graph(islands[i]) == root) temp++;
	}
	
	
	
//	printf("island: %d, bridge: %d\n", island_count, count);
	if (result == 0 || temp < islands.size()) printf("-1");
	else printf("%d", result);
	
	
	//�� ���鸶�� �ֻ��� ��带 ���ϱ� (�Ϸ�) 
	//�� ���鸶�� �ִܰŸ��� ���� ���ο� �׷����� ������ ����ġ�� ���ϱ� (�ϴ� �ٸ������)
	//�׷��� ���� ����ġ�� ���� �ּ� ���д� Ʈ�� �����
	//�ּ� ���д� Ʈ���� ��� ����ġ ���ϱ�
	
	//���� �����ϴ� ���հ� ���� ���� ������ ���� �����ؾ� ��  
}
