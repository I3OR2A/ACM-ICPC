#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int a, b, c, d;
	double n;
	while(scanf("%d%d", &a, &b) == 2){
		scanf("%lf", &n);
		
		c = 1;
		for(d = 1; ; d++){
			
			while(a * d >= b * c) c++;

			if((double) b * (double) c - (double) a * (double) d <= n * (double) b * (double) d){
				break;
			}
		}

		printf("%d %d\n", c, d);
	}
	return 0;
}
