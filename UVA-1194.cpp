#include<cstdio>
#include<cstring>

using namespace std;

int ltotal,rtotal;
int llink[120],rlink[120];
bool used[120],adj[120][120];

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
	while(scanf("%d",&ltotal)!=EOF && ltotal){
		int k;
		scanf("%d%d",&rtotal,&k);	
		memset(adj,false,sizeof(adj));
		for(int i = 0;i<k;++i){
			int job_num,a_mode,b_mode;
			scanf("%d%d%d",&job_num,&a_mode,&b_mode);
			if(a_mode!=0 || b_mode!=0)
				adj[a_mode][b_mode] = true;
		}
		printf("%d\n",Bipartite());
	}
	return 0;
}
