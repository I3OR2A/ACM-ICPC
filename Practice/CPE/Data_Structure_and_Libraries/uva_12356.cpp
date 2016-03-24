#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 10;
int L[MAXN], R[MAXN];
int main(){
	int S,B;
	while(scanf("%d%d", &S, &B) == 2 && (S || B)){
		

		for(int i = 1; i <= S; ++i){
			L[i] = i - 1;
			R[i] = i + 1;
		}
		L[0] = R[0] = R[S] = 0;

		for(int i = 0; i < B; ++i){
			int l , r;
			scanf("%d%d", &l, &r);

			if(L[l] == 0){
				printf("* ");
			}else{
				printf("%d ", L[l]);
			}
			if(R[r] == 0){
				printf("*\n");
			}else{
				printf("%d\n", R[r]);
			}
			
			L[R[r]] = L[l];
			R[L[l]] = R[r];

		}
		puts("-");
	}
	return 0;
}
