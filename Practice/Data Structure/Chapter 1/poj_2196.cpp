#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int calc(int num, int radix){
	int sum = 0;
	while(num / radix){
			sum = sum + num % radix;
			num = num / radix;
	}
	sum = sum + num;
	return sum;
}

int main(){
	for(int i = 2991; i <= 9999; ++i){
		int a = calc(i, 10);
		int b = calc(i, 12);
		int c = calc(i, 16);
		
		if(a == b && b == c){
			printf("%d\n", i);
		}
	}
	return 0;
}
