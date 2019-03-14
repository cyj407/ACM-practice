#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

int ltotal,rtotal;
int llink[500],rlink[500];
bool used[500],adj[500][500];

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
	int case_n;
	while(scanf("%d",&case_n)!=EOF){
		memset(adj,false,sizeof(adj));
		int ltotal,rtotal;
		scanf("%d%d",&ltotal,&rtotal);
		for(int i = 1;i<=ltotal;++i){
			for(int j = 1;j<=rtotal;++j){
				int tmp;
				scanf("%d",&tmp);
				if(tmp == 1)
					adj[i][j] = true;
			}
		}
		printf("%d\n",Bipartite());
	}
	return 0;
}
