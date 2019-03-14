#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>

using namespace std;

struct loc{
	double x,y;
};

struct Edge{
	int node1, node2;
	double len;
};

bool operator < (Edge e1,Edge e2){
	return e1.len < e2.len;
}

struct loc node[1100];
struct Edge edge[1100*1100];
int p[1100],num[1100];

int find(int x){
	if(x == p[x])	return x;
	return x = find(p[x]);
}

void Union(int x, int y){
	int X = find(x);
	int Y = find(y);
	if(num[X] > num[Y]){
		p[Y] = X;
		num[X] += num[Y];
	}
	else{
		p[X] = Y;
		num[Y] += num[X];
	}
}

double Kruskal(int n, int e){
	double cost = 0.0f;
	int total = 0;
	sort(edge,edge+e);
	for(int j = 0;j<e && total < n-1;++j){
		if(find(edge[j].node1) != find(edge[j].node2)){
			Union(edge[j].node1,edge[j].node2);
			cost += edge[j].len;
			total++;
		}
	}
	return cost;
}

int main(){
	int n,tmp;
	while(scanf("%d%d",&n,&tmp)!=EOF){
		int e = 0, connect = 0;
		for(int i = 1;i<=n;++i){
			p[i] = i;
			num[i] = 1;
		}
		memset(edge,0,sizeof(edge));
		for(int i = 1;i<=n;++i)
			scanf("%lf%lf",&node[i].x,&node[i].y);
		for(int i = 1;i<=tmp;++i){
			int x,y;
			scanf("%d%d",&x,&y);
			if(find(x) != find(y)){
				Union(x,y);
				connect++;
			}
		}
		for(int i = 1;i<=n;++i)
			for(int j = i+1;j<=n;++j)
				if(find(i) != find(j)){
					double dx = node[i].x - node[j].x;
					double dy = node[i].y - node[j].y;
					edge[e].node1 = i, edge[e].node2 = j;
					edge[e++].len = sqrt(pow(dx,2) + pow(dy,2));
				}
		printf("%.2lf\n",Kruskal(n-connect,e));
	}
	return 0;
}
