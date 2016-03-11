#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cmath>
using namespace std;

int calc(string name){
	int name_length = name.length();
	int sum = 0;

	for(int i = 0; i < name_length; ++i){
		float tmp;
		if(name[i] >= 'A' && name[i] <= 'Z'){
				tmp = name[i] - 'A'	+ 1;
		}
		if(name[i] >= 'a' && name[i] <= 'z'){
				tmp = name[i] - 'a' + 1;
		}

		sum = sum + tmp;
	}

	string string_sum;
	while((sum /10) != 0){
		
		stringstream int2str;
		int2str << sum;
		string_sum = int2str.str();

		sum = 0;
		int string_sum_length = string_sum.length();
		for(int i = 0; i < string_sum_length; ++i){
			sum += string_sum[i] - '0';
		}
	}

	return sum;
}


int main(){
	
	string person_A;
	string person_B;

	while(getline(cin, person_A)){
		getline(cin, person_B);

		float sum_A = (float)calc(person_A);
		float sum_B = (float)calc(person_B);

//		cout << sum_A << endl;
//		cout << sum_B << endl;

		float sum_C;
		if(sum_A > sum_B){
			sum_C = sum_A;
			sum_A = sum_B;
			sum_B = sum_C;
		}

		sum_C = sum_A * 100 / sum_B;
		sum_C = sum_C > 100.0 ? 100.0 : sum_C;
		printf("%.2f %%\n", sum_C);
	}

	return 0;
}
