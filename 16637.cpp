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

// ��� �����ڴ� �켱������ ����. ���ʿ������� ���������� ����� 
// ex) `<1*2>+3*4*5-6*0 => <2+3>*4*5-6*0 => <5*4>*5-6*0 ... => <94*0> => 0

// ��ȣ �ȿ��� ������ �ϳ��� �־�� ��

// ��ø�Ͽ� ��ȣ�� ������� ����
 