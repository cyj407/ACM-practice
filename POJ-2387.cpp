#include<iostream>
#include<cstring>

using namespace std;
int dis[2500];

struct e{
	int start;
	int end;
	int weight;
};

struct e edge[2500];

void Relax(int u,int v,int w){
	if(dis[u] + w < dis[v])
		dis[v] = dis[u] + w;
}

void BellmanFord(int t, int n){
	memset(dis,1000000,sizeof(dis));
	dis[1] = 0;		// start from 1

	for(int i = 0;i<n-1;++i){	// n-1 times
		for(int j = 0;j<t;++j){
			int u = edge[j].start;
			int v = edge[j].end;
			int w = edge[j].weight;
			Relax(u,v,w);
			Relax(v,u,w);
		}
	}

}

int main(){
	int t,n;	// t = edge , n = node
	while(cin >> t >> n){
		memset(edge,0,sizeof(struct e));
		for(int i = 0;i<t;++i){
			cin >> edge[i].start >> edge[i].end >> edge[i].weight;
		}
		BellmanFord(t,n);
		cout << dis[n] << endl;
	}
	return 0;
}
