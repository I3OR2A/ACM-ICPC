#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>
using namespace std;

const int MAX = 30 + 5;

char G[MAX][MAX];
bool used[MAX][MAX];
int N, M, X, Y;

struct Pos{
	int y;
	int x;
};

const int dir[4][2] = {
	{-1,0},
	{1,0},
	{0,-1},
	{0,1}
};

char chl;

int BFS(int y, int x){
	struct Pos sp;
	sp.x = x;
	sp.y = y;
	queue<struct Pos> que;
	que.push(sp);

	int land = 0;
	while(!que.empty()){
		struct Pos cp;
		cp = que.front();
		que.pop();
		land = land + 1;
		used[cp.y][cp.x] = true;
		for(int i = 0; i < 4; ++i){
			struct Pos np;
			np.x = ((cp.x + dir[i][0]) + N) % N;
			np.y = cp.y+ dir[i][1];
			if(np.y >= 0 && np.y < M && G[np.y][np.x] == chl && used[np.y][np.x] == false){
				que.push(np);
			}
		}
	}
	return land;
}

int main(){
	while(scanf("%d%d", &M, &N) == 2){
		for(int i = 0; i < M; ++i){
			scanf("%s", &G[i]);
			memset(used[i], false, sizeof(bool) * N);
		}
		scanf("%d%d", &X, &Y);
		chl = G[X][Y];
		BFS(X, Y);
		int ans = 0;
		for(int i = 0; i < M; ++i){
			for(int j = 0; j < N; ++j){
				if(G[i][j] == chl && used[i][j] == false){
					int tmp = BFS(i, j);
					ans = ans > tmp ? ans : tmp;
				}
			}
		}
		printf("%d\n", ans);

	}
	return 0;
}
