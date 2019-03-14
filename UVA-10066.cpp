#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
int a,b,case_n = 1;
int in1[100],in2[100];

void LCS(){
	int lcs[a+1][b+1];
	memset(lcs,0,sizeof(lcs));
	for(int i = 1;i<=a;++i){
		for(int j = 1;j<=b;++j){
			if(in1[i-1] == in2[j-1])
				lcs[i][j] = lcs[i-1][j-1]+1;
			else
				lcs[i][j] = (lcs[i-1][j]>lcs[i][j-1])?lcs[i-1][j]:lcs[i][j-1];
		}
	}
	printf("Twin Towers #%d\nNumber of Tiles : %d\n\n",case_n++,lcs[a][b]);
}

int main(){
	while(scanf("%d%d",&a,&b)!=EOF && a+b!=0){
		memset(in1,0,sizeof(in1));
		memset(in2,0,sizeof(in2));
		for(int i = 0;i<a;++i)
			scanf("%d",&in1[i]);
		for(int j = 0;j<b;++j)
			scanf("%d",&in2[j]);
		LCS();
	}
	return 0;
}
