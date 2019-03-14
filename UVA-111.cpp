#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;
vector<int> order;
int n;

void LIS(int base[]){
	int corr[n];
	for(int i = 0;i<n;++i)
		corr[base[i]-1] = order[i];		// correct
	int lis[n], max = -1;
	for(int i = 0;i<n;++i){
		lis[i] = 1;
		for(int j = 0;j<i;++j){
			if(corr[i] > corr[j] && lis[i] < lis[j]+1)
				lis[i] = lis[j]+1;
		}
		if(lis[i] > max)
			max = lis[i];
	}
	cout << max << endl;
}

int main(){
	scanf("%d",&n);
	int stan[n];
	for(int i = 0;i<n;++i)
		scanf("%d",&stan[i]);
	int count = 0, tmp;
	while(scanf("%d",&tmp) == 1){
		if(count <= n){
			count++;
			order.push_back(tmp);
			if(count == n){
				LIS(stan);
				order.clear();
				count = 0;
			}
		}
	}
	return 0;
}
