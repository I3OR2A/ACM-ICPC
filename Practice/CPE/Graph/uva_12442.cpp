#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int MAXN = 50000 + 10;
bool vis[MAXN], vis2[MAXN];
int list[MAXN];
int ans, tmp_ans, idx;
int tmpa, tmpb;
int n;

void DFS(int cur, int step){

	if(vis2[cur]){
		tmp_ans = tmp_ans > step - 1 ? tmp_ans : step - 1;
		return;
	}

	vis2[cur] = true;
	vis[cur] = true;

	DFS(list[cur], step + 1);

}

int main(){
	int testcases;
	scanf("%d", &testcases);
	for(int testcase = 0; testcase < testcases; ++testcase){
		scanf("%d", &n);

		for(int i = 0; i < n; ++i){
			scanf("%d%d", &tmpa, &tmpb);
			list[tmpa] = tmpb;
		}

		ans = -1;
		memset(vis, false, sizeof(bool) * (n + 1));

		// memset(out, false, sizeof(bool) * (n + 1));
		for(int i = 1; i <= n; ++i){
			if(vis[i] == false){
				tmp_ans = -1;

				memset(vis2, false, sizeof(bool) * (n + 1));
				DFS(i, 0);

				if(tmp_ans > ans){
					ans = tmp_ans;
					idx = i;
				}
			}
		}
		printf("Case %d: %d\n", testcase + 1, idx);
	}
	return 0;
}
