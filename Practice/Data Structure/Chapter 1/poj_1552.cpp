#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

const int MAXN = 20;

int a[MAXN];
int n = 0, cnt;

int main(){
	scanf("%d", &a[n++]);
	while(a[0] != -1){
		for(;;n++){
			scanf("%d", &a[n]);
			if(a[n] == 0) break;
		}
		cnt = 0;
		for(int i = 0; i < n - 1; ++i){
			for(int j = i + 1; j < n; ++j){
				if(a[i] * 2 == a[j] || a[j] * 2 == a[i]){
					cnt++;
				}
			}
		}
		n = 0;
		printf("%d\n", cnt);
		scanf("%d", &a[n++]);
	}
	return 0;
}
