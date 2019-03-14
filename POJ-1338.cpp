#include<iostream>
#include<cstdio>

using namespace std;

int main(){
	long long int ans[1500];
	ans[0] = 1;
	long long int cur2 = 0, cur3 = 0, cur5 = 0;
	long long int tmp2 = 1, tmp3 = 1, tmp5 = 1;
	for(int i = 1;i<1500;i++){
		while(tmp2 <= ans[i-1]){
			tmp2 = ans[cur2++]*2;
		}
		while(tmp3 <= ans[i-1]){
			tmp3 = ans[cur3++]*3;
		}
		while(tmp5 <= ans[i-1]){
			tmp5 = ans[cur5++]*5;
		}
		long long int tmp = (tmp2>tmp3)?tmp3:tmp2;
		tmp = (tmp>tmp5)?tmp5:tmp;
		ans[i] = tmp;
	}
	int n;
	while(scanf("%d",&n)!=EOF && n!=0){
		printf("%lld\n",ans[n-1]);
	}
	return 0;
}
