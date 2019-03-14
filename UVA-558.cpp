#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;
int dis[1500];

struct e{
	int start,end,weight;
};
struct e edge[2500];

bool BellmanFord(int nodeNum, int edgeNum){
	dis[1500] = {1000000};
	dis[0] = 0;

	for(int i = 0;i<nodeNum-1;++i)
		for(int j = 0;j<edgeNum;++j)
			if(dis[edge[j].start] + edge[j].weight < dis[edge[j].end])
				dis[edge[j].end] = dis[edge[j].start] + edge[j].weight;

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
		int n,m;	// n = node , m = edge
		cin >> n >> m;
		memset(edge,0,sizeof(edge));
		for(int i = 0;i<m;++i)
			cin >> edge[i].start >> edge[i].end >> edge[i].weight;
		if(BellmanFord(n,m))
			printf("possible\n");
		else
			printf("not possible\n");
	}
	return 0;
}
