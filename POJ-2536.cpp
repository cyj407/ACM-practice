#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

int ltotal,rtotal;
int llink[120],rlink[120];
bool used[120],adj[120][120];

struct Node{
	double x,y;
};

bool DFS(int now){
	for(int i = 1;i<=rtotal;++i){
		if(!used[i] && adj[now][i]){
			used[i] = true;
			if(rlink[i] == 0 || DFS(rlink[i])){
				llink[now] = i;
				rlink[i] = now;
				return true;
			}
		}
	}
	return false;
}

int Bipartite(){
	int ans = 0;
	memset(llink,0,sizeof(llink));
	memset(rlink,0,sizeof(rlink));
	for(int i = 1;i<=ltotal;++i){
		memset(used,false,sizeof(used));
		if(DFS(i))
			++ans;
	}
	return ans;
}

int main(){
	int sec,speed;
	while(scanf("%d%d%d%d",&ltotal,&rtotal,&sec,&speed)!=EOF){
		struct Node lnode[ltotal+1],rnode[rtotal+1];
		for(int i = 1;i<=ltotal;++i)
			scanf("%lf%lf",&lnode[i].x,&lnode[i].y);
		for(int i = 1;i<=rtotal;++i)
			scanf("%lf%lf",&rnode[i].x,&rnode[i].y);
		memset(adj,false,sizeof(adj));
		for(int i = 1;i<=ltotal;++i){
			for(int j = 1;j<=rtotal;++j){
				double length = sqrt(pow(lnode[i].x-rnode[j].x,2) + pow(lnode[i].y-rnode[j].y,2));
				if(length/speed <= (double)sec)
					adj[i][j] = true;
			}
		}
		printf("%d\n",ltotal-Bipartite());
	}
	return 0;
}
