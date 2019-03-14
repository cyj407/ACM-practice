#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
	int total,quest;
	int case_num = 1;
	while(scanf("%d%d",&total,&quest)!=EOF && total+quest!=0){
		int marble[total],ask[quest];
		for(int i = 0;i<total;++i)	scanf("%d",&marble[i]);
		for(int i = 0;i<quest;++i)	scanf("%d",&ask[i]);

		sort(marble,marble+total);
		int ans[quest];
		for(int i = 0;i<quest;++i)	ans[i] = -1;
		for(int i = 0;i<quest;++i){
			for(int j = 0;j<total;++j){
				if(marble[j] == ask[i]){
					ans[i] = j+1;
					break;
				}
			}
		}
		printf("CASE# %d:\n",case_num++);
		for(int i = 0;i<quest;++i){
			if(ans[i]<0)	printf("%d not found\n",ask[i]);
			else	printf("%d found at %d\n",ask[i],ans[i]);
		}
	}
	return 0;
}
