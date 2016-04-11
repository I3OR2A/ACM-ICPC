#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;
const int MAXN = 100000 + 10;
vector<int> g[MAXN];
int vis[MAXN], low[MAXN];
int t, top;
int stack[MAXN];
bool instack[MAXN];
int contract[MAXN];
int n, m;
set<int> group[MAXN];
set<int> con;

void solve(int cur){
	vis[cur] = low[cur] = ++t;
	stack[top++] = cur;
	instack[cur] = true;

	for(int i = 0; i < g[cur].size(); ++i){
		int nxt  = g[cur][i];
		if(!vis[nxt]){
			solve(nxt);
		}
		if(instack[nxt]){
			low[cur] = min(low[cur], low[nxt]);
		}
	}

	if(vis[cur] == low[cur]){
		int k;
		do{
			k = stack[--top];
			instack[k] = false;
			contract[k] = cur;
			group[cur].insert(k);
		}while(k != cur);
		con.insert(k);
	}

}

int in[MAXN];
int main(){
	int testcases, a, b;
	scanf("%d", &testcases);
	for(int testcase = 0; testcase < testcases; ++testcase){
		scanf("%d%d", &n, &m);
		for(int i = 0; i <= n; ++i){
			g[i].clear();
			group[i].clear();
			in[i] = 0;
		}	

		for(int i = 0; i < m; ++i){
			scanf("%d%d", &a, &b);
			g[a].push_back(b);
		}	

		con.clear();
		memset(vis, 0, sizeof(int) * (n + 1));
		memset(low, 0, sizeof(int) * (n + 1));
		memset(stack, 0, sizeof(int) * (n + 1));
		memset(instack, false, sizeof(bool) * (n + 1));
		t = 0;
		top = 0;
		for(int i = 1; i <= n; ++i){
			if(!vis[i]){
				solve(i);
			}
		}

		for(int i = 1; i <= n; ++i){
			for(int j = 0; j < g[i].size(); ++j){
			int nxt = g[i][j];
				if(contract[i] != contract[nxt]){
					in[contract[nxt]]++;
				}
			}
		}

		int cnt = 0;
		for(set<int>::iterator it = con.begin(); it != con.end(); ++it){
			if(in[*it] == 0)cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}
