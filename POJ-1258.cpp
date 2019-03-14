#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;
int n;
int edge[120][120];
int dis[120];
int p[120];
bool vis[120];

void Prim(int n){
	for(int i = 1;i<=n;++i){
		vis[i] = false;
		dis[i] = edge[0][i];
		p[i] = 0;
	}
	vis[0] = true;

	int cost = 0;
	for(int i = 1;i<n;++i){		// n-1 edges
		int u = -1;
		for(int j = 0;j<n;++j){
			if(!vis[j] && (dis[j] < dis[u] || u == -1))
				u = j;
		}
		cost += edge[p[u]][u];
		vis[u] = true;
		for(int v = 0;v<n;++v){
			if(!vis[v] && edge[u][v] < dis[v]){
				dis[v] = edge[u][v];
				p[v] = u;
			}
		}
	}
	printf("%d\n",cost);
}

int main(){
	int n;
	while(cin >> n){
		for(int i = 0;i<n;++i)
			for(int j = 0;j<n;++j)
				scanf("%d",&edge[i][j]);
		Prim(n);
	}
	return 0;
}

