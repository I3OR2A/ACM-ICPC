#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;
const int W = 12880;
const int N = 3402;
int n, m;
int w[N], d[N];
int c[W];

int main(){
	while(scanf("%d%d", &n, &m) == 2){
		for(int i = 0; i < n; ++i){
			scanf("%d%d", &w[i], &d[i]);
		}

		memset(c, 0, sizeof(c));
		for(int i = 0; i < n; ++i){
			for(int j = m; j - w[i] >= 0; --j){
				c[j] = max(c[j], c[j - w[i]] + d[i]);
			}
		}

		printf("%d\n", *max_element(c, c + m + 1));
	}

	return 0;
}
