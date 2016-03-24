#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

int main(){
	int testcase;
	scanf("%d", &testcase);
	for(int w = 0; w < testcase; ++w){
		int num;
		scanf("%d", &num);
		map<char, int> lookup;
		char clean[10];
		gets(clean);
		for(int i = 0; i < num; ++i){
			string line;
			getline(cin, line);
			istringstream stream(line);
			char c;
			int v;
			stream >> c >> v;
			lookup[c] = v;
		}
		scanf("%d", &num);
		gets(clean);
		double sum = 0.0;
		for(int i = 0; i < num; ++i){
			string line;
			getline(cin, line);
			for(int j = 0; j < line.length(); ++j){
				if(lookup.find(line[j]) != lookup.end()){
					sum += lookup[line[j]];
				}
			}

		}

		printf("%.2lf$\n", sum / 100.0);
	}
	return 0;
}
