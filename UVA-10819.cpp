#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;
int dp[13000];
int cost[3500],desire[3500];

int collect(int spend,int n){
	memset(dp,0,sizeof(dp));
	if(spend > 1800)	spend += 200;
	for(int k = 0;k<n;++k){
		for(int i = spend;i>=cost[k];--i){
			if(desire[k]+ dp[i-cost[k]] > dp[i]){
				dp[i] = desire[k]+ dp[i-cost[k]];
			}
		}	
	}
	int budget = spend;
	while(budget > 0 && dp[budget] == dp[budget-1]){
		--budget;
	} // find the closest dp
	if(spend > 2000 && budget <= 2000)	return dp[spend-200];
	return dp[spend];
}

int main(){
	int budget,n;
	while(scanf("%d%d",&budget,&n)!=EOF){
		for(int i = 0;i<n;++i){
			scanf("%d%d",&cost[i],&desire[i]);
		}
		cout << collect(budget,n) << endl;
	}
	return 0;
}
