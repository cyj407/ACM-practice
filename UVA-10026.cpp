#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

struct order{
	int num;
	double finePerDay;
};

bool cmp(struct order o1,struct order o2){
	return o1.finePerDay < o2.finePerDay;
}

using namespace std;

int main(){
	int case_num;
	scanf("%d",&case_num);
	int task;
	for(int i = 0;i<case_num;++i){
		scanf("%d",&task);
		struct order ans[1000];
		for(int j = 0;j<task;++j){	
			double day,fine;
			scanf("%lf %lf",&day,&fine);
			ans[j].finePerDay = day/fine;
			ans[j].num = j+1;
		}// read all data
		sort(ans,ans+task,cmp);
		for(int j = 0;j<task;++j){
			printf("%d",ans[j].num);
			if(j!=task-1)	printf(" ");
		}
		printf("\n");
		if(i != case_num-1)	printf("\n");
	}
	return 0;
}
