#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <sstream>
using namespace std;
const int MAXN = 100 + 10;

vector<int> list[MAXN];
int visit[MAXN];
int low[MAXN];
int n;
int ans = 0;
int t;

void solve(int p, int c){
	visit[c] = low[c] = ++t;

	int child = 0;
	bool ap = false;

	for(int i = 0; i < list[c].size(); ++i){
		int nxt = list[c][i];
		if(nxt != p){
			if(visit[nxt]){
				low[c] = min(low[c], visit[nxt]);
			}	
			else{
				child++;
				solve(c, nxt);

				low[c] = min(low[c], low[nxt]);

				if(low[nxt] >= visit[c]) ap = true;
			}
		}
	}

	if((c == p && child > 1) || (c != p && ap)){
		ans++;
	}
}

int main(){
	while(scanf("%d", &n) == 1 && n){
		string line;
		char clean[10];
		gets(clean);
		ans = 0;
		t = 0;
		for(int i = 0; i <= n; ++i){
			list[i].clear();
			visit[i] = 0;
			low[i] = 0;
		}

		while(getline(cin, line)){
			istringstream stream(line);
			int s, t;
			stream >> s;
			if(s == 0) break;
			while(stream >> t){
				list[s].push_back(t);
				list[t].push_back(s);
			}
		}

		for(int i = 1; i <= n; ++i){
			if(visit[i] == 0){
				solve(i, i);
			}
		}

		printf("%d\n", ans);
	}
	return 0;
}
