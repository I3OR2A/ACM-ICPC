#include <string>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <cstdio>
using namespace std;

const int MAXN = 10000 + 10;
map<int,int> mymap[MAXN];
int M, N;

int main(){
	while(scanf("%d%d", &M, &N) == 2){

		for(int i = 0; i <= M; ++i){
			mymap[i].clear();
		}

		for(int i =1 ;i <= M; ++i){
			int num, tmp;
			vector<int> list;
			scanf("%d", &num);
			for(int j = 0; j < num; ++j){
				scanf("%d", &tmp);
				list.push_back(tmp);
			}
			for(int j = 0; j < num; ++j){
				scanf("%d", &tmp);
				mymap[i][list[j]] = tmp;
			}
		}

		printf("%d %d\n", N, M);

		for(int j = 1; j <= N; ++j){
			map<int, int> tmpmap;
			vector<int> tmplist;
			int cnt = 0;
			for(int i = 1; i <= M; ++i){
				if(mymap[i].find(j) != mymap[i].end()){
					tmpmap[i] = mymap[i][j];
					tmplist.push_back(i);
				}
			}

			printf("%d", (int)tmplist.size());
			for(int k = 0; k < tmplist.size(); ++k){
				printf(" %d", tmplist[k]);
			}	
			puts("");
			if(tmplist.size() > 0)
				for(int k = 0; k < tmplist.size() - 1; ++k){
					printf("%d ", tmpmap[tmplist[k]]);
				}
			if(tmplist.size() > 0){
				printf("%d\n", tmpmap[tmplist[tmplist.size() - 1]]);
			}

			if(tmplist.size() == 0){
				puts("");
			}
		}
	}
	return 0;
}
