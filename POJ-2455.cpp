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

int FordFulkerson(int n){
	int maxFlow = 0;
	while(1){
		memset(vis,false,sizeof(vis));
		if(!DFS(1,n,n))		// can't find augmenting path
			break;
		maxFlow += FindFlow(1,n,n);		// total flow
	}
	return maxFlow;
}

int main(){
	int n,p,t;	// n nodes, p edges, t roads
	scanf("%d%d%d",&n,&p,&t);
	int max_edge = 0;
	vector<struct Edge> edge;
	for(int i = 0;i<p;++i){
		struct Edge e;
		scanf("%d%d%d",&e.st,&e.end,&e.len);
		edge.push_back(e);
		max_edge = max(max_edge, e.len);
	}
	int lf = 0, rt = max_edge, mid;
	while(lf != rt){
		mid = (lf+rt)/2;
		memset(cap,0,sizeof(cap));
		memset(flow,0,sizeof(flow));

		for(int i = 0;i<edge.size();++i){
			if(edge[i].len <= mid){
				++(cap[edge[i].end][edge[i].st]);
				cap[edge[i].st][edge[i].end] = cap[edge[i].end][edge[i].st];
			}
		}
		(FordFulkerson(n) >= t)?(rt = mid):(lf = mid + 1);
	}
	printf("%d\n",lf);
	return 0;
}
