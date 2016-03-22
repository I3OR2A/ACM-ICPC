#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
const int maxn = 300;
const double delta = 1e-8;

int zero(double x){
	if (x < -delta) return -1;
	return x > delta;
}

int main(){
	double len[maxn];
	int total;

	len[0] = 0.0;
	for(total = 1; zero(len[total - 1] - 5.20) < 0; ++total){
		len[total] = len[total - 1] + 1.0 / double(total + 1);
	}

	double x;
	while(scanf("%lf", &x) == 1 && zero(x)){
		int l, r;
		l = 0;
		r = total;
		while(l + 1 < r){
			int mid = (l + r) >> 1;
			if(zero(len[mid] - x) < 0)
				l = mid;
			else
				r = mid;
		}

		printf("%d card(s)\n", r);
	}
	return 0;
}
