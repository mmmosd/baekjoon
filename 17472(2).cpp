#include <stdio.h>

int grid[15][15];

int n, m;

int main() {
	scanf("%d%d", &n, &m);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &grid[i][j]);
		}
	}
	
	
}
