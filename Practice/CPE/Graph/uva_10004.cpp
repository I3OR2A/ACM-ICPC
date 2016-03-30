#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
const int MAXN = 200 + 10;
int n, m;
int a, b;
vector<int> list[MAXN];
int used[MAXN];

bool wa = false;

bool solve(int cur, int color){

	if(wa) return false;

	used[cur] = color;

	for(int i = 0; i < list[cur].size(); ++i){
		int nxt = list[cur][i];

		if(used[nxt] != 0 && used[nxt] == color){
				wa = true;
				return false;
		}
	}

	for(int i = 0; i < list[cur].size(); ++i){
		int nxt = list[cur][i];
		
		if(used[nxt] == 0){
			if(!solve(nxt, (2 - color) + 1)){
				wa = true;
				return false;
			}
		}
	}

	return true;
}

int main(){
	while(scanf("%d", &n) == 1 && n){
		scanf("%d", &m);
		for(int i = 0; i < n; ++i){
			memset(used, 0, sizeof(int) * (n + 1));
			list[i].clear();
		}
		
		for(int i = 0; i < m; ++i){
			scanf("%d%d", &a, &b);
			list[a].push_back(b);
			list[b].push_back(a);
		}

		wa = false;
		for(int i = 0; i < n; ++i){
			wa = false;
			if(used[i] == 0){
				solve(i, 1);
				if(wa){
					break;
				}
			}
		}

		if(!wa){
			printf("BICOLORABLE.\n");
		}else{
			printf("NOT BICOLORABLE.\n");
		}
	}
	return 0;
}
