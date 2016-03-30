#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;
const int MAX = 200 + 20;
int n, m;
map<string, int> idmap;
map<int, string> namemap;
vector<int> list[MAX];
int in[MAX];

int main(){
	int testcase = 0;
	while(scanf("%d", &n) == 1){
		idmap.clear();
		namemap.clear();
		int cnt = 0;

		for(int i = 0; i < n; ++i){
			list[i].clear();
			in[i] = 0;
		}

		for(int i = 0; i < n; ++i){
			string line;
			cin >> line;
			if(idmap.find(line) == idmap.end()){
				namemap[i] = line;
				idmap[line] = i;
			}
		}
		scanf("%d", &m);
		for(int i = 0; i < m; ++i){
			string  wineA, wineB ;
			cin >> wineA >> wineB;
			//cout << wineA << " " << wineB << endl;
			list[idmap[wineA]].push_back(idmap[wineB]);
			in[idmap[wineB]]++;
		}

		priority_queue<int, vector<int>, greater<int> > que;

		for(int i = 0; i < n; ++i){
			if(in[i] == 0) que.push(i);
		}

		vector<int> ans;
		while(!que.empty()){
			int cur = que.top();
			que.pop();
			ans.push_back(cur);
			in[cur] = -1;
			for(int i = 0; i < list[cur].size(); ++i){
				int nxt = list[cur][i];
				in[nxt] = in[nxt] - 1;
				if(in[nxt] == 0){
					que.push(nxt);
				}
			}
		}

		printf("Case #%d: Dilbert should drink beverages in this order:", ++testcase);
		for(int i = 0; i < ans.size(); ++i){
			printf(" %s", namemap[ans[i]].c_str());
		}
		printf(".\n\n");
	}
	return 0;
}
