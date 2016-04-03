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
int parent[MAXN];
vector<pair<int, int> > ans;
int n;
int t = 0;

void solve(int p, int i){
	visit[i] = low[i] = ++t;

	for(int j = 0; j < n; ++j){
		if(adj[i][j])
		if(!visit[j]){
			solve(i, j);

			low[i] = min(low[i], low[j]);
			
			if(low[j] > visit[i]){
				if(i <= j)
				ans.push_back(make_pair(i, j));
				else
				ans.push_back(make_pair(j, i));
				// cout << "bridge : " << i << " -> " << j << endl;
			}
		}else if(j != p || (j == p && adj[i][j] >= 2)){
			low[i] = min(low[i], low[j]);
		}
	}
}

void DFS(int i){
	visit[i] = low[i] = ++t;
	for(int j = 0; j < n; ++j){
		if(adj[i][j]){
			if(!visit[j]){
				parent[j] = i;
				DFS(j);
			}

			if(!(j == parent[i] && adj[i][j] == 1)){
				low[i] = min(low[i], low[j]);
			}
		}
	}
}

void bridge(){
	memset(visit, 0, sizeof(visit));

	t = 0;

	for(int i = 0; i < n; ++i){
		if(visit[i] == 0){
			parent[i] = i;
			DFS(i);
		}
	}

	for(int i = 0; i < n; ++i){
		if(visit[i] == low[i] && parent[i] != i)
			cout << "Bridge : " << parent[i] << " " << i << endl;
	}
}

bool cmp(pair<int, int> a, pair<int, int> b){
	return a.first < b.first;
}

int main(){
	while(scanf("%d", &n) == 1){
		string line, trash;
		ans.clear();
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
				// list[d].push_back(s);
				adj[s][d]++;
				// adj[d][s]++;
			}
		}

		memset(visit, 0, sizeof(visit));
		t = 0;
		for(int i = 0; i < n; ++i){
			if(!visit[i])
				solve(i, i);
		}

		// bridge();
		sort(ans.begin(), ans.end(), cmp);
		printf("%d critical links\n", ans.size());
		for(int i = 0; i < ans.size(); ++i){
			printf("%d - %d\n", ans[i].first, ans[i].second);
		}
		puts("");
	}
	return 0;
}
