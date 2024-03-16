#include <stdio.h>
#include <vector>
using namespace std;

typedef long long ll;

vector<ll> segment;

int n;

void update_seg(int now, int left, int right, int x, int diff) {
	if(left==right){
        segment[now]+=diff;
        return;
    }

    if (x < left || x > right) return;

    int mid = (left + right)/2;

    update_seg(now*2, left, mid, x, diff);
    update_seg(now*2+1, mid+1, right, x, diff);

    segment[now]=segment[now*2]+segment[now*2+1];
    return;

}

ll sum_seg(int now, int left, int right, int tar) {
	if(left==right)return left;
    ll mid=(left+right)/2;
    if(segment[now*2]>=tar)return sum_seg(now*2+1,mid+1,right,tar);
    else return sum_seg(now*2,left,mid,tar);
}

int main() {
	scanf("%d", &n);

    segment.resize(n*4);

	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		
		if (a == 1) { //»çÅÁ ²¨³»±â r
			int b;
			scanf("%d", &b);
			printf("%d\n",sum_seg(1,1,1000000,b));
		}
		else if (a == 2) { //»çÅÁ ³Ö±â 
			int b, c;
			scanf("%d%d", &b, &c);
			update_seg(1,1,1000000,b,c);
		}
	}
}
