#include<climits>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
int cap[210][210], flow[210][210];
bool vis[210];
int p[210];

struct Edge{
	int st,end,len;
};

int FindFlow(int s, int t,int n){	// start, end, total_node
	int pre;
	int bottleneck = 1000000;
	
	// find the bottleneck
	for(int i = t;i!=s;i = p[i]){
		pre = p[i];
		if(cap[pre][i] - flow[pre][i] > 0)		// cap <= flow
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
	for(int i = 0;i<=n;++i){
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

int FordFulkerson(int n){
	int maxFlow = 0;
	while(1){
		memset(vis,false,sizeof(vis));
		if(!DFS(0,n,n))		// can't find augmenting path
			break;
		maxFlow += FindFlow(0,n,n);		// total flow
	}
	return maxFlow;
}

int main(){
	int n,edgeNum;
	while(scanf("%d",&n)!=EOF && n){
		int gold[n+1],storage[n+1];
		int max_edge = 0;
		int totalGold = 0;
		for(int i = 1;i<=n;++i){
			scanf("%d",&gold[i]);
			totalGold += gold[i];
			max_edge = max(max_edge, gold[i]);
		}
		for(int i = 1;i<=n;++i){
			scanf("%d",&storage[i]);
			max_edge = max(max_edge, storage[i]);
		}
		scanf("%d",&edgeNum);
		vector<struct Edge> edge;
		for(int i = 0;i<edgeNum;++i){
			struct Edge e;
			scanf("%d%d%d",&e.st,&e.end,&e.len);
			edge.push_back(e);
			max_edge = max(max_edge, e.len);
		}

		int s = 0, t = 2*n+1, nodeNum = 2*n+2;

		int lf = 0, rt = max_edge, mid;
		while(lf <= rt){
			mid = (lf+rt)/2;
			memset(cap,0,sizeof(cap));
			memset(flow,0,sizeof(flow));
			for(int i = 1;i<=n;++i){
				cap[s][i] = cap[i][s] = gold[i];
				cap[i][t] = cap[t][i] = storage[i];
				if(gold[i] <= mid)
					cap[s][i] = cap[i][s] = INT_MAX;
				if(storage[i] <= mid)
					cap[i][t] = cap[t][i] = INT_MAX;
			}
			for(int i = 0;i<edge.size();++i)
				if(edge[i].len <= mid)
					cap[edge[i].st][edge[i].end] = cap[edge[i].end][edge[i].st] = INT_MAX;
			(FordFulkerson(nodeNum) == totalGold)?(rt = mid):(lf = mid + 1);
		}
		printf("%d\n",rt);
	}
	return 0;
}
