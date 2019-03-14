#include<cstdio>
#include<iostream>
#include<cstdlib>

using namespace std;

int a[50001],case_num = 0;

int find(int x){
	if(x == a[x])	return x;
	return a[x] = find(a[x]);
}

void Union(int x,int y){
	int X = find(x);
	int Y = find(y);
	a[X] = Y;
}

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF && n+m!=0){	
		case_num++;
		/* initialize */
		int i,j;
		for(int k = 1;k<=n;++k)	a[k] = k;
		for(int k = 0;k<m;++k){
			scanf("%d %d\n",&i,&j);
			Union(i,j);
		}
		int count[n+1],amount = 0;
		for(int k = 0;k<=n;++k)	count[k] = 0;
		int temp;
		for(int k = 1;k<=n;++k){
			a[k] = find(k);
			temp = a[k];
			count[temp]++;
		}
		for(int k = 1;k<=n;++k){
			if(count[k]!=0)	amount++;
		}
		printf("Case %d: %d\n",case_num,amount);
	}
	return 0;
}
