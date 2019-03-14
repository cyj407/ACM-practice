#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;
int dp[10001];

void term(){
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	for(int i = 3;i<10001;++i){
		dp[i] = i;
		for(int j = i-1;j>=1;--j){
			if(i == pow(j,2)){
				dp[i] = 1;
			}
			if(dp[i] > dp[j] + dp[i-j]){
				dp[i] = dp[j] + dp[i-j];
			}
		}
	}
}


int main(){
	int t;
	scanf("%d",&t);
	term();
	while(t--){
		int n;
		scanf("%d",&n);
		printf("%d\n",dp[n]);
	}
	return 0;
}
