#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

long long int solve(long long int n, long long int cnt){
	if(n == 1)
		return cnt + 1;

	if(n % 2 != 0)
		n = n *  3 + 1;
	else
		n = n / 2;

	solve(n, cnt + 1);
}

int main(){

	long long int i, j;

	while(scanf("%lld%lld", &i, &j) == 2){
	
		long long int final_i = i;
		;long long int final_j = j;

		if(i > j){
			long long int tmp = i;
			i = j;
			j = tmp;
		}

		long long int max_ans = -1;
		for(long long int k = i; k <= j; ++k){
		 	long long int ans = solve(k, 0);
			max_ans = max_ans > ans ? max_ans : ans;
		}

		printf("%lld %lld %lld\n", final_i, final_j, max_ans);
	}

	return 0;
}
