#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 1100;
int Tree[MAXN * 3][MAXN * 3];
int S;
void add_x(int pRootY, int pRootX, int L, int R, int x, int delta){
	Tree[pRootY][pRootX] += delta;
	if(L == R){
		return ;
	}
	int M = (L + R) >> 1;
	if(x <= M){
		add_x(pRootY, (pRootX << 1) + 1, L, M, x, delta);
	}else{
		add_x(pRootY, (pRootX << 1) + 2, M + 1, R, x, delta);
	}
}

void add_y(int pRootY, int L, int R, int y, int x, int delta){
	add_x(pRootY, 0, 1, S, x, delta);
	if(L == R){
		return ;
	}
	int M = (L + R) >> 1;
	if(y <= M){
		add_y((pRootY << 1) + 1, L, M, y, x, delta);
	}else{
		add_y((pRootY << 1) + 2, M + 1, R, y, x, delta);
	}
}

int querySum_x(int pRootY, int pRootX, int L, int R, int x1, int x2){
	if(L == x1 && R ==x2){
		return Tree[pRootY][pRootX];		
	}

	int M = (L + R) >> 1;
	if(x2 <= M){
		return querySum_x(pRootY, (pRootX << 1) + 1, L, M, x1, x2); 
	}else if(x1 > M){
		return querySum_x(pRootY, (pRootX << 1) + 2, M + 1, R, x1, x2);
	}else{
		return querySum_x(pRootY, (pRootX << 1) + 1, L, M, x1, M) 
			+ querySum_x(pRootY, (pRootX << 1) + 2, M + 1, R, M + 1, x2);
	}
}

int querySum_y(int pRootY, int L, int R, int y1, int y2, int x1, int x2){
	if(L == y1 && R == y2){
		return querySum_x(pRootY, 0, 1, S, x1, x2);
	}

	int M = (L + R) >> 1;
	if(y2 <= M){
		return querySum_y((pRootY << 1) + 1, L, M, y1, y2, x1, x2);
	}else if(y1 > M){
		return querySum_y((pRootY << 1) + 2, M + 1, R, y1, y2, x1, x2);
	}else{
		return querySum_y((pRootY << 1) + 1, L, M, y1, M, x1, x2)
			+ querySum_y((pRootY << 1) + 2, M + 1, R, M + 1, y2, x1, x2);
	}
}

int main(){
	int cmd;
	int x, y, delta, l, t, b, r;
	while(true){
		scanf("%d", &cmd);
		if(cmd == 0){
			scanf("%d", &S);
			memset(Tree, 0, sizeof(Tree));
		}
		else if(cmd == 1){
			scanf("%d%d%d", &x, &y, &delta);
			add_y(0, 1, S, y + 1, x + 1, delta);
		}
		else if(cmd == 2){
			scanf("%d%d%d%d", &l, &b, &r, &t);
			b++; t++; l++; r++;
			printf("%d\n", querySum_y(0, 1, S, b, t, l, r));
		}
		else{
			return 0;
		}

	}
}
