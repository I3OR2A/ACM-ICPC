#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <sstream>
using namespace std;
const int MAXN = 100 + 10;
vector<int> list[MAXN];
int visit[MAXN];
int adj[MAXN][MAXN];
int low[MAXN];
int n;
int t = 0;

void solve(int p, int c){
	visit[c] = low[c] = ++t;

	for(int i = 0; i < list[c].size(); ++i){
		int nxt = list[c][i];
		if(!visit[nxt]){
			solve(c, nxt);

			low[c] = min(low[c], low[nxt]);
			
			if(low[nxt] > visit[c]){
				cout << "bridge : " << c << " -> " << nxt << endl;
			}
		}else if(nxt != p || (nxt == p && adj[c][nxt] >= 2)){
			low[c] = min(low[c], visit[nxt]);
		}
	}
}

int main(){
	while(scanf("%d", &n) == 1){
		string line, trash;
		char clean[10];
		memset(adj, 0, sizeof(adj));
		gets(clean);
		for(int i = 0; i <= n; ++i){
			visit[i] = 0;
			list[i].clear();
		}

		for(int i = 0; i < n; ++i){
			getline(cin, line);
			int s ,d;
			istringstream stream(line);
			stream >> s;
			stream >> trash;
			while(stream >> d){
				list[s].push_back(d);
				list[d].push_back(s);
				adj[s][d]++;
				adj[d][s]++;
			}
		}

		t = 0;

		for(int i = 0; i < n; ++i){
			if(visit[i] == 0){
				solve(i, i);
			}
		}
	}
	return 0;
}
