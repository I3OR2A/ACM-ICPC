#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAX = 3;
const int IDX = 1;

int solve(int* num){
	sort(num, num + MAX);
	return num[IDX];
}

int main(){
	int testcase;
	scanf("%d", &testcase);
	for(int i = 0; i < testcase; ++i){
		int num[MAX];
		for(int j = 0; j < MAX; ++j){
			scanf("%d", &num[j]);
		}
		printf("Case %d: %d\n", i + 1, solve(num));
	}
}
