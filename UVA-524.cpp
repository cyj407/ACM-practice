#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
int ans[16];
int n,total;
int prime[] = { 2,3,5,7,11,13,17,19,23,29,31 };
bool visit[16];

bool isPrime(int check){
	for(int i = 0;i<11;++i){
		if(prime[i] == check){
			return true;
		}
	}
	return false;
}

void backtracking(int digit){
	ans[0] = 1;
	if(digit == n){
 		if(isPrime(ans[n-1]+ans[0])){
			for(int j = 0;j<n;++j){
				cout << ans[j];
				if(j != n-1)	cout << " ";
			}
			cout << endl;
		}
		return;
	}
	for(int k = 2;k<=n;++k){	
		if(visit[k])	continue;
		if(isPrime(k+ans[digit-1])){
			visit[k] = true;
			ans[digit] = k;
			backtracking(digit+1);
			visit[k] = false;
		}
	}
}

int main(){
	int case_n = 1;
	while(scanf("%d",&n)!=EOF){
		memset(visit,false,sizeof(visit));
		if(case_n != 1)	cout << endl;
		total = 0;
		printf("Case %d:\n",case_n++);
		backtracking(1);
	}
	return 0;
}
