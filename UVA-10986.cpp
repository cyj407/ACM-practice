#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>

using namespace std;
int dis[20001];
bool inqueue[20001];

struct e{
	int n1,n2,wt;
};
struct e edge[20001];

bool SPFA(int nodeNum, int edgeNum, int s){
	int count[nodeNum];
	memset(count,0,sizeof(count));
	memset(inqueue,false,sizeof(inqueue));
	for(int i = 0;i<nodeNum;++i)
		dis[i] = 1000000;
	dis[s] = 0;
	inqueue[s] = true;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int cur = q.front();
		inqueue[cur] = false;
		q.pop();
		for(int i = 0;i<edgeNum;++i){
			int v = 1000000;
			if(cur == edge[i].n1)
				v = edge[i].n2;
			if(cur == edge[i].n2)
				v = edge[i].n1;
			if(v != 1000000 && dis[cur] + edge[i].wt < dis[v]){
				dis[v] = edge[i].wt + dis[cur];
				if(!inqueue[v]){
					q.push(v);
					inqueue[v] = true;
					++count[v];
					if(count[v] >= nodeNum)
						return true;
				}
			}
		}
	}
	return false;
}

int main(){
	int case_n,ca = 1;
	scanf("%d",&case_n);
	while(case_n--){
		int n,m,s,t;
		scanf("%d%d%d%d",&n,&m,&s,&t);
		int k = 0;		// edge from 0~k-1
		for(int i = 0;i<m;++i,++k){
			scanf("%d%d%d",&edge[i].n1,&edge[i].n2,&edge[i].wt);
		}
		if(s > t){
			int tmp = s;
			s = t;
			t = tmp;
		}
		SPFA(n,m,s);
		if(dis[t] == 1000000)
			printf("Case #%d: unreachable\n",ca++);
		else
			printf("Case #%d: %d\n",ca++,dis[t]);
	}
	return 0;
}
