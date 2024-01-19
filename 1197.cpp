#include <stdio.h>
#include <algorithm>
using namespace std;

typedef struct {
	int a, b, c;
} rkstjs;

int p[10005];

rkstjs e[100005];

int V, E;

int find(int v) {
	if (p[v] == v) return v;
	return p[v] = find(p[v]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	
	if (a == b) return;
	
	if (a<b) p[b] = a;
	else p[a] = b;
}

bool cmp(rkstjs a, rkstjs b) {
	return a.c < b.c;
}

int main() {
	int result = 0;
	
	scanf("%d%d", &V, &E);
	
	for (int i = 1; i <= V; i++) {
		p[i] = i;
	}
	
	for (int i = 0; i < E; i++) {
		scanf("%d%d%d", &e[i].a, &e[i].b, &e[i].c);
	}
	
	sort(e, e+E, cmp);
	
	for (int i = 0; i < E; i++) {
		int a = e[i].a, b= e[i].b;
		
		if (find(a) == find(b)) continue;
		merge(e[i].a, e[i].b);
		
		result += e[i].c;
	}
	
	printf("%d", result);
}
