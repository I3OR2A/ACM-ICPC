#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 64;

int mat[MAXN][MAXN];
bool row[MAXN], col[MAXN];
bool lhe[MAXN], rhe[MAXN];
int ans;

void backtrack(int y, int x, int tot, int cnt){
	if(cnt == 8){
		ans = ans > tot ? ans : tot;
		return ;
	}

	for(int i = y; i < 8; ++i){
		for(int j = 0; j < 8; ++j){
			int lhe_para = i - j + 8;
			int rhe_para = i + j;
			if(row[i] == false && col[j] == false && lhe[lhe_para] == false && rhe[rhe_para] == false){
				row[i] = true;
				col[j] = true;
				lhe[lhe_para] = true;
				rhe[rhe_para] = true;
				backtrack(i + 1, j, tot + mat[i][j], cnt + 1);
				row[i] = false;
				col[j] = false;
				lhe[lhe_para] = false;
				rhe[rhe_para] = false;
			}
		}
	}

}

int main(){
	int testcases;
	scanf("%d", &testcases);
	for(int testcase = 0; testcase < testcases; ++testcase){
		//int tmp;
		for(int i = 0; i < 8; ++i){
			for( int j = 0; j < 8; ++j){
				scanf("%d", &mat[i][j]);
			}
		}
		memset(row, false, sizeof(row));
		memset(col, false, sizeof(col));
		memset(lhe, false, sizeof(lhe));
		memset(rhe, false, sizeof(rhe));

		ans = -1;
		backtrack(0, 0, 0, 0);
		printf("%5d\n", ans);
	}
	return 0;
}
