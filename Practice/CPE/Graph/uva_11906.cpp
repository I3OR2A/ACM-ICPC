#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <utility>
using namespace std;

const int MAXN = 100 + 10;
int R, C, M, N;
int G[MAXN][MAXN];

struct Pos{
	int y;
	int x;
};

void BFS(){

	int dir[8][2] = {
		{N,M},
		{-N,M},
		{N,-M},
		{-N,-M},
		{M,N},
		{M,-N},
		{-M,N},
		{-M,-N}
	};

	int odd = 0, even = 0;
	struct Pos sp;
	sp.y = 0;
	sp.x = 0;
	G[0][0] = 2;
	queue<struct Pos> que;
	que.push(sp);

	while(!que.empty()){
		struct Pos cp = que.front();
		int cy = cp.y;
		int cx = cp.x;
		que.pop();
		set< pair<int,int> > s;

		for(int i = 0; i < 8; ++i){
			int ny = cy + dir[i][0];
			int nx = cx + dir[i][1];
			if(ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
			if(G[ny][nx] == 0) continue;

			s.insert(make_pair(ny, nx));
			if(G[ny][nx] == 1){
				struct Pos np;
				np.y = ny;
				np.x = nx;
				que.push(np);
				G[ny][nx] = 2;
			}
			
			// s.size() % 2 == 0 ? even++ : odd++;
		}
		s.size() % 2 == 0 ? odd++ : even++;	
	}

	printf("%d %d\n", odd, even);
}

int main(){

	int cnt;
	scanf("%d", &cnt);
	for(int f = 0; f < cnt; ++f){
		scanf("%d%d%d%d", & R, &C, &M, &N);
		int wc, tmpa, tmpb;
		scanf("%d", &wc);
		// memset(mat, 1, sizeof(mat));
			
		for(int i = 0; i < R; ++i){
			for(int j = 0; j < C; ++j){
				G[i][j] = 1;
			}
		}

		for(int i = 0; i < wc; ++i){
			scanf("%d%d", &tmpa, &tmpb);
			G[tmpa][tmpb] = 0;
		}

		printf("Case %d: ", f + 1);
		BFS();
	}
	return 0;
}
