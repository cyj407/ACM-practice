#include<iostream>
#include<cstdio>
#include<stack>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> edge[100010];
int dfn[100010],low[100010];
bool inStk[100010];
stack<int> s;
int scc, dfsn;
int lead[100010];

void DFS(int cur){
	dfn[cur] = low[cur] = ++dfsn;
	s.push(cur);
	inStk[cur] = true;
	for(int i = 0;i<edge[cur].size();++i){
		int tmp = edge[cur][i];
		if(!dfn[tmp]){
			DFS(tmp);
			low[cur] = min(low[cur],low[tmp]);
		}
		if(inStk[tmp])
			low[cur] = min(low[cur],low[tmp]);
	}
	if(dfn[cur] == low[cur]){
		int top;
		++scc;
		do{
			top = s.top();
			s.pop();
			lead[top] = scc;
			inStk[top] = false;
		}while(top != cur);
	}
}

int main(){
	int case_n;
	scanf("%d",&case_n);
	while(case_n--){
		int n,e;
		scanf("%d%d",&n,&e);
		for(int i = 0;i<100010;++i)
			edge[i].clear();
		memset(inStk,false,sizeof(inStk));
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		for(int i = 0;i<e;++i){
			int st,end;
			scanf("%d%d",&st,&end);
			edge[st].push_back(end);
		}
		scc = 0, dfsn = 0;
		for(int i = 1;i<=n;++i){
			if(!dfn[i])
				DFS(i);
		}
		int indeg[100010] = {};
		for(int i = 1;i<=n;++i)
			for(int j = 0;j<edge[i].size();++j)
				if(lead[i] != lead[edge[i][j]])
					indeg[lead[edge[i][j]]]++;
		int count = 0;
		for(int i = 1;i<=scc;++i)
			if(!indeg[i])
				count++;
		printf("%d\n",count);
	}
	return 0;
}
