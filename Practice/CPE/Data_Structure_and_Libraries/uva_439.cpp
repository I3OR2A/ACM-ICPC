#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <string>
#include <queue>
#include <sstream>
using namespace std;

const int MAXN = 8;

bool mat[MAXN][MAXN];

struct Pos{
	int y; 
	int x;
	int s;
};

const int dir[8][2] = {
	{1,2},
	{-1,2},
	{1,-2},
	{-1,-2},
	{2,1},
	{-2,1},
	{2,-1},
	{-2,-1}
};

int main(){
	
	string line;
	while(getline(cin, line)){
		memset(mat, false, sizeof(mat));

		istringstream stream(line);
		string a, b;
		stream >> a >> b;
		int sx = a[0] - 'a';
		int sy = a[1] - '1';
		int ex = b[0] - 'a';
		int ey = b[1] - '1';

		struct Pos sp;
		sp.y = sy;
		sp.x = sx;
		sp.s = 0;
		mat[sy][sx] = true;
		queue<struct Pos> que;
		que.push(sp);
		int ans = 0;
		while(!que.empty()){
			struct Pos cp = que.front();
			que.pop();
			int cy = cp.y;
			int cx = cp.x;
			int cs = cp.s;


			if(cy == ey && cx == ex){
				ans = cs;
				break;
			}
	
			for(int i = 0; i < 8; ++i){
				int ny = cy + dir[i][0];
				int nx = cx + dir[i][1];

				if(ny >= 0 && ny < MAXN && nx >= 0 && nx < MAXN && mat[ny][nx] == false){
					mat[ny][nx] = true;
					struct Pos np;
					np.y = ny;
					np.x = nx;
					np.s = cs + 1;
					que.push(np);
				}
			}
		}

	 	printf("To get from %s to %s takes %d knight moves.\n", a.c_str(), b.c_str(), ans);
	}

	return 0;
}
