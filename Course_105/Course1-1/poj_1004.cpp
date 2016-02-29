#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

const int MONTH = 12;

int main(){
	float sum = 0.0;
	float tmp;

	for(int i = 0; i < MONTH; ++i){
		scanf("%f", &tmp);

		sum = sum + tmp;
	}

	printf("$%.2f\n", sum / 12.0);
	return 0;
}
