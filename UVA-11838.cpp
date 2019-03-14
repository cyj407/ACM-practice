#include<iostream>
#include<cstdio>
#include<stack>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> edge[2200];
int dfn[2200],low[2200];
bool inStk[2200];
stack<int> s[2200];
int ans, dfsn;

void DFS(int cur,int n){
	dfn[cur] = low[cur] = ++dfsn;
	s[cur].push(cur);
	inStk[cur] = true;
	for(int i = 0;i<edge[cur].size();++i){
		int tmp = edge[cur][i];
		if(!dfn[tmp])
			DFS(tmp,n);
		if(inStk[tmp])
			low[cur] = min(low[cur],low[tmp]);
	}
	if(dfn[cur] == low[cur]){
		int top;
		do{
			top = s[cur].top();
			s[cur].pop();
			inStk[top] = false;
		}while(top != cur);
		++ans;
	}
}

int main(){
	int n,e;
	while(cin >> n >> e && n+e){
		int st,end,dir;
		for(int i = 0;i<2200;++i)
			edge[i].clear();
		memset(inStk,false,sizeof(inStk));
		memset(dfn,0,sizeof(dfn));
		for(int i = 0;i<e;++i){
			cin >> st >> end >> dir;
			edge[st].push_back(end);
			if(dir == 2)
				edge[end].push_back(st);
		}
		ans = 0;
		for(int i = 1;i<=n;++i){
			dfsn = 0;
			if(!dfn[i])
				DFS(i,n);
		}
		if(ans == 1)
			cout << "1" << endl;
		else
			cout << "0" << endl;
	}
	return 0;
}
