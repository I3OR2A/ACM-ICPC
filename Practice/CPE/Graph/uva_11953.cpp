#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 100 + 10;

char G[MAXN][MAXN];
int n;

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

bool BFS(int y, int x){
	struct Pos sp;
	sp.y = y;
	sp.x = x;
	queue<struct Pos> que;
	que.push(sp);
	bool isAlive = false;	
	while(!que.empty()){
		struct Pos cp;
		cp = que.front();
		que.pop();
		int cy = cp.y;
		int cx = cp.x;

		if(G[cy][cx] == 'x') isAlive = true;
		G[cy][cx] = '.';

		for(int i = 0; i < 4; ++i){
			struct Pos np;
			np.y = cy + dir[i][0];
			np.x = cx + dir[i][1];
			if(np.y >= 0 && np.y < n && np.x >= 0 && np.x < n && G[np.y][np.x] != '.'){
				que.push(np);
			}
		}
	}

	return isAlive;
}

int main(){
	int testcases;
	scanf("%d", &testcases);
	for(int testcase = 0; testcase < testcases; ++testcase){
		scanf("%d", &n);
		for(int i = 0; i < n; ++i){
			scanf("%s", &G[i]);
		}
		int ans = 0;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				if(G[i][j] != '.'){
					if(BFS(i , j)) ans++;
				}
			}
		}

		printf("Case %d: %d\n", testcase + 1, ans);
	}
	return 0;
}
