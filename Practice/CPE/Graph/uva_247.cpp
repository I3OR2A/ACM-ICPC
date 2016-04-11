#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <cstdlib>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAXN = 30;
map<string, int> ntd;
map<int, string> dtn;
vector<int> g[MAXN];
int vis[MAXN];
int low[MAXN];
int t;
int stack[MAXN], top = 0;
bool instack[MAXN];
int contract[MAXN];

void solve(int cur){
	vis[cur] = low[cur] = ++t;
	stack[top++] = cur;
	instack[cur] = true;
	
	for(int i = 0; i < g[cur].size(); ++i){
		int nxt = g[cur][i];
		if(!vis[nxt])
			solve(nxt);
		if(instack[nxt])
			low[cur] = min(low[cur], low[nxt]);
	}

	if(vis[cur] == low[cur]){
		int k;
		do{
			k = stack[--top];
			instack[k] = false;
			contract[k] = cur;
			if(k != cur){
				cout << dtn[k] << ", ";
			}
		}while(k != cur);
		cout << dtn[k] << endl;
	}
}

int n, m, id;

int main(){
int testcase = 0;
	while(scanf("%d%d", &n, &m) == 2){
		if(n == 0 && m == 0) break;
		id = 0;
		ntd.clear();
		dtn.clear();
		for(int i = 0; i < n; ++i){
			g[i].clear();
		}
		for(int i = 0; i < m; ++i){
			string c1, c2;
			cin >> c1 >> c2;
			if(ntd.find(c1) == ntd.end()){
				dtn[id] = c1;
				ntd[c1] = id++;
			}
			if(ntd.find(c2) == ntd.end()){
				dtn[id] = c2;
				ntd[c2] = id++;
			}

			g[ntd[c1]].push_back(ntd[c2]);
		}

		memset(vis, 0 ,sizeof(int) * n);
		memset(stack, 0, sizeof(int) * n);
		memset(instack, false, sizeof(bool) * n);
		int top = 0;
		int t = 0;
		if(testcase) puts("");
		printf("Calling circles for data set %d:\n", ++testcase);
		for(int i = 0; i < n; ++i){
			if(!vis[i]){
				solve(i);
			}
		}
	}
	return 0;
}
