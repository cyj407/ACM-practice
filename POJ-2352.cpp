#include<cstdio>
#include<cstring>

using namespace std;

int s[32100], vis[32100];

int lowbit(int in){
	return in&(-in);
}

int get_sum(int index){
	int ans = 0;
	while(index > 0){
		ans += s[index];
		index -= lowbit(index);
	}
	return ans;
}

void change(int index,int delta){
	for(int i = index;i<=32001;i += lowbit(i))
		s[i] += delta;
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		memset(vis,0,sizeof(vis));
		for(int i = 0;i<n;++i){
			int x,y;
			scanf("%d%d",&x,&y);
			change(++x,1);
			int sum = get_sum(x);
			++vis[sum];
		}
		for(int i = 1;i<=n;++i)
			printf("%d\n",vis[i]);
	}
	return 0;
}
