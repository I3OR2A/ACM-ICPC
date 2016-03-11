#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const string START = "START";
const string END = "END";
const string ENDOFINPUT = "ENDOFINPUT";
const int ALPHA = 26;
const int SHIFT = 5;

int main(){
	string line;
	while(getline(cin, line)){
		if(line.compare(START) == 0) continue;
		if(line.compare(END) == 0) continue;
		if(line.compare(ENDOFINPUT) == 0) break;

		int line_length = line.length();
		for(int i = 0; i < line_length; ++i){
			if(line[i] >= 'A' && line[i] <= 'Z'){
				int num = line[i] - 'A';
				num = (num - SHIFT) < 0 ? (num + ALPHA - SHIFT) : (num - SHIFT);
				printf("%c", 'A' + num);
			}
			else
				printf("%c", line[i]);
		}
	    puts("");
	}
	return 0;
}
