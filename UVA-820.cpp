#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
int cap[210][210], flow[210][210];
bool vis[210];
int p[210];

int FindFlow(int s, int t,int n){	// start, end, total_node
	int pre;
	int bottleneck = 10000;
	
	// find the bottleneck
	for(int i = t;i!=s;i = p[i]){
		pre = p[i];
		if(cap[pre][i] - flow[pre][i] > 0)		// cap > flow
			bottleneck = min(bottleneck,cap[pre][i] - flow[pre][i]);
		else	// reverse flow
			bottleneck = min(bottleneck,flow[i][pre]);
	}
	// update the flow
	for(int i = t;i!=s;i = p[i]){
		pre = p[i];
		if(cap[pre][i] - flow[pre][i] > 0)		// cap <= flow
			flow[pre][i] += bottleneck;
		else	// reverse flow
			flow[i][pre] -= bottleneck;
	}
	return bottleneck;
}

bool DFS(int cur, int t, int n){
	vis[cur] = true;
	if(cur == t)	// current point == sink >> already find the augmenting path
		return true;
	for(int i = 1;i<=n;++i){
		if(vis[i])
			continue;
		if(cap[cur][i] - flow[cur][i] > 0 || flow[i][cur] > 0){
		// cap <= flow or reverse flow
			p[i] = cur;		// i's previous point = cur 
			if(DFS(i,t,n))		// path from i to t is exist
				return true;
		}
	}
	return false;
}

int FordFulkerson(int n, int s, int t){
	int maxFlow = 0;
	while(1){
		memset(vis,false,sizeof(vis));
		if(!DFS(s,t,n))		// can't find augmenting path
			break;
		maxFlow += FindFlow(s,t,n);		// total flow
	}
	return maxFlow;
}

int main(){
	int n, network = 1;
	while(scanf("%d",&n)!=EOF && n){
		memset(cap,0,sizeof(cap));
		memset(flow,0,sizeof(flow));
		memset(p,0,sizeof(p));
		int s,t,edgeNum;
		scanf("%d%d%d",&s,&t,&edgeNum);
		for(int i = 0;i<edgeNum;++i){
			int st,end,ca;
			scanf("%d%d%d",&st,&end,&ca);
			cap[st][end] += ca;
			int max_bw = max(cap[end][st], cap[st][end]);
			cap[st][end] = cap[end][st] = max_bw;
		}
		printf("Network %d\n",network++);
		printf("The bandwidth is %d.\n\n",FordFulkerson(n,s,t));
	}
	return 0;
}
