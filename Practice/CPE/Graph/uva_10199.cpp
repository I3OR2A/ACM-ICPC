#include <cstdio>
#include <cstring>
#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
const int MAXN = 100 + 10;
map<string, int> ntd;
map<int ,string> dtn;
vector<int> g[MAXN];
set<string> l;
int vis[MAXN];
int low[MAXN];
int n;
int ans;
int t;

void solve(int par, int cur){
		vis[cur] = low[cur] = ++t;

		int child = 0;
		bool ap = false;

		for(int i = 0; i < g[cur].size(); ++i){
			int nxt = g[cur][i];
			if(nxt != par){
				if(vis[nxt]){
					low[cur] = min(low[cur], vis[nxt]);
				}else{
					child++;
					solve(cur, nxt);
					low[cur] = min(low[cur], low[nxt]);
					if(low[nxt] >= vis[cur]) ap = true;
				}
			}
		}

		if((cur == par && child > 1) || (cur != par && ap)){
			ans++;
			l.insert(dtn[cur]);
		}
}

int main(){
	int testcase = 0;
	while(scanf("%d", &n) == 1 && n){
		if(testcase) puts("");
		dtn.clear();
		ntd.clear();
		for(int i = 0; i < n; ++i){
			string name;
			cin >> name;
			ntd[name] = i;
			dtn[i] = name;
			g[i].clear();
		}
		l.clear();

		int r;
		scanf("%d", &r);
		for(int i = 0; i < r; ++i){
			string c1, c2;
			cin >> c1 >> c2;
			g[ntd[c1]].push_back(ntd[c2]);
			g[ntd[c2]].push_back(ntd[c1]);
		}

		t = 0;
		ans = 0;
		memset(vis, 0, sizeof(vis));
		// memset(low, 0, sizeof(int) * (n + 1));
		
		for(int i = 0; i < n; ++i){
			if(!vis[i]){
				solve(i, i);
			}
		}

		printf("City map #%d: %d camera(s) found\n", ++testcase, l.size());
		for(set<string>::iterator it = l.begin(); it != l.end(); ++it){
			cout << *it << endl;	
		}
	}
	return 0;
}
