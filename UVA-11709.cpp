#include<iostream>
#include<cstdio>
#include<stack>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
#include<string>

using namespace std;
vector<int> edge[1200];
int dfn[1200],low[1200];
bool inStk[1200];
stack<int> s;
int ans, dfsn;

void DFS(int cur){
	dfn[cur] = low[cur] = ++dfsn;
	s.push(cur);

	for(int i = 0;i<edge[cur].size();++i){
		int tmp = edge[cur][i];
		if(inStk[tmp])	continue;
		if(!dfn[tmp]){
			DFS(tmp);
			low[cur] = min(low[cur],low[tmp]);
		}
		else
			low[cur] = min(low[cur],dfn[tmp]);
	}
	if(dfn[cur] == low[cur]){
		ans++;
		int top;
		do{
			top = s.top();
			s.pop();
			inStk[top] = true;
		}while(top != cur);
	}
}

int main(){
	int n,e;
	while(scanf("%d%d\n",&n,&e)!=EOF && n+e){
		memset(inStk,false,sizeof(inStk));
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		map<string,int> trust;
		for(int i = 1;i<=n;++i){
			string in;
			getline(cin,in);
			trust[in] = i;
		}
		for(int i = 0;i<1200;++i)
			edge[i].clear();
		for(int i = 1;i<=e;++i){
			string n1,n2;
			getline(cin,n1);
			getline(cin,n2);
			int st = trust[n1];
			int end = trust[n2];
			edge[st].push_back(end);
		}
		ans = 0,dfsn = 0;
		for(int i = 1;i<=n;++i){
			if(!dfn[i])
				DFS(i);
		}
		cout << ans << endl;
	}
	return 0;
}
