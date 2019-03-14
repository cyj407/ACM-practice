#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;
int num[1100];

void LIS(int n){
	int lis[n],max = -1;
	memset(lis,1,sizeof(lis));
	for(int i = 0;i<n;++i){
		lis[i] = 1;
		for(int j = 0;j<i;++j){
			if(num[i] > num[j] && lis[j]+1 > lis[i])	
				lis[i] = lis[j]+1;
		}
		if(lis[i] > max)
			max = lis[i];
	}
	cout << max << endl;
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i = 0;i<n;++i)
			scanf("%d",&num[i]);
		LIS(n);
	}
	return 0;
}
