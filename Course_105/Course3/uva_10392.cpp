#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 1000000;
vector<int> prime;

bool isPrime(int n){
	for(int i = 0; prime[i] * prime[i] <= n;  ++i){
		if(n % prime[i] == 0)
			return false;
	}
	return true;
}

void makePrime(){
	prime.push_back(2);
	prime.push_back(3);
	for(int i = 5, gap = 2; i < MAX; i += gap, gap = 6 - gap){
		if(isPrime(i)) prime.push_back(i);
	}
}

long long int num;

int main(){
	
	makePrime();

	while(scanf("%lld", &num)){
		if(num < 0) break;

		for(int i = 0; i < prime.size();){
			if(num % prime[i] == 0){
				num = num / prime[i];
				printf("    %lld\n", prime[i]);
			}else{
				i++;
			}
		}

		if(num != 1)
			printf("    %lld\n", num);
		puts("");
	}

	return 0;
}
