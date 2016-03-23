#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int list[100];
int ans[100];
bool used[100];
int num;

void backtrack(int cur, int cnt){
	if(cnt == 6){
		for(int i = 0; i < 5; ++i){
			printf("%d ", ans[i]);
		}
		printf("%d\n", ans[5]);
		return ;
	}
	for(int i = cur; i < num; ++i){
		if(used[i] == false){
			used[i] = true;
			ans[cnt] = list[i];
			backtrack(i + 1, cnt + 1);
			used[i] = false;
		}
	}
}

int main() {
	// your code goes here
	// int num;
	bool first = true;
	while(scanf("%d", &num) == 1 && num){
		if(first){
			first = false;
		}
		else{
			puts("");
		}
		for(int i = 0 ; i < num; ++i){
			int tmp;
			scanf("%d", &tmp);
			list[i] = tmp;;
		}
		memset(used, false, sizeof(used));
		// sort(list, list + num);
		backtrack(0, 0);
		// puts("");
	}
	return 0;
}
