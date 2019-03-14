#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
int dis[1000];

struct e{
	int start;
	int end;
	int weight;
};
struct e edge[3000];

void Relax(int u, int v, int w){
	if(dis[u] + w < dis[v])
		dis[v] = dis[u] + w;
}

bool BellmanFord(int nodeNum, int edgeNum , int pos){
	memset(dis,100000,sizeof(dis));
	dis[0] = 1;
	
	for(int i = 0;i<nodeNum-1;++i){
		for(int j = 0;j<edgeNum;++j){
			if(j < pos){
				Relax(edge[j].start,edge[j].end,edge[j].weight);
				Relax(edge[j].end,edge[j].start,edge[j].weight);
			}
			else
				Relax(edge[j].start,edge[j].end,edge[j].weight);
		}
	}

	for(int i = 0;i<edgeNum;++i){
		if(dis[edge[i].start] + edge[i].weight < dis[edge[i].end])
			return true;
	}
	return false;
}

int main(){
	int case_n;
	cin >> case_n;
	while(case_n--){
		int node,pos,neg;
		cin >> node >> pos >> neg;
		int edge_num = pos+neg;
		for(int i = 0;i<edge_num; ++i){
			cin >> edge[i].start >> edge[i].end >> edge[i].weight;
			if(i > pos-1)
				edge[i].weight *= -1;
		}
		if(BellmanFord(node, edge_num, pos))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
