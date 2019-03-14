#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>

using namespace std;

struct Edge{
	int node1, node2, len;
};

bool operator < (Edge e1,Edge e2){
	return e1.len < e2.len;
}

struct Edge edge[11000];
int p[2100],num[2100];

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

void Kruskal(int n, int e){
	int total = 0, Max = 0;
	sort(edge,edge+e);
	for(int j = 0;j<e && total < n-1;++j){
		if(find(edge[j].node1) != find(edge[j].node2)){
			Union(edge[j].node1,edge[j].node2);
			Max = max(edge[j].len,Max);
			total++;
		}
	}
	cout << Max << endl;
}

int main(){
	int n,e;
	while(cin >> n >> e){
		memset(edge,0,sizeof(edge));
		for(int i = 1;i<=n;++i){
			p[i] = i;
			num[i] = 1;
		}
		for(int i = 0;i<e;++i)
			cin >> edge[i].node1 >> edge[i].node2 >> edge[i].len;
		Kruskal(n,e);
	}
	return 0;
}
