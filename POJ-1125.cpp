#include<iostream>
#include<cstring>

using namespace std;
int dis[150][150];

struct e{
	int st,end,wt;
};
struct e edge[10000];

void Floyd(int nodeNum,int edgeNum){
	for(int i = 1;i<=nodeNum;++i)
		for(int j = 1;j<=nodeNum;++j)
			dis[i][j] = 1000000;
	for(int i = 1;i<=nodeNum;++i)
		dis[i][i] = 0;
	for(int i = 0;i<edgeNum;++i)
		dis[edge[i].st][edge[i].end] = edge[i].wt;
	for(int k = 1;k<=nodeNum;++k)
		for(int i = 1;i<=nodeNum;++i)
			for(int j = 1;j<=nodeNum;++j)
				if(dis[i][k] + dis[k][j] < dis[i][j])
					dis[i][j] = dis[i][k] + dis[k][j];
}

int main(){
	int n;		// node range: 1~n
	while(cin >> n && n){
		memset(dis,0,sizeof(dis));
		memset(edge,0,sizeof(edge));
		int k = 0;		// edge range: 0~k-1
		for(int i = 1;i<=n;++i){
			int num;
			cin >> num;
			for(int j = 0;j<num;++j,++k){
				edge[k].st = i;
				cin >> edge[k].end >> edge[k].wt;
			}
		}
		Floyd(n,k);
		int start = 0, min = 1000000;
		for(int i = 1;i<=n;++i){
			int max = 0;
			for(int j = 1;j<=n;++j)
				if(dis[i][j] > max)
					max = dis[i][j];
			if(max < min && max != 1000000){
				start = i;
				min = max;
			}
		}
		if(min == 1000000)
			cout << "disjoint" << endl;
		else
			cout << start << " " << min << endl;
	}
	return 0;
}
