#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;
int weight[3500],desire[3500];

int collect(int dp[],int n,int m){
	for(int k = 0;k<n;++k){
		for(int i = m;i>=0;--i){
			if(weight[k]<=i){
				if(desire[k]+ dp[i-weight[k]] > dp[i]){
					dp[i] = desire[k]+ dp[i-weight[k]];
				}
			}	
		}	
	}
	return dp[m];
}

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(weight,0,sizeof(weight));
		memset(desire,0,sizeof(desire));
		for(int i = 0;i<n;++i)
			scanf("%d%d",&weight[i],&desire[i]);
		int dp[13000];
		memset(dp,0,sizeof(dp));
		cout << collect(dp,n,m) << endl;
	}
	return 0;
}
