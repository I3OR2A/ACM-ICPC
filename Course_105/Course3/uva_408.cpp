#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int WIDTH_STEP = 10;
const int WIDTH_MOD = 10;
const int WIDTH_RESULT = 5;

int STEP, MOD;

int main(){
while(scanf("%d%d", &STEP, &MOD) == 2){
	map<int, bool> mymap;
	int seed = 0;

	while(mymap.find(seed) == mymap.end()){
		mymap[seed] = true;

		seed = (seed + STEP) % MOD;
	}

	int size = mymap.size();
	if(size == MOD){
		printf("%*d%*d    %s\n\n", WIDTH_STEP, STEP, WIDTH_MOD, MOD, "Good Choice");
	}else{
		printf("%*d%*d    %s\n\n", WIDTH_STEP, STEP, WIDTH_MOD, MOD, "Bad Choice");
	}
}
return 0;
}
