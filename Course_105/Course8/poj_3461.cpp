#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 1000000 + 10;
int ans = 0;
int pi[MAXN];
char A[MAXN], B[MAXN];

void calc(char *B, int *pi){
	int len = strlen(B);
	pi[0] = -1;
	for(int i = 1, cur_pos = -1; i < len; ++i){
		while(cur_pos >= 0 && B[i] != B[cur_pos + 1]){
			cur_pos = pi[cur_pos];
		}
		if(B[i] == B[cur_pos + 1]) ++cur_pos;
		pi[i] = cur_pos;
	}
}

void fail(char *A, char *B, int *pi){
	int lenA = strlen(A);
	int lenB = strlen(B);
	for(int i = 0, cur_pos = -1; i < lenA; ++i){
		while(cur_pos >= 0 && A[i] != B[cur_pos + 1]){
			cur_pos = pi[cur_pos];
		}
		if(A[i] == B[cur_pos + 1]) ++cur_pos;
		if(cur_pos + 1 == lenB){
			cur_pos = pi[cur_pos];
			ans++;
		}
	}
}	

int main(){
	int testcases;
	scanf("%d", &testcases);
	while(testcases--){
		ans = 0;
		// char A[MAXN], B[MAXN];
		// int pi[MAXN];
		scanf("%s", &B);
		scanf("%s", &A);
		calc(B, pi);
		fail(A, B, pi);
		printf("%d\n", ans);
	}
	return 0;
}
