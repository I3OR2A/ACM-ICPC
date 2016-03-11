#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const float angle_per_hour = 360 / 12;
const float angle_per_minute =  360 / 60;
const float angle_per_ratio = angle_per_hour / 60;

int main(){

	int hour, minute;

	while(scanf("%d:%d", &hour, &minute) == 2){
		if(hour == 0 && minute == 0) break;

		float diff = abs(hour * angle_per_hour 
				+ minute * angle_per_ratio 
				- minute * angle_per_minute);

		diff = diff > 180.0 ? 360.0 - diff : diff;

		printf("%.3f\n", diff);
	}

	return 0;
}
