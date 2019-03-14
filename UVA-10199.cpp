#include<map>
#include<vector>
#include<iostream>
#include<cstdio>
#include<sstream>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;

map<string,int> city;
int edge[120][120];
int dfn[120],low[120];
int dfsn, ans;
vector<string> order;

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
	if((child > 1 && cur == pre) || (cur != pre && ap)){
		map<string,int>::iterator it;
		for(it = city.begin();it!= city.end();++it){
			if(it->second == cur){
				order.push_back(it->first);
				break;
			}
		}
		ans++;
	}
}

int main(){
	int n,case_n = 1;
	while(cin >> n && n){
		getchar();
		memset(edge,false,sizeof(edge));
		for(int i = 0;i<120;++i)
			dfn[i] = low[i] = 0;
		city.clear();
		for(int i = 1;i<=n;++i){
			string tmp;
			getline(cin,tmp);
			city[tmp] = i;
		}
		int e;
		cin >> e;
		getchar();
		for(int i = 1;i<=e;++i){
			string t;
			getline(cin,t);
			string t1 = t.substr(0,t.find(" "));
			string t2 = t.substr(t.find(" ")+1,t.length());
			edge[city[t1]][city[t2]] = edge[city[t2]][city[t1]] = true;
		}
		ans = 0;
		for(int i = 1;i<=n;++i){
			dfsn = 0;
			DFS(i,i,n);
		}
		if(case_n != 1)	cout << endl;
		printf("City map #%d: %d camera(s) found\n",case_n++,ans);
		sort(order.begin(),order.end());
		for(int i = 0;i<order.size();++i)
			cout << order[i] << endl;
		order.clear();
	}
	return 0;
}
