#include<iostream>
#include<cstdio>
#include<sstream>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;
bool edge[120][120];
int dfn[120],low[120];
int dfsn = 0, ans;

void DFS(int pre,int cur,int n){
	dfn[cur] = low[cur]	= ++dfsn;
	int child = 0;
	bool ap = false;
	for(int i = 1;i<=n;++i){
		if(edge[cur][i] && i != pre){	// i not visit
			if(!dfn[i]){
				++child;
				DFS(cur,i,n);
				low[cur] = min(low[cur],low[i]);
				if(low[i] >= dfn[cur])
					ap = true;
			}
			else
				low[cur] = min(low[cur],dfn[i]);
		}
	}
	if((child > 1 && cur == pre) || (cur != pre && ap))
		ans++;
}

int main(){
	int n;
	while(cin >> n && n){
		memset(edge,false,sizeof(edge));
		for(int i = 0;i<120;++i)
			dfn[i] = low[i] = 0;
		getchar();
		while(1){
			string s;
			getline(cin,s);
			stringstream ss;
			ss.clear();
			ss.str(s);
			int st, end;
			ss >> st;
			if(st == 0)	break;
			while(1){
				if(ss.fail())	break;
				ss >> end;
				edge[st][end] = edge[end][st] = true;
			}
		}
		ans = 0;
		DFS(1,1,n);
		cout << ans << endl;
	}
	return 0;
}
