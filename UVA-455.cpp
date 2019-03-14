#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int findPeriod(string input){
	int len = input.length();
	int period;
	bool per[len];
	memset(per,false,sizeof(per));
	for(period = 1;period < len;++period){
		if(len%period != 0)
			continue;
		string tmp[len];
		bool find = true;
		for(int i = 0;i<len/period;++i){
			tmp[i] = input.substr(i*period,period);
			if(tmp[0] != tmp[i]){
				find = false;
				break;
			}
		}
		if(find)
			per[period] = true;
	}
	for(int i = 1;i<len;++i)
		if(per[i])
			return i;
	return len;
}

int main(){
	int case_n;
	scanf("%d\n",&case_n);
	while(case_n--){
		string input = "\0";
		while(input == "\0")
			getline(cin,input);
		cout << findPeriod(input) << endl;
		if(case_n)
			cout << endl;
	}
	return 0;
}
