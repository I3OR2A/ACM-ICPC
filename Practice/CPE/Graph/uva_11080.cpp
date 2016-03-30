#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 10000 + 10;

int v, e;
int a, b;
vector<int> list[MAXN];
int used[MAXN];
int ans;
int v_cnt = 0;
int wa = false;

void solve(int cur, int color){
	if(wa) return ;

	if(color == 1) ans++;
	used[cur] = color;
	v_cnt++;

	vector<int> tmp;
	for(int i = 0; i < list[cur].size(); ++i){
		int nxt = list[cur][i];
		if(used[nxt] == 0){
			tmp.push_back(nxt);
		}

		if(used[nxt] == color){
			wa = true;
			return ;
		}
	}

	for(int i = 0; i < tmp.size() && !wa; ++i){
		int nxt = tmp[i];
		if(used[nxt] == 0)
			solve(nxt, 3 - color);
	}

	return;
}

int main(){
	int testcases;
	scanf("%d", &testcases);
	for(int testcase = 0; testcase < testcases; ++testcase){
		scanf("%d%d", &v, &e);
		for(int i = 0; i < v; ++i){
			list[i].clear();
			used[i] = 0;
		}

		for(int i = 0; i < e; ++i){
			scanf("%d%d", &a, &b);
			list[a].push_back(b);
			list[b].push_back(a);
		}

		int final_ans = 0;

		for(int i = 0; i < v; ++i){
			wa = false;
			ans = 0;
			v_cnt = 0;
			if(used[i] == 0){
				solve(i, 1);
				if(wa) break;
				
				final_ans += v_cnt != 1 ? min(v_cnt - ans, ans) : 1;
			}
		}

		if(wa){
			printf("-1\n");
		}else{
			printf("%d\n", final_ans);
		}
	}
	return 0;
}
