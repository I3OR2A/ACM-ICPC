#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
const int k = 7490;

int c[k];
int v[5] = {1,5,10,25,50};

void calc(){
	memset(c, 0, sizeof(c));
	c[0] = 1;
	for(int i = 0; i < 5; ++i){
		for(int j = v[i]; j < k; ++j){
			c[j] += c[j - v[i]];	
		}
	}
}

int main(){
	int num;

	calc();

	while(scanf("%d", &num) == 1){
		printf("%d\n", c[num]);		
	}	
	return 0;
}
