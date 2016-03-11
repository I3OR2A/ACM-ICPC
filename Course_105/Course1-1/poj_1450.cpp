#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(){
	int testcase;
	int m, n;
	scanf("%d", &testcase);
	for(int i = 0; i < testcase; ++i){
		scanf("%d%d", &m, &n);
		if(m % 2 != 0 && n % 2!= 0)
			printf("Scenario #%d:\n%.2f\n\n", (i + 1), (float)(n * m) + 1.414 - 1.0);
		else
			printf("Scenario #%d:\n%.2f\n\n", (i + 1), (float)(n * m));
		
	}
	return 0;
}
