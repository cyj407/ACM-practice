#include<iostream>
#include<cstdio>
#include<cstring>
#define N 5

using namespace std;
bool visit[100];
int ans[6];
static int num;
int list[100];

void backtracking(int digit,int index){
	visit[index] = true;
	ans[digit] = list[index];
	
	for(int i = index+1;i<num;++i){
		if(visit[i] == false){
			backtracking(digit+1,i);
		}
	}

	if(digit == N){
		printf("%d",ans[0]);
		for(int i = 1;i<N+1;++i){
			printf(" %d",ans[i]);
		}
		puts("");
	}

	visit[index] = false;
	return;
}

int main(){
	int case_n = 0;
	while(scanf("%d",&num)!=EOF){
		if(num == 0)	break;
		if(num != 0 && case_n!= 0)	printf("\n");
		memset(visit,0,sizeof(visit));
		memset(list,0,sizeof(list));
		for(int i = 0;i<num;++i) {
			scanf("%d",&list[i]);
		}
		for(int i = 0;i<num;++i){
			backtracking(0,i);
		}
		case_n++;
	}
	return 0;
}
