#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>

using namespace std;
string in1,in2;
int case_n = 1;

void LCS(){
	int lcs[in1.length()+1][in2.length()+1];
	memset(lcs,0,sizeof(lcs));
	for(int i = 1;i<=in1.length();++i){
		for(int j = 1;j<=in2.length();++j){
			if(in1[i-1] == in2[j-1])
				lcs[i][j] = lcs[i-1][j-1]+1;
			else
				lcs[i][j] = (lcs[i-1][j]>lcs[i][j-1])?lcs[i-1][j]:lcs[i][j-1];
		}
	}
	printf("Case #%d: you can visit at most %d cities.\n",case_n++,lcs[in1.length()][in2.length()]);
}

int main(){
	while(getline(cin,in1)){
		if(in1[0] == '#')	break;
		getline(cin,in2);
		LCS();
		in1.clear();
		in2.clear();
	}
	return 0;
}
