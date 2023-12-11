#include <stdio.h>

int num[25];
char oper[25];

int n;

int main() {
	scanf("%d", &n);
	
	int i1 = 0, i2 = 0;
	for (int i = 0; i < n; i++) {
		if (i%2 == 0) {
			scanf("%d", &num[i1]);
		}
		else {
			scanf("%d", &oper[i2]);
		}
	}
	
	
}

// 모든 연산자는 우선순위가 같다. 왼쪽에서부터 순차적으로 계산함 
// ex) `<1*2>+3*4*5-6*0 => <2+3>*4*5-6*0 => <5*4>*5-6*0 ... => <94*0> => 0

// 괄호 안에는 연산자 하나만 있어야 함

// 중첩하여 괄호를 사용하지 못함
 
