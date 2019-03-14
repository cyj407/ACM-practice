#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;
vector<int> input;
int case_n = 1;

void LDS(){
	int lds[input.size()], max = 0;
	for(int i = 0;i<input.size();++i){
		lds[i] = 1;
		for(int j = 0;j<i;++j){
			if(input[i] <= input[j] && lds[i] < lds[j]+1){
				lds[i] = lds[j]+1;
			}
		}
		if(lds[i] > max)
			max = lds[i];
	}
	if(case_n != 1)	cout << endl;
	printf("Test #%d:\n  maximum possible interceptions: %d\n",case_n++,max);
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		if(n != -1)
			input.push_back(n);
		else{
			if(input.empty())
				break;
			LDS();
			input.clear();
		}
	}
	return 0;
}
