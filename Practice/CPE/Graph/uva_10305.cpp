#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <map>
using namespace std;
const int MAXN = 100 + 10;
int m, n;
vector<int> list[MAXN];
int in[MAXN];

int main(){
	while(scanf("%d%d", &n, &m) == 2){

		if(n == 0 && m == 0){
				break;
		}
		int tmpa, tmpb;
		for(int i = 0; i <= n; ++i){
			list[i].clear();
			in[i] = 0;
		}
		for(int i = 0; i < m ;++i){
			scanf("%d%d", &tmpa, &tmpb);
				in[tmpb]++;
				list[tmpa].push_back(tmpb);
		}

		queue<int> que;
		for(int i = 1; i <= n; ++i){
			if(in[i] == 0){
				que.push(i);
			}
		}

		vector<int> ans;
		while(!que.empty()){
			int cur = que.front();
			que.pop();
			ans.push_back(cur);
			in[cur] = -1;

			for(int i = 0; i < list[cur].size(); ++i){
				int nxt = list[cur][i];
				in[nxt]--;
				if(in[nxt] == 0) que.push(nxt);
			}
		}

		printf("%d", ans[0]);
		for(int i = 1; i < ans.size(); ++i){
			printf(" %d", ans[i]);
		}
		puts("");
	}

	return 0;
}
