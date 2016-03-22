#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
using namespace std;

const int MAXN = 10000+10;
vector<int> prime;

bool isPrime(int n){
	for(int i = 0; prime[i] * prime[i] <= n; ++i){
		if(n % prime[i] == 0)
			return false;

	}
	return true;
}

void makePrime(){
	prime.push_back(2);
	prime.push_back(3);
	for( int i = 5, gap=2; i < MAXN; i += gap, gap = 6 - gap){
		if(isPrime(i)) prime.push_back(i);
	}
}

int p;

int main(){

	makePrime();

	while(scanf("%d", &p) == 1){
		if(p == 0) break;

		int ans = 0;
		for(int i = 0; p >= prime[i]; ++i){
			int cnt = 0;
			for(int j = i; j < prime.size() && cnt < p; ++j){
				cnt += prime[j];
			}

			if(cnt == p)
				++ans;
		}

		printf("%d\n", ans);
	}
	return 0;
}
