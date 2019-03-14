#include<cstdio>
#include<cmath>
#include<iostream>

using namespace std;
long long int c[201][201];

void count_way(){
	// C(n,k) = C(n-1,k) + C(n-1,k-1)
//	cout << up << " " << down << endl;
	for(int i = 0;i<201;++i){
		c[i][1] = i;
		c[i][0] = 1;
		c[i][i] = 1;
	}
	for(int i = 1;i<201;++i){
		for(int j = 2;j<201;++j){
			c[j][i] = (c[j-1][i] + c[j-1][i-1])%1000000;
		}
	}
}

int main(){
	long long int n,k;
	count_way();
	while(scanf("%lld%lld",&n,&k)!=EOF && n+k!=0){
		cout << c[n+k-1][n] << endl;
	}
	return 0;
}
