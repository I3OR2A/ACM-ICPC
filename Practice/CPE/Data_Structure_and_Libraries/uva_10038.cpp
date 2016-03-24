#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
const int MAXN = 3000 + 10;
int list[MAXN];
bool used[MAXN];

int main(){
	int num;
	while(scanf("%d", &num) == 1){
		for(int i = 0 ; i < num; ++i){
			scanf("%d", &list[i]);
		}
		
		memset(used, false, sizeof(bool) * num);
		for(int i = 0; i < num - 1; ++i){
				int tmp = list[i] > list[i + 1] ? list[i] - list[i + 1] : list[i + 1] - list[i];
				if(tmp < MAXN) used[tmp] = true;

			
		}

		bool isJolly = true;
		for(int i = 1; i < num; ++i){
			if(used[i] == false) {
				isJolly  = false;
				break;
			} 
		}

		if(isJolly){
			puts("Jolly");
		}else{
			puts("Not jolly");
		}
	}
	return 0;
}
