#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

bool solve(string, string);

int main(){

	string message_A;
	string message_B;
	while(getline(cin, message_A)){
		getline(cin, message_B);

		if(solve(message_A, message_B)){
			puts("YES");
		}else
			puts("NO");
	}

	return 0;
}

bool solve(string message_A, string message_B){
	int cnt_A[26] = {0};
	int cnt_B[26] = {0};

	int message_length_A = message_A.length();
	int message_length_B = message_B.length();

	for(int i = 0; i < message_length_A; ++i){
		if(message_A[i] >= 'A' && message_A[i] <= 'Z')
			cnt_A[message_A[i] - 'A']++;
	}
	for(int i = 0; i < message_length_B; ++i){
		if(message_B[i] >= 'A' && message_B[i] <= 'Z')
			cnt_B[message_B[i] - 'A']++;
	}

	sort(cnt_A, cnt_A + 26);
	sort(cnt_B, cnt_B + 26);

	for(int i = 0; i < 26; ++i){
		if(cnt_A[i] != cnt_B[i]) return false;
	}

	return true;
}
