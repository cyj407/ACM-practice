#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
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

int charToNum(char size, int n){
	switch(size){
		case 'S':
			return n+1;
		case 'M':
			return n+2;
		case 'L':
			return n+3;
		case 'X':
			return n+4;
		case 'T':
			return n+5;
	}
}

int main(){
	int n;
	string start;
	while(cin >> start && start != "ENDOFINPUT"){
		cin >> n;
		memset(cap,0,sizeof(cap));
		memset(flow,0,sizeof(flow));
		memset(p,0,sizeof(p));
		// 1~n node + S,M,L,X,T 5 nodes
		int s = n+6, t = n+7, nodeNum = n+7;
		for(int i = 1;i<=n;++i){
			string srcToSink;
			cin >> srcToSink;
			cap[s][i] = 1;
			for(int j = charToNum(srcToSink[0],n);j<=charToNum(srcToSink[1],n);++j)
				cap[i][j] = 1;
		}
		for(int i = n+1;i<=n+5;++i){	// size's flow
			int tmp;
			scanf("%d",&tmp);
			cap[i][t] = tmp;
		}
		string end;
		cin >> end;
		if(FordFulkerson(nodeNum,s,t) >= n)
			printf("T-shirts rock!\n");
		else
			printf("I'd rather not wear a shirt anyway...\n");
	}
	return 0;
}
