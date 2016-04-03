#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 1100;
int Tree[MAXN * 3][MAXN * 3];
int S, T;

void update_x(int pRootY, int pRootX, int L, int R, int x1, int x2){
	if(L == x1 && R == x2){
		Tree[pRootY][pRootX] = (Tree[pRootY][pRootX] + 1) % 2;
		return ;
	}

	int M = (L + R) >> 1;
	if(x2 <= M){
		update_x(pRootY, (pRootX << 1) + 1, L, M, x1, x2);	
	}else if(x1 > M){
		update_x(pRootY, (pRootX << 1) + 2, M + 1, R, x1, x2);
	}else{
		update_x(pRootY, (pRootX << 1) + 1, L, M, x1, M);
		update_x(pRootY, (pRootX << 1) + 2, M + 1, R, M + 1, x2);
	}
}

void update_y(int pRootY, int L, int R, int y1, int y2, int x1, int x2){
	if(L == y1 && R == y2){
		update_x(pRootY, 0, 1, S, x1, x2);
		return ;
	}

	int M = (L + R) >> 1;
	if(y2 <= M){
		update_y((pRootY << 1) + 1, L, M, y1, y2, x1, x2);
	}else if(y1 > M){
		update_y((pRootY << 1) + 2, M + 1, R, y1, y2, x1, x2);
	}else{
		update_y((pRootY << 1) + 1, L, M, y1, M, x1, x2);
		update_y((pRootY << 1) + 2, M + 1, R, M + 1, y2, x1, x2);
	}
}

int query_x(int pRootY, int pRootX, int L, int R, int x){
	if(L == R){
		return Tree[pRootY][pRootX] % 2;
	}

	int M = (L + R) >> 1;
	if(x <= M){
		return (query_x(pRootY, (pRootX << 1) + 1, L, M, x) + Tree[pRootY][pRootX]) % 2;
	}else{
		return (query_x(pRootY, (pRootX << 1) + 2, M + 1, R, x) + Tree[pRootY][pRootX]) % 2;
	}
}

int query_y(int pRootY, int L, int R, int y, int x){
	if(L == R){
		return query_x(pRootY, 0, 1, S, x);
	}

	int M = (L + R) >> 1;
	if(y <= M){
		return (query_y((pRootY << 1) + 1, L, M, y, x) + query_x(pRootY, 0, 1, S, x)) % 2;
	}else{
		return (query_y((pRootY << 1) + 2, M + 1, R, y, x) + query_x(pRootY, 0, 1, S, x)) % 2;
	}
}

int main(){
	char cmd;
	int x, y, x1, x2, y1, y2;
	int testcases;
	scanf("%d", & testcases);
	for(int testcase = 0; testcase < testcases; ++testcase){
		if(testcase != 0) puts("");
		scanf("%d%d", &S, &T);
		memset(Tree, 0, sizeof(Tree));
		for(int i = 0; i < T; ++i){
			scanf(" %c", &cmd);
			// cout << "cmd " << cmd << endl;
			if(cmd == 'C'){
				scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
				// cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
				//x1++, x2++, y1++,y2++;

				update_y(0, 1, S, y1, y2, x1, x2);
			}else {
				scanf("%d%d", &x, &y);
				// cout << x << " " << y << endl;
				// x++, y++;
				printf("%d\n", query_y(0, 1, S, y, x));
			}
		}
	}
	return 0;
}
