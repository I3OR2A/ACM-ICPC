#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

const int MONTH = 12;

int main(){

	int testcase;
	scanf("%d", &testcase);
	for(int j = 0; j < testcase; ++j){

		double avg, sum = 0.0, val;
		for(int i = 0; i < MONTH; ++i){
			scanf("%lf", &val);
			sum += val;
		}

		
		avg = sum / (double)MONTH;

		int pre = (int)avg / 1000;

		avg = avg - (double)pre * 1000.0;

		if(pre > 0)
			printf("%d $%d,%.2lf\n", j + 1, pre, avg);
		else
			printf("%d $%.2lf\n", j + 1, avg);
	}
	return 0;
}
