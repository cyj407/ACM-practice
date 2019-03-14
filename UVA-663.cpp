#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

int n;
int llink[1000],rlink[1000];
bool used[1000],adj[1000][1000];

bool DFS(int now){
	for(int i = 1;i<=n;++i){
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
	for(int i = 1;i<=n;++i){
		memset(used,false,sizeof(used));
		if(DFS(i))
			++ans;
	}
	return ans;
}

int main(){
	int case_n = 0;
	while(scanf("%d",&n)!=EOF && n){
		int xmin[n+1],xmax[n+1],ymin[n+1],ymax[n+1];
		for(int i = 1;i<=n;++i)
			scanf("%d%d%d%d",&xmin[i],&xmax[i],&ymin[i],&ymax[i]);
		memset(adj,false,sizeof(adj));
		for(int i = 1;i<=n;++i){
			int x,y;
			scanf("%d%d",&x,&y);
			for(int j = 1;j<=n;++j)
				if(x >= xmin[j] && x <= xmax[j] && y >= ymin[j] && y <= ymax[j])
					adj[j][i] = true;
		}

		int first_match = Bipartite();
		int lmatch[n+1];
		memset(lmatch,0,sizeof(lmatch));
		for(int i = 1;i<=n;++i)
			lmatch[i] = llink[i];
		printf("Heap %d\n",++case_n);
		bool find = false;
		for(int i = 1;i<=n;++i){
			adj[i][lmatch[i]] = false;
			if(Bipartite() < first_match){
				if(find)
					printf(" ");
				printf("(%c,%d)",i+'A'-1,lmatch[i]);
				find = true;
			}
			adj[i][lmatch[i]] = true;
		}
		if(!find)
			printf("none");
		printf("\n\n");
	}
	return 0;
}
