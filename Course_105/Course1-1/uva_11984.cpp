#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

float calc(int);

int main(){
	int testcase;
	scanf("%d", &testcase);
	for(int i = 0; i < testcase; ++i){
		int C, d;
		scanf("%d%d", &C, &d);

		printf("Case %d: %.2f\n", i + 1, (float)C + calc(d));		
	}
	return 0;
}


float calc(int d){
	return (float)d * 5.0 / 9.0;
}
