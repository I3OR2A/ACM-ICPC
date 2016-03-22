#include <string> 
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

int main(){
	string line;
	while(getline(cin, line)){
		if(line.length() == 1 && line[0] == '#') break;

		int sum= 0 ;
		int len = line.length();
		for(int i = 0; i < len; ++i){
			if(line[i] >= 'A' && line[i] <= 'Z'){
				sum += (i + 1) * ((line[i] - 'A') + 1);
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}
