#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;
long long int s[12000];

struct Edge{
	int st,end;
};

struct Edge edge[1000100];

int lowbit(int in){
	return in&(-in);
}

long long int get_sum(int index){
	long long int ans = 0;
	while(index > 0){
		ans += s[index];
		index -= lowbit(index);
	}
	return ans;
}

void change(int index,int delta){
	for(int i = index;i<=12000;i += lowbit(i))
		s[i] += delta;
}

bool cmp(struct Edge e1,struct Edge e2){
	if(e1.st != e2.st)
		return e1.st < e2.st;
	return e1.end < e2.end;
}

int main(){
	int case_n,ca = 0;
	scanf("%d",&case_n);
	while(case_n--){
		memset(s,0,sizeof(s));
		int n,m,k;
		long long int crossNum = 0;
		scanf("%d%d%d",&n,&m,&k);
		for(int i = 1;i<=k;++i)
			scanf("%d%d",&edge[i].st,&edge[i].end);
		sort(edge+1,edge+k+1,cmp);
		for(int i = 1;i<=k;++i){
			change(edge[i].end,1);
			long long int sum = get_sum(edge[i].end);
			crossNum += i-sum;
		}
		printf("Test case %d: %lld\n",++ca,crossNum);
	}
	return 0;
}
