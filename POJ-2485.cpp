#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;
int edge[510][510];
int dis[510];
int p[510];
bool vis[510];

void Prim(int n){
	for(int i = 1;i<=n;++i){
		vis[i] = false;
		dis[i] = edge[0][i];
		p[i] = 0;
	}
	vis[0] = true;

	int Max = -1;
	for(int i = 1;i<n;++i){		// n-1 edges
		int u = -1;
		for(int j = 0;j<n;++j){
			if(!vis[j] && (dis[j] < dis[u] || u == -1))
				u = j;
		}
		Max = max(edge[p[u]][u],Max);
		vis[u] = true;
		for(int v = 0;v<n;++v){
			if(!vis[v] && edge[u][v] < dis[v]){
				dis[v] = edge[u][v];
				p[v] = u;
			}
		}
	}
	printf("%d\n",Max);
}

int main(){
	int case_n;
	cin >> case_n;
	while(case_n--){
		int n;
		cin >> n;
		for(int i = 0;i<n;++i)
			for(int j = 0;j<n;++j)
				scanf("%d",&edge[i][j]);
		Prim(n);
	}
	return 0;
}

