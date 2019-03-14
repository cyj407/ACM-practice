#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<sstream>
#include<map>

using namespace std;

struct Edge{
	int node1, node2, len;
};

bool operator < (Edge e1,Edge e2){
	return e1.len < e2.len;
}

struct Edge edge[79850];
int p[410],num[410];
map<string,int> m;

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
	int total = 0, cost = 0;
	for(int i = 1;i<=n;++i){
		p[i] = i;
		num[i] = 1;
	}
	sort(edge,edge+e);
	for(int j = 0;j<e && total < n-1;++j){
		if(find(edge[j].node1) != find(edge[j].node2)){
			Union(edge[j].node1,edge[j].node2);
			cost += edge[j].len;
			total++;
		}
	}
	if(total != n-1)
		cout << "Impossible" << endl;
	else
		cout << cost << endl;
}

int main(){
	int n,e;
	while(scanf("%d%d",&n,&e)!=EOF && n+e){
		memset(edge,0,sizeof(edge));
		for(int i = 1;i<=n;++i){
			string name;
			getline(cin,name);
			m[name] = i;
		}
		for(int i = 0;i<e;++i){
			string n1,n2;
			cin >> n1 >> n2 >> edge[i].len;
			edge[i].node1 = m[n1];
			edge[i].node2 = m[n2];
		}
		string st;
		getline(cin,st);
		Kruskal(n,e);
	}
	return 0;
}
