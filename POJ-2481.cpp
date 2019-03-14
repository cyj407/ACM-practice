#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int s[100001], vis[100001];

struct Node{
	int st,end,order;
};

struct Node node[100001];

bool cmp(struct Node a, struct Node b){
	if(a.end == b.end)
		return a.st < b.st;
	return b.end < a.end;
}

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
	for(int i = index;i<=100001;i += lowbit(i))
		s[i] += delta;
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF && n){
		memset(vis,0,sizeof(vis));
		memset(s,0,sizeof(s));
		for(int i = 0;i<n;++i){
			node[i].order = i+1;
			scanf("%d%d",&node[i].st,&node[i].end);
			++node[i].st;
		}
		sort(node,node+n,cmp);
		for(int i = 0;i<n;++i){
			if(node[i].st == node[i-1].st && node[i].end == node[i-1].end && i != 0){
				vis[node[i].order] = vis[node[i-1].order];
				change(node[i].st,1);
				continue;
			}
			vis[node[i].order] = get_sum(node[i].st);
			change(node[i].st,1);
		}
		for(int i = 1;i<n;++i)
			printf("%d ",vis[i]);
		printf("%d\n",vis[n]);
	}
	return 0;
}
