#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<climits>
#include<cstdio>
#include<cstdlib>
#define MAX 10000000

using namespace std;
bool prime[MAX];
vector<long long int>element;

void is_prime(){
	memset(prime,1,sizeof(prime));
	prime[0] = false;
	prime[1] = false;
	for(long long int i = 2;i<=sqrt(MAX);++i){
		if(prime[i]){
			for(long long int j = i+i;j<MAX;j+=i){
				prime[j] = false;
			}
		}
	}
}

void find_prime(long long int n){
	for(long long int i = 2;i<MAX;++i){
		if(n == 1)	return;
		if(n % i == 0 && prime[i]){
			element.push_back(i);
			n = n/i;
		}
	}
	for(int i = 0;i<element.size();++i){
		while(n % element[i] == 0 && n!=1){
			element.push_back(element[i]);
			n = n/element[i];
		}
	}
	if(n!=1)	element.push_back(n);
}

int main(){
	long long int num;
	while(scanf("%lld",&num)!=EOF && num>0){
		is_prime();
		find_prime(num);
		sort(element.begin(),element.end());
		for(int i = 0;i<element.size();++i){
			printf("    %lld\n",element[i]);
		}
		printf("\n");
		element.clear();
	}
	return 0;
}
