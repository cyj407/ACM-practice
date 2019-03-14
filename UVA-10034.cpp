#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;
int n;
double edge[120][120];
double dis[120];
int p[120];
bool vis[120];

void Prim(int n){
	for(int i = 1;i<=n;++i){
		vis[i] = false;
		dis[i] = edge[0][i];
		p[i] = 0;
	}
	vis[0] = true;

	double cost = 0.0f;
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
	printf("%.2lf\n",cost);
}

int main(){
	int case_n;
	scanf("%d",&case_n);
	while(case_n--){
		scanf("%d",&n);
		double x[n],y[n];
		for(int i = 0;i<n;++i)
			scanf("%lf%lf",&x[i],&y[i]);
		for(int i = 0;i<n;++i){
			for(int j = 0;j<n;++j){
				double dx = x[i]-x[j];
				double dy = y[i]-y[j];
				edge[i][j] = sqrt(pow(dx,2) + pow(dy,2));	
			}
		}
		Prim(n);
		if(case_n)
			cout << endl;
	}
	return 0;
}

