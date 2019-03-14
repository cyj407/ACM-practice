#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

int dis[1001][1001];

void Floyd(int nodeNum, int edgeNum){
	for(int k = 1;k<=nodeNum;++k)
		for(int i = 1;i<=nodeNum;++i)
			for(int j = 1;j<=nodeNum;++j)
				if(max(dis[i][k],dis[k][j]) < dis[i][j])
					dis[i][j] = max(dis[i][k],dis[k][j]);
}

int main(){
	int c,q,s,case_n = 1;
	while(scanf("%d%d%d",&c,&q,&s)!=EOF && c+q+s){
		for(int i = 1;i<=c;++i)
			for(int j = 1;j<=c;++j)
				dis[i][j] = dis[j][i] = 1000000;
		for(int i = 1;i<=c;++i)
			dis[i][i] = 0;
		int st,end;
		for(int i = 0;i<q;++i){
			int dist;
			scanf("%d%d%d",&st,&end,&dist);
			dis[end][st] = dis[st][end] = dist;
		}
		Floyd(c,q);
		int qSt[s],qEd[s];
		for(int i = 0;i<s;++i){
			scanf("%d%d",&qSt[i],&qEd[i]);
			if(qSt[i] > qEd[i])
				swap(qSt[i],qEd[i]);
		}

		if(case_n != 1)	printf("\n");
		printf("Case #%d\n",case_n++);
		for(int i = 0;i<s;++i){
			if(dis[qSt[i]][qEd[i]] == 1000000)
				printf("no path\n");
			else
				printf("%d\n",dis[qSt[i]][qEd[i]]);
		}
	}
	return 0;
}
