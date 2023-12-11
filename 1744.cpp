#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(int a, int b) {
	return a>b;
}

int ary[55];

int n;

int max(int a, int b) {
	return a>b?a:b;
}

int run() {
//	���� ����
//	    i-2  i-1   i
//	... ��---��   ��
//	... ��   ��---�� 
//	... ��   ��   ��
//  � �迭�� �����Ͽ� ���� ��ȣ�� �ش��ϴ� ��ġ����
//  ���� �� �ִ� �ִ��� ����
	
	int result = 0;
	int dp[55] = {0,};
	
	dp[0] = ary[0];
	dp[1] = max(ary[0] + ary[1], ary[0] * ary[1]);
	dp[2] = max(max(ary[0] * ary[1] + ary[2], ary[0] + ary[1] * ary[2]), ary[0] + ary[1] + ary[2]);
	
	for (int i = 3; i < n; i++) {
		dp[i] = max(dp[i-1] + ary[i], dp[i-2] + ary[i-1] * ary[i]);
	}
	
	result = dp[n-1];
	
	return result;
}

int main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &ary[i]);
	}
	
	sort(ary, ary+n, cmp);
	
//	puts("================");
//	for (int i = 0; i < n; i++) {
//		printf("%d\n", ary[i]);
//	}
	
	printf("%d", run());
}
