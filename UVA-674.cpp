#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
int v[5] = {1,5,10,25,50};

void coin(int dp[],int amount){
	dp[0] = 1;
	for(int k = 0;k<5;++k){
		for(int i = v[k];i<=amount;++i){
			if(dp[i-v[k]]!=0)
				dp[i] += dp[i-v[k]];
		}
	}
}

int main(){
	int amount;
	while(scanf("%d",&amount)!=EOF){
		int dp[amount+1];
		memset(dp,0,sizeof(dp));
		coin(dp,amount);
		printf("%d\n",dp[amount]);
	}
	return 0;
}
